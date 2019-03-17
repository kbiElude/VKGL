/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BUFFER_MANAGER_H
#define VKGL_GL_BUFFER_MANAGER_H

#include "OpenGL/frontend/gl_object_manager.h"
#include "OpenGL/frontend/snapshot_manager.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLBufferManager> GLBufferManagerUniquePtr;

    class GLBufferManager : public GLObjectManager<OpenGL::GLBufferReference, OpenGL::GLBufferReferenceUniquePtr>
    {
    public:
        /* Public functions */

        static GLBufferManagerUniquePtr create();

        ~GLBufferManager();

        void*               get_buffer_map_pointer        (const GLuint&                in_id,
                                                           const OpenGL::TimeMarker*    in_opt_time_marker_ptr) const;
        size_t              get_buffer_size               (const GLuint&                in_id,
                                                           const OpenGL::TimeMarker*    in_opt_time_marker_ptr) const;
        OpenGL::BufferUsage get_buffer_usage              (const GLuint&                in_id,
                                                           const OpenGL::TimeMarker*    in_opt_time_marker_ptr) const;
        bool                get_buffer_used_buffer_targets(const GLuint&                in_id,
                                                           const OpenGL::TimeMarker*    in_opt_time_marker_ptr,
                                                           uint32_t*                    out_n_result_targets_ptr,
                                                           const OpenGL::BufferTarget** out_result_targets_ptr_ptr) const;

        void get_buffer_property (const GLuint&                     in_id,
                                  const OpenGL::TimeMarker*         in_opt_time_marker_ptr,
                                  const OpenGL::BufferProperty&     in_pname,
                                  const OpenGL::GetSetArgumentType& in_arg_type,
                                  const uint32_t&                   in_n_args,
                                  void*                             out_result_ptr) const;
        bool get_buffer_state_ptr(const GLuint&                     in_id,
                                  const OpenGL::TimeMarker*         in_opt_time_marker_ptr,
                                  const OpenGL::BufferState**       out_state_ptr) const;

        void on_buffer_bound_to_buffer_target(const GLuint&               in_id,
                                              const OpenGL::BufferTarget& in_target);

        bool set_buffer_store_size(const GLuint&              in_id,
                                   const size_t&              in_size);
        bool set_buffer_usage     (const GLuint&              in_id,
                                   const OpenGL::BufferUsage& in_usage);

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > clone_internal_data_object (const void* in_ptr,
                                                                                       const bool& in_convert_from_proxy_to_nonproxy) final;
        void                                               copy_internal_data_object  (const void* in_src_ptr,
                                                                                       void*       in_dst_ptr)                        final;
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object()                                              final;

    private:
        /* Private type definitions */

        typedef struct Buffer
        {
            BufferState state;

            Buffer()                        = default;
            Buffer(const Buffer& in_buffer) = default;
        } Buffer;

        /* Private functions */

        GLBufferManager();

        const Buffer* get_buffer_ptr(const GLuint&             in_id,
                                     const OpenGL::TimeMarker* in_opt_time_marker_ptr) const;
        Buffer*       get_buffer_ptr(const GLuint&             in_id,
                                     const OpenGL::TimeMarker* in_opt_time_marker_ptr);

        /* Private variables */
    };
}
#endif /* VKGL_GL_BUFFER_MANAGER_H */