/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.2/gl_sample_maski.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"

static bool validate(OpenGL::Context*  in_context_ptr,
                     const GLuint&     in_mask_number,
                     const GLbitfield& in_mask)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglSampleMaski(GLuint     maskNumber,
                                           GLbitfield mask)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    VKGL_TRACE("glSampleMaski(maskNumber=[%u] mask=[%x])",
               maskNumber,
               mask);

    dispatch_table_ptr->pGLSampleMaski(dispatch_table_ptr->bound_context_ptr,
                                       maskNumber,
                                       mask);
}

static void vkglSampleMaski_execute(OpenGL::Context*  in_context_ptr,
                                    const GLuint&     in_mask_number,
                                    const GLbitfield& in_mask)
{
    in_context_ptr->set_sample_mask(in_mask_number,
                                    in_mask);
}

void OpenGL::vkglSampleMaski_with_validation(OpenGL::Context*  in_context_ptr,
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
