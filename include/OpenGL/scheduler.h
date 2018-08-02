#ifndef VKGL_SCHEDULER_H
#define VKGL_SCHEDULER_H

#include "OpenGL/types.h"

namespace VKGL
{
    typedef std::unique_ptr<Scheduler> SchedulerUniquePtr;

    class Scheduler
    {
    public:
        /* Public functions */
        static SchedulerUniquePtr create();

        ~Scheduler();

        void clear            (const VKGL::ClearBufferBits& in_buffers_to_clear);
        void finish           ();
        void flush            ();
        void get_texture_image(const VKGL::TextureTarget&   in_target,
                               const uint32_t&              in_level,
                               const VKGL::PixelFormat&     in_format,
                               const VKGL::PixelType&       in_type,
                               void*                        out_pixels_ptr);
        void read_pixels      (const int32_t&               in_x,
                               const int32_t&               in_y,
                               const size_t&                in_width,
                               const size_t&                in_height,
                               const VKGL::PixelFormat&     in_format,
                               const VKGL::PixelType&       in_type,
                               void*                        out_pixels_ptr);

    private:
        /* Private functions */

        Scheduler();

        bool init();


        /* Private variables */

    };
}

#endif /* VKGL_SCHEDULER_H */