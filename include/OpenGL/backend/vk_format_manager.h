/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_FORMAT_MANAGER_H
#define VKGL_VK_FORMAT_MANAGER_H

#include "Anvil/include/misc/types.h"
#include "OpenGL/types.h"


namespace OpenGL
{
    typedef std::unique_ptr<VKFormatManager> VKFormatManagerUniquePtr;

    class VKFormatManager
    {
    public:
        /* Public functions */
        ~VKFormatManager();

        static VKFormatManagerUniquePtr create(Anvil::SGPUDevice* in_device_ptr);

        Anvil::Format get_best_fit_anvil_format(const OpenGL::InternalFormat&    in_internal_format,
                                                const Anvil::FormatFeatureFlags& in_format_features);

    private:
        /* Private type definitions */
        typedef std::pair<OpenGL::InternalFormat, Anvil::FormatFeatureFlags> GLToVKFormatMapKey;

        /* Private functions */

        VKFormatManager(Anvil::SGPUDevice* in_device_ptr);

        Anvil::FormatType get_anvil_format_type_for_gl_format_data_type(const OpenGL::FormatDataType& in_data_type) const;

        /* Private variables */
        Anvil::SGPUDevice* const m_device_ptr;

        std::map<GLToVKFormatMapKey, Anvil::Format> m_gl_to_vk_format_map;
        std::mutex                                  m_gl_to_vk_format_map_mutex;
    };
}

#endif /* VKGL_VK_FORMAT_MANAGER_H */
