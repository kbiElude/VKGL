/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_TYPEDEFS_H
#define VKGL_TYPES_TYPEDEFS_H

namespace OpenGL
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
    typedef void      (*PFNVKGLBINDTEXTUREPROC)      (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_texture);
    typedef void      (*PFNVKGLCOPYTEXIMAGE1DPROC)   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum&  in_internalformat, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLint& in_border);
    typedef void      (*PFNVKGLCOPYTEXIMAGE2DPROC)   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum&  in_internalformat, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height, const GLint& in_border);
    typedef void      (*PFNVKGLCOPYTEXSUBIMAGE1DPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_x, const GLint& in_y, const GLsizei& in_width);
    typedef void      (*PFNVKGLCOPYTEXSUBIMAGE2DPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);
    typedef void      (*PFNVKGLDELETETEXTURESPROC)   (OpenGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_textures);
    typedef void      (*PFNVKGLDRAWARRAYSPROC)       (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLint&  in_first, const GLsizei& in_count);
    typedef void      (*PFNVKGLDRAWELEMENTSPROC)     (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei& in_count, const GLenum& in_type, const void* in_indices);
    typedef void      (*PFNVKGLGENTEXTURESPROC)      (OpenGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* in_textures);
    typedef GLboolean (*PFNVKGLISTEXTUREPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_texture);
    typedef void      (*PFNVKGLPOLYGONOFFSETPROC)    (OpenGL::Context* in_context_ptr, const GLfloat& in_factor, const GLfloat& in_units);
    typedef void      (*PFNVKGLTEXSUBIMAGE1DPROC)    (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLsizei& in_width, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);
    typedef void      (*PFNVKGLTEXSUBIMAGE2DPROC)    (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLsizei& in_width, const GLsizei& in_height, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);

    /* VKG GL entrypoints : GL 1.2 */
    typedef void (*PFNVKGLCOPYTEXSUBIMAGE3DPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_zoffset, const GLint& in_x, const GLint& in_y, const GLsizei& in_width, const GLsizei& in_height);
    typedef void (*PFNVKGLDRAWRANGEELEMENTSPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLuint& in_start, const GLuint& in_end, const GLsizei& in_count, const GLenum& in_type, const void* in_indices);
    typedef void (*PFNVKGLTEXIMAGE3DPROC)       (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLint& in_border, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);
    typedef void (*PFNVKGLTEXSUBIMAGE3DPROC)    (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_zoffset, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLenum& in_format, const GLenum& in_type, const void* in_pixels);

    /* VKG GL entrypoints : GL 1.3 */
    typedef void (*PFNVKGLACTIVETEXTUREPROC)          (OpenGL::Context* in_context_ptr, const GLenum& in_texture);
    typedef void (*PFNVKGLCOMPRESSEDTEXIMAGE1DPROC)   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_internalformat, const GLsizei& in_width, const GLint& in_border, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXIMAGE2DPROC)   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLint& in_border, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXIMAGE3DPROC)   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLint& in_border, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXSUBIMAGE1DPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLsizei& in_width, const GLenum& in_format, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXSUBIMAGE2DPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLsizei& in_width, const GLsizei& in_height, const GLenum& in_format, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLCOMPRESSEDTEXSUBIMAGE3DPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, const GLint& in_xoffset, const GLint& in_yoffset, const GLint& in_zoffset, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLenum& in_format, const GLsizei& in_image_size, const void* in_data);
    typedef void (*PFNVKGLGETCOMPRESSEDTEXIMAGEPROC)  (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLint& in_level, void* in_img);
    typedef void (*PFNVKGLSAMPLECOVERAGEPROC)         (OpenGL::Context* in_context_ptr, const GLfloat& in_value, const GLboolean& in_invert);

    /* VKGL GL entrypoints : GL 1.4 */
    typedef void (*PFNVKGLBLENDCOLORPROC)       (OpenGL::Context* in_context_ptr, const GLfloat& red, const GLfloat& green, const GLfloat& blue, const GLfloat& alpha);
    typedef void (*PFNVKGLBLENDEQUATIONPROC)    (OpenGL::Context* in_context_ptr, const GLenum& mode);
    typedef void (*PFNVKGLBLENDFUNCSEPARATEPROC)(OpenGL::Context* in_context_ptr, const GLenum& sfactorRGB, const GLenum& dfactorRGB, const GLenum& sfactorAlpha, const GLenum& dfactorAlpha);
    typedef void (*PFNVKGLMULTIDRAWARRAYSPROC)  (OpenGL::Context* in_context_ptr, const GLenum& mode, const GLint* first, const GLsizei* count, const GLsizei& drawcount);
    typedef void (*PFNVKGLMULTIDRAWELEMENTSPROC)(OpenGL::Context* in_context_ptr, const GLenum& mode, const GLsizei* count, const GLenum& type, const void* const* indices, const GLsizei& drawcount);
    typedef void (*PFNVKGLPOINTPARAMETERFPROC)  (OpenGL::Context* in_context_ptr, const GLenum& pname, const GLfloat& param);
    typedef void (*PFNVKGLPOINTPARAMETERFVPROC) (OpenGL::Context* in_context_ptr, const GLenum& pname, const GLfloat* params);
    typedef void (*PFNVKGLPOINTPARAMETERIPROC)  (OpenGL::Context* in_context_ptr, const GLenum& pname, const GLint&  param);
    typedef void (*PFNVKGLPOINTPARAMETERIVPROC) (OpenGL::Context* in_context_ptr, const GLenum& pname, const GLint* params);

    /* VKGL GL entrypoints: GL 1.5 */
    typedef void  (*PFNVKGLBEGINQUERYPROC)          (OpenGL::Context* in_context_ptr, const GLenum& target, const GLuint& id);
    typedef void  (*PFNVKGLBINDBUFFERPROC)          (OpenGL::Context* in_context_ptr, const GLenum& target, const GLuint& buffer);
    typedef void  (*PFNVKGLBUFFERDATAPROC)          (OpenGL::Context* in_context_ptr, const GLenum& target, const GLsizeiptr& size, const void* data, const GLenum& usage);
    typedef void  (*PFNVKGLBUFFERSUBDATAPROC)       (OpenGL::Context* in_context_ptr, const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, const void* data);
    typedef void  (*PFNVKGLDELETEBUFFERSPROC)       (OpenGL::Context* in_context_ptr, const GLsizei& n, const GLuint* buffers);
    typedef void  (*PFNVKGLDELETEQUERIESPROC)       (OpenGL::Context* in_context_ptr, const GLsizei& n, const GLuint* ids);
    typedef void  (*PFNVKGLENDQUERYPROC)            (OpenGL::Context* in_context_ptr, const GLenum& target);
    typedef void  (*PFNVKGLGENBUFFERSPROC)          (OpenGL::Context* in_context_ptr, const GLsizei& n, GLuint* buffers);
    typedef void  (*PFNVKGLGENQUERIESPROC)          (OpenGL::Context* in_context_ptr, const GLsizei& n, GLuint* ids);
    typedef void  (*PFNVKGLGETBUFFERPARAMETERIVPROC)(OpenGL::Context* in_context_ptr, const GLenum& target, const GLenum& pname, GLint* params);
    typedef void  (*PFNVKGLGETBUFFERPOINTERVPROC)   (OpenGL::Context* in_context_ptr, const GLenum& target, const GLenum& pname, void** params);
    typedef void  (*PFNVKGLGETBUFFERSUBDATAPROC)    (OpenGL::Context* in_context_ptr, const GLenum& target, const GLintptr& offset, const GLsizeiptr& size, void* data);
    typedef void  (*PFNVKGLGETQUERYOBJECTIVPROC)    (OpenGL::Context* in_context_ptr, const GLuint& id, const GLenum& pname, GLint* params);
    typedef void  (*PFNVKGLGETQUERYOBJECTUIVPROC)   (OpenGL::Context* in_context_ptr, const GLuint& id, const GLenum& pname, GLuint* params);
    typedef void  (*PFNVKGLGETQUERYIVPROC)          (OpenGL::Context* in_context_ptr, const GLenum& target, const GLenum& pname, GLint* params);
    typedef bool  (*PFNVKGLISBUFFERPROC)            (OpenGL::Context* in_context_ptr, const GLuint& buffer);
    typedef bool  (*PFNVKGLISQUERYPROC)             (OpenGL::Context* in_context_ptr, const GLuint& id);
    typedef void* (*PFNVKGLMAPBUFFERPROC)           (OpenGL::Context* in_context_ptr, const GLenum& target, const GLenum& access);
    typedef bool  (*PFNVKGLUNMAPBUFFERPROC)         (OpenGL::Context* in_context_ptr, const GLenum& target);

    /* VKGL GL entrypoints: GL 2.0 */

    typedef void      (*PFNVKGLATTACHSHADERPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_shader);
    typedef void      (*PFNVKGLBINDATTRIBLOCATIONPROC)      (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLchar* in_name);
    typedef void      (*PFNVKGLBLENDEQUATIONSEPARATEPROC)   (OpenGL::Context* in_context_ptr, const GLenum& in_modeRGB, const GLenum& in_modeAlpha);
    typedef void      (*PFNVKGLCOMPILESHADERPROC)           (OpenGL::Context* in_context_ptr, const GLuint& in_shader);
    typedef GLuint    (*PFNVKGLCREATEPROGRAMPROC)           (OpenGL::Context* in_context_ptr);
    typedef GLuint    (*PFNVKGLCREATESHADERPROC)            (OpenGL::Context* in_context_ptr, const GLenum& in_type);
    typedef void      (*PFNVKGLDELETEPROGRAMPROC)           (OpenGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLDELETESHADERPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_shader);
    typedef void      (*PFNVKGLDETACHSHADERPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_shader);
    typedef void      (*PFNVKGLDISABLEVERTEXATTRIBARRAYPROC)(OpenGL::Context* in_context_ptr, const GLuint& in_index);
    typedef void      (*PFNVKGLDRAWBUFFERSPROC)             (OpenGL::Context* in_context_ptr, const GLsizei& in_n, const GLenum* in_bufs);
    typedef void      (*PFNVKGLENABLEVERTEXATTRIBARRAYPROC) (OpenGL::Context* in_context_ptr, const GLuint& in_index);
    typedef void      (*PFNVKGLGETACTIVEATTRIBPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLsizei& in_bufSize, GLsizei* in_length, GLint* in_size, GLenum* in_type, GLchar* in_name);
    typedef void      (*PFNVKGLGETACTIVEUNIFORMPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLsizei& in_bufSize, GLsizei* in_length, GLint* in_size, GLenum* in_type, GLchar* in_name);
    typedef void      (*PFNVKGLGETATTACHEDSHADERSPROC)      (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_maxCount, GLsizei* in_count, GLuint* in_shaders);
    typedef GLint     (*PFNVKGLGETATTRIBLOCATIONPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_name);
    typedef void      (*PFNVKGLGETPROGRAMINFOLOGPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_bufSize, GLsizei* in_length, GLchar* in_infoLog);
    typedef void      (*PFNVKGLGETPROGRAMIVPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLenum& in_pname, GLint* in_params);
    typedef void      (*PFNVKGLGETSHADERINFOLOGPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_shader, const GLsizei& in_bufSize, GLsizei* in_length, GLchar* in_infoLog);
    typedef void      (*PFNVKGLGETSHADERSOURCEPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_shader, const GLsizei& in_bufSize, GLsizei* in_length, GLchar* in_source);
    typedef void      (*PFNVKGLGETSHADERIVPROC)             (OpenGL::Context* in_context_ptr, const GLuint& in_shader, const GLenum& in_pname, GLint* in_params);
    typedef GLint     (*PFNVKGLGETUNIFORMLOCATIONPROC)      (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_name);
    typedef void      (*PFNVKGLGETUNIFORMFVPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLint& in_location, GLfloat* in_params);
    typedef void      (*PFNVKGLGETUNIFORMIVPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLint& in_location, GLint* in_params);
    typedef void      (*PFNVKGLGETVERTEXATTRIBPOINTERVPROC) (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, void** in_pointer);
    typedef void      (*PFNVKGLGETVERTEXATTRIBDVPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLdouble* in_params);
    typedef void      (*PFNVKGLGETVERTEXATTRIBFVPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLfloat* in_params);
    typedef void      (*PFNVKGLGETVERTEXATTRIBIVPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLint* in_params);
    typedef bool      (*PFNVKGLISPROGRAMPROC)               (OpenGL::Context* in_context_ptr, const GLuint& in_program);
    typedef bool      (*PFNVKGLISSHADERPROC)                (OpenGL::Context* in_context_ptr, const GLuint& in_shader);
    typedef void      (*PFNVKGLLINKPROGRAMPROC)             (OpenGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLSHADERSOURCEPROC)            (OpenGL::Context* in_context_ptr, const GLuint& in_shader, const GLsizei& in_count,const GLchar* const* in_string, const GLint* in_length);
    typedef void      (*PFNVKGLSTENCILFUNCSEPARATEPROC)     (OpenGL::Context* in_context_ptr, const GLenum& in_face, const GLenum& in_func,const GLint& in_ref, const GLuint& in_mask);
    typedef void      (*PFNVKGLSTENCILMASKSEPARATEPROC)     (OpenGL::Context* in_context_ptr, const GLenum& in_face,const GLuint& in_mask);
    typedef void      (*PFNVKGLSTENCILOPSEPARATEPROC)       (OpenGL::Context* in_context_ptr, const GLenum& in_face, const GLenum& in_sfail, const GLenum& in_dpfail, const GLenum& in_dppass);
    typedef void      (*PFNVKGLUNIFORM1FPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0);
    typedef void      (*PFNVKGLUNIFORM1FVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM1IPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0);
    typedef void      (*PFNVKGLUNIFORM1IVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORM2FPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0, const GLfloat& in_v1);
    typedef void      (*PFNVKGLUNIFORM2FVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM2IPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0, const GLint& in_v1);
    typedef void      (*PFNVKGLUNIFORM2IVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORM3FPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0, const GLfloat& in_v1, const GLfloat& in_v2);
    typedef void      (*PFNVKGLUNIFORM3FVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM3IPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0, const GLint& in_v1, const GLint& in_v2);
    typedef void      (*PFNVKGLUNIFORM3IVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORM4FPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLfloat& in_v0, const GLfloat& in_v1, const GLfloat& in_v2, const GLfloat& in_v3);
    typedef void      (*PFNVKGLUNIFORM4FVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORM4IPROC)               (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLint& in_v0, const GLint& in_v1, const GLint& in_v2, const GLint& in_v3);
    typedef void      (*PFNVKGLUNIFORM4IVPROC)              (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLint* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX2FVPROC)        (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX3FVPROC)        (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX4FVPROC)        (OpenGL::Context* in_context_ptr, const GLint& in_location,const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUSEPROGRAMPROC)              (OpenGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLVALIDATEPROGRAMPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_program);
    typedef void      (*PFNVKGLVERTEXATTRIB1DPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x);
    typedef void      (*PFNVKGLVERTEXATTRIB1DVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB1FPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x);
    typedef void      (*PFNVKGLVERTEXATTRIB1FVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB1SPROC)          (OpenGL::Context* in_context_ptr, const GLuint&  in_index, const GLshort& in_x);
    typedef void      (*PFNVKGLVERTEXATTRIB1SVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB2DPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x, const GLdouble& in_y);
    typedef void      (*PFNVKGLVERTEXATTRIB2DVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB2FPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x, const GLfloat& in_y);
    typedef void      (*PFNVKGLVERTEXATTRIB2FVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB2SPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort& in_x, const GLshort& in_y);
    typedef void      (*PFNVKGLVERTEXATTRIB2SVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB3DPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x, const GLdouble& in_y, const GLdouble& in_z);
    typedef void      (*PFNVKGLVERTEXATTRIB3DVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB3FPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x, const GLfloat& in_y, const GLfloat& in_z);
    typedef void      (*PFNVKGLVERTEXATTRIB3FVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB3SPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort& in_x, const GLshort& in_y, const GLshort& in_z);
    typedef void      (*PFNVKGLVERTEXATTRIB3SVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4BVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLbyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4DPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble& in_x, const GLdouble& in_y, const GLdouble& in_z, const GLdouble& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4DVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLdouble* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4FPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat& in_x, const GLfloat& in_y, const GLfloat& in_z, const GLfloat& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4FVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLfloat* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4IVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NBVPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLbyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NIVPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NSVPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUBPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte& in_x, const GLubyte& in_y, const GLubyte& in_z, const GLubyte& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUBVPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUIVPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4NUSVPROC)       (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLushort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4SPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort& in_x, const GLshort& in_y, const GLshort& in_z, const GLshort& in_w);
    typedef void      (*PFNVKGLVERTEXATTRIB4SVPROC)         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4UBVPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4UIVPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIB4USVPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLushort* in_v);
    typedef void      (*PFNVKGLVERTEXATTRIBPOINTERPROC)     (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_size, const GLenum& in_type, const GLboolean& in_normalized, const GLsizei& in_stride, const void* in_pointer);

    /* VKGL GL entrypoints : GL 2.1 */
    typedef void      (*PFNVKGLUNIFORMMATRIX2X3FVPROC)      (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX2X4FVPROC)      (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX3X2FVPROC)      (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX3X4FVPROC)      (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX4X2FVPROC)      (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);
    typedef void      (*PFNVKGLUNIFORMMATRIX4X3FVPROC)      (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLboolean& in_transpose, const GLfloat* in_value);

    /* VKGL GL entrypoints : GL 3.0 */
    typedef void           (*PFNVKGLBEGINCONDITIONALRENDERPROC)             (OpenGL::Context* in_context_ptr, const GLuint& in_id, const GLenum& in_mode);
    typedef void           (*PFNVKGLBEGINTRANSFORMFEEDBACKPROC)             (OpenGL::Context* in_context_ptr, const GLenum& in_primitive_mode);
    typedef void           (*PFNVKGLBINDBUFFERBASEPROC)                     (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, const GLuint& in_buffer);
    typedef void           (*PFNVKGLBINDBUFFERRANGEPROC)                    (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, const GLuint& in_buffer, const GLintptr& in_offset, const GLsizeiptr& in_size);
    typedef void           (*PFNVKGLBINDFRAGDATALOCATIONPROC)               (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_color, const GLchar* in_name_ptr);
    typedef void           (*PFNVKGLBINDFRAMEBUFFERPROC)                    (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_framebuffer);
    typedef void           (*PFNVKGLBINDRENDERBUFFERPROC)                   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_renderbuffer);
    typedef void           (*PFNVKGLBINDVERTEXARRAYPROC)                    (OpenGL::Context* in_context_ptr, const GLuint& in_array);
    typedef void           (*PFNVKGLBLITFRAMEBUFFERPROC)                    (OpenGL::Context* in_context_ptr, const GLint& in_srcX0, const GLint& in_srcY0, const GLint& in_srcX1, const GLint& in_srcY1, const GLint& in_dstX0, const GLint& in_dstY0, const GLint& in_dstX1, const GLint& in_dstY1, const GLbitfield& in_mask, const GLenum& in_filter);
    typedef GLenum         (*PFNVKGLCHECKFRAMEBUFFERSTATUSPROC)             (OpenGL::Context* in_context_ptr, const GLenum& in_target);
    typedef void           (*PFNVKGLCLAMPCOLORPROC)                         (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_clamp);
    typedef void           (*PFNVKGLCLEARBUFFERFIPROC)                      (OpenGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLfloat& in_depth, const GLint& in_stencil);
    typedef void           (*PFNVKGLCLEARBUFFERFVPROC)                      (OpenGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLfloat* in_value_ptr);
    typedef void           (*PFNVKGLCLEARBUFFERIVPROC)                      (OpenGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLint* in_value_ptr);
    typedef void           (*PFNVKGLCLEARBUFFERUIVPROC)                     (OpenGL::Context* in_context_ptr, const GLenum& in_buffer, const GLint& in_drawbuffer, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLCOLORMASKIPROC)                         (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLboolean& in_r, const GLboolean& in_g, const GLboolean& in_b, const GLboolean& in_a);
    typedef void           (*PFNVKGLDELETEFRAMEBUFFERSPROC)                 (OpenGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_framebuffers_ptr);
    typedef void           (*PFNVKGLDELETERENDERBUFFERSPROC)                (OpenGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_renderbuffers_ptr);
    typedef void           (*PFNVKGLDELETEVERTEXARRAYSPROC)                 (OpenGL::Context* in_context_ptr, const GLsizei& in_n, const GLuint* in_arrays_ptr);
    typedef void           (*PFNVKGLDISABLEIPROC)                           (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index);
    typedef void           (*PFNVKGLENABLEIPROC)                            (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index);
    typedef void           (*PFNVKGLENDCONDITIONALRENDERPROC)               (OpenGL::Context* in_context_ptr);
    typedef void           (*PFNVKGLENDTRANSFORMFEEDBACKPROC)               (OpenGL::Context* in_context_ptr);
    typedef void           (*PFNVKGLFLUSHMAPPEDBUFFERRANGEPROC)             (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLintptr& in_offset, const GLsizeiptr& in_length);
    typedef void           (*PFNVKGLFRAMEBUFFERRENDERBUFFERPROC)            (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_renderbuffertarget, const GLuint& in_renderbuffer);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURE1DPROC)               (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_textarget, const GLuint& in_texture, const GLint& in_level);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURE2DPROC)               (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_textarget, const GLuint& in_texture, const GLint& in_level);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURE3DPROC)               (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_textarget, const GLuint& in_texture, const GLint& in_level, const GLint& in_zoffset);
    typedef void           (*PFNVKGLFRAMEBUFFERTEXTURELAYERPROC)            (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLuint& in_texture, const GLint& in_level, const GLint& in_layer);
    typedef void           (*PFNVKGLGENFRAMEBUFFERSPROC)                    (OpenGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* out_framebuffers_ptr);
    typedef void           (*PFNVKGLGENRENDERBUFFERSPROC)                   (OpenGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* out_renderbuffers_ptr);
    typedef void           (*PFNVKGLGENVERTEXARRAYSPROC)                    (OpenGL::Context* in_context_ptr, const GLsizei& in_n, GLuint* in_arrays_ptr);
    typedef void           (*PFNVKGLGENERATEMIPMAPPROC)                     (OpenGL::Context* in_context_ptr, const GLenum& in_target);
    typedef void           (*PFNVKGLGETBOOLEANI_VPROC)                      (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, GLboolean* out_data_ptr);
    typedef GLint          (*PFNVKGLGETFRAGDATALOCATIONPROC)                (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_name_ptr);
    typedef void           (*PFNVKGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETINTEGERI_VPROC)                      (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, GLint* out_data_ptr);
    typedef void           (*PFNVKGLGETRENDERBUFFERPARAMETERIVPROC)         (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint* out_params_ptr);
    typedef const GLubyte* (*PFNVKGLGETSTRINGIPROC)                         (OpenGL::Context* in_context_ptr, const GLenum& in_name, const GLuint& in_index);
    typedef void           (*PFNVKGLGETTEXPARAMETERIIVPROC)                 (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETTEXPARAMETERIUIVPROC)                (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLuint* out_params_ptr);
    typedef void           (*PFNVKGLGETTRANSFORMFEEDBACKVARYINGPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_index, const GLsizei& in_buf_size, GLsizei* out_length_ptr, GLsizei* out_size_ptr, GLenum* out_type_ptr, GLchar* out_name_ptr);
    typedef void           (*PFNVKGLGETUNIFORMUIVPROC)                      (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLint& in_location, GLuint* out_params_ptr);
    typedef void           (*PFNVKGLGETVERTEXATTRIBIIVPROC)                 (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void           (*PFNVKGLGETVERTEXATTRIBIUIVPROC)                (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLenum& in_pname, GLuint* out_params_ptr);
    typedef bool           (*PFNVKGLISENABLEDIPROC)                         (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index);
    typedef bool           (*PFNVKGLISFRAMEBUFFERPROC)                      (OpenGL::Context* in_context_ptr, const GLuint& in_framebuffer);
    typedef bool           (*PFNVKGLISRENDERBUFFERPROC)                     (OpenGL::Context* in_context_ptr, const GLuint& in_renderbuffer);
    typedef bool           (*PFNVKGLISVERTEXARRAYPROC)                      (OpenGL::Context* in_context_ptr, const GLuint& in_array);
    typedef void*          (*PFNVKGLMAPBUFFERRANGEPROC)                     (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLintptr& in_offset, const GLsizeiptr& in_length, const GLbitfield& in_access);
    typedef void           (*PFNVKGLRENDERBUFFERSTORAGEPROC)                (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height);
    typedef void           (*PFNVKGLRENDERBUFFERSTORAGEMULTISAMPLEPROC)     (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLsizei& in_samples, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height);
    typedef void           (*PFNVKGLTEXPARAMETERIIVPROC)                    (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLint* in_params_ptr);
    typedef void           (*PFNVKGLTEXPARAMETERIUIVPROC)                   (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, const GLuint* in_params_ptr);
    typedef void           (*PFNVKGLTRANSFORMFEEDBACKVARYINGSPROC)          (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_count, const GLchar* const* in_varyings_ptr_ptr, const GLenum& in_buffer_mode);
    typedef void           (*PFNVKGLUNIFORM1UIPROC)                         (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0);
    typedef void           (*PFNVKGLUNIFORM1UIVPROC)                        (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLUNIFORM2UIPROC)                         (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0, const GLuint& in_v1);
    typedef void           (*PFNVKGLUNIFORM2UIVPROC)                        (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLUNIFORM3UIPROC)                         (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0, const GLuint& in_v1, const GLuint& in_v2);
    typedef void           (*PFNVKGLUNIFORM3UIVPROC)                        (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLUNIFORM4UIPROC)                         (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLuint& in_v0, const GLuint& in_v1, const GLuint& in_v2, const GLuint& in_v3);
    typedef void           (*PFNVKGLUNIFORM4UIVPROC)                        (OpenGL::Context* in_context_ptr, const GLint& in_location, const GLsizei& in_count, const GLuint* in_value_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI1IPROC)                    (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x);
    typedef void           (*PFNVKGLVERTEXATTRIBI1IVPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI1UIPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x);
    typedef void           (*PFNVKGLVERTEXATTRIBI1UIVPROC)                  (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI2IPROC)                    (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x, const GLint& in_y);
    typedef void           (*PFNVKGLVERTEXATTRIBI2IVPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI2UIPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x, const GLuint& in_y);
    typedef void           (*PFNVKGLVERTEXATTRIBI2UIVPROC)                  (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI3IPROC)                    (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x, const GLint& in_y, const GLint& in_z);
    typedef void           (*PFNVKGLVERTEXATTRIBI3IVPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI3UIPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x, const GLuint& in_y, const GLuint& in_z);
    typedef void           (*PFNVKGLVERTEXATTRIBI3UIVPROC)                  (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4BVPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLbyte* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4IPROC)                    (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_x, const GLint& in_y, const GLint& in_z, const GLint& in_w);
    typedef void           (*PFNVKGLVERTEXATTRIBI4IVPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4SVPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLshort* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4UBVPROC)                  (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLubyte* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4UIPROC)                   (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint& in_x, const GLuint& in_y, const GLuint& in_z, const GLuint& in_w);
    typedef void           (*PFNVKGLVERTEXATTRIBI4UIVPROC)                  (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLuint* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBI4USVPROC)                  (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLushort* in_v_ptr);
    typedef void           (*PFNVKGLVERTEXATTRIBIPOINTERPROC)               (OpenGL::Context* in_context_ptr, const GLuint& in_index, const GLint& in_size, const GLenum& in_type, const GLsizei& in_stride, const void* in_pointer_ptr);

    /* VKGL GL entrypoints : GL 3.1 */
    typedef void   (*PFNVKGLCOPYBUFFERSUBDATAPROC)        (OpenGL::Context* in_context_ptr, const GLenum& in_read_target, const GLenum& in_write_target, const GLintptr& in_read_offset, const GLintptr& in_write_offset, const GLsizeiptr& in_size);
    typedef void   (*PFNVKGLDRAWARRAYSINSTANCEDPROC)      (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLint& in_first, const GLsizei& in_count, const GLsizei& in_instancecount);
    typedef void   (*PFNVKGLDRAWELEMENTSINSTANCEDPROC)    (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei& in_count, const GLenum& in_type, const void* in_indices_ptr, const GLsizei& in_instancecount);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMBLOCKNAMEPROC)(OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_block_index, const GLsizei& in_buf_size, GLsizei* in_length_ptr, GLchar* out_uniform_block_name);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMBLOCKIVPROC)  (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_block_index, const GLenum& in_pname, GLint* out_params_ptr);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMNAMEPROC)     (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_index, const GLsizei& in_buf_size, GLsizei* out_length_ptr, GLchar*  out_uniform_name_ptr);
    typedef void   (*PFNVKGLGETACTIVEUNIFORMSIVPROC)      (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_uniform_count, const GLuint* in_uniform_indices_ptr, const GLenum& in_pname, GLint* out_params_ptr);
    typedef GLuint (*PFNVKGLGETUNIFORMBLOCKINDEXPROC)     (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLchar* in_uniform_block_name_ptr);
    typedef void   (*PFNVKGLGETUNIFORMINDICESPROC)        (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLsizei& in_uniform_count, const GLchar* const* in_uniform_names_ptr_ptr, GLuint* out_uniform_indices_ptr);
    typedef void   (*PFNVKGLPRIMITIVERESTARTINDEXPROC)    (OpenGL::Context* in_context_ptr, const GLuint& in_index);
    typedef void   (*PFNVKGLTEXBUFFERPROC)                (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_internalformat, const GLuint& in_buffer);
    typedef void   (*PFNVKGLUNIFORMBLOCKBINDINGPROC)      (OpenGL::Context* in_context_ptr, const GLuint& in_program, const GLuint& in_uniform_block_index, const GLuint& in_uniform_block_binding);

    /* VKGL GL entrypoints : GL 3.2 */
    typedef GLenum    (*PFNVKGLCLIENTWAITSYNCPROC)                 (OpenGL::Context* in_context_ptr, const GLsync& in_sync, const GLbitfield& in_flags, const GLuint64& in_timeout);
    typedef void      (*PFNVKGLDELETESYNCPROC)                     (OpenGL::Context* in_context_ptr, const GLsync& in_sync);
    typedef void      (*PFNVKGLDRAWELEMENTSBASEVERTEXPROC)         (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei& in_count, const GLenum& in_type, const void* in_indices, const GLint& in_basevertex);
    typedef void      (*PFNVKGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC)(OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei& in_count, const GLenum& in_type, const void* in_indices, const GLsizei& in_instancecount, const GLint& in_basevertex);
    typedef void      (*PFNVKGLDRAWRANGEELEMENTSBASEVERTEXPROC)    (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLuint& in_start, const GLuint& in_end, const GLsizei& in_count, const GLenum& in_type, const void* in_indices, const GLint& in_basevertex);
    typedef GLsync    (*PFNVKGLFENCESYNCPROC)                      (OpenGL::Context* in_context_ptr, const GLenum& in_condition, const GLbitfield& in_flags);
    typedef void      (*PFNVKGLFRAMEBUFFERTEXTUREPROC)             (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_attachment, const GLuint& in_texture, const GLint& in_level);
    typedef void      (*PFNVKGLGETBUFFERPARAMETERI64VPROC)         (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLenum& in_pname, GLint64* in_params);
    typedef void      (*PFNVKGLGETINTEGER64I_VPROC)                (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLuint& in_index, GLint64* in_data);
    typedef void      (*PFNVKGLGETINTEGER64VPROC)                  (OpenGL::Context* in_context_ptr, const GLenum& in_pname, GLint64* in_data);
    typedef void      (*PFNVKGLGETMULTISAMPLEFVPROC)               (OpenGL::Context* in_context_ptr, const GLenum& in_pname, const GLuint& in_index, GLfloat* in_val);
    typedef void      (*PFNVKGLGETSYNCIVPROC)                      (OpenGL::Context* in_context_ptr, const GLsync& in_sync, const GLenum& in_pname, const GLsizei& in_bufSize, GLsizei* in_length, GLint* in_values);
    typedef GLboolean (*PFNVKGLISSYNCPROC)                         (OpenGL::Context* in_context_ptr, const GLsync& in_sync);
    typedef void      (*PFNVKGLMULTIDRAWELEMENTSBASEVERTEXPROC)    (OpenGL::Context* in_context_ptr, const GLenum& in_mode, const GLsizei* in_count, const GLenum& in_type, const void* const* in_indices, const GLsizei& in_drawcount, const GLint* in_basevertex);
    typedef void      (*PFNVKGLPROVOKINGVERTEXPROC)                (OpenGL::Context* in_context_ptr, const GLenum& in_mode);
    typedef void      (*PFNVKGLSAMPLEMASKIPROC)                    (OpenGL::Context* in_context_ptr, const GLuint& in_maskNumber, const GLbitfield& in_mask);
    typedef void      (*PFNVKGLTEXIMAGE2DMULTISAMPLEPROC)          (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLsizei& in_samples, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLboolean& in_fixedsamplelocations);
    typedef void      (*PFNVKGLTEXIMAGE3DMULTISAMPLEPROC)          (OpenGL::Context* in_context_ptr, const GLenum& in_target, const GLsizei& in_samples, const GLenum& in_internalformat, const GLsizei& in_width, const GLsizei& in_height, const GLsizei& in_depth, const GLboolean& in_fixedsamplelocations);
    typedef void      (*PFNVKGLWAITSYNCPROC)                       (OpenGL::Context* in_context_ptr, const GLsync& in_sync, const GLbitfield& in_flags, const GLuint64& in_timeout);

    typedef uint32_t TextureUnit;
}

#endif /* VKGL_TYPES_TYPEDEFS_H */