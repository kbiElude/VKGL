/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_sample_maski.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLuint&     in_mask_number,
                     const GLbitfield& in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

VKGL_API void VKGL_APIENTRY vkglSampleMaski(GLuint     maskNumber,
                                            GLbitfield mask)
{
    const auto& dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLSampleMaski(dispatch_table_ptr->bound_context_ptr,
                                       maskNumber,
                                       mask);
}

void vkglSampleMaski_execute(VKGL::Context*    in_context_ptr,
                             const GLuint&     in_mask_number,
                             const GLbitfield& in_mask)
{
    in_context_ptr->set_sample_mask(in_mask_number,
                                    in_mask);
}

void vkglSampleMaski_with_validation(VKGL::Context*    in_context_ptr,
                                     const GLuint&     in_mask_number,
                                     const GLbitfield& in_mask)
{
    if (validate(in_context_ptr,
                 in_mask_number,
                 in_mask) )
    {
        vkglSampleMaski_execute(in_context_ptr,
                                in_mask_number,
                                in_mask);
    }
}
