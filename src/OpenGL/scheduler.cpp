#include "OpenGL/scheduler.h"

VKGL::Scheduler::Scheduler()
{
    /* Stub */
}

VKGL::Scheduler::~Scheduler()
{
    /* Stub */
}

void VKGL::Scheduler::clear(const VKGL::ClearBufferBits& in_buffers_to_clear)
{
    todo;
}

VKGL::SchedulerUniquePtr VKGL::Scheduler::create()
{
    VKGL::SchedulerUniquePtr result_ptr;

    result_ptr.reset(
        new VKGL::Scheduler()
    );

    if (result_ptr != nullptr)
    {
        if (!result_ptr->init() )
        {
            result_ptr.reset();
        }
    }

    return result_ptr;
}

void VKGL::Scheduler::finish()
{
    todo;
}

void VKGL::Scheduler::flush()
{
    todo;
}

void VKGL::Scheduler::get_texture_image(const VKGL::TextureTarget& in_target,
                                        const uint32_t&            in_level,
                                        const VKGL::PixelFormat&   in_format,
                                        const VKGL::PixelType&     in_type,
                                        void*                      out_pixels_ptr)
{
    todo;
}

void VKGL::Scheduler::read_pixels(const int32_t&           in_x,
                                  const int32_t&           in_y,
                                  const size_t&            in_width,
                                  const size_t&            in_height,
                                  const VKGL::PixelFormat& in_format,
                                  const VKGL::PixelType&   in_type,
                                  void*                    out_pixels_ptr)
{
    todo;
}

bool VKGL::Scheduler::init()
{
    bool result = false;

    // ..

    result = true;
    return result;
}