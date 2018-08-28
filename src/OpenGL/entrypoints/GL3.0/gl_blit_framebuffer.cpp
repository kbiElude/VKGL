/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "OpenGL/entrypoints/GL3.0/gl_blit_framebuffer.h"
#include "OpenGL/context.h"
#include "OpenGL/globals.h"
#include "OpenGL/utils_enum.h"

static bool validate(VKGL::Context*    in_context_ptr,
                     const GLint&      in_src_x0,
                     const GLint&      in_src_y0,
                     const GLint&      in_src_x1,
                     const GLint&      in_src_y1,
                     const GLint&      in_dst_x0,
                     const GLint&      in_dst_y0,
                     const GLint&      in_dst_x1,
                     const GLint&      in_dst_y1,
                     const GLbitfield& in_mask,
                     const GLenum&     in_filter)\
{
    bool result = false;

    // ..

    result = true;
    return result;
}

void VKGL_APIENTRY OpenGL::vkglBlitFramebuffer(GLint      srcX0,
                                               GLint      srcY0,
                                               GLint      srcX1,
                                               GLint      srcY1,
                                               GLint      dstX0,
                                               GLint      dstY0,
                                               GLint      dstX1,
                                               GLint      dstY1,
                                               GLbitfield mask,
                                               GLenum     filter)
{
    const auto& dispatch_table_ptr = OpenGL::g_dispatch_table_ptr;

    dispatch_table_ptr->pGLBlitFramebuffer(dispatch_table_ptr->bound_context_ptr,
                                           srcX0,
                                           srcY0,
                                           srcX1,
                                           srcY1,
                                           dstX0,
                                           dstY0,
                                           dstX1,
                                           dstY1,
                                           mask,
                                           filter);
}

static void vkglBlitFramebuffer_execute(VKGL::Context*    in_context_ptr,
                                        const GLint&      in_src_x0,
                                        const GLint&      in_src_y0,
                                        const GLint&      in_src_x1,
                                        const GLint&      in_src_y1,
                                        const GLint&      in_dst_x0,
                                        const GLint&      in_dst_y0,
                                        const GLint&      in_dst_x1,
                                        const GLint&      in_dst_y1,
                                        const GLbitfield& in_mask,
                                        const GLenum&     in_filter)
{
    const auto filter_vkgl = VKGL::Utils::get_blit_filter_for_gl_enum   (in_filter);
    const auto mask_vkgl   = VKGL::Utils::get_blit_mask_bits_for_gl_enum(in_mask);

    in_context_ptr->blit_framebuffer(in_src_x0,
                                     in_src_y0,
                                     in_src_x1,
                                     in_src_y1,
                                     in_dst_x0,
                                     in_dst_y0,
                                     in_dst_x1,
                                     in_dst_y1,
                                     mask_vkgl,
                                     filter_vkgl);
}

void OpenGL::vkglBlitFramebuffer_with_validation(VKGL::Context*    in_context_ptr,
                                                 const GLint&      in_src_x0,
                                                 const GLint&      in_src_y0,
                                                 const GLint&      in_src_x1,
                                                 const GLint&      in_src_y1,
                                                 const GLint&      in_dst_x0,
                                                 const GLint&      in_dst_y0,
                                                 const GLint&      in_dst_x1,
                                                 const GLint&      in_dst_y1,
                                                 const GLbitfield& in_mask,
                                                 const GLenum&     in_filter)
{
    if (validate(in_context_ptr,
                 in_src_x0,
                 in_src_y0,
                 in_src_x1,
                 in_src_y1,
                 in_dst_x0,
                 in_dst_y0,
                 in_dst_x1,
                 in_dst_y1,
                 in_mask,
                 in_filter) )
    {
        vkglBlitFramebuffer_execute(in_context_ptr,
                                    in_src_x0,
                                    in_src_y0,
                                    in_src_x1,
                                    in_src_y1,
                                    in_dst_x0,
                                    in_dst_y0,
                                    in_dst_x1,
                                    in_dst_y1,
                                    in_mask,
                                    in_filter);
    }
}
