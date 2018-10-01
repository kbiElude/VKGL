/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_VK_COMMANDS_H
#define VKGL_VK_COMMANDS_H

#include "OpenGL/types.h"
#include "OpenGL/frontend/gl_reference.h"

namespace OpenGL
{
    enum class CommandType
    {
        BUFFER_DATA,
        BUFFER_SUB_DATA,
        CLEAR,
        COMPILE_SHADER,
        COMPRESSED_TEX_IMAGE_1D,
        COMPRESSED_TEX_IMAGE_2D,
        COMPRESSED_TEX_IMAGE_3D,
        COMPRESSED_TEX_SUB_IMAGE_1D,
        COMPRESSED_TEX_SUB_IMAGE_2D,
        COMPRESSED_TEX_SUB_IMAGE_3D,
        COPY_BUFFER_SUB_DATA,
        COPY_TEX_IMAGE_1D,
        COPY_TEX_IMAGE_2D,
        COPY_TEX_SUB_IMAGE_1D,
        COPY_TEX_SUB_IMAGE_2D,
        COPY_TEX_SUB_IMAGE_3D,
        DRAW_ARRAYS,
        DRAW_ELEMENTS,
        DRAW_RANGE_ELEMENTS,
        FINISH,
        FLUSH,
        FLUSH_MAPPED_BUFFER_RANGE,
        GET_BUFFER_SUB_DATA,
        GET_COMPRESSED_TEX_IMAGE,
        GET_TEXTURE_IMAGE,
        LINK_PROGRAM,
        MAP_BUFFER,
        MULTI_DRAW_ARRAYS,
        MULTI_DRAW_ELEMENTS,
        READ_PIXELS,
        TEX_IMAGE_1D,
        TEX_IMAGE_2D,
        TEX_IMAGE_3D,
        TEX_SUB_IMAGE_1D,
        TEX_SUB_IMAGE_2D,
        TEX_SUB_IMAGE_3D,
        UNMAP_BUFFER,
        VALIDATE_PROGRAM,

        UNKNOWN
    };

    typedef std::unique_ptr<void,    std::function<void(void*)    > > DataUniquePtr;
    typedef std::unique_ptr<GLint,   std::function<void(GLint*)   > > GLIntArrayUniquePtr;
    typedef std::unique_ptr<GLsizei, std::function<void(GLsizei*) > > GLSizeiArrayUniquePtr;

    typedef struct CommandBase
    {
        CommandType type;

        CommandBase()
            :type(CommandType::UNKNOWN)
        {
            /* Stub */
        }

        CommandBase(const CommandType& in_type)
            :type(in_type)
        {
             /* Stub */
        }

        virtual ~CommandBase()
        {
            /* Stub */
        }
    } CommandBase;

    typedef std::unique_ptr<CommandBase, std::function<void(CommandBase*) > > CommandBaseUniquePtr;

    struct BufferDataCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr buffer_reference_ptr;
        OpenGL::DataUniquePtr        data_ptr;
        GLsizeiptr                   size;

