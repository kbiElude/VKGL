/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.3/gl_sample_coverage.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLfloat&   in_value,
                     const GLboolean& in_invert)
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglSampleCoverage(GLfloat   value,
                                              GLboolean invert)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLSampleCoverage(dispatch_table_ptr->bound_context_ptr,
                                          value,
                                          invert);
}

static void vkglSampleCoverage_execute(OpenGL::Context* in_context_ptr,
                                       const GLfloat&   in_value,
                                       const GLboolean& in_invert)
{
    in_context_ptr->sample_coverage(in_value,
                                    in_invert);
}

void OpenGL::vkglSampleCoverage_with_validation(OpenGL::Context* in_context_ptr,
                                                const GLfloat&   in_value,
                                                const GLboolean& in_invert)
{
    if (validate(in_context_ptr,
                 in_value,
                 in_invert) )
    {
        vkglSampleCoverage_execute(in_context_ptr,
                                   in_value,
                                   in_invert);
    }
}
