/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_NAMESPACE_H
#define VKGL_NAMESPACE_H

#include "OpenGL/types.h"


namespace OpenGL
{
    /* NOT MT-safe
     *
     * MT-safety should not be required, given only one thread at a time is allowed to issue GL commands
     * against a given GL context.
     */
    class Namespace
    {
    public:
        /* Public functions */
         Namespace(const GLuint& in_start_id = 0);
        ~Namespace();

        void allocate   (const uint32_t& in_n_ids,
                         GLuint*         out_ids_ptr);
        void release    (const uint32_t& in_n_ids,
                         const GLuint*   in_ids_ptr);

    private:
        /* Private variables */
        std::vector<GLuint> m_available_ids;

        GLuint       m_n_allocated_ids;
        const GLuint m_start_id;
    };

    typedef std::unique_ptr<Namespace> NamespaceUniquePtr;
}

#endif /* VKGL_NAMESPACE_H */