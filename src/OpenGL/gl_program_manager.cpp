/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#include "Common/macros.h"
#include "OpenGL/converters.h"
#include "OpenGL/gl_program_manager.h"
#include "OpenGL/gl_reference.h"


OpenGL::GLProgramManager::GLProgramManager()
    :GLObjectManager(1,    /* in_first_valid_nondefault_id */
                     true) /* in_expose_default_object     */
{
    /*  Stub */
}

OpenGL::GLProgramManager::~GLProgramManager()
{
    /* Stub - everything is handled by the base class. */
}

OpenGL::GLProgramManagerUniquePtr OpenGL::GLProgramManager::create()
{
    OpenGL::GLProgramManagerUniquePtr result_ptr;

    result_ptr.reset(new GLProgramManager() );

    if (result_ptr == nullptr)
    {
        vkgl_assert(result_ptr != nullptr);

        goto end;
    }

    if (!result_ptr->init() )
    {
        vkgl_assert_fail();

        result_ptr.reset();
    }

end:
    return result_ptr;
}

std::unique_ptr<void, std::function<void(void*)> > OpenGL::GLProgramManager::create_internal_data_object(const GLuint& in_id)
{
    std::unique_ptr<void, std::function<void(void*)> > result_ptr(nullptr,
                                                                  [](void* in_ptr){delete reinterpret_cast<Program*>(in_ptr); });

    result_ptr.reset(
        new Program()
    );

    vkgl_assert(result_ptr != nullptr);
    return result_ptr;
}

const OpenGL::GLProgramManager::Program* OpenGL::GLProgramManager::get_program_ptr(const GLuint& in_id) const
{
    return reinterpret_cast<const OpenGL::GLProgramManager::Program*>(get_internal_object_props_ptr(in_id) );
}

OpenGL::GLProgramManager::Program* OpenGL::GLProgramManager::get_program_ptr(const GLuint& in_id)
{
    return reinterpret_cast<OpenGL::GLProgramManager::Program*>(get_internal_object_props_ptr(in_id) );
}
