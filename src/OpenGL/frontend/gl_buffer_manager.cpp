/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_buffer_manager.h"
#include "OpenGL/frontend/gl_reference.h"


OpenGL::GLBufferManager::GLBufferManager()
    :GLObjectManager(1,    /* in_first_valid_nondefault_id */
                     true) /* in_expose_default_object     */
{
    /*  Stub */
}

OpenGL::GLBufferManager::~GLBufferManager()
{
    /* Stub - everything is handled by the base class. */
}

OpenGL::GLBufferManagerUniquePtr OpenGL::GLBufferManager::create()
{
    OpenGL::GLBufferManagerUniquePtr result_ptr;

    result_ptr.reset(new GLBufferManager() );

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

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLBufferManager::create_internal_data_object()
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Buffer*>(in_ptr); });

    result_ptr.reset(
        new Buffer()
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

void* OpenGL::GLBufferManager::get_buffer_map_pointer(const GLuint&             in_id,
                                                      const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    auto  buffer_ptr = get_buffer_ptr(in_id,
                                      in_opt_time_marker_ptr);
    void* result_ptr = nullptr;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        result_ptr = buffer_ptr->map_pointer;
    }

    return result_ptr;
}

const OpenGL::GLBufferManager::Buffer* OpenGL::GLBufferManager::get_buffer_ptr(const GLuint&             in_id,
                                                                               const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    return reinterpret_cast<const OpenGL::GLBufferManager::Buffer*>(get_internal_object_props_ptr(in_id,
                                                                                                  in_opt_time_marker_ptr) );
}

OpenGL::GLBufferManager::Buffer* OpenGL::GLBufferManager::get_buffer_ptr(const GLuint&             in_id,
                                                                         const OpenGL::TimeMarker* in_opt_time_marker_ptr)
{
    return reinterpret_cast<OpenGL::GLBufferManager::Buffer*>(get_internal_object_props_ptr(in_id,
                                                                                            in_opt_time_marker_ptr) );
}

size_t OpenGL::GLBufferManager::get_buffer_size(const GLuint&             in_id,
                                                const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    auto   buffer_ptr = get_buffer_ptr(in_id,
                                       in_opt_time_marker_ptr);
    size_t result     = 0;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        result = static_cast<size_t>(buffer_ptr->size);
    }

    return result;
}

void OpenGL::GLBufferManager::get_buffer_property(const GLuint&                     in_id,
                                                  const OpenGL::TimeMarker*         in_opt_time_marker_ptr,
                                                  const OpenGL::BufferProperty&     in_pname,
                                                  const OpenGL::GetSetArgumentType& in_arg_type,
                                                  const uint32_t&                   in_n_args,
                                                  void*                             out_result_ptr) const
{
    vkgl_not_implemented();
}

bool OpenGL::GLBufferManager::set_buffer_store_size(const GLuint& in_id,
                                                    const size_t& in_size)
{
    auto buffer_ptr = get_buffer_ptr(in_id,
                                     nullptr); /* in_opt_time_marker_ptr */
    bool result     = false;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        if (buffer_ptr->size != in_size)
        {
            buffer_ptr->size = in_size;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}

bool OpenGL::GLBufferManager::set_buffer_usage(const GLuint&              in_id,
                                               const OpenGL::BufferUsage& in_usage)
{
    auto buffer_ptr = get_buffer_ptr(in_id,
                                     nullptr); /* in_opt_time_marker_ptr */
    bool result     = false;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        if (buffer_ptr->usage != in_usage)
        {
            buffer_ptr->usage = in_usage;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}
