/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_OBJECT_MANAGER_H
#define VKGL_GL_OBJECT_MANAGER_H

#include "OpenGL/namespace.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    class IGLObjectManager
    {
    public:
        virtual ~IGLObjectManager()
        {
            /* Stub */
        }

        virtual GLBindingUniquePtr get_default_object_binding() const = 0;
    };

    class GLObjectManager : public IObjectManagerBindingRelease,
                            public IGLObjectManager
    {
    public:
        /* Public functions */

        bool delete_ids      (const uint32_t& in_n_ids,
                              const GLuint*   in_ids_ptr);
        bool generate_ids    (const uint32_t& in_n_ids,
                              GLuint*         out_ids_ptr);
        bool is_alive_id     (const GLuint&   in_id)       const;
        bool mark_id_as_bound(const GLuint&   in_id);

        GLBindingUniquePtr acquire_binding           (const GLuint& in_id);
        GLBindingUniquePtr get_default_object_binding()                    const final;

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

        /* IObjectManagerBindingRelease interface */
        void release_binding(const OpenGL::GLBinding* in_binding_ptr) final;

        /* Protected functions */

        GLObjectManager(const bool&      in_expose_default_object,
                        const IGLLimits* in_limits_ptr);

        bool init();

        /* NOTE: Functions below are called with m_lock acquired! */
        virtual bool     add_binding      (const GLuint&    in_id,
                                           const GLBinding* in_binding_ptr) = 0;
        virtual bool     delete_binding   (const GLuint&    in_id,
                                           const GLBinding* in_binding_ptr) = 0;
        virtual bool     delete_object    (const GLuint&    in_id)          = 0;
        virtual uint32_t get_n_bindings   (const GLuint&    in_id) const    = 0;
        virtual Status   get_object_status(const GLuint&    in_id) const    = 0;
        virtual bool     insert_object    (const GLuint&    in_id)          = 0;
        virtual bool     is_id_valid      (const GLuint&    in_id) const    = 0;
        virtual bool     set_object_status(const GLuint&    in_id,
                                           const Status&    in_new_status)  = 0;

        /* Private variables */
        OpenGL::NamespaceUniquePtr m_id_manager_ptr;
        const IGLLimits* const     m_limits_ptr;

        GLBindingUniquePtr m_default_object_binding_ptr;
        const bool         m_expose_default_object;
        mutable std::mutex m_lock;
        bool               m_releasing;

        friend class GLBinding;
    };
}
#endif /* VKGL_GL_OBJECT_MANAGER_H */