        BufferDataCommand(OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                          OpenGL::DataUniquePtr        in_data_ptr,
                          const GLsizeiptr&            in_size)
            :CommandBase         (CommandType::BUFFER_DATA),
             buffer_reference_ptr(std::move(in_buffer_reference_ptr) ),
             data_ptr            (std::move(in_data_ptr) ),
             size                (in_size)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(buffer_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct BufferSubDataCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr buffer_reference_ptr;
        OpenGL::DataUniquePtr        data_ptr;
        GLsizeiptr                   size;
        GLsizeiptr                   start_offset;

        BufferSubDataCommand(OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                             OpenGL::DataUniquePtr        in_data_ptr,
                             const GLsizeiptr&            in_size,
                             const GLsizeiptr&            in_start_offset)
            :CommandBase         (CommandType::BUFFER_SUB_DATA),
             buffer_reference_ptr(std::move(in_buffer_reference_ptr) ),
             data_ptr            (std::move(in_data_ptr) ),
             size                (in_size),
             start_offset        (in_start_offset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(buffer_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct ClearCommand : public CommandBase
    {
        OpenGL::ClearBufferBits buffers_to_clear;

        ClearCommand(const OpenGL::ClearBufferBits& in_buffers_to_clear)
            :CommandBase     (CommandType::CLEAR),
             buffers_to_clear(in_buffers_to_clear)
        {
            /* Stub */
        }
    };

    struct CompileShaderCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr shader_reference_ptr;

        CompileShaderCommand(OpenGL::GLReferenceUniquePtr in_shader_reference_ptr)
            :CommandBase         (CommandType::COMPILE_SHADER),
             shader_reference_ptr(std::move(in_shader_reference_ptr) )
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(shader_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CompressedTexImage1DCommand : public CommandBase
    {
        GLint                        border;
        OpenGL::DataUniquePtr        data_ptr;
        GLsizei                      image_size;
        OpenGL::InternalFormat       internalformat;
        GLint                        level;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;

        CompressedTexImage1DCommand(const GLint&                 in_border,
                                    OpenGL::DataUniquePtr        in_data_ptr,
                                    const GLsizei&               in_image_size,
                                    OpenGL::InternalFormat       in_internalformat,
                                    const GLint&                 in_level,
                                    OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                    const GLsizei&               in_width)
            :CommandBase          (CommandType::COMPRESSED_TEX_IMAGE_1D),
             border               (in_border),
             data_ptr             (std::move(in_data_ptr) ),
             image_size           (in_image_size),
             internalformat       (in_internalformat),
             level                (in_level),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             width                (in_width)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CompressedTexImage2DCommand : public CommandBase
    {
        GLint                        border;
        OpenGL::DataUniquePtr        data_ptr;
        GLsizei                      height;
        GLsizei                      image_size;
        OpenGL::InternalFormat       internalformat;
        GLint                        level;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;

        CompressedTexImage2DCommand(const GLint&                 in_border,
                                    OpenGL::DataUniquePtr        in_data_ptr,
                                    const GLsizei&               in_height,
                                    const GLsizei&               in_image_size,
                                    OpenGL::InternalFormat       in_internalformat,
                                    const GLint&                 in_level,
                                    OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                    const GLsizei&               in_width)
            :CommandBase          (CommandType::COMPRESSED_TEX_IMAGE_2D),
             border               (in_border),
             data_ptr             (std::move(in_data_ptr) ),
             height               (in_height),
             image_size           (in_image_size),
             internalformat       (in_internalformat),
             level                (in_level),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             width                (in_width)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CompressedTexImage3DCommand : public CommandBase
    {
        GLint                        border;
        OpenGL::DataUniquePtr        data_ptr;
        GLsizei                      depth;
        GLsizei                      height;
        GLsizei                      image_size;
        OpenGL::InternalFormat       internalformat;
        GLint                        level;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;

        CompressedTexImage3DCommand(const GLint&&                in_border,
                                    OpenGL::DataUniquePtr        in_data_ptr,
                                    const GLsizei&               in_depth,
                                    const GLsizei&               in_height,
                                    const GLsizei&               in_image_size,
                                    OpenGL::InternalFormat       in_internalformat,
                                    const GLint&                 in_level,
                                    OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                    const GLsizei&               in_width)
            :CommandBase          (CommandType::COMPRESSED_TEX_IMAGE_3D),
             border               (in_border),
             data_ptr             (std::move(in_data_ptr) ),
             depth                (in_depth),
             height               (in_height),
             image_size           (in_image_size),
             internalformat       (in_internalformat),
             level                (in_level),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             width                (in_width)

        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CompressedTexSubImage1DCommand : public CommandBase
    {
        OpenGL::DataUniquePtr        data_ptr;
        OpenGL::PixelFormat          format;
        GLsizei                      image_size;
        GLint                        level;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        xoffset;

        CompressedTexSubImage1DCommand(OpenGL::DataUniquePtr        in_data_ptr,
                                       const OpenGL::PixelFormat&   in_format,
                                       const GLsizei&               in_image_size,
                                       const GLint&                 in_level,
                                       OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                       const GLsizei&               in_width,
                                       const GLint&                 in_xoffset)
            :CommandBase          (CommandType::COMPRESSED_TEX_SUB_IMAGE_1D),
             data_ptr             (std::move(in_data_ptr) ),
             format               (in_format),
             image_size           (in_image_size),
             level                (in_level),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             width                (in_width),
             xoffset              (in_xoffset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CompressedTexSubImage2DCommand : public CommandBase
    {
        OpenGL::DataUniquePtr        data_ptr;
        OpenGL::PixelFormat          format;
        GLsizei                      height;
        GLsizei                      image_size;
        GLint                        level;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        yoffset;

        CompressedTexSubImage2DCommand(OpenGL::DataUniquePtr        in_data_ptr,
                                       const OpenGL::PixelFormat&   in_format,
                                       const GLsizei&               in_height,
                                       const GLsizei&               in_image_size,
                                       const GLint&                 in_level,
                                       OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                       const GLsizei&               in_width,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset)
            :CommandBase          (CommandType::COMPRESSED_TEX_SUB_IMAGE_2D),
             data_ptr             (std::move(in_data_ptr) ),
             format               (in_format),
             height               (in_height),
             image_size           (in_image_size),
             level                (in_level),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             width                (in_width),
             xoffset              (in_xoffset),
             yoffset              (in_yoffset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CompressedTexSubImage3DCommand : public CommandBase
    {
        OpenGL::DataUniquePtr        data_ptr;
        OpenGL::PixelFormat          format;
        GLsizei                      height;
        GLsizei                      image_size;
        GLint                        level;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        yoffset;
        GLint                        zoffset;

        CompressedTexSubImage3DCommand(OpenGL::DataUniquePtr        in_data_ptr,
                                       const OpenGL::PixelFormat&   in_format,
                                       const GLsizei&               in_height,
                                       const GLsizei&               in_image_size,
                                       const GLint&                 in_level,
                                       OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                       const GLsizei&               in_width,
                                       const GLint&                 in_xoffset,
                                       const GLint&                 in_yoffset,
                                       const GLint&                 in_zoffset)
            :CommandBase          (CommandType::COMPRESSED_TEX_SUB_IMAGE_3D),
             data_ptr             (std::move(in_data_ptr) ),
             format               (in_format),
             height               (in_height),
             image_size           (in_image_size),
             level                (in_level),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             width                (in_width),
             xoffset              (in_xoffset),
             yoffset              (in_yoffset),
             zoffset              (in_zoffset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CopyBufferSubDataCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr read_buffer_ptr;
        GLintptr                     read_offset;
        GLsizeiptr                   size;
        OpenGL::GLReferenceUniquePtr write_buffer_ptr;
        GLintptr                     write_offset;

        CopyBufferSubDataCommand(OpenGL::GLReferenceUniquePtr in_read_buffer_ptr,
                                 const GLintptr&              in_read_offset,
                                 const GLsizeiptr&            in_size,
                                 OpenGL::GLReferenceUniquePtr in_write_buffer_ptr,
                                 const GLintptr&              in_write_offset)
            :CommandBase     (CommandType::COPY_BUFFER_SUB_DATA),
             read_buffer_ptr (std::move(in_read_buffer_ptr) ),
             read_offset     (in_read_offset),
             size            (in_size),
             write_buffer_ptr(std::move(in_write_buffer_ptr) ),
             write_offset    (in_write_offset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(read_buffer_ptr->get_time_marker () != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
            vkgl_assert(write_buffer_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CopyTexImage1DCommand : public CommandBase
    {
        GLint                        border;
        OpenGL::InternalFormat       internalformat;
        GLint                        level;
        OpenGL::ReadBuffer           read_buffer_state_at_call_time;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        x;
        GLint                        y;

        CopyTexImage1DCommand(const GLint&                  in_border,
                              const OpenGL::InternalFormat& in_internalformat,
                              const GLint&                  in_level,
                              const OpenGL::ReadBuffer&     in_read_buffer_state_at_call_time,
                              OpenGL::GLReferenceUniquePtr  in_texture_reference_ptr,
                              const GLsizei&                in_width,
                              const GLint&                  in_x,
                              const GLint&                  in_y)
            :CommandBase                   (CommandType::COPY_TEX_IMAGE_1D),
             border                        (in_border),
             internalformat                (in_internalformat),
             level                         (in_level),
             read_buffer_state_at_call_time(in_read_buffer_state_at_call_time),
             texture_reference_ptr         (std::move(in_texture_reference_ptr) ),
             width                         (in_width),
             x                             (in_x),
             y                             (in_y)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CopyTexImage2DCommand : public CommandBase
    {
        GLint                        border;
        GLsizei                      height;
        OpenGL::InternalFormat       internalformat;
        GLint                        level;
        OpenGL::ReadBuffer           read_buffer_state_at_call_time;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        x;
        GLint                        y;

        CopyTexImage2DCommand(const GLint&                  in_border,
                              const GLsizei&                in_height,
                              const OpenGL::InternalFormat& in_internalformat,
                              const GLint&                  in_level,
                              const OpenGL::ReadBuffer&     in_read_buffer_state_at_call_time,
                              OpenGL::GLReferenceUniquePtr  in_texture_reference_ptr,
                              const GLsizei&                in_width,
                              const GLint&                  in_x,
                              const GLint&                  in_y)
            :CommandBase                   (CommandType::COPY_TEX_IMAGE_2D),
             border                        (in_border),
             height                        (in_height),
             internalformat                (in_internalformat),
             level                         (in_level),
             read_buffer_state_at_call_time(in_read_buffer_state_at_call_time),
             texture_reference_ptr         (std::move(in_texture_reference_ptr) ),
             width                         (in_width),
             x                             (in_x),
             y                             (in_y)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CopyTexSubImage1DCommand : public CommandBase
    {
        GLint                        level;
        OpenGL::ReadBuffer           read_buffer_state_at_call_time;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        x;
        GLint                        y;

        CopyTexSubImage1DCommand(const GLint&                 in_level,
                                 const OpenGL::ReadBuffer&    in_read_buffer_state_at_call_time,
                                 OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                 const GLsizei&               in_width,
                                 const GLint&                 in_xoffset,
                                 const GLint&                 in_x,
                                 const GLint&                 in_y)
            :CommandBase                   (CommandType::COPY_TEX_SUB_IMAGE_1D),
             level                         (in_level),
             read_buffer_state_at_call_time(in_read_buffer_state_at_call_time),
             texture_reference_ptr         (std::move(in_texture_reference_ptr) ),
             width                         (in_width),
             xoffset                       (in_xoffset),
             x                             (in_x),
             y                             (in_y)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CopyTexSubImage2DCommand : public CommandBase
    {
        GLsizei                      height;
        GLint                        level;
        OpenGL::ReadBuffer           read_buffer_state_at_call_time;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        yoffset;
        GLint                        x;
        GLint                        y;

        CopyTexSubImage2DCommand(const GLsizei&               in_height,
                                 const GLint&                 in_level,
                                 const OpenGL::ReadBuffer&    in_read_buffer_state_at_call_time,
                                 OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                 const GLsizei&               in_width,
                                 const GLint&                 in_xoffset,
                                 const GLint&                 in_yoffset,
                                 const GLint&                 in_x,
                                 const GLint&                 in_y)
            :CommandBase                   (CommandType::COPY_TEX_SUB_IMAGE_2D),
             height                        (in_height),
             level                         (in_level),
             read_buffer_state_at_call_time(in_read_buffer_state_at_call_time),
             texture_reference_ptr         (std::move(in_texture_reference_ptr) ),
             width                         (in_width),
             xoffset                       (in_xoffset),
             yoffset                       (in_yoffset),
             x                             (in_x),
             y                             (in_y)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct CopyTexSubImage3DCommand : public CommandBase
    {
        GLsizei                      height;
        GLint                        level;
        OpenGL::ReadBuffer           read_buffer_state_at_call_time;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        yoffset;
        GLint                        zoffset;
        GLint                        x;
        GLint                        y;

        CopyTexSubImage3DCommand(const GLsizei&               in_height,
                                 const GLint&                 in_level,
                                 const OpenGL::ReadBuffer&    in_read_buffer_state_at_call_time,
                                 OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                                 const GLsizei&               in_width,
                                 const GLint&                 in_xoffset,
                                 const GLint&                 in_yoffset,
                                 const GLint&                 in_zoffset,
                                 const GLint&                 in_x,
                                 const GLint&                 in_y)
            :CommandBase                   (CommandType::COPY_TEX_SUB_IMAGE_3D),
             height                        (in_height),
             level                         (in_level),
             read_buffer_state_at_call_time(in_read_buffer_state_at_call_time),
             texture_reference_ptr         (std::move(in_texture_reference_ptr) ),
             width                         (in_width),
             xoffset                       (in_xoffset),
             yoffset                       (in_yoffset),
             zoffset                       (in_zoffset),
             x                             (in_x),
             y                             (in_y)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct DrawArraysCommand : public CommandBase
    {
        GLsizei                      count;
        GLint                        first;
        OpenGL::DrawCallMode         mode;
        OpenGL::GLReferenceUniquePtr state_reference_ptr;

        DrawArraysCommand(const GLsizei&               in_count,
                          const GLint&                 in_first,
                          const OpenGL::DrawCallMode&  in_mode,
                          OpenGL::GLReferenceUniquePtr in_state_reference_ptr)
            :CommandBase        (CommandType::DRAW_ARRAYS),
             count              (in_count),
             first              (in_first),
             mode               (in_mode),
             state_reference_ptr(std::move(in_state_reference_ptr) )
        {
            /* Stub */
        }
    };

    struct DrawElementsCommand : public CommandBase
    {
        GLsizei                      count;
        OpenGL::DataUniquePtr        index_data_ptr;
        OpenGL::DrawCallMode         mode;
        OpenGL::GLReferenceUniquePtr state_reference_ptr;
        OpenGL::DrawCallIndexType    type;

        DrawElementsCommand(const GLsizei&                   in_count,
                            OpenGL::DataUniquePtr            in_index_data_ptr,
                            const OpenGL::DrawCallMode&      in_mode,
                            OpenGL::GLReferenceUniquePtr     in_state_reference_ptr,
                            const OpenGL::DrawCallIndexType& in_type)
            :CommandBase        (CommandType::DRAW_ELEMENTS),
             count              (in_count),
             index_data_ptr     (std::move(in_index_data_ptr) ),
             mode               (in_mode),
             state_reference_ptr(std::move(in_state_reference_ptr) ),
             type               (in_type)
        {
            /* Stub */
        }
    };

    struct DrawRangeElementsCommand : public CommandBase
    {
        GLsizei                      count;
        GLuint                       end_index;
        OpenGL::DataUniquePtr        index_data_ptr;
        OpenGL::DrawCallMode         mode;
        GLuint                       start_index;
        OpenGL::GLReferenceUniquePtr state_reference_ptr;
        OpenGL::DrawCallIndexType    type;

        DrawRangeElementsCommand(const GLsizei&                   in_count,
                                 const GLuint&                    in_end_index,
                                 OpenGL::DataUniquePtr            in_index_data_ptr,
                                 const OpenGL::DrawCallMode&      in_mode,
                                 const GLuint&                    in_start_index,
                                 OpenGL::GLReferenceUniquePtr     in_state_reference_ptr,
                                 const OpenGL::DrawCallIndexType& in_type)
            :CommandBase        (CommandType::DRAW_RANGE_ELEMENTS),
             count              (in_count),
             end_index          (in_end_index),
             index_data_ptr     (std::move(in_index_data_ptr) ),
             mode               (in_mode),
             start_index        (in_start_index),
             state_reference_ptr(std::move(in_state_reference_ptr) ),
             type               (in_type)
        {
            /*  Stub */
        }
    };

    struct FinishCommand : public CommandBase
    {
        FinishCommand()
            :CommandBase(CommandType::FINISH)
        {
            /* Stub */
        }
    };

    struct FlushCommand : public CommandBase
    {
        FlushCommand()
            :CommandBase(CommandType::FLUSH)
        {
            /* Stub */
        }
    };

    struct FlushMappedBufferRangeCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr buffer_reference_ptr;
        GLintptr                     offset;
        GLsizeiptr                   length;

        FlushMappedBufferRangeCommand(OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                                      const GLintptr&              in_offset,
                                      const GLsizeiptr&            in_length)
            :CommandBase         (CommandType::FLUSH_MAPPED_BUFFER_RANGE),
             buffer_reference_ptr(std::move(in_buffer_reference_ptr) ),
             offset              (in_offset),
             length              (in_length)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(buffer_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct GetBufferSubDataCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr buffer_reference_ptr;
        void*                        result_data_ptr;
        GLsizeiptr                   size;
        GLintptr                     start_offset;

        GetBufferSubDataCommand(OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                                void*                        in_result_data_ptr,
                                const GLsizeiptr&            in_size,
                                const GLintptr&              in_start_offset)
            :CommandBase         (CommandType::GET_BUFFER_SUB_DATA),
             buffer_reference_ptr(std::move(in_buffer_reference_ptr) ),
             result_data_ptr     (in_result_data_ptr),
             size                (in_size),
             start_offset        (in_start_offset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(buffer_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct GetCompressedTexImageCommand : public CommandBase
    {
        GLint                        level;
        void*                        result_data_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;

        GetCompressedTexImageCommand(const GLint&                 in_level,
                                     void*                        in_result_data_ptr,
                                     OpenGL::GLReferenceUniquePtr in_texture_reference_ptr)
            :CommandBase          (CommandType::GET_COMPRESSED_TEX_IMAGE),
             level                (in_level),
             result_data_ptr      (in_result_data_ptr),
             texture_reference_ptr(std::move(in_texture_reference_ptr) )
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct GetTextureImageCommand : public CommandBase
    {
        OpenGL::PixelFormat          format;
        uint32_t                     level;
        void*                        result_data_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;

        GetTextureImageCommand(const OpenGL::PixelFormat&   in_format,
                               const uint32_t&              in_level,
                               void*                        in_result_data_ptr,
                               OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                               const OpenGL::PixelType&     in_type)
            :CommandBase          (CommandType::GET_TEXTURE_IMAGE),
             format               (in_format),
             level                (in_level),
             result_data_ptr      (in_result_data_ptr),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct LinkProgramCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr program_reference_ptr;

        LinkProgramCommand(OpenGL::GLReferenceUniquePtr in_program_reference_ptr)
            :CommandBase          (CommandType::LINK_PROGRAM),
             program_reference_ptr(std::move(in_program_reference_ptr) )
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(program_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct MapBufferCommand : public CommandBase
    {
        OpenGL::BufferAccess         access;
        OpenGL::GLReferenceUniquePtr buffer_reference_ptr;
        GLsizeiptr                   length;
        void**                       result_ptr_ptr;
        GLintptr                     start_offset;

        MapBufferCommand(const OpenGL::BufferAccess&  in_access,
                         OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr,
                         const GLsizeiptr&            in_length,
                         void**                       in_result_ptr_ptr,
                         const GLintptr&              in_start_offset)
            :CommandBase         (CommandType::MAP_BUFFER),
             access              (in_access),
             buffer_reference_ptr(std::move(in_buffer_reference_ptr) ),
             length              (in_length),
             result_ptr_ptr      (in_result_ptr_ptr),
             start_offset        (in_start_offset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(buffer_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct MultiDrawArraysCommand : public CommandBase
    {
        OpenGL::GLSizeiArrayUniquePtr    count_ptr;
        GLsizei                          drawcount;
        OpenGL::GLIntArrayUniquePtr      first_ptr;
        OpenGL::DrawCallMode             mode;
        OpenGL::GLReferenceUniquePtr     state_reference_ptr;

        MultiDrawArraysCommand(OpenGL::GLSizeiArrayUniquePtr in_count_ptr,
                               const GLsizei&                in_drawcount,
                               OpenGL::GLIntArrayUniquePtr   in_first_ptr,
                               const OpenGL::DrawCallMode&   in_mode,
                               OpenGL::GLReferenceUniquePtr  in_state_reference_ptr)
            :CommandBase        (CommandType::MULTI_DRAW_ARRAYS),
             count_ptr          (std::move(count_ptr) ),
             drawcount          (drawcount),
             first_ptr          (std::move(first_ptr) ),
             mode               (mode),
             state_reference_ptr(std::move(state_reference_ptr) )
        {
            /* Stub */
        }
    };

    struct MultiDrawElementsCommand : public CommandBase
    {
        OpenGL::GLSizeiArrayUniquePtr count_ptr;
        GLsizei                       drawcount;
        OpenGL::DataUniquePtr         indices_ptr;
        OpenGL::DrawCallMode          mode;
        OpenGL::GLReferenceUniquePtr  state_reference_ptr;
        OpenGL::DrawCallIndexType     type;

        MultiDrawElementsCommand(OpenGL::GLSizeiArrayUniquePtr    in_count_ptr,
                                 const GLsizei&                   in_drawcount,
                                 OpenGL::DataUniquePtr            in_indices_ptr,
                                 const OpenGL::DrawCallMode&      in_mode,
                                 OpenGL::GLReferenceUniquePtr     in_state_reference_ptr,
                                 const OpenGL::DrawCallIndexType& in_type)
            :CommandBase        (CommandType::MULTI_DRAW_ELEMENTS),
             count_ptr          (std::move(in_count_ptr) ),
             drawcount          (in_drawcount),
             indices_ptr        (std::move(in_indices_ptr) ),
             mode               (in_mode),
             state_reference_ptr(std::move(in_state_reference_ptr) ),
             type               (in_type)
        {
            /* Stub */
        }
    };

    struct ReadPixelsCommand : public CommandBase
    {
        OpenGL::PixelFormat format;
        size_t              height;
        OpenGL::ReadBuffer  read_buffer_state_at_call_time;
        void*               result_ptr;
        OpenGL::PixelType   type;
        size_t              width;
        int32_t             x;
        int32_t             y;

        ReadPixelsCommand(const OpenGL::PixelFormat& in_format,
                          const size_t&              in_height,
                          const OpenGL::ReadBuffer&  in_read_buffer_state_at_call_time,
                          void*                      in_result_ptr,
                          const OpenGL::PixelType&   in_type,
                          const size_t&              in_width,
                          const int32_t&             in_x,
                          const int32_t&             in_y)
            :CommandBase                   (CommandType::READ_PIXELS),
             format                        (in_format),
             height                        (in_height),
             read_buffer_state_at_call_time(in_read_buffer_state_at_call_time),
             result_ptr                    (in_result_ptr),
             type                          (in_type),
             width                         (in_width),
             x                             (in_x),
             y                             (in_y)
        {
            /* Stub */
        }
    };

    struct TexImage1DCommand : public CommandBase
    {
        int32_t                      border;
        OpenGL::PixelFormat          format;
        OpenGL::InternalFormat       internalformat;
        int32_t                      level;
        OpenGL::DataUniquePtr        pixels_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;
        int32_t                      width;

        TexImage1DCommand(const int32_t&                in_border,
                          const OpenGL::PixelFormat&    in_format,
                          const OpenGL::InternalFormat& in_internalformat,
                          const int32_t&                in_level,
                          OpenGL::DataUniquePtr         in_pixels_ptr,
                          OpenGL::GLReferenceUniquePtr  in_texture_reference_ptr,
                          const OpenGL::PixelType&      in_type,
                          const int32_t&                in_width)
            :CommandBase          (CommandType::TEX_IMAGE_1D),
             border               (in_border),
             format               (in_format),
             internalformat       (in_internalformat),
             level                (in_level),
             pixels_ptr           (std::move(in_pixels_ptr) ),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type),
             width                (in_width)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct TexImage2DCommand : public CommandBase
    {
        int32_t                      border;
        OpenGL::PixelFormat          format;
        int32_t                      height;
        OpenGL::InternalFormat       internalformat;
        int32_t                      level;
        OpenGL::DataUniquePtr        pixels_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;
        int32_t                      width;

        TexImage2DCommand(const int32_t&                in_border,
                          const OpenGL::PixelFormat&    in_format,
                          const int32_t&                in_height,
                          const OpenGL::InternalFormat& in_internalformat,
                          const int32_t&                in_level,
                          OpenGL::DataUniquePtr         in_pixels_ptr,
                          OpenGL::GLReferenceUniquePtr  in_texture_reference_ptr,
                          const OpenGL::PixelType&      in_type,
                          const int32_t&                in_width)
            :CommandBase          (CommandType::TEX_IMAGE_2D),
             border               (in_border),
             format               (in_format),
             height               (in_height),
             internalformat       (in_internalformat),
             level                (in_level),
             pixels_ptr           (std::move(in_pixels_ptr) ),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type),
             width                (in_width)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct TexImage3DCommand : public CommandBase
    {
        int32_t                      border;
        int32_t                      depth;
        OpenGL::PixelFormat          format;
        int32_t                      height;
        OpenGL::InternalFormat       internalformat;
        int32_t                      level;
        OpenGL::DataUniquePtr        pixels_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;
        int32_t                      width;

        TexImage3DCommand(const int32_t&                in_border,
                          const int32_t&                in_depth,
                          const OpenGL::PixelFormat&    in_format,
                          const int32_t&                in_height,
                          const OpenGL::InternalFormat& in_internalformat,
                          const int32_t&                in_level,
                          OpenGL::DataUniquePtr         in_pixels_ptr,
                          OpenGL::GLReferenceUniquePtr  in_texture_reference_ptr,
                          const OpenGL::PixelType&      in_type,
                          const int32_t&                in_width)
            :CommandBase          (CommandType::TEX_IMAGE_3D),
             border               (in_border),
             depth                (in_depth),
             format               (in_format),
             height               (in_height),
             internalformat       (in_internalformat),
             level                (in_level),
             pixels_ptr           (std::move(in_pixels_ptr) ),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type),
             width                (in_width)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct TexSubImage1DCommand : public CommandBase
    {
        OpenGL::PixelFormat          format;
        GLint                        level;
        OpenGL::DataUniquePtr        pixels_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;
        GLsizei                      width;
        GLint                        xoffset;

        TexSubImage1DCommand(const OpenGL::PixelFormat&   in_format,
                             const GLint&                 in_level,
                             OpenGL::DataUniquePtr        in_pixels_ptr,
                             OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                             const OpenGL::PixelType&     in_type,
                             const GLsizei&               in_width,
                             const GLint&                 in_xoffset)
            :CommandBase          (CommandType::TEX_SUB_IMAGE_1D),
             format               (in_format),
             level                (in_level),
             pixels_ptr           (std::move(in_pixels_ptr) ),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type),
             width                (in_width),
             xoffset              (in_xoffset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct TexSubImage2DCommand : public CommandBase
    {
        OpenGL::PixelFormat          format;
        GLsizei                      height;
        GLint                        level;
        OpenGL::DataUniquePtr        pixels_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        yoffset;

        TexSubImage2DCommand(const OpenGL::PixelFormat&   in_format,
                             const GLsizei&               in_height,
                             const GLint&                 in_level,
                             OpenGL::DataUniquePtr        in_pixels_ptr,
                             OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                             const OpenGL::PixelType&     in_type,
                             const GLsizei&               in_width,
                             const GLint&                 in_xoffset,
                             const GLint&                 in_yoffset)
            :CommandBase          (CommandType::TEX_SUB_IMAGE_2D),
             format               (in_format),
             height               (in_height),
             level                (in_level),
             pixels_ptr           (std::move(in_pixels_ptr) ),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type),
             width                (in_width),
             xoffset              (in_xoffset),
             yoffset              (in_yoffset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct TexSubImage3DCommand : public CommandBase
    {
        GLsizei                      depth;
        OpenGL::PixelFormat          format;
        GLsizei                      height;
        GLint                        level;
        OpenGL::DataUniquePtr        pixels_ptr;
        OpenGL::GLReferenceUniquePtr texture_reference_ptr;
        OpenGL::PixelType            type;
        GLsizei                      width;
        GLint                        xoffset;
        GLint                        yoffset;
        GLint                        zoffset;

        TexSubImage3DCommand(const GLsizei&               in_depth,
                             const OpenGL::PixelFormat&   in_format,
                             const GLsizei&               in_height,
                             const GLint&                 in_level,
                             OpenGL::DataUniquePtr        in_pixels_ptr,
                             OpenGL::GLReferenceUniquePtr in_texture_reference_ptr,
                             const OpenGL::PixelType&     in_type,
                             const GLsizei&               in_width,
                             const GLint&                 in_xoffset,
                             const GLint&                 in_yoffset,
                             const GLint&                 in_zoffset)
            :CommandBase          (CommandType::TEX_SUB_IMAGE_3D),
             depth                (in_depth),
             format               (in_format),
             height               (in_height),
             level                (in_level),
             pixels_ptr           (std::move(in_pixels_ptr) ),
             texture_reference_ptr(std::move(in_texture_reference_ptr) ),
             type                 (in_type),
             width                (in_width),
             xoffset              (in_xoffset),
             yoffset              (in_yoffset),
             zoffset              (in_zoffset)
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(texture_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct UnmapBufferCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr buffer_reference_ptr;

        UnmapBufferCommand(OpenGL::GLReferenceUniquePtr in_buffer_reference_ptr)
            :CommandBase         (CommandType::UNMAP_BUFFER),
             buffer_reference_ptr(std::move(in_buffer_reference_ptr) )
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(buffer_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

    struct ValidateProgramCommand : public CommandBase
    {
        OpenGL::GLReferenceUniquePtr program_reference_ptr;

        ValidateProgramCommand(OpenGL::GLReferenceUniquePtr in_program_reference_ptr)
            :CommandBase          (CommandType::VALIDATE_PROGRAM),
             program_reference_ptr(std::move(in_program_reference_ptr) )
        {
            /* NOTE: Backend must not be fed references pointing to ToT snapshots (since it's out-of-sync with frontend) */
            vkgl_assert(program_reference_ptr->get_time_marker() != OpenGL::LATEST_SNAPSHOT_AVAILABLE);
        }
    };

};

#endif /* VKGL_VK_COMMANDS_H */
