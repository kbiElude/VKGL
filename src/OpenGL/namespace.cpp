/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/namespace.h"

OpenGL::Namespace::Namespace(const GLuint& in_start_id)
    :m_n_allocated_ids(0),
     m_start_id       (in_start_id)
{
    /* Stub */
}

OpenGL::Namespace::~Namespace()
{
    /* Stub */
}

void OpenGL::Namespace::allocate(const uint32_t& in_n_ids,
                                 GLuint*         out_ids_ptr)
{
    uint32_t n_allocated_ids = 0;

    /* Try to assign IDs from a pool of IDs which have already been distributed & returned. */
    while (n_allocated_ids != in_n_ids)
    {
        if (m_available_ids.size() == 0)
        {
            break;
        }
        else
        {
            out_ids_ptr[n_allocated_ids] = m_available_ids.back();

            m_available_ids.pop_back();
            n_allocated_ids++;
        }
    }

    /* Any remaining IDs have to be unique */
    while (n_allocated_ids != in_n_ids)
    {
        out_ids_ptr[n_allocated_ids] = (m_start_id) + m_n_allocated_ids;

        m_n_allocated_ids++;
        n_allocated_ids++;
    }
}

void OpenGL::Namespace::release(const uint32_t& in_n_ids,
                                const GLuint*   in_ids_ptr)
{
    for (uint32_t n_id = 0;
                  n_id < in_n_ids;
                ++n_id)
    {
        vkgl_assert(std::find(m_available_ids.begin(),
                              m_available_ids.end(),
                              in_ids_ptr[n_id]) == m_available_ids.end() );

        m_available_ids.push_back(in_ids_ptr[n_id]);
    }
}
