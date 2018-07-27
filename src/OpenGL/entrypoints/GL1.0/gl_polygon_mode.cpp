#include "OpenGL/entrypoints/GL1.0/gl_polygon_mode.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_face,
                     const GLenum&  in_mode)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API void VKGL_APIENTRY glPolygonMode(GLenum face,
                                          GLenum mode)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLPolygonMode(dispatch_table_ptr->bound_context_ptr,
                                       face,
                                       mode);
}

void vkglPolygonMode_with_validation(VKGL::Context* in_context_ptr,
                                     const GLenum&  in_face,
                                     const GLenum&  in_mode)
{
    if (validate(in_context_ptr,
                 in_face,
                 in_mode) )
    {
        todo;
    }
}