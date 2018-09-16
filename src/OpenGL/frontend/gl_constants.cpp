/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/frontend/gl_constants.h"

OpenGL::GLConstants::GLConstants(const IContext* in_context_ptr)
    :m_context_ptr(in_context_ptr)
{
    /* todo */

    m_context_flags            = 0;
    m_context_profile_mask     = 0;
    m_extensions               = ""; /* Filled by init_extension_constants() */
    m_major_version            = 3;
    m_minor_version            = 2;
    m_n_extensions             = 0;  /* Filled by init_extension_constants() */
    m_renderer                 = "VKGL";
    m_shading_language_version = "3.2 VKGL";
    m_vendor                   = "VKGL";
    m_version                  = "3.2.0";

    /* NOTE: m_indexed_prop_map only holds OpenGL::ContextProperty::Extensions, hence it's init'ed in init_extension_contacts() */
    m_prop_map =
    {
        // todo: compressed_texture_formats, num_compressed_texture_formats

        /* NOTE: This must stay in sync with OpenGL::Utils::is_context_property_gl_constant() ! */
        {OpenGL::ContextProperty::Context_Flags,            PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_context_flags)},
        {OpenGL::ContextProperty::Context_Profile_Mask,     PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_context_profile_mask)},
        {OpenGL::ContextProperty::Extensions,               PropertyData(OpenGL::GetSetArgumentType::String,       1, m_extensions.c_str() )},
        {OpenGL::ContextProperty::Major_Version,            PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_major_version)},
        {OpenGL::ContextProperty::Minor_Version,            PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_minor_version)},
        {OpenGL::ContextProperty::Num_Extensions,           PropertyData(OpenGL::GetSetArgumentType::Unsigned_Int, 1, &m_n_extensions)},
        {OpenGL::ContextProperty::Renderer,                 PropertyData(OpenGL::GetSetArgumentType::String,       1, m_renderer.c_str                () )},
        {OpenGL::ContextProperty::Shading_Language_Version, PropertyData(OpenGL::GetSetArgumentType::String,       1, m_shading_language_version.c_str() )},
        {OpenGL::ContextProperty::Vendor,                   PropertyData(OpenGL::GetSetArgumentType::String,       1, m_vendor.c_str                  () )},
        {OpenGL::ContextProperty::Version,                  PropertyData(OpenGL::GetSetArgumentType::String,       1, m_version.c_str                 () )},
    };

    if (m_context_ptr != nullptr)
    {
        init_extension_constants();
    }
}

OpenGL::GLConstants::~GLConstants()
{
    vkgl_not_implemented();
}

void OpenGL::GLConstants::get_parameter(const OpenGL::ContextProperty&    in_pname,
                                        const OpenGL::GetSetArgumentType& in_arg_type,
                                        void*                             out_arg_value_ptr) const
{
    const auto pname_iterator = m_prop_map.find(in_pname);

    vkgl_assert(pname_iterator != m_prop_map.end() );
    if (pname_iterator != m_prop_map.end() )
    {
        const auto& pname_props = pname_iterator->second;

        OpenGL::Converters::convert(pname_props.type,
                                    pname_props.data_ptr,
                                    pname_props.n_components,
                                    in_arg_type,
                                    out_arg_value_ptr);
    }
}

void OpenGL::GLConstants::get_parameter_indexed(const OpenGL::ContextProperty&    in_pname,
                                                const OpenGL::GetSetArgumentType& in_arg_type,
                                                const uint32_t&                   in_index,
                                                void*                             out_arg_value_ptr) const
{
    const auto pname_iterator = m_indexed_prop_map.find(in_pname);

    vkgl_assert(pname_iterator != m_indexed_prop_map.end() );
    if (pname_iterator != m_indexed_prop_map.end() )
    {
        const auto& pname_props = pname_iterator->second;

        vkgl_assert(pname_props.data_ptrs.size() > in_index);

        OpenGL::Converters::convert(pname_props.type,
                                    pname_props.data_ptrs.at(in_index),
                                    pname_props.n_components,
                                    in_arg_type,
                                    out_arg_value_ptr);
    }
}

void OpenGL::GLConstants::init_extension_constants()
{
    const auto& supported_extensions          = m_context_ptr->get_supported_extensions();
    auto        supported_extensions_raw_ptrs = std::vector<const void*>(m_extensions.size() );

    /* Cache extension name data under corresponding fields.. */
    for (const auto& current_extension : supported_extensions)
    {
        if (m_extensions.size() != 0)
        {
            m_extensions += " ";
        }

        m_extensions += current_extension;

        /* NOTE: GLConstants is released at the same time as OpenGL::Context, so this is safe. */
        supported_extensions_raw_ptrs.push_back(current_extension.c_str() );
    }

    m_n_extensions = static_cast<uint32_t>(supported_extensions.size() );

    /* Initialize indexed prop map, now that all data is locally cached. */
    m_indexed_prop_map[OpenGL::ContextProperty::Extensions] = IndexedPropertyData(OpenGL::GetSetArgumentType::String, 1, supported_extensions_raw_ptrs);
}