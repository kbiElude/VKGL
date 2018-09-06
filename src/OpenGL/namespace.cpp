/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/namespace.h"

OpenGL::Namespace::Namespace()
{
    vkgl_not_implemented();
}

OpenGL::Namespace::~Namespace()
{
    vkgl_not_implemented();
}

void OpenGL::Namespace::allocate(const uint32_t& in_n_ids,
                                 GLuint*         out_ids_ptr)
{
    vkgl_not_implemented();
}

bool OpenGL::Namespace::is_alive_id(const GLuint& in_id) const
{
    vkgl_not_implemented();

    return false;
}

void OpenGL::Namespace::release(const uint32_t& in_n_ids,
                                const GLuint*   in_ids_ptr)
{
    vkgl_not_implemented();
}
