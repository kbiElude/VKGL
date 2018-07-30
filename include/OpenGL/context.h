#ifndef VKGL_CONTEXT_H
#define VKGL_CONTEXT_H

namespace VKGL
{
    class Context
    {
    public:
        /* Public functions */
         Context();
        ~Context();

    private:
        /* Private functions */

        /* Private variables */

        VKGL::ContextState m_state;
    };
}

#endif /* VKGL_CONTEXT_H */