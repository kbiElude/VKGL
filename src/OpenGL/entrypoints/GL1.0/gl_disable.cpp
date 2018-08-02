#include "OpenGL/entrypoints/GL1.0/gl_disable.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context* in_context_ptr,
                     const GLenum&  in_cap)
{
    bool result = false;

    // ..

    result = true;
    return result;
}


VKGL_API void VKGL_APIENTRY glDisable(GLenum cap)
{
    const auto dispatch_table_ptr = g_dispatch_table_ptr;

    dispatch_table_ptr->pGLDisable(dispatch_table_ptr->bound_context_ptr,
                                   cap);
}

void vkglDisable_execute(VKGL::Context* in_context_ptr,
                         const GLenum&  in_cap)
{
    const auto cap_vkgl = VKGL::Utils::get_nonindexed_capability_for_gl_enum(in_cap);

    in_context_ptr->disable(cap_vkgl);
}

void vkglDisable_with_validation(VKGL::Context* in_context_ptr,
                                 const GLenum&  in_cap)
{
    if (validate(in_context_ptr,
                 in_cap) )
    {
        vkglDisable_execute(in_context_ptr,
                            in_cap);
    }
}