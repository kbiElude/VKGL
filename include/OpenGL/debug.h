#ifndef VKGL_DEBUG_H
#define VKGL_DEBUG_H

namespace VKGL
{
    namespace Debug
    {
        void assert_failed(const char*  in_filename,
                           unsigned int in_line,
                           const char*  in_message);
    }
}

#endif /* VKGL_DEBUG_H */