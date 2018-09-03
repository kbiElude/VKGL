/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL1.0/gl_front_face.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(OpenGL::Context* in_context_ptr,
                     const GLenum&    in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


void VKGL_APIENTRY OpenGL::vkglFrontFace(GLenum mode)
{
    const auto dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFrontFace(dispatch_table_ptr->bound_context_ptr,
                                     mode);
}

static void vkglFrontFace_execute(OpenGL::Context* in_context_ptr,
                                  const GLenum&    in_mode)
{
    const auto orientation_vkgl = OpenGL::Utils::get_front_face_orientation_for_gl_enum(in_mode);

    in_context_ptr->set_front_face_orientation(orientation_vkgl);
}

void OpenGL::vkglFrontFace_with_validation(OpenGL::Context* in_context_ptr,
                                           const GLenum&    in_mode)
{
    if (validate(in_context_ptr,
                 in_mode) )
    {
        vkglFrontFace_execute(in_context_ptr,
                              in_mode);
    }
}