/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_NAMESPACE_H
#define VKGL_NAMESPACE_H

#include "OpenGL/types.h"


namespace OpenGL
{
    class Namespace
    {
    public:
        /* Public functions */
         Namespace();
        ~Namespace();

        void allocate   (const uint32_t& in_n_ids,
                         GLuint*         out_ids_ptr);
        bool is_alive_id(const GLuint&   in_id) const;
        void release    (const uint32_t& in_n_ids,
                         const GLuint*   in_ids_ptr);

    private:
        /* Private variables */
        std::vector<GLuint> alive_ids;
        std::vector<GLuint> returned_ids;
    };

    typedef std::unique_ptr<Namespace> NamespaceUniquePtr;
}

#endif /* VKGL_NAMESPACE_H */