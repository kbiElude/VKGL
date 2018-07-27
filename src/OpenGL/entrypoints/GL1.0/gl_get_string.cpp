#include "OpenGL/entrypoints/GL1.0/gl_get_string.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_name)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


VKGL_API const GLubyte *APIENTRY glGetString(GLenum name)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    return dispatch_table_ptr->pGLGetString(dispatch_table_ptr->bound_context_ptr,
                                            name);
}

const GLubyte* vkglGetString_with_validation(VKGL::Context* in_context_ptr,
                                             const GLenum&  in_name)
{
    if (validate(in_context_ptr,
                 in_name) )
    {
        todo;
    }
}