/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_RENDERBUFFER_MANAGER_H
#define VKGL_GL_RENDERBUFFER_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/snapshot_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLRenderbufferManager> GLRenderbufferManagerUniquePtr;

    class GLRenderbufferManager : public GLObjectManager<OpenGL::GLRenderbufferReference, OpenGL::GLRenderbufferReferenceUniquePtr>
    {
    public:
        /* Public functions */

        static GLRenderbufferManagerUniquePtr create();

        ~GLRenderbufferManager();

        void get_renderbuffer_property(const GLuint&                       in_id,
                                       const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                       const OpenGL::RenderbufferProperty& in_pname,
                                       const OpenGL::GetSetArgumentType&   in_arg_type,
                                       const uint32_t&                     in_n_args,
                                       void*                               out_result_ptr) const;

        bool set_renderbuffer_storage(const GLuint&                 in_id,
                                      const OpenGL::InternalFormat& in_internalformat,
                                      const uint32_t&               in_width,
                                      const uint32_t&               in_height,
                                      const uint32_t&               in_samples);


    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr,
                                                                                       const bool& in_convert_from_proxy_to_nonproxy) final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr)                        final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                                              final;

    private:
        /* Private type definitions */

        typedef struct Renderbuffer
        {
            uint32_t               alpha_size; //< todo: backend needs to set this at backend-side object creation time
            uint32_t               blue_size;  //< todo: backend needs to set this at backend-side object creation time
            uint32_t               depth_size; //< todo: backend needs to set this at backend-side object creation time
            uint32_t               green_size; //< todo: backend needs to set this at backend-side object creation time
            uint32_t               height;
            OpenGL::InternalFormat internalformat;
            uint32_t               red_size;  //< todo: backend needs to set this at backend-side object creation time
            uint32_t               samples;
            uint32_t               stencil_size; //< todo: backend needs to set this at backend-side object creation time
            uint32_t               width;

            Renderbuffer()
            {
                alpha_size     = 0;
                blue_size      = 0;
                depth_size     = 0;
                green_size     = 0;
                height         = 0;
                internalformat = OpenGL::InternalFormat::RGBA;
                samples        = 0;
                stencil_size   = 0;
                width          = 0;
            }

            Renderbuffer(const Renderbuffer& in_buffer) = default;
        } Renderbuffer;

        /* Private functions */

        GLRenderbufferManager();

        const Renderbuffer* get_renderbuffer_ptr(const GLuint&             in_id,
                                                 const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        Renderbuffer*       get_renderbuffer_ptr(const GLuint&             in_id,
                                                 const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */
    };
}
#endif /* VKGL_GL_BUFFER_MANAGER_H */