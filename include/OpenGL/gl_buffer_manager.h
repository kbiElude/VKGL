/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_GL_BUFFER_MANAGER_H
#define VKGL_GL_BUFFER_MANAGER_H

#include "OpenGL/gl_object_manager.h"
#include "OpenGL/types.h"

namespace OpenGL
{
    typedef std::unique_ptr<GLBufferManager> GLBufferManagerUniquePtr;

    class GLBufferManager : public GLObjectManager
    {
    public:
        /* Public functions */

        static GLBufferManagerUniquePtr create();

        ~GLBufferManager();

        void*  get_buffer_map_pointer(const GLuint& in_id) const;
        size_t get_buffer_size       (const GLuint& in_id) const;

        void get_buffer_property(const GLuint&                     in_id,
                                 const OpenGL::BufferProperty&     in_pname,
                                 const OpenGL::GetSetArgumentType& in_arg_type,
                                 const uint32_t&                   in_n_args,
                                 void*                             out_result_ptr) const;

        bool set_buffer_store_size(const GLuint&              in_id,
                                   const size_t&              in_size);
        bool set_buffer_usage     (const GLuint&              in_id,
                                   const OpenGL::BufferUsage& in_usage);

    protected:
        /* Protected functions */
        std::unique_ptr<void, std::function<void(void*)> > create_internal_data_object(const GLuint& in_id) final;

    private:
        /* Private type definitions */

        typedef struct Buffer
        {

            // OpenGL::BufferAccessFlags access_flags; TODO
            int64_t             map_offset;
            void*               map_pointer;
            int64_t             map_size;
            int64_t             size;
            OpenGL::BufferUsage usage;

            Buffer()
            {
                /* As per table 2.7 from GL 3.2 core spec */
                // access_flags = 0;
                map_pointer  = nullptr;
                map_offset   = 0;
                map_size     = 0;
                size         = 0;
                usage        = OpenGL::BufferUsage::Static_Draw;
            }
        } Buffer;

        /* Private functions */

        GLBufferManager();

        const Buffer* get_buffer_ptr(const GLuint& in_id) const;
        Buffer*       get_buffer_ptr(const GLuint& in_id);

        /* Private variables */
    };
}
#endif /* VKGL_GL_BUFFER_MANAGER_H */