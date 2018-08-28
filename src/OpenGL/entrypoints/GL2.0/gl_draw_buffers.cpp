#include "OpenGL/entrypoints/GL2.0/gl_draw_buffers.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

#define N_MAX_DRAW_BUFFERS (32)

static bool validate(VKGL::Context* in_context_ptr,
                     const GLsizei& in_n,
                     const GLenum*  in_bufs)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglDrawBuffers(GLsizei       n,
                                           const GLenum* bufs)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDrawBuffers(dispatch_table_ptr->bound_context_ptr,
                                       n,
                                       bufs);
}

static void vkglDrawBuffers_execute(VKGL::Context* in_context_ptr,
                                    const GLsizei& in_n,
                                    const GLenum*  in_bufs)
{
    VKGL::DrawBuffer bufs_vkgl[N_MAX_DRAW_BUFFERS];

    vkgl_assert(in_n < N_MAX_DRAW_BUFFERS);

    for (uint32_t n = 0;
                  n < in_n;
                ++n)
    {
        bufs_vkgl[n] = VKGL::Utils::get_draw_buffer_for_gl_enum(in_bufs[n]);
    }

    in_context_ptr->draw_buffers(in_n,
                                 bufs_vkgl);
}

void OpenGL::vkglDrawBuffers_with_validation(VKGL::Context* in_context_ptr,
                                             const GLsizei& in_n,
                                             const GLenum*  in_bufs)
{
    if (validate(in_context_ptr,
                 in_n,
                 in_bufs) )
    {
        vkglDrawBuffers_execute(in_context_ptr,
                                in_n,
                                in_bufs);
    }
}