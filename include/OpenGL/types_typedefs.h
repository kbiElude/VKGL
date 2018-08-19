/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_TYPEDEFS_H
#define VKGL_TYPES_TYPEDEFS_H

namespace VKGL
{
    /* Bitfield type definitions */
    typedef uint32_t BlitMaskBits;
    typedef uint32_t ClearBufferBits;
    typedef uint32_t WaitSyncBits;

    /* VKGL GL entrypoints : GL 1.0 */
    typedef void           (*PFNVKGLBLENDFUNCPROC)              (Context* context_ptr, const GLenum& in_sfactor, const GLenum& in_dfactor);
    typedef void           (*PFNVKGLCLEARPROC)                  (Context* context_ptr, const GLbitfield& in_mask);
    typedef void           (*PFNVKGLCLEARCOLORPROC)             (Context* context_ptr, const GLfloat& in_red, const GLfloat& in_green, const GLfloat& in_blue, const GLfloat& in_alpha);
    typedef void           (*PFNVKGLCLEARDEPTHPROC)             (Context* context_ptr, const GLdouble& in_depth);
    typedef void           (*PFNVKGLCLEARSTENCILPROC)           (Context* context_ptr, const GLint& in_s);
    typedef void           (*PFNVKGLCOLORMASKPROC)              (Context* context_ptr, const GLboolean& in_red, const GLboolean& in_green, const GLboolean& in_blue, const GLboolean& in_alpha);
    typedef void           (*PFNVKGLCULLFACEPROC)               (Context* context_ptr, const GLenum& in_mode);
    typedef void           (*PFNVKGLDEPTHFUNCPROC)              (Context* context_ptr, const GLenum& in_func);
    typedef void           (*PFNVKGLDEPTHMASKPROC)              (Context* context_ptr, const GLboolean& in_flag);
    typedef void           (*PFNVKGLDEPTHRANGEPROC)             (Context* context_ptr, const GLdouble& in_n, const GLdouble& in_f);
    typedef void           (*PFNVKGLDISABLEPROC)                (Context* context_ptr, const GLenum& in_cap);
    typedef void           (*PFNVKGLDRAWBUFFERPROC)             (Context* context_ptr, const GLenum& in_buf);
    typedef void           (*PFNVKGLENABLEPROC)                 (Context* context_ptr, const GLenum& in_cap);
    typedef void           (*PFNVKGLFINISHPROC)                 (Context* context_ptr);
    typedef void           (*PFNVKGLFLUSHPROC)                  (Context* context_ptr);
    typedef void           (*PFNVKGLFRONTFACEPROC)              (Context* context_ptr, const GLenum& in_mode);
    typedef void           (*PFNVKGLGETBOOLEANVPROC)            (Context* context_ptr, const GLenum& in_pname, GLboolean* out_data_ptr);
    typedef void           (*PFNVKGLGETDOUBLEVPROC)             (Context* context_ptr, const GLenum& in_pname, GLdouble* out_data_ptr);
    typedef GLenum         (*PFNVKGLGETERRORPROC)               (Context* context_ptr);
    typedef void           (*PFNVKGLGETFLOATVPROC)              (Context* context_ptr, const GLenum& in_pname, GLfloat* out_data_ptr);
    typedef void           (*PFNVKGLGETINTEGERVPROC)            (Context* context_ptr, const GLenum& in_pname, GLint* out_data_ptr);
    typedef const GLubyte* (*PFNVKGLGETSTRINGPROC)              (Context* context_ptr, const GLenum& in_name);
    typedef void           (*PFNVKGLGETTEXIMAGEPROC)            (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_format, const GLenum& in_type, void* out_pixels_ptr);
    typedef void           (*PFNVKGLGETTEXLEVELPARAMETERFVPROC) (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_pname, GLfloat* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXLEVELPARAMETERIVPROC) (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXPARAMETERFVPROC)      (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, GLfloat* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXPARAMETERIVPROC)      (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLHINTPROC)                   (Context* context_ptr, const GLenum& in_target, const GLenum& in_mode);
    typedef GLboolean      (*PFNVKGLISENABLEDPROC)              (Context* context_ptr, const GLenum& in_cap);
    typedef void           (*PFNVKGLLINEWIDTHPROC)              (Context* context_ptr, const GLfloat& in_width);
    typedef void           (*PFNVKGLLOGICOPPROC)                (Context* context_ptr, const GLenum& in_opcode);
    typedef void           (*PFNVKGLPIXELSTOREFPROC)            (Context* context_ptr, const GLenum& in_pname, const GLfloat& in_param);
    typedef void           (*PFNVKGLPIXELSTOREIPROC)            (Context* context_ptr, const GLenum& in_pname, const GLint& in_param);
    typedef void           (*PFNVKGLPOINTSIZEPROC)              (Context* context_ptr, const GLfloat& in_size);
    typedef void           (*PFNVKGLPOLYGONMODEPROC)            (Context* context_ptr, const GLenum& in_face, const GLenum& in_mode);
    typedef void           (*PFNVKGLREADBUFFERPROC)             (Context* context_ptr, const GLenum& in_src);
    typedef void           (*PFNVKGLREADPIXELSPROC)             (Context* context_ptr, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height, const GLenum& in_format, const GLenum& in_type, void* out_pixels_ptr);
    typedef void           (*PFNVKGLSCISSORPROC)                (Context* context_ptr, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);
    typedef void           (*PFNVKGLSTENCILFUNCPROC)            (Context* context_ptr, const GLenum& in_func, const GLint& in_ref, const GLuint& in_mask);
    typedef void           (*PFNVKGLSTENCILOPPROC)              (Context* context_ptr, const GLenum& in_fail, const GLenum& in_zfail, const GLenum& in_zpass);
    typedef void           (*PFNVKGLSTENCILMASKPROC)            (Context* context_ptr, const GLuint& in_mask);
    typedef void           (*PFNVKGLTEXIMAGE1DPROC)             (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_internalformat, const GLsizei& in_width, const GLint& in_border, const GLenum& in_format, const GLenum& in_type, const void* in_pixels_ptr);
    typedef void           (*PFNVKGLTEXIMAGE2DPROC)             (Context* context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLint& in_border, const GLenum& in_format, const GLenum& in_type, const void* in_pixels_ptr);
    typedef void           (*PFNVKGLTEXPARAMETERFPROC)          (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLfloat& in_param);
    typedef void           (*PFNVKGLTEXPARAMETERFVPROC)         (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLfloat* in_params_ptr);
    typedef void           (*PFNVKGLTEXPARAMETERIPROC)          (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLint& in_param);
    typedef void           (*PFNVKGLTEXPARAMETERIVPROC)         (Context* context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLint* in_params_ptr);
    typedef void           (*PFNVKGLVIEWPORTPROC)               (Context* context_ptr, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);

