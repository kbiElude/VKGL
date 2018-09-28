/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_OBJECT_MANAGER_H
#define VKGL_GL_OBJECT_MANAGER_H

#include "OpenGL/frontend/gl_reference.h"
#include "OpenGL/namespace.h"

namespace OpenGL
{
    class IGLObjectManager
    {
    public:
        virtual ~IGLObjectManager()
        {
            /* Stub */
        }

        virtual GLReferenceUniquePtr get_default_object_reference() const = 0;
    };

    class GLObjectManager : public IObjectManagerReference,
                            public IGLObjectManager
    {
    public:
        /* Public functions */

        bool delete_ids      (const uint32_t& in_n_ids,
                              const GLuint*   in_ids_ptr);
        bool generate_ids    (const uint32_t& in_n_ids,
                              GLuint*         out_ids_ptr);
        bool is_alive_id     (const GLuint&   in_id)       const;
        bool mark_id_as_alive(const GLuint&   in_id);

        GLReferenceUniquePtr acquire_always_latest_snapshot_reference (const GLuint& in_id);
        GLReferenceUniquePtr acquire_current_latest_snapshot_reference(const GLuint& in_id);

        virtual ~GLObjectManager();

    protected:
        /* Protected type definitions */

        enum class Status
        {
            Created_Not_Bound,
            Alive,
            Deleted_References_Pending,

            Unknown
        };

        typedef struct GeneralObjectProps
        {
            GLuint                                             id;
            std::unique_ptr<void, std::function<void(void*)> > internal_data_ptr;
            OpenGL::TimeMarker                                 last_modified_time;
            std::vector<const GLReference*>                    references;
            Status                                             status;

            GeneralObjectProps()
            {
                id                 = UINT32_MAX;
                last_modified_time = std::chrono::high_resolution_clock::now();
                status             = Status::Unknown;
            }

            GeneralObjectProps(const GLuint& in_id)
            {
                id                 = in_id;
                last_modified_time = std::chrono::high_resolution_clock::now();
                status             = Status::Created_Not_Bound;
            }
        } GeneralObjectProps;

        /* IGLObjectManager interface */
        GLReferenceUniquePtr get_default_object_reference() const final;

        /* IObjectManagerReference interface */
        GLReferenceUniquePtr acquire_reference     (const GLuint&              in_id,
                                                    const OpenGL::TimeMarker&  in_time_marker)   final;
        void                 on_reference_created  (const OpenGL::GLReference* in_reference_ptr) final;
        void                 on_reference_destroyed(const OpenGL::GLReference* in_reference_ptr) final;

        /* Protected functions */

        GLObjectManager(const GLuint& in_first_valid_nondefault_id,
                        const bool&   in_expose_default_object);

        const GeneralObjectProps* get_general_object_props_ptr (const GLuint& in_id) const;
        const void*               get_internal_object_props_ptr(const GLuint& in_id) const;
        void*                     get_internal_object_props_ptr(const GLuint& in_id);
        bool                      init                         ();
        void                      update_last_modified_time    (const GLuint& in_id);

        virtual std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object(const GLuint& in_id) = 0;

        /* Protected variables */
        OpenGL::NamespaceUniquePtr m_id_manager_ptr;

        GLReferenceUniquePtr m_default_object_reference_ptr;
        const bool           m_expose_default_object;
        const GLuint         m_first_valid_nondefault_id;
        mutable std::mutex   m_lock;
        bool                 m_releasing;

    private:
        /* Private functions */

        bool     delete_object    (const GLuint&      in_id);
        uint32_t get_n_references (const GLuint&      in_id) const;
        Status   get_object_status(const GLuint&      in_id) const;
        bool     insert_object    (const GLuint&      in_id);
        bool     is_id_valid      (const GLuint&      in_id) const;
        bool     set_object_status(const GLuint&      in_id,
                                   const Status&      in_new_status);

        GeneralObjectProps* get_general_object_props_ptr(const GLuint& in_id);

        /* Private variables */
        std::unordered_map<GLuint, std::unique_ptr<GeneralObjectProps> > m_object_ptrs;

        friend class GLReference;
    };
}
#endif /* VKGL_GL_OBJECT_MANAGER_H */