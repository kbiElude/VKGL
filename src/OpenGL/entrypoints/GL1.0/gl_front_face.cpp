#include "OpenGL/entrypoints/GL1.0/gl_front_face.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_mode)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glFrontFace(GLenum mode)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLFrontFace(dispatch_table_ptr->bound_context_ptr,
                                     mode);
}

void vkglFrontFace_execute(VKGL::Context* in_context_ptr,
                           const GLenum&  in_mode)
{
    const auto orientation_vkgl = VKGL::Utils::get_front_face_orientation_for_gl_enum(in_mode);

    in_context_ptr->set_front_face_orientation(orientation_vkgl);
}

void vkglFrontFace_with_validation(VKGL::Context* in_context_ptr,
                                   const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_mode) )
    {
        vkglFrontFace_execute(in_context_ptr,
                              in_mode);
    }
}