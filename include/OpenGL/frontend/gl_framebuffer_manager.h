/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_FRAMEBUFFER_MANAGER_H
#define VKGL_GL_FRAMEBUFFER_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/snapshot_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLFramebufferManager> GLFramebufferManagerUniquePtr;

    class GLFramebufferManager : public GLObjectManager<OpenGL::GLFramebufferReference, OpenGL::GLFramebufferReferenceUniquePtr>
    {
    public:
        /* Public functions */

        static GLFramebufferManagerUniquePtr create(const OpenGL::IGLLimits* in_limits_ptr);

        ~GLFramebufferManager();

        void                    get_framebuffer_property(const GLuint&                       in_id,
                                                         const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                                         const OpenGL::RenderbufferProperty& in_pname,
                                                         const OpenGL::GetSetArgumentType&   in_arg_type,
                                                         const uint32_t&                     in_n_args,
                                                         void*                               out_result_ptr) const;
        const FramebufferState* get_framebuffer_state   (const GLuint&                       in_id,
                                                         const OpenGL::TimeMarker*           in_opt_time_marker_ptr) const;

        bool set_attachment_renderbuffer (const GLuint&                             in_id,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          OpenGL::GLRenderbufferReferenceUniquePtr  in_rb_ptr);
        bool set_attachment_texture      (const GLuint&                             in_id,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                          const GLint&                              in_level);
        bool set_attachment_texture_1D   (const GLuint&                             in_id,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                          const GLint&                              in_level);
        bool set_attachment_texture_2D   (const GLuint&                             in_id,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          const OpenGL::TextureTarget&              in_textarget,
                                          OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                          const GLint&                              in_level);
        bool set_attachment_texture_3D   (const GLuint&                             in_id,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          const OpenGL::TextureTarget&              in_textarget,
                                          OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                          const GLint&                              in_level,
                                          const GLint&                              in_zoffset);
        bool set_attachment_texture_layer(const GLuint&                             in_id,
                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                          OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                          const GLint&                              in_level,
                                          const GLint&                              in_layer);

        bool set_draw_buffers(const GLuint&             in_id,
                              const GLsizei&            in_n,
                              const OpenGL::DrawBuffer* in_bufs_ptr);
        bool set_read_buffer (const GLuint&             in_id,
                              const OpenGL::ReadBuffer& in_buf);

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr)     final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr) final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                       final;

    private:
        /* Private type definitions */

        typedef struct Framebuffer
        {
            FramebufferState state;

            Framebuffer& operator=(const Framebuffer& in_framebuffer);
            Framebuffer           (const Framebuffer& in_framebuffer);
            Framebuffer           (const IGLLimits*   in_limits_ptr);
        } Framebuffer;

        /* Private functions */

        GLFramebufferManager(const OpenGL::IGLLimits* in_limits_ptr);

        const Framebuffer* get_framebuffer_ptr(const GLuint&             in_id,
                                               const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        Framebuffer*       get_framebuffer_ptr(const GLuint&             in_id,
                                               const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */
        const OpenGL::IGLLimits* m_limits_ptr;
    };
}
#endif /* VKGL_GL_FRAMEBUFFER_MANAGER_H */
