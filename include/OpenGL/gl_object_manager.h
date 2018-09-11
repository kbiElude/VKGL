/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_OBJECT_MANAGER_H
#define VKGL_GL_OBJECT_MANAGER_H

#include "OpenGL/gl_reference.h"
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

    class GLObjectManager : public IObjectManagerReferenceRelease,
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

        GLReferenceUniquePtr acquire_reference(const GLuint& in_id);

        virtual ~GLObjectManager();

    protected:
        /* Protected type definitions */

        enum class Status
        {
            Created_Not_Bound,
            Alive,
            Deleted_Bindings_Pending,

            Unknown
        };

        /* IGLObjectManager interface */
        GLReferenceUniquePtr get_default_object_reference() const final;

        /* IObjectManagerReferenceRelease interface */
        void release_reference(const OpenGL::GLReference* in_reference_ptr) final;

        /* Protected functions */

        GLObjectManager(const GLuint& in_first_valid_nondefault_id,
                        const bool&   in_expose_default_object);

        bool init();

        /* NOTE: Functions below are called with m_lock acquired! */
        virtual bool     add_reference    (const GLuint&      in_id,
                                           const GLReference* in_reference_ptr) = 0;
        virtual bool     delete_object    (const GLuint&      in_id)            = 0;
        virtual bool     delete_reference (const GLuint&      in_id,
                                           const GLReference* in_reference_ptr) = 0;
        virtual uint32_t get_n_references (const GLuint&      in_id) const      = 0;
        virtual Status   get_object_status(const GLuint&      in_id) const      = 0;
        virtual bool     insert_object    (const GLuint&      in_id)            = 0;
        virtual bool     is_id_valid      (const GLuint&      in_id) const      = 0;
        virtual bool     set_object_status(const GLuint&      in_id,
                                           const Status&      in_new_status)    = 0;

        /* Private variables */
        OpenGL::NamespaceUniquePtr m_id_manager_ptr;

        GLReferenceUniquePtr m_default_object_reference_ptr;
        const bool           m_expose_default_object;
        const GLuint         m_first_valid_nondefault_id;
        mutable std::mutex   m_lock;
        bool                 m_releasing;

        friend class GLReference;
    };
}
#endif /* VKGL_GL_OBJECT_MANAGER_H */