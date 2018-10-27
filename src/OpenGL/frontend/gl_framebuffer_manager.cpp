/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_framebuffer_manager.h"
#include "OpenGL/frontend/gl_reference.h"


OpenGL::GLFramebufferManager::Framebuffer& OpenGL::GLFramebufferManager::Framebuffer::operator=(const Framebuffer& in_framebuffer)
{
    state = in_framebuffer.state;

    return *this;
}

OpenGL::GLFramebufferManager::Framebuffer::Framebuffer(const OpenGL::GLFramebufferManager::Framebuffer& in_framebuffer)
{
    state = in_framebuffer.state;
}

OpenGL::GLFramebufferManager::Framebuffer::Framebuffer(const OpenGL::IGLLimits* in_limits_ptr)
    :state(in_limits_ptr->get_max_color_attachments() )
{
    /* Stub */
}

OpenGL::GLFramebufferManager::GLFramebufferManager(const OpenGL::IGLLimits* in_limits_ptr,
                                                   const VKGL::IWSIContext* in_wsi_context_ptr)
    :GLObjectManager  (0,     /* in_first_valid_nondefault_id */
                       true), /* in_expose_default_object     */
     m_limits_ptr     (in_limits_ptr),
     m_wsi_context_ptr(in_wsi_context_ptr)
{
    /*  Stub */
}

OpenGL::GLFramebufferManager::~GLFramebufferManager()
{
    /* Stub - everything is handled by the base class. */
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLFramebufferManager::clone_internal_data_object(const void* in_ptr)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Framebuffer*>(in_ptr); });

    result_ptr.reset(
        new Framebuffer(*reinterpret_cast<const Framebuffer*>(in_ptr) )
    );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

void OpenGL::GLFramebufferManager::copy_internal_data_object(const void* in_src_ptr,
                                                             void*       in_dst_ptr)
{
    *reinterpret_cast<Framebuffer*>(in_dst_ptr) = *reinterpret_cast<const Framebuffer*>(in_src_ptr);
}

OpenGL::GLFramebufferManagerUniquePtr OpenGL::GLFramebufferManager::create(const OpenGL::IGLLimits* in_limits_ptr,
                                                                           const VKGL::IWSIContext* in_wsi_context_ptr)
{
    OpenGL::GLFramebufferManagerUniquePtr result_ptr;

    result_ptr.reset(new GLFramebufferManager(in_limits_ptr,
                                              in_wsi_context_ptr) );

    if (result_ptr == nullptr)
    {
        vkgl_assert(result_ptr != nullptr);

        goto end;
    }

    if (!result_ptr->init() )
    {
        vkgl_assert_fail();

        result_ptr.reset();
    }

    /* Make sure to set default framebuffer's draw buffer to Back. */
    {
        static const OpenGL::DrawBuffer default_fb_draw_buffer = OpenGL::DrawBuffer::Back;

        result_ptr->set_draw_buffers(0, /* in_id */
                                     1, /* in_n  */
                                    &default_fb_draw_buffer);
    }

    /* If depth and/or stencil planes were requested, mark that in default FB's config, too. */
    {
        auto        default_fb_ptr    = result_ptr->get_framebuffer_ptr                  (0, /* in_id */
                                                                                          nullptr);
        const auto& pixel_format_reqs = in_wsi_context_ptr->get_pixel_format_requirements();
        bool        update_needed     = false;

        if (pixel_format_reqs.n_depth_bits > 0)
        {
            default_fb_ptr->state.depth_attachment.type = OpenGL::FramebufferAttachmentObjectType::Framebuffer_Default;
            update_needed                               = true;
        }

        if (pixel_format_reqs.n_stencil_bits > 0)
        {
            default_fb_ptr->state.stencil_attachment.type = OpenGL::FramebufferAttachmentObjectType::Framebuffer_Default;
            update_needed                                 = true;
        }

        if (update_needed)
        {
            result_ptr->update_last_modified_time(0 /* in_id */);
        }
    }

end:
    return result_ptr;
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLFramebufferManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Framebuffer*>(in_ptr); });

    result_ptr.reset(
        new Framebuffer(m_limits_ptr)
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

const OpenGL::GLFramebufferManager::Framebuffer* OpenGL::GLFramebufferManager::get_framebuffer_ptr(const GLuint&             in_id,
                                                                                                   const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    return reinterpret_cast<const OpenGL::GLFramebufferManager::Framebuffer*>(get_internal_object_props_ptr(in_id,
                                                                                                            in_opt_time_marker_ptr) );
}

OpenGL::GLFramebufferManager::Framebuffer* OpenGL::GLFramebufferManager::get_framebuffer_ptr(const GLuint&             in_id,
                                                                                              const OpenGL::TimeMarker* in_opt_time_marker_ptr)
{
    return reinterpret_cast<OpenGL::GLFramebufferManager::Framebuffer*>(get_internal_object_props_ptr(in_id,
                                                                                                      in_opt_time_marker_ptr) );
}

void OpenGL::GLFramebufferManager::get_framebuffer_property(const GLuint&                       in_id,
                                                            const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                                            const OpenGL::RenderbufferProperty& in_pname,
                                                            const OpenGL::GetSetArgumentType&   in_arg_type,
                                                            const uint32_t&                     in_n_args,
                                                            void*                               out_result_ptr) const
{
    vkgl_not_implemented();
}

const OpenGL::FramebufferState* OpenGL::GLFramebufferManager::get_framebuffer_state(const GLuint&             in_id,
                                                                                    const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    auto                            fb_ptr     = get_framebuffer_ptr(in_id,
                                                                     in_opt_time_marker_ptr);
    const OpenGL::FramebufferState* result_ptr = nullptr;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        result_ptr = &fb_ptr->state;
    }

    return result_ptr;
}

bool OpenGL::GLFramebufferManager::set_attachment_renderbuffer(const GLuint&                             in_id,
                                                               const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                               OpenGL::GLRenderbufferReferenceUniquePtr  in_rb_ptr)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        const auto n_attachment = (static_cast<uint32_t>(in_attachment) - static_cast<uint32_t>(OpenGL::FramebufferAttachmentPoint::Color_Attachment0) );

        vkgl_assert(n_attachment >= 0 &&
                    n_attachment <= 7);

        auto& attachment_props = fb_ptr->state.color_attachments.at(n_attachment);

        if ( attachment_props.type                       != OpenGL::FramebufferAttachmentObjectType::Renderbuffer ||
            *attachment_props.renderbuffer_reference_ptr != *in_rb_ptr)
        {
            attachment_props.renderbuffer_reference_ptr = std::move(in_rb_ptr);
            attachment_props.type                       = OpenGL::FramebufferAttachmentObjectType::Renderbuffer;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLFramebufferManager::set_attachment_texture(const GLuint&                             in_id,
                                                          const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                          OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                                          const GLint&                              in_level)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        const auto n_attachment = (static_cast<uint32_t>(in_attachment) - static_cast<uint32_t>(OpenGL::FramebufferAttachmentPoint::Color_Attachment0) );

        vkgl_assert(n_attachment >= 0 &&
                    n_attachment <= 7);

        auto& attachment_props = fb_ptr->state.color_attachments.at(n_attachment);

        if ( attachment_props.type                  != OpenGL::FramebufferAttachmentObjectType::Texture ||
            *attachment_props.texture_reference_ptr != *in_texture_ptr                                  ||
             attachment_props.texture_level         != in_level)
        {
            attachment_props.type                  = OpenGL::FramebufferAttachmentObjectType::Texture;
            attachment_props.texture_reference_ptr = std::move(in_texture_ptr);
            attachment_props.texture_level         = in_level;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLFramebufferManager::set_attachment_texture_1D(const GLuint&                             in_id,
                                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                             OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                                             const GLint&                              in_level)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        const auto n_attachment = (static_cast<uint32_t>(in_attachment) - static_cast<uint32_t>(OpenGL::FramebufferAttachmentPoint::Color_Attachment0) );

        vkgl_assert(n_attachment >= 0 &&
                    n_attachment <= 7);

        auto& attachment_props = fb_ptr->state.color_attachments.at(n_attachment);

        if ( attachment_props.type                  != OpenGL::FramebufferAttachmentObjectType::Texture_1D ||
            *attachment_props.texture_reference_ptr != *in_texture_ptr                                     ||
             attachment_props.texture_level         != in_level)
        {
            attachment_props.type                  = OpenGL::FramebufferAttachmentObjectType::Texture_1D;
            attachment_props.texture_reference_ptr = std::move(in_texture_ptr);
            attachment_props.texture_level         = in_level;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLFramebufferManager::set_attachment_texture_2D(const GLuint&                             in_id,
                                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                             const OpenGL::TextureTarget&              in_textarget,
                                                             OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                                             const GLint&                              in_level)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        const auto n_attachment          = (static_cast<uint32_t>(in_attachment) - static_cast<uint32_t>(OpenGL::FramebufferAttachmentPoint::Color_Attachment0) );
        const auto texture_cube_map_face = (in_textarget == OpenGL::TextureTarget::Cube_Map_Negative_X) ? OpenGL::TextureCubeMapFace::Negative_X :
                                           (in_textarget == OpenGL::TextureTarget::Cube_Map_Negative_Y) ? OpenGL::TextureCubeMapFace::Negative_Y :
                                           (in_textarget == OpenGL::TextureTarget::Cube_Map_Negative_Z) ? OpenGL::TextureCubeMapFace::Negative_Z :
                                           (in_textarget == OpenGL::TextureTarget::Cube_Map_Positive_X) ? OpenGL::TextureCubeMapFace::Positive_X :
                                           (in_textarget == OpenGL::TextureTarget::Cube_Map_Positive_Y) ? OpenGL::TextureCubeMapFace::Positive_Y :
                                           (in_textarget == OpenGL::TextureTarget::Cube_Map_Positive_Z) ? OpenGL::TextureCubeMapFace::Positive_Z :
                                                                                                          OpenGL::TextureCubeMapFace::None;
        vkgl_assert(n_attachment >= 0 &&
                    n_attachment <= 7);

        auto& attachment_props = fb_ptr->state.color_attachments.at(n_attachment);

        if ( attachment_props.type                  != OpenGL::FramebufferAttachmentObjectType::Texture_2D ||
             attachment_props.texture_cube_map_face != texture_cube_map_face                               ||
            *attachment_props.texture_reference_ptr != *in_texture_ptr                                     ||
             attachment_props.texture_level         != in_level)
        {
            attachment_props.type                  = OpenGL::FramebufferAttachmentObjectType::Texture_2D;
            attachment_props.texture_cube_map_face = texture_cube_map_face;
            attachment_props.texture_reference_ptr = std::move(in_texture_ptr);
            attachment_props.texture_level         = in_level;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLFramebufferManager::set_attachment_texture_3D(const GLuint&                             in_id,
                                                             const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                             const OpenGL::TextureTarget&              in_textarget,
                                                             OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                                             const GLint&                              in_level,
                                                             const GLint&                              in_layer)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(in_textarget == OpenGL::TextureTarget::_3D);
    vkgl_assert(fb_ptr       != nullptr);

    if (fb_ptr != nullptr)
    {
        const auto n_attachment = (static_cast<uint32_t>(in_attachment) - static_cast<uint32_t>(OpenGL::FramebufferAttachmentPoint::Color_Attachment0) );

        vkgl_assert(n_attachment >= 0 &&
                    n_attachment <= 7);

        auto& attachment_props = fb_ptr->state.color_attachments.at(n_attachment);

        if ( attachment_props.type                  != OpenGL::FramebufferAttachmentObjectType::Texture_3D ||
            *attachment_props.texture_reference_ptr != *in_texture_ptr                                     ||
             attachment_props.texture_layer         != in_layer                                            ||
             attachment_props.texture_level         != in_level)
        {
            attachment_props.type                  = OpenGL::FramebufferAttachmentObjectType::Texture_3D;
            attachment_props.texture_reference_ptr = std::move(in_texture_ptr);
            attachment_props.texture_layer         = in_layer;
            attachment_props.texture_level         = in_level;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLFramebufferManager::set_attachment_texture_layer(const GLuint&                             in_id,
                                                                const OpenGL::FramebufferAttachmentPoint& in_attachment,
                                                                OpenGL::GLTextureReferenceUniquePtr       in_texture_ptr,
                                                                const GLint&                              in_level,
                                                                const GLint&                              in_layer)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);

    if (fb_ptr != nullptr)
    {
        const auto n_attachment = (static_cast<uint32_t>(in_attachment) - static_cast<uint32_t>(OpenGL::FramebufferAttachmentPoint::Color_Attachment0) );

        vkgl_assert(n_attachment >= 0 &&
                    n_attachment <= 7);

        auto& attachment_props = fb_ptr->state.color_attachments.at(n_attachment);

        if ( attachment_props.type                  != OpenGL::FramebufferAttachmentObjectType::Texture_Layer ||
            *attachment_props.texture_reference_ptr != *in_texture_ptr                                        ||
             attachment_props.texture_layer         != in_layer                                               ||
             attachment_props.texture_level         != in_level)
        {
            attachment_props.type                  = OpenGL::FramebufferAttachmentObjectType::Texture_Layer;
            attachment_props.texture_reference_ptr = std::move(in_texture_ptr);
            attachment_props.texture_layer         = in_layer;
            attachment_props.texture_level         = in_level;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}


bool OpenGL::GLFramebufferManager::set_draw_buffers(const GLuint&             in_id,
                                                    const GLsizei&            in_n,
                                                    const OpenGL::DrawBuffer* in_bufs_ptr)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        static_assert(sizeof(OpenGL::DrawBuffer)                                                == sizeof(fb_ptr->state.draw_buffer_per_color_output.at(0) ), "");
        vkgl_assert  (static_cast<uint32_t>(fb_ptr->state.draw_buffer_per_color_output.size() ) >= static_cast<uint32_t>(in_n) );

        if (memcmp(fb_ptr->state.draw_buffer_per_color_output.data(),
                   in_bufs_ptr,
                   sizeof(OpenGL::DrawBuffer) * in_n) != 0)
        {
            memcpy(fb_ptr->state.draw_buffer_per_color_output.data(),
                   in_bufs_ptr,
                   sizeof(OpenGL::DrawBuffer) * in_n);

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLFramebufferManager::set_read_buffer(const GLuint&             in_id,
                                                   const OpenGL::ReadBuffer& in_buf)
{
    auto fb_ptr = get_framebuffer_ptr(in_id,
                                      nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(fb_ptr != nullptr);
    if (fb_ptr != nullptr)
    {
        if (fb_ptr->state.read_buffer != in_buf)
        {
            fb_ptr->state.read_buffer = in_buf;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}