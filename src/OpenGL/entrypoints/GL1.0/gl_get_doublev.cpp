#include "OpenGL/entrypoints/GL1.0/gl_get_doublev.h"
#include "OpenGL/globals.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_pname,
                     GLdouble*      out_data_ptr)
{
    bool result = false;

    // ..

    result = true;
end:
    return result;
}


void vkglGetDoublev_with_validation(VKGL::Context* in_context_ptr,
                                    const GLenum&  in_pname,
                                    GLdouble*      out_data_ptr)
{
    todo;
}