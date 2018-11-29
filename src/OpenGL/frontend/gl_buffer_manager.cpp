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

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLBufferManager::clone_internal_data_object(const void* in_ptr)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Buffer*>(in_ptr); });

    result_ptr.reset(
        new Buffer(*reinterpret_cast<const Buffer*>(in_ptr) )
    );
    vkgl_assert(result_ptr != nullptr);

    return result_ptr;
}

void OpenGL::GLBufferManager::copy_internal_data_object(const void* in_src_ptr,
                                                        void*       in_dst_ptr)
{
    *reinterpret_cast<Buffer*>(in_dst_ptr) = *reinterpret_cast<const Buffer*>(in_src_ptr);
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
        result_ptr = buffer_ptr->state.map_pointer;
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
        result = static_cast<size_t>(buffer_ptr->state.size);
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

bool OpenGL::GLBufferManager::get_buffer_state_ptr(const GLuint&                     in_id,
                                                   const OpenGL::TimeMarker*         in_opt_time_marker_ptr,
                                                   const OpenGL::BufferState**       out_state_ptr) const
{
    auto buffer_ptr = get_buffer_ptr(in_id,
                                     in_opt_time_marker_ptr);
    bool result     = false;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        *out_state_ptr = &buffer_ptr->state;
        result         = true;
    }

    return result;
}

OpenGL::BufferUsage OpenGL::GLBufferManager::get_buffer_usage(const GLuint&             in_id,
                                                              const OpenGL::TimeMarker* in_opt_time_marker_ptr) const
{
    auto                buffer_ptr = get_buffer_ptr(in_id,
                                                    in_opt_time_marker_ptr);
    OpenGL::BufferUsage result     = OpenGL::BufferUsage::Unknown;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        result = buffer_ptr->state.usage;
    }

    return result;
}

bool OpenGL::GLBufferManager::get_buffer_used_buffer_targets(const GLuint&                in_id,
                                                             const OpenGL::TimeMarker*    in_opt_time_marker_ptr,
                                                             uint32_t*                    out_n_result_targets_ptr,
                                                             const OpenGL::BufferTarget** out_result_targets_ptr_ptr) const
{
    auto buffer_ptr = get_buffer_ptr(in_id,
                                     in_opt_time_marker_ptr);
    bool result     = false;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        const uint32_t n_buffer_targets_used = static_cast<uint32_t>(buffer_ptr->state.buffer_targets_used.size() );

        *out_n_result_targets_ptr   = n_buffer_targets_used;
        *out_result_targets_ptr_ptr = (n_buffer_targets_used != 0) ? &buffer_ptr->state.buffer_targets_used.at(0)
                                                                   : nullptr;

        result = true;
    }

    return result;
}

void OpenGL::GLBufferManager::on_buffer_bound_to_buffer_target(const GLuint&               in_id,
                                                               const OpenGL::BufferTarget& in_target)
{
    auto buffer_ptr = get_buffer_ptr(in_id,
                                     nullptr); /* in_opt_time_marker_ptr */
    bool result     = false;

    vkgl_assert(buffer_ptr != nullptr);
    if (buffer_ptr != nullptr)
    {
        if (std::find(buffer_ptr->state.buffer_targets_used.begin(),
                      buffer_ptr->state.buffer_targets_used.end  (),
                      in_target) == buffer_ptr->state.buffer_targets_used.end() )
        {
            buffer_ptr->state.buffer_targets_used.push_back(in_target);

            update_last_modified_time(in_id);
        }
    }
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
        if (buffer_ptr->state.size != in_size)
        {
            buffer_ptr->state.size = in_size;

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
        if (buffer_ptr->state.usage != in_usage)
        {
            buffer_ptr->state.usage = in_usage;

            update_last_modified_time(in_id);
        }

        result = true;
    }

    return result;
}