    /* VKGL GL entrypoints : GL 1.1 */
    typedef void      (*PFNVKGLBINDTEXTUREPROC)      (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_texture);
    typedef void      (*PFNVKGLCOPYTEXIMAGE1DPROC)   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum&  in_internalformat, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLint& in_border);
    typedef void      (*PFNVKGLCOPYTEXIMAGE2DPROC)   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum&  in_internalformat, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height, const GLint& in_border);
    typedef void      (*PFNVKGLCOPYTEXSUBIMAGE1DPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_x, const GLint& in_y, const GLsizei& in_width);
    typedef void      (*PFNVKGLCOPYTEXSUBIMAGE2DPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);
    typedef void      (*PFNVKGLDELETETEXTURESPROC)   (VKGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_textures);
    typedef void      (*PFNVKGLDRAWARRAYSPROC)       (VKGL::Context* in_context_ptr, const GLenum& in_mode, const GLint&  in_first, const GLsizei& in_count);
    typedef void      (*PFNVKGLDRAWELEMENTSPROC)     (VKGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei& in_count, const GLenum& in_type, const void* in_indices);
    typedef void      (*PFNVKGLGENTEXTURESPROC)      (VKGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* in_textures);
    typedef GLboolean (*PFNVKGLISTEXTUREPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_texture);
    typedef void      (*PFNVKGLPOLYGONOFFSETPROC)    (VKGL::Context* in_context_ptr, const GLfloat& in_factor, const GLfloat& in_units);
    typedef void      (*PFNVKGLTEXSUBIMAGE1DPROC)    (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLsizei& in_width, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);
    typedef void      (*PFNVKGLTEXSUBIMAGE2DPROC)    (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLsizei& in_width, const GLsizei& in_height, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);

    /* VKG GL entrypoints : GL 1.2 */
    typedef void (*PFNVKGLCOPYTEXSUBIMAGE3DPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_zoffset, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);
    typedef void (*PFNVKGLDRAWRANGEELEMENTSPROC)(VKGL::Context* in_context_ptr, const GLenum& in_mode, const GLuint& in_start, const GLuint& in_end, const GLsizei& in_count, const GLenum& in_type, const void* in_indices);
    typedef void (*PFNVKGLTEXIMAGE3DPROC)       (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLint& in_border, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);
    typedef void (*PFNVKGLTEXSUBIMAGE3DPROC)    (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_zoffset, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);

    /* VKG GL entrypoints : GL 1.3 */
    typedef void (*PFNVKGLACTIVETEXTUREPROC)          (VKGL::Context* in_context_ptr, const GLenum& in_texture);
    typedef void (*PFNVKGLCOMPRESSEDTEXIMAGE1DPROC)   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_internalformat, const GLsizei& in_width, const GLint& in_border, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXIMAGE2DPROC)   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLint& in_border, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXIMAGE3DPROC)   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLint& in_border, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXSUBIMAGE1DPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLsizei& in_width, const GLenum& in_format, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXSUBIMAGE2DPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLsizei& in_width, const GLsizei& in_height, const GLenum& in_format, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXSUBIMAGE3DPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_zoffset, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLenum& in_format, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLGETCOMPRESSEDTEXIMAGEPROC)  (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, void* in_img);
    typedef void (*PFNVKGLSAMPLECOVERAGEPROC)         (VKGL::Context* in_context_ptr, const GLfloat& in_value, const GLboolean& in_invert);

    /* VKGL GL entrypoints : GL 1.4 */
    typedef void (*PFNVKGLBLENDCOLORPROC)       (VKGL::Context* in_context_ptr, const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha);
    typedef void (*PFNVKGLBLENDEQUATIONPROC)    (VKGL::Context* in_context_ptr, const GLenum& mode);
    typedef void (*PFNVKGLBLENDFUNCSEPARATEPROC)(VKGL::Context* in_context_ptr, const GLenum& sfactorRGB, const GLenum& dfactorRGB, const GLenum& sfactorAlpha, const GLenum& dfactorAlpha);
    typedef void (*PFNVKGLMULTIDRAWARRAYSPROC)  (VKGL::Context* in_context_ptr, const GLenum& mode, const GLint* first, const GLsizei* count, const GLsizei& drawcount);
    typedef void (*PFNVKGLMULTIDRAWELEMENTSPROC)(VKGL::Context* in_context_ptr, const GLenum& mode, const GLsizei* count, const GLenum& type, const void* const* indices, const GLsizei& drawcount);
    typedef void (*PFNVKGLPOINTPARAMETERFPROC)  (VKGL::Context* in_context_ptr, const GLenum& pname, const GLfloat& param);
    typedef void (*PFNVKGLPOINTPARAMETERFVPROC) (VKGL::Context* in_context_ptr, const GLenum& pname, const GLfloat* params);
    typedef void (*PFNVKGLPOINTPARAMETERIPROC)  (VKGL::Context* in_context_ptr, const GLenum& pname, const GLint&  param);
    typedef void (*PFNVKGLPOINTPARAMETERIVPROC) (VKGL::Context* in_context_ptr, const GLenum& pname, const GLint* params);

    /* VKGL GL entrypoints: GL 1.5 */
    typedef void      (*PFNVKGLBEGINQUERYPROC)          (VKGL::Context* in_context_ptr, GLenum target, GLuint id);
    typedef void      (*PFNVKGLBINDBUFFERPROC)          (VKGL::Context* in_context_ptr, GLenum target, GLuint buffer);
    typedef void      (*PFNVKGLBUFFERDATAPROC)          (VKGL::Context* in_context_ptr, GLenum target, GLsizeiptr size, const void* data, GLenum usage);
    typedef void      (*PFNVKGLBUFFERSUBDATAPROC)       (VKGL::Context* in_context_ptr, GLenum target, GLintptr offset, GLsizeiptr size, const void* data);
    typedef void      (*PFNVKGLDELETEBUFFERSPROC)       (VKGL::Context* in_context_ptr, GLsizei n, const GLuint* buffers);
    typedef void      (*PFNVKGLDELETEQUERIESPROC)       (VKGL::Context* in_context_ptr, GLsizei n, const GLuint* ids);
    typedef void      (*PFNVKGLENDQUERYPROC)            (VKGL::Context* in_context_ptr, GLenum target);
    typedef void      (*PFNVKGLGENBUFFERSPROC)          (VKGL::Context* in_context_ptr, GLsizei n, GLuint* buffers);
    typedef void      (*PFNVKGLGENQUERIESPROC)          (VKGL::Context* in_context_ptr, GLsizei n, GLuint* ids);
    typedef void      (*PFNVKGLGETBUFFERPARAMETERIVPROC)(VKGL::Context* in_context_ptr, GLenum target, GLenum pname, GLint* params);
    typedef void      (*PFNVKGLGETBUFFERPOINTERVPROC)   (VKGL::Context* in_context_ptr, GLenum target, GLenum pname, void** params);
    typedef void      (*PFNVKGLGETBUFFERSUBDATAPROC)    (VKGL::Context* in_context_ptr, GLenum target, GLintptr offset, GLsizeiptr size, void* data);
    typedef void      (*PFNVKGLGETQUERYOBJECTIVPROC)    (VKGL::Context* in_context_ptr, GLuint id, GLenum pname, GLint* params);
    typedef void      (*PFNVKGLGETQUERYOBJECTUIVPROC)   (VKGL::Context* in_context_ptr, GLuint id, GLenum pname, GLuint* params);
    typedef void      (*PFNVKGLGETQUERYIVPROC)          (VKGL::Context* in_context_ptr, GLenum target, GLenum pname, GLint* params);
    typedef GLboolean (*PFNVKGLISBUFFERPROC)            (VKGL::Context* in_context_ptr, GLuint buffer);
    typedef GLboolean (*PFNVKGLISQUERYPROC)             (VKGL::Context* in_context_ptr, GLuint id);
    typedef void*     (*PFNVKGLMAPBUFFERPROC)           (VKGL::Context* in_context_ptr, GLenum target, GLenum access);
    typedef GLboolean (*PFNVKGLUNMAPBUFFERPROC)         (VKGL::Context* in_context_ptr, GLenum target);

    /* VKGL GL entrypoints: GL 2.0 */

    typedef void      (*PFNVKGLATTACHSHADERPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_shader);
    typedef void      (*PFNVKGLBINDATTRIBLOCATIONPROC)      (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLchar* in_name);
    typedef void      (*PFNVKGLBLENDEQUATIONSEPARATEPROC)   (VKGL::Context* in_context_ptr, const GLenum& in_modeRGB, const GLenum& in_modeAlpha);
    typedef void      (*PFNVKGLCOMPILESHADERPROC)           (VKGL::Context* in_context_ptr, const GLuint& in_shader);
    typedef GLuint    (*PFNVKGLCREATEPROGRAMPROC)           (VKGL::Context* in_context_ptr);
    typedef GLuint    (*PFNVKGLCREATESHADERPROC)            (VKGL::Context* in_context_ptr, const GLenum& in_type);
    typedef void      (*PFNVKGLDELETEPROGRAMPROC)           (VKGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLDELETESHADERPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_shader);
    typedef void      (*PFNVKGLDETACHSHADERPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_shader);
    typedef void      (*PFNVKGLDISABLEVERTEXATTRIBARRAYPROC)(VKGL::Context* in_context_ptr, const GLuint& in_index);
    typedef void      (*PFNVKGLDRAWBUFFERSPROC)             (VKGL::Context* in_context_ptr, const GLsizei& in_n, const GLenum* in_bufs);
    typedef void      (*PFNVKGLENABLEVERTEXATTRIBARRAYPROC) (VKGL::Context* in_context_ptr, const GLuint& in_index);
    typedef void      (*PFNVKGLGETACTIVEATTRIBPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLsizei& in_bufSize, GLsizei* in_length, GLint* in_size, GLenum* in_type, GLchar* in_name);
    typedef void      (*PFNVKGLGETACTIVEUNIFORMPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLsizei& in_bufSize, GLsizei* in_length, GLint* in_size, GLenum* in_type, GLchar* in_name);
    typedef void      (*PFNVKGLGETATTACHEDSHADERSPROC)      (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_maxCount, GLsizei* in_count, GLuint* in_shaders);
    typedef GLint     (*PFNVKGLGETATTRIBLOCATIONPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_name);
    typedef void      (*PFNVKGLGETPROGRAMINFOLOGPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_bufSize, GLsizei* in_length, GLchar* in_infoLog);
    typedef void      (*PFNVKGLGETPROGRAMIVPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_program, GLenum in_pname, GLint* in_params);
    typedef void      (*PFNVKGLGETSHADERINFOLOGPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_shader, const GLsizei& in_bufSize, GLsizei* in_length, GLchar* in_infoLog);
    typedef void      (*PFNVKGLGETSHADERSOURCEPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_shader, const GLsizei& in_bufSize, GLsizei* in_length, GLchar* in_source);
    typedef void      (*PFNVKGLGETSHADERIVPROC)             (VKGL::Context* in_context_ptr, const GLuint& in_shader, const GLenum& in_pname, GLint* in_params);
    typedef GLint     (*PFNVKGLGETUNIFORMLOCATIONPROC)      (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_name);
    typedef void      (*PFNVKGLGETUNIFORMFVPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLint& in_location, GLfloat* in_params);
    typedef void      (*PFNVKGLGETUNIFORMIVPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLint& in_location, GLint* in_params);
    typedef void      (*PFNVKGLGETVERTEXATTRIBPOINTERVPROC) (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, void** in_pointer);
    typedef void      (*PFNVKGLGETVERTEXATTRIBDVPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLdouble* in_params);
    typedef void      (*PFNVKGLGETVERTEXATTRIBFVPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLfloat* in_params);
    typedef void      (*PFNVKGLGETVERTEXATTRIBIVPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLint* in_params);
    typedef GLboolean (*PFNVKGLISPROGRAMPROC)               (VKGL::Context* in_context_ptr, const GLuint& in_program);
    typedef GLboolean (*PFNVKGLISSHADERPROC)                (VKGL::Context* in_context_ptr, const GLuint& in_shader);
    typedef void      (*PFNVKGLLINKPROGRAMPROC)             (VKGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLSHADERSOURCEPROC)            (VKGL::Context* in_context_ptr, const GLuint& in_shader, const GLsizei& in_count,const GLchar* const* in_string, const GLint* in_length);
    typedef void      (*PFNVKGLSTENCILFUNCSEPARATEPROC)     (VKGL::Context* in_context_ptr, const GLenum& in_face, const GLenum& in_func,const GLint& in_ref, const GLuint& in_mask);
    typedef void      (*PFNVKGLSTENCILMASKSEPARATEPROC)     (VKGL::Context* in_context_ptr, const GLenum& in_face,const GLuint& in_mask);
    typedef void      (*PFNVKGLSTENCILOPSEPARATEPROC)       (VKGL::Context* in_context_ptr, const GLenum& in_face, const GLenum& in_sfail, const GLenum& in_dpfail, const GLenum& in_dppass);
    typedef void      (*PFNVKGLUNIFORM1FPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0);
    typedef void      (*PFNVKGLUNIFORM1FVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM1IPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0);
    typedef void      (*PFNVKGLUNIFORM1IVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORM2FPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0, const GLfloat& in_v1);
    typedef void      (*PFNVKGLUNIFORM2FVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM2IPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0, const GLint& in_v1);
    typedef void      (*PFNVKGLUNIFORM2IVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORM3FPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0, const GLfloat& in_v1, const GLfloat& in_v2);
    typedef void      (*PFNVKGLUNIFORM3FVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM3IPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0, const GLint& in_v1, const GLint& in_v2);
    typedef void      (*PFNVKGLUNIFORM3IVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORM4FPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0, const GLfloat& in_v1, const GLfloat& in_v2, const GLfloat& in_v3);
    typedef void      (*PFNVKGLUNIFORM4FVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM4IPROC)               (VKGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0, const GLint& in_v1, const GLint& in_v2, const GLint& in_v3);
    typedef void      (*PFNVKGLUNIFORM4IVPROC)              (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX2FVPROC)        (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX3FVPROC)        (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX4FVPROC)        (VKGL::Context* in_context_ptr, const GLint& in_location,const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUSEPROGRAMPROC)              (VKGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLVALIDATEPROGRAMPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLVERTEXATTRIB1DPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x);
    typedef void      (*PFNVKGLVERTEXATTRIB1DVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB1FPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x);
    typedef void      (*PFNVKGLVERTEXATTRIB1FVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB1SPROC)          (VKGL::Context* in_context_ptr, const GLuint&  in_index, const GLshort& in_x);
    typedef void      (*PFNVKGLVERTEXATTRIB1SVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB2DPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x, const GLdouble& in_y);
    typedef void      (*PFNVKGLVERTEXATTRIB2DVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB2FPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x, const GLfloat& in_y);
    typedef void      (*PFNVKGLVERTEXATTRIB2FVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB2SPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort& in_x, const GLshort& in_y);
    typedef void      (*PFNVKGLVERTEXATTRIB2SVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB3DPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x, const GLdouble& in_y, const GLdouble& in_z);
    typedef void      (*PFNVKGLVERTEXATTRIB3DVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB3FPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x, const GLfloat& in_y, const GLfloat& in_z);
    typedef void      (*PFNVKGLVERTEXATTRIB3FVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB3SPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort& in_x, const GLshort& in_y, const GLshort& in_z);
    typedef void      (*PFNVKGLVERTEXATTRIB3SVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4BVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLbyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4DPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x, const GLdouble& in_y, const GLdouble& in_z, const GLdouble& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4DVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4FPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x, const GLfloat& in_y, const GLfloat& in_z, const GLfloat& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4FVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4IVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NBVPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLbyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NIVPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NSVPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUBPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte& in_x, const GLubyte& in_y, const GLubyte& in_z, const GLubyte& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUBVPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUIVPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUSVPROC)       (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLushort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4SPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort& in_x, const GLshort& in_y, const GLshort& in_z, const GLshort& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4SVPROC)         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4UBVPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4UIVPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4USVPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLushort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIBPOINTERPROC)     (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_size, const GLenum& in_type, const GLboolean& in_normalized, const GLsizei& in_stride, const void* in_pointer);

    /* VKGL GL entrypoints : GL 2.1 */
    typedef void      (*PFNVKGLUNIFORMMATRIX2X3FVPROC)      (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX2X4FVPROC)      (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX3X2FVPROC)      (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX3X4FVPROC)      (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX4X2FVPROC)      (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX4X3FVPROC)      (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);

    /* VKGL GL entrypoints : GL 3.0 */
    typedef void           (*PFNVKGLBEGINCONDITIONALRENDERPROC)             (VKGL::Context* in_context_ptr, const GLuint& in_id, const GLenum& in_mode);
    typedef void           (*PFNVKGLBEGINTRANSFORMFEEDBACKPROC)             (VKGL::Context* in_context_ptr, const GLenum& in_primitive_mode);
    typedef void           (*PFNVKGLBINDBUFFERBASEPROC)                     (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, const GLuint& in_buffer);
    typedef void           (*PFNVKGLBINDBUFFERRANGEPROC)                    (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, const GLuint& in_buffer, const GLintptr& in_offset, const GLsizeiptr& in_size);
    typedef void           (*PFNVKGLBINDFRAGDATALOCATIONPROC)               (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_color, const GLchar* in_name_ptr);
    typedef void           (*PFNVKGLBINDFRAMEBUFFERPROC)                    (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_framebuffer);
    typedef void           (*PFNVKGLBINDRENDERBUFFERPROC)                   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_renderbuffer);
    typedef void           (*PFNVKGLBINDVERTEXARRAYPROC)                    (VKGL::Context* in_context_ptr, const GLuint& in_array);
    typedef void           (*PFNVKGLBLITFRAMEBUFFERPROC)                    (VKGL::Context* in_context_ptr, const GLint& in_srcX0, const GLint& in_srcY0, const GLint& in_srcX1, const GLint& in_srcY1, const GLint& in_dstX0, const GLint& in_dstY0, const GLint& in_dstX1, const GLint& in_dstY1, const GLbitfield& in_mask, const GLenum& in_filter);
    typedef GLenum         (*PFNVKGLCHECKFRAMEBUFFERSTATUSPROC)             (VKGL::Context* in_context_ptr, const GLenum& in_target);
    typedef void           (*PFNVKGLCLAMPCOLORPROC)                         (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_clamp);
    typedef void           (*PFNVKGLCLEARBUFFERFIPROC)                      (VKGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLfloat& in_depth, const GLint& in_stencil);
    typedef void           (*PFNVKGLCLEARBUFFERFVPROC)                      (VKGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLfloat* in_value_ptr);
    typedef void           (*PFNVKGLCLEARBUFFERIVPROC)                      (VKGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLint* in_value_ptr);
    typedef void           (*PFNVKGLCLEARBUFFERUIVPROC)                     (VKGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLCOLORMASKIPROC)                         (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLboolean& in_r, const GLboolean& in_g, const GLboolean& in_b, const GLboolean& in_a);
    typedef void           (*PFNVKGLDELETEFRAMEBUFFERSPROC)                 (VKGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_framebuffers_ptr);
    typedef void           (*PFNVKGLDELETERENDERBUFFERSPROC)                (VKGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_renderbuffers_ptr);
    typedef void           (*PFNVKGLDELETEVERTEXARRAYSPROC)                 (VKGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_arrays_ptr);
    typedef void           (*PFNVKGLDISABLEIPROC)                           (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index);
    typedef void           (*PFNVKGLENABLEIPROC)                            (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index);
    typedef void           (*PFNVKGLENDCONDITIONALRENDERPROC)               (VKGL::Context* in_context_ptr);
    typedef void           (*PFNVKGLENDTRANSFORMFEEDBACKPROC)               (VKGL::Context* in_context_ptr);
    typedef void           (*PFNVKGLFLUSHMAPPEDBUFFERRANGEPROC)             (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLintptr& in_offset, const GLsizeiptr& in_length);
    typedef void           (*PFNVKGLFRAMEBUFFERRENDERBUFFERPROC)            (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_renderbuffertarget, const GLuint& in_renderbuffer);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURE1DPROC)               (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_textarget, const GLuint& in_texture, const GLint& in_level);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURE2DPROC)               (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_textarget, const GLuint& in_texture, const GLint& in_level);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURE3DPROC)               (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_textarget, const GLuint& in_texture, const GLint& in_level, const GLint& in_zoffset);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURELAYERPROC)            (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLuint& in_texture, const GLint& in_level, const GLint& in_layer);
    typedef void           (*PFNVKGLGENFRAMEBUFFERSPROC)                    (VKGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* out_framebuffers_ptr);
    typedef void           (*PFNVKGLGENRENDERBUFFERSPROC)                   (VKGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* out_renderbuffers_ptr);
    typedef void           (*PFNVKGLGENVERTEXARRAYSPROC)                    (VKGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* in_arrays_ptr);
    typedef void           (*PFNVKGLGENERATEMIPMAPPROC)                     (VKGL::Context* in_context_ptr, const GLenum& in_target);
    typedef void           (*PFNVKGLGETBOOLEANI_VPROC)                      (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, GLboolean* out_data_ptr);
    typedef GLint          (*PFNVKGLGETFRAGDATALOCATIONPROC)                (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_name_ptr);
    typedef void           (*PFNVKGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETINTEGERI_VPROC)                      (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, GLint* out_data_ptr);
    typedef void           (*PFNVKGLGETRENDERBUFFERPARAMETERIVPROC)         (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint* out_params_ptr);
    typedef const GLubyte* (*PFNVKGLGETSTRINGIPROC)                         (VKGL::Context* in_context_ptr, const GLenum& in_name, const GLuint& in_index);
    typedef void           (*PFNVKGLGETTEXPARAMETERIIVPROC)                 (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXPARAMETERIUIVPROC)                (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLuint* out_params_ptr);
    typedef void           (*PFNVKGLGETTRANSFORMFEEDBACKVARYINGPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLsizei& in_buf_size, GLsizei* out_length_ptr, GLsizei* out_size_ptr, GLenum* out_type_ptr, GLchar* out_name_ptr);
    typedef void           (*PFNVKGLGETUNIFORMUIVPROC)                      (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLint& in_location, GLuint* out_params_ptr);
    typedef void           (*PFNVKGLGETVERTEXATTRIBIIVPROC)                 (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETVERTEXATTRIBIUIVPROC)                (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLuint* out_params_ptr);
    typedef GLboolean      (*PFNVKGLISENABLEDIPROC)                         (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index);
    typedef GLboolean      (*PFNVKGLISFRAMEBUFFERPROC)                      (VKGL::Context* in_context_ptr, const GLuint& in_framebuffer);
    typedef GLboolean      (*PFNVKGLISRENDERBUFFERPROC)                     (VKGL::Context* in_context_ptr, const GLuint& in_renderbuffer);
    typedef GLboolean      (*PFNVKGLISVERTEXARRAYPROC)                      (VKGL::Context* in_context_ptr, const GLuint& in_array);
    typedef void*          (*PFNVKGLMAPBUFFERRANGEPROC)                     (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLintptr& in_offset, const GLsizeiptr& in_length, const GLbitfield& in_access);
    typedef void           (*PFNVKGLRENDERBUFFERSTORAGEPROC)                (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height);
    typedef void           (*PFNVKGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)     (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLsizei& in_samples, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height);
    typedef void           (*PFNVKGLTEXPARAMETERIIVPROC)                    (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLint* in_params_ptr);
    typedef void           (*PFNVKGLTEXPARAMETERIUIVPROC)                   (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLuint* in_params_ptr);
    typedef void           (*PFNVKGLTRANSFORMFEEDBACKVARYINGSPROC)          (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_count, const GLchar* const* in_varyings_ptr_ptr, const GLenum& in_buffer_mode);
    typedef void           (*PFNVKGLUNIFORM1UIPROC)                         (VKGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0);
    typedef void           (*PFNVKGLUNIFORM1UIVPROC)                        (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLUNIFORM2UIPROC)                         (VKGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0, const GLuint& in_v1);
    typedef void           (*PFNVKGLUNIFORM2UIVPROC)                        (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLUNIFORM3UIPROC)                         (VKGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0, const GLuint& in_v1, const GLuint& in_v2);
    typedef void           (*PFNVKGLUNIFORM3UIVPROC)                        (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLUNIFORM4UIPROC)                         (VKGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0, const GLuint& in_v1, const GLuint& in_v2, const GLuint& in_v3);
    typedef void           (*PFNVKGLUNIFORM4UIVPROC)                        (VKGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI1IPROC)                    (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x);
    typedef void           (*PFNVKGLVERTEXATTRIBI1IVPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI1UIPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x);
    typedef void           (*PFNVKGLVERTEXATTRIBI1UIVPROC)                  (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI2IPROC)                    (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x, const GLint& in_y);
    typedef void           (*PFNVKGLVERTEXATTRIBI2IVPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI2UIPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x, const GLuint& in_y);
    typedef void           (*PFNVKGLVERTEXATTRIBI2UIVPROC)                  (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI3IPROC)                    (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x, const GLint& in_y, const GLint& in_z);
    typedef void           (*PFNVKGLVERTEXATTRIBI3IVPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI3UIPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x, const GLuint& in_y, const GLuint& in_z);
    typedef void           (*PFNVKGLVERTEXATTRIBI3UIVPROC)                  (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4BVPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLbyte* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4IPROC)                    (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x, const GLint& in_y, const GLint& in_z, const GLint& in_w);
    typedef void           (*PFNVKGLVERTEXATTRIBI4IVPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4SVPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4UBVPROC)                  (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4UIPROC)                   (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x, const GLuint& in_y, const GLuint& in_z, const GLuint& in_w);
    typedef void           (*PFNVKGLVERTEXATTRIBI4UIVPROC)                  (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4USVPROC)                  (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLushort* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBIPOINTERPROC)               (VKGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_size, const GLenum& in_type, const GLsizei& in_stride, const void* in_pointer_ptr);

    /* VKGL GL entrypoints : GL 3.1 */
    typedef void   (*PFNVKGLCOPYBUFFERSUBDATAPROC)        (VKGL::Context* in_context_ptr, const GLenum& in_read_target, const GLenum& in_write_target, const GLintptr& in_read_offset, const GLintptr& in_write_offset, const GLsizeiptr& in_size);
    typedef void   (*PFNVKGLDRAWARRAYSINSTANCEDPROC)      (VKGL::Context* in_context_ptr, const GLenum& in_mode, const GLint& in_first, const GLsizei& in_count, const GLsizei& in_instancecount);
    typedef void   (*PFNVKGLDRAWELEMENTSINSTANCEDPROC)    (VKGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei& in_count, const GLenum& in_type, const void* in_indices_ptr, const GLsizei& in_instancecount);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMBLOCKNAMEPROC)(VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_block_index, const GLsizei& in_buf_size, GLsizei* in_length_ptr, GLchar* out_uniform_block_name);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMBLOCKIVPROC)  (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_block_index, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMNAMEPROC)     (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_index, const GLsizei& in_buf_size, GLsizei* out_length_ptr, GLchar*  out_uniform_name_ptr);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMSIVPROC)      (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_uniform_count, const GLuint* in_uniform_indices_ptr, const GLenum& in_pname, GLint* out_params_ptr);
    typedef GLuint (*PFNVKGLGETUNIFORMBLOCKINDEXPROC)     (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_uniform_block_name_ptr);
    typedef void   (*PFNVKGLGETUNIFORMINDICESPROC)        (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_uniform_count, const GLchar* const* in_uniform_names_ptr_ptr, GLuint* out_uniform_indices_ptr);
    typedef void   (*PFNVKGLPRIMITIVERESTARTINDEXPROC)    (VKGL::Context* in_context_ptr, const GLuint& in_index);
    typedef void   (*PFNVKGLTEXBUFFERPROC)                (VKGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_internalformat, const GLuint& in_buffer);
    typedef void   (*PFNVKGLUNIFORMBLOCKBINDINGPROC)      (VKGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_block_index, const GLuint& in_uniform_block_binding);

    /* VKGL GL entrypoints : GL 3.2 */
    typedef GLenum    (*PFNVKGLCLIENTWAITSYNCPROC)                 (VKGL::Context* in_context_ptr, GLsync in_sync, GLbitfield in_flags, GLuint64 in_timeout);
    typedef void      (*PFNVKGLDELETESYNCPROC)                     (VKGL::Context* in_context_ptr, GLsync in_sync);
    typedef void      (*PFNVKGLDRAWELEMENTSBASEVERTEXPROC)         (VKGL::Context* in_context_ptr, GLenum in_mode, GLsizei in_count, GLenum in_type, const void* in_indices, GLint in_basevertex);
    typedef void      (*PFNVKGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(VKGL::Context* in_context_ptr, GLenum in_mode, GLsizei in_count, GLenum in_type, const void* in_indices, GLsizei in_instancecount, GLint in_basevertex);
    typedef void      (*PFNVKGLDRAWRANGEELEMENTSBASEVERTEXPROC)    (VKGL::Context* in_context_ptr, GLenum in_mode, GLuint in_start, GLuint in_end, GLsizei in_count, GLenum in_type, const void* in_indices, GLint in_basevertex);
    typedef GLsync    (*PFNVKGLFENCESYNCPROC)                      (VKGL::Context* in_context_ptr, GLenum in_condition, GLbitfield in_flags);
    typedef void      (*PFNVKGLFRAMEBUFFERTEXTUREPROC)             (VKGL::Context* in_context_ptr, GLenum in_target, GLenum in_attachment, GLuint in_texture, GLint in_level);
    typedef void      (*PFNVKGLGETBUFFERPARAMETERI64VPROC)         (VKGL::Context* in_context_ptr, GLenum in_target, GLenum in_pname, GLint64* in_params);
    typedef void      (*PFNVKGLGETINTEGER64I_VPROC)                (VKGL::Context* in_context_ptr, GLenum in_target, GLuint in_index, GLint64* in_data);
    typedef void      (*PFNVKGLGETINTEGER64VPROC)                  (VKGL::Context* in_context_ptr, GLenum in_pname, GLint64* in_data);
    typedef void      (*PFNVKGLGETMULTISAMPLEFVPROC)               (VKGL::Context* in_context_ptr, GLenum in_pname, GLuint in_index, GLfloat* in_val);
    typedef void      (*PFNVKGLGETSYNCIVPROC)                      (VKGL::Context* in_context_ptr, GLsync in_sync, GLenum in_pname, GLsizei in_bufSize, GLsizei* in_length, GLint* in_values);
    typedef GLboolean (*PFNVKGLISSYNCPROC)                         (VKGL::Context* in_context_ptr, GLsync in_sync);
    typedef void      (*PFNVKGLMULTIDRAWELEMENTSBASEVERTEXPROC)    (VKGL::Context* in_context_ptr, GLenum in_mode, const GLsizei* in_count, GLenum in_type, const void* const* in_indices, GLsizei in_drawcount, const GLint* in_basevertex);
    typedef void      (*PFNVKGLPROVOKINGVERTEXPROC)                (VKGL::Context* in_context_ptr, GLenum in_mode);
    typedef void      (*PFNVKGLSAMPLEMASKIPROC)                    (VKGL::Context* in_context_ptr, GLuint in_maskNumber, GLbitfield in_mask);
    typedef void      (*PFNVKGLTEXIMAGE2DMULTISAMPLEPROC)          (VKGL::Context* in_context_ptr, GLenum in_target, GLsizei in_samples, GLenum in_internalformat, GLsizei in_width, GLsizei in_height, GLboolean in_fixedsamplelocations);
    typedef void      (*PFNVKGLTEXIMAGE3DMULTISAMPLEPROC)          (VKGL::Context* in_context_ptr, GLenum in_target, GLsizei in_samples, GLenum in_internalformat, GLsizei in_width, GLsizei in_height, GLsizei in_depth, GLboolean in_fixedsamplelocations);
    typedef void      (*PFNVKGLWAITSYNCPROC)                       (VKGL::Context* in_context_ptr, GLsync in_sync, GLbitfield in_flags, GLuint64 in_timeout);

}

#endif /* VKGL_TYPES_TYPEDEFS_H */