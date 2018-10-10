/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_SCHEDULER_H
#define VKGL_VK_SCHEDULER_H

#include "Common/ring_buffer.h"
#include "OpenGL/types.h"
#include "OpenGL/backend/vk_commands.h"
#include <atomic>
#include <thread>

namespace OpenGL
{
    class VKScheduler
    {
    public:
        /* Public functions */
        static VKSchedulerUniquePtr create(const IContextObjectManagers* in_frontend_ptr,
                                           IBackend*                     in_backend_ptr);

        ~VKScheduler();

        void submit(OpenGL::CommandBaseUniquePtr in_command_ptr);

    private:
        /* Private functions */
        VKScheduler(const IContextObjectManagers* in_frontend_ptr,
                    IBackend*                     in_backend_ptr);

        bool init                  ();
        void main_thread_entrypoint();
        void process_command       (OpenGL::CommandBaseUniquePtr in_command_ptr);

        void process_buffer_data_command                (OpenGL::CommandBaseUniquePtr            in_command_ptr);
        void process_buffer_sub_data_command            (OpenGL::CommandBaseUniquePtr            in_command_ptr);
        void process_clear_command                      (OpenGL::ClearCommand*                   in_command_ptr);
        void process_compile_shader_command             (OpenGL::CompileShaderCommand*           in_command_ptr);
        void process_compressed_tex_image_1D_command    (OpenGL::CompressedTexImage1DCommand*    in_command_ptr);
        void process_compressed_tex_image_2D_command    (OpenGL::CompressedTexImage2DCommand*    in_command_ptr);
        void process_compressed_tex_image_3D_command    (OpenGL::CompressedTexImage3DCommand*    in_command_ptr);
        void process_compressed_tex_sub_image_1D_command(OpenGL::CompressedTexSubImage1DCommand* in_command_ptr);
        void process_compressed_tex_sub_image_2D_command(OpenGL::CompressedTexSubImage2DCommand* in_command_ptr);
        void process_compressed_tex_sub_image_3D_command(OpenGL::CompressedTexSubImage3DCommand* in_command_ptr);
        void process_copy_buffer_sub_data_command       (OpenGL::CopyBufferSubDataCommand*       in_command_ptr);
        void process_copy_tex_image_1D_command          (OpenGL::CopyTexImage1DCommand*          in_command_ptr);
        void process_copy_tex_image_2D_command          (OpenGL::CopyTexImage2DCommand*          in_command_ptr);
        void process_copy_tex_sub_image_1D_command      (OpenGL::CopyTexSubImage1DCommand*       in_command_ptr);
        void process_copy_tex_sub_image_2D_command      (OpenGL::CopyTexSubImage2DCommand*       in_command_ptr);
        void process_copy_tex_sub_image_3D_command      (OpenGL::CopyTexSubImage3DCommand*       in_command_ptr);
        void process_draw_arrays_command                (OpenGL::DrawArraysCommand*              in_command_ptr);
        void process_draw_elements_command              (OpenGL::DrawElementsCommand*            in_command_ptr);
        void process_draw_range_elements_command        (OpenGL::DrawRangeElementsCommand*       in_command_ptr);
        void process_finish_command                     (OpenGL::FinishCommand*                  in_command_ptr);
        void process_flush_command                      (OpenGL::FlushCommand*                   in_command_ptr);
        void process_flush_mapped_buffer_range_command  (OpenGL::FlushMappedBufferRangeCommand*  in_command_ptr);
        void process_get_buffer_sub_data_command        (OpenGL::GetBufferSubDataCommand*        in_command_ptr);
        void process_get_compressed_tex_image_command   (OpenGL::GetCompressedTexImageCommand*   in_command_ptr);
        void process_get_texture_image_command          (OpenGL::GetTextureImageCommand*         in_command_ptr);
        void process_link_program_command               (OpenGL::LinkProgramCommand*             in_command_ptr);
        void process_map_buffer_command                 (OpenGL::MapBufferCommand*               in_command_ptr);
        void process_multi_draw_arrays_command          (OpenGL::MultiDrawArraysCommand*         in_command_ptr);
        void process_multi_draw_elements_command        (OpenGL::MultiDrawElementsCommand*       in_command_ptr);
        void process_read_pixels_command                (OpenGL::ReadPixelsCommand*              in_command_ptr);
        void process_tex_image_1D_command               (OpenGL::TexImage1DCommand*              in_command_ptr);
        void process_tex_image_2D_command               (OpenGL::TexImage2DCommand*              in_command_ptr);
        void process_tex_image_3D_command               (OpenGL::TexImage3DCommand*              in_command_ptr);
        void process_tex_sub_image_1D_command           (OpenGL::TexSubImage1DCommand*           in_command_ptr);
        void process_tex_sub_image_2D_command           (OpenGL::TexSubImage2DCommand*           in_command_ptr);
        void process_tex_sub_image_3D_command           (OpenGL::TexSubImage3DCommand*           in_command_ptr);
        void process_unmap_buffer_command               (OpenGL::UnmapBufferCommand*             in_command_ptr);
        void process_validate_program_command           (OpenGL::ValidateProgramCommand*         in_command_ptr);

        /* Private variables */
        IBackend*                                                m_backend_ptr;
        std::unique_ptr<VKGL::RingBuffer<CommandBaseUniquePtr> > m_command_ring_buffer_ptr;
        const IContextObjectManagers*                            m_frontend_ptr;
        std::unique_ptr<std::thread>                             m_scheduler_thread_ptr;
        std::atomic_bool                                         m_terminating;
    };
};

#endif /* VKGL_VK_SCHEDULER_H */