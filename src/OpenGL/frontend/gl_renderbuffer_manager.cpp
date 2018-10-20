/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_renderbuffer_manager.h"
#include "OpenGL/frontend/gl_reference.h"


OpenGL::GLRenderbufferManager::GLRenderbufferManager()
    :GLObjectManager(1,    /* in_first_valid_nondefault_id */
                     true) /* in_expose_default_object     */
{
    /*  Stub */
}

OpenGL::GLRenderbufferManager::~GLRenderbufferManager()
{
    /* Stub - everything is handled by the base class. */
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLRenderbufferManager::clone_internal_data_object(const void* in_ptr)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Renderbuffer*>(in_ptr); });

    result_ptr.reset(
        new Renderbuffer(*reinterpret_cast<const Renderbuffer*>(in_ptr) )
    );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

void OpenGL::GLRenderbufferManager::copy_internal_data_object(const void* in_src_ptr,
                                                              void*       in_dst_ptr)
{
    *reinterpret_cast<Renderbuffer*>(in_dst_ptr) = *reinterpret_cast<const Renderbuffer*>(in_src_ptr);
}

OpenGL::GLRenderbufferManagerUniquePtr OpenGL::GLRenderbufferManager::create()
{
    OpenGL::GLRenderbufferManagerUniquePtr result_ptr;

    result_ptr.reset(new GLRenderbufferManager() );

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

end:
    return result_ptr;
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLRenderbufferManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Renderbuffer*>(in_ptr); });

    result_ptr.reset(
        new Renderbuffer()
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

const OpenGL::GLRenderbufferManager::Renderbuffer* OpenGL::GLRenderbufferManager::get_renderbuffer_ptr(const GLuint&             in_id,
                                                                                                       const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    return reinterpret_cast<const OpenGL::GLRenderbufferManager::Renderbuffer*>(get_internal_object_props_ptr(in_id,
                                                                                                              in_opt_time_marker_ptr) );
}

OpenGL::GLRenderbufferManager::Renderbuffer* OpenGL::GLRenderbufferManager::get_renderbuffer_ptr(const GLuint&             in_id,
                                                                                                 const OpenGL::TimeMarker* in_opt_time_marker_ptr)
{
    return reinterpret_cast<OpenGL::GLRenderbufferManager::Renderbuffer*>(get_internal_object_props_ptr(in_id,
                                                                                                        in_opt_time_marker_ptr) );
}

void OpenGL::GLRenderbufferManager::get_renderbuffer_property(const GLuint&                       in_id,
                                                              const OpenGL::TimeMarker*           in_opt_time_marker_ptr,
                                                              const OpenGL::RenderbufferProperty& in_pname,
                                                              const OpenGL::GetSetArgumentType&   in_arg_type,
                                                              const uint32_t&                     in_n_args,
                                                              void*                               out_result_ptr) const
{
    vkgl_not_implemented();
}

bool OpenGL::GLRenderbufferManager::set_renderbuffer_storage(const GLuint&                 in_id,
                                                             const OpenGL::InternalFormat& in_internalformat,
                                                             const uint32_t&               in_width,
                                                             const uint32_t&               in_height,
                                                             const uint32_t&               in_samples)
{
    auto rb_ptr = get_renderbuffer_ptr(in_id,
                                       nullptr); /* in_opt_time_marker_ptr */
    bool result = false;

    vkgl_assert(rb_ptr != nullptr);
    if (rb_ptr != nullptr)
    {
        if (rb_ptr->height         != in_height         ||
            rb_ptr->internalformat != in_internalformat ||
            rb_ptr->samples        != in_samples        ||
            rb_ptr->width          != in_width)
        {
            rb_ptr->height         = in_height;
            rb_ptr->internalformat = in_internalformat;
            rb_ptr->samples        = in_samples;
            rb_ptr->width          = in_width;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}