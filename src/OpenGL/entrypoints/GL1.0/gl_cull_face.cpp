#include "OpenGL/entrypoints/GL1.0/gl_cull_face.h"
#include "OpenGL/globals.h"

VKGL_API void VKGL_APIENTRY glCullFace(GLenum mode)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLCullFace(dispatch_table_ptr->bound_context_ptr,
                                    mode);
}

void vkglCullFace_with_validation(VKGL::Context* in_context_ptr,
                                  const GLenum&  in_mode)
{
    todo;
}