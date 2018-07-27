#include "OpenGL/entrypoints/GL1.0/gl_depth_range.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context*  in_context_ptr,
                     const GLdouble& in_n,
                     const GLdouble& in_f)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glDepthRange(GLdouble n,
                                         GLdouble f)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDepthRange(dispatch_table_ptr->bound_context_ptr,
                                      n,
                                      f);
}

void vkglDepthRange_with_validation(VKGL::Context*  in_context_ptr,
                                    const GLdouble& in_n,
                                    const GLdouble& in_f)
{
    todo;
}