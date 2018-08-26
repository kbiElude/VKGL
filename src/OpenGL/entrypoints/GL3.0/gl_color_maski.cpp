/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_color_maski.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*   in_context_ptr,
                     const GLuint&    in_index,
                     const GLboolean& in_r,
                     const GLboolean& in_g,
                     const GLboolean& in_b,
                     const GLboolean& in_a)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY vkglColorMaski(GLuint    index,
                                  GLboolean r,
                                  GLboolean g,
                                  GLboolean b,
                                  GLboolean a)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLColorMaski(dispatch_table_ptr->bound_context_ptr,
                                      index,
                                      r,
                                      g,
                                      b,
                                      a);
}

void vkglColorMaski_execute(VKGL::Context*   in_context_ptr,
                            const GLuint&    in_index,
                            const GLboolean& in_r,
                            const GLboolean& in_g,
                            const GLboolean& in_b,
                            const GLboolean& in_a)
{
    in_context_ptr->set_color_maski(in_index,
                                    in_r,
                                    in_g,
                                    in_b,
                                    in_a);
}

void vkglColorMaski_with_validation(VKGL::Context*   in_context_ptr,
                                    const GLuint&    in_index,
                                    const GLboolean& in_r,
                                    const GLboolean& in_g,
                                    const GLboolean& in_b,
                                    const GLboolean& in_a)
{
    if (validate(in_context_ptr,
                 in_index,
                 in_r,
                 in_g,
                 in_b,
                 in_a) )
    {
        vkglColorMaski_execute(in_context_ptr,
                               in_index,
                               in_r,
                               in_g,
                               in_b,
                               in_a);
    }
}
