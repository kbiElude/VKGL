/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_STRUCTS_H
#define VKGL_TYPES_STRUCTS_H

#include "OpenGL/types_interfaces.h"

namespace OpenGL
{
    /* Forward declarations */
    struct VertexAttributeArrayState;

    typedef union UniformValue
    {
        int32_t  ivec4[4];
        uint32_t uvec4[4];
        float    vec4 [4];

        UniformValue();
    } UniformValue;

    typedef struct BufferState
    {
        OpenGL::BufferAccess              access;
        std::vector<OpenGL::BufferTarget> buffer_targets_used;
        void*                             map_pointer;
        uint64_t                          map_size;
        uint64_t                          map_start_offset;
        bool                              mapped;
        uint64_t                          size;
        OpenGL::BufferUsage               usage;

        BufferState();
    } BufferState;

    typedef std::pair<OpenGL::BufferTarget, uint32_t> IndexedBufferTarget;

    struct IndexedBufferTargetHashFunction
    {
        size_t operator() (const IndexedBufferTarget& in_key) const noexcept
        {
            return std::hash<OpenGL::BufferTarget>{}(in_key.first) ^
                   std::hash<uint32_t>            {}(in_key.second);
        }
    };

    typedef struct IndexedBufferBinding
    {
        OpenGL::GLBufferReferenceUniquePtr reference_ptr;
        size_t                             size;
        size_t                             start_offset;

        IndexedBufferBinding()
        {
            size         = SIZE_MAX;
            start_offset = SIZE_MAX;
        }

        IndexedBufferBinding(OpenGL::GLBufferReferenceUniquePtr in_reference_ptr,
                             const size_t&                      in_start_offset,
                             const size_t&                      in_size)
            :reference_ptr(std::move(in_reference_ptr) ),
             size         (in_size),
             start_offset (in_start_offset)
        {
            /* Stub */
        }

        IndexedBufferBinding           (const IndexedBufferBinding& in_binding);
        IndexedBufferBinding& operator=(const IndexedBufferBinding& in_binding);
    } IndexedBufferBinding;

    typedef struct RangedBufferBinding
    {
        GLuint   buffer_id;
        uint64_t size;
        uint64_t start_offset;

        RangedBufferBinding();
    } RangedBufferBinding;

    typedef struct SamplePosition
    {
        float x;
        float y;

        SamplePosition();
    } SamplePosition;

    typedef struct TransformFeedbackVaryingState
    {
        std::string  name;
        uint32_t     size;
        VariableType type;

        TransformFeedbackVaryingState();
    } TransformFeedbackVaryingState;

    /* Dispatch table - holds all function pointers as well as miscellaneous context-specific information.
     *
     * NOTE: The reason behind the additional indirection here is to support extensions such as no_error in the future.
     */
    struct DispatchTable
    {
        Context* bound_context_ptr;

        /* GL 1.0 */
        PFNVKGLBLENDFUNCPROC              pGLBlendFunc;
        PFNVKGLCLEARPROC                  pGLClear;
        PFNVKGLCLEARCOLORPROC             pGLClearColor;
        PFNVKGLCLEARDEPTHPROC             pGLClearDepth;
        PFNVKGLCLEARSTENCILPROC           pGLClearStencil;
        PFNVKGLCOLORMASKPROC              pGLColorMask;
        PFNVKGLCULLFACEPROC               pGLCullFace;
        PFNVKGLDEPTHFUNCPROC              pGLDepthFunc;
        PFNVKGLDEPTHMASKPROC              pGLDepthMask;
        PFNVKGLDEPTHRANGEPROC             pGLDepthRange;
        PFNVKGLDISABLEPROC                pGLDisable;
        PFNVKGLDRAWBUFFERPROC             pGLDrawBuffer;
        PFNVKGLENABLEPROC                 pGLEnable;
        PFNVKGLFINISHPROC                 pGLFinish;
        PFNVKGLFLUSHPROC                  pGLFlush;
        PFNVKGLFRONTFACEPROC              pGLFrontFace;
        PFNVKGLGETBOOLEANVPROC            pGLGetBooleanv;
        PFNVKGLGETDOUBLEVPROC             pGLGetDoublev;
        PFNVKGLGETERRORPROC               pGLGetError;
        PFNVKGLGETFLOATVPROC              pGLGetFloatv;
        PFNVKGLGETINTEGERVPROC            pGLGetIntegerv;
        PFNVKGLGETSTRINGPROC              pGLGetString;
        PFNVKGLGETTEXIMAGEPROC            pGLGetTexImage;
        PFNVKGLGETTEXLEVELPARAMETERFVPROC pGLGetTexLevelParameterfv;
        PFNVKGLGETTEXLEVELPARAMETERIVPROC pGLGetTexLevelParameteriv;
        PFNVKGLGETTEXPARAMETERFVPROC      pGLGetTexParameterfv;
        PFNVKGLGETTEXPARAMETERIVPROC      pGLGetTexParameteriv;
        PFNVKGLHINTPROC                   pGLHint;
        PFNVKGLISENABLEDPROC              pGLIsEnabled;
        PFNVKGLLINEWIDTHPROC              pGLLineWidth;
        PFNVKGLLOGICOPPROC                pGLLogicOp;
        PFNVKGLPIXELSTOREFPROC            pGLPixelStoref;
        PFNVKGLPIXELSTOREIPROC            pGLPixelStorei;
        PFNVKGLPOINTSIZEPROC              pGLPointSize;
        PFNVKGLPOLYGONMODEPROC            pGLPolygonMode;
        PFNVKGLREADBUFFERPROC             pGLReadBuffer;
        PFNVKGLREADPIXELSPROC             pGLReadPixels;
        PFNVKGLSCISSORPROC                pGLScissor;
        PFNVKGLSTENCILFUNCPROC            pGLStencilFunc;
        PFNVKGLSTENCILMASKPROC            pGLStencilMask;
        PFNVKGLSTENCILOPPROC              pGLStencilOp;
        PFNVKGLTEXIMAGE1DPROC             pGLTexImage1D;
        PFNVKGLTEXIMAGE2DPROC             pGLTexImage2D;
        PFNVKGLTEXPARAMETERFPROC          pGLTexParameterf;
        PFNVKGLTEXPARAMETERFVPROC         pGLTexParameterfv;
        PFNVKGLTEXPARAMETERIPROC          pGLTexParameteri;
        PFNVKGLTEXPARAMETERIVPROC         pGLTexParameteriv;
        PFNVKGLVIEWPORTPROC               pGLViewport;

        /* GL 1.1 */
        PFNVKGLBINDTEXTUREPROC       pGLBindTexture;
        PFNVKGLCOPYTEXIMAGE1DPROC    pGLCopyTexImage1D;
        PFNVKGLCOPYTEXIMAGE2DPROC    pGLCopyTexImage2D;
        PFNVKGLCOPYTEXSUBIMAGE1DPROC pGLCopyTexSubImage1D;
        PFNVKGLCOPYTEXSUBIMAGE2DPROC pGLCopyTexSubImage2D;
        PFNVKGLDELETETEXTURESPROC    pGLDeleteTextures;
        PFNVKGLDRAWARRAYSPROC        pGLDrawArrays;
        PFNVKGLDRAWELEMENTSPROC      pGLDrawElements;
        PFNVKGLGENTEXTURESPROC       pGLGenTextures;
        PFNVKGLISTEXTUREPROC         pGLIsTexture;
        PFNVKGLPOLYGONOFFSETPROC     pGLPolygonOffset;
        PFNVKGLTEXSUBIMAGE1DPROC     pGLTexSubImage1D;
        PFNVKGLTEXSUBIMAGE2DPROC     pGLTexSubImage2D;

        /* GL 1.2 */
        PFNVKGLCOPYTEXSUBIMAGE3DPROC pGLCopyTexSubImage3D;
        PFNVKGLDRAWRANGEELEMENTSPROC pGLDrawRangeElements;
        PFNVKGLTEXIMAGE3DPROC        pGLTexImage3D;
        PFNVKGLTEXSUBIMAGE3DPROC     pGLTexSubImage3D;

        /* GL 1.3 */
        PFNVKGLACTIVETEXTUREPROC           pGLActiveTexture;
        PFNVKGLCOMPRESSEDTEXIMAGE1DPROC    pGLCompressedTexImage1D;
        PFNVKGLCOMPRESSEDTEXIMAGE2DPROC    pGLCompressedTexImage2D;
        PFNVKGLCOMPRESSEDTEXIMAGE3DPROC    pGLCompressedTexImage3D;
        PFNVKGLCOMPRESSEDTEXSUBIMAGE1DPROC pGLCompressedTexSubImage1D;
        PFNVKGLCOMPRESSEDTEXSUBIMAGE2DPROC pGLCompressedTexSubImage2D;
        PFNVKGLCOMPRESSEDTEXSUBIMAGE3DPROC pGLCompressedTexSubImage3D;
        PFNVKGLGETCOMPRESSEDTEXIMAGEPROC   pGLGetCompressedTexImage;
        PFNVKGLSAMPLECOVERAGEPROC          pGLSampleCoverage;

        /* GL 1.4 */
        PFNVKGLBLENDCOLORPROC        pGLBlendColor;
        PFNVKGLBLENDEQUATIONPROC     pGLBlendEquation;
        PFNVKGLBLENDFUNCSEPARATEPROC pGLBlendFuncSeparate;
        PFNVKGLMULTIDRAWARRAYSPROC   pGLMultiDrawArrays;
        PFNVKGLMULTIDRAWELEMENTSPROC pGLMultiDrawElements;
        PFNVKGLPOINTPARAMETERFPROC   pGLPointParameterf;
        PFNVKGLPOINTPARAMETERFVPROC  pGLPointParameterfv;
        PFNVKGLPOINTPARAMETERIPROC   pGLPointParameteri;
        PFNVKGLPOINTPARAMETERIVPROC  pGLPointParameteriv;

        /* GL 1.5 */
        PFNVKGLBEGINQUERYPROC           pGLBeginQuery;
        PFNVKGLBINDBUFFERPROC           pGLBindBuffer;
        PFNVKGLBUFFERDATAPROC           pGLBufferData;
        PFNVKGLBUFFERSUBDATAPROC        pGLBufferSubData;
        PFNVKGLDELETEBUFFERSPROC        pGLDeleteBuffers;
        PFNVKGLDELETEQUERIESPROC        pGLDeleteQueries;
        PFNVKGLENDQUERYPROC             pGLEndQuery;
        PFNVKGLGENBUFFERSPROC           pGLGenBuffers;
        PFNVKGLGENQUERIESPROC           pGLGenQueries;
        PFNVKGLGETBUFFERPARAMETERIVPROC pGLGetBufferParameteriv;
        PFNVKGLGETBUFFERPOINTERVPROC    pGLGetBufferPointerv;
        PFNVKGLGETBUFFERSUBDATAPROC     pGLGetBufferSubData;
        PFNVKGLGETQUERYOBJECTIVPROC     pGLGetQueryObjectiv;
        PFNVKGLGETQUERYOBJECTUIVPROC    pGLGetQueryObjectuiv;
        PFNVKGLGETQUERYIVPROC           pGLGetQueryiv;
        PFNVKGLISBUFFERPROC             pGLIsBuffer;
        PFNVKGLISQUERYPROC              pGLIsQuery;
        PFNVKGLMAPBUFFERPROC            pGLMapBuffer;
        PFNVKGLUNMAPBUFFERPROC          pGLUnmapBuffer;

        /* GL 2.0 */
        PFNVKGLATTACHSHADERPROC             pGLAttachShader;
        PFNVKGLBINDATTRIBLOCATIONPROC       pGLBindAttribLocation;
        PFNVKGLBLENDEQUATIONSEPARATEPROC    pGLBlendEquationSeparate;
        PFNVKGLCOMPILESHADERPROC            pGLCompileShader;
        PFNVKGLCREATEPROGRAMPROC            pGLCreateProgram;
        PFNVKGLCREATESHADERPROC             pGLCreateShader;
        PFNVKGLDELETEPROGRAMPROC            pGLDeleteProgram;
        PFNVKGLDELETESHADERPROC             pGLDeleteShader;
        PFNVKGLDETACHSHADERPROC             pGLDetachShader;
        PFNVKGLDISABLEVERTEXATTRIBARRAYPROC pGLDisableVertexAttribArray;
        PFNVKGLDRAWBUFFERSPROC              pGLDrawBuffers;
        PFNVKGLENABLEVERTEXATTRIBARRAYPROC  pGLEnableVertexAttribArray;
        PFNVKGLGETACTIVEATTRIBPROC          pGLGetActiveAttrib;
        PFNVKGLGETACTIVEUNIFORMPROC         pGLGetActiveUniform;
        PFNVKGLGETATTACHEDSHADERSPROC       pGLGetAttachedShaders;
        PFNVKGLGETATTRIBLOCATIONPROC        pGLGetAttribLocation;
        PFNVKGLGETPROGRAMINFOLOGPROC        pGLGetProgramInfoLog;
        PFNVKGLGETPROGRAMIVPROC             pGLGetProgramiv;
        PFNVKGLGETSHADERINFOLOGPROC         pGLGetShaderInfoLog;
        PFNVKGLGETSHADERSOURCEPROC          pGLGetShaderSource;
        PFNVKGLGETSHADERIVPROC              pGLGetShaderiv;
        PFNVKGLGETUNIFORMLOCATIONPROC       pGLGetUniformLocation;
        PFNVKGLGETUNIFORMFVPROC             pGLGetUniformfv;
        PFNVKGLGETUNIFORMIVPROC             pGLGetUniformiv;
        PFNVKGLGETVERTEXATTRIBPOINTERVPROC  pGLGetVertexAttribPointerv;
        PFNVKGLGETVERTEXATTRIBDVPROC        pGLGetVertexAttribdv;
        PFNVKGLGETVERTEXATTRIBFVPROC        pGLGetVertexAttribfv;
        PFNVKGLGETVERTEXATTRIBIVPROC        pGLGetVertexAttribiv;
        PFNVKGLISPROGRAMPROC                pGLIsProgram;
        PFNVKGLISSHADERPROC                 pGLIsShader;
        PFNVKGLLINKPROGRAMPROC              pGLLinkProgram;
        PFNVKGLSHADERSOURCEPROC             pGLShaderSource;
        PFNVKGLSTENCILFUNCSEPARATEPROC      pGLStencilFuncSeparate;
        PFNVKGLSTENCILMASKSEPARATEPROC      pGLStencilMaskSeparate;
        PFNVKGLSTENCILOPSEPARATEPROC        pGLStencilOpSeparate;
        PFNVKGLUNIFORM1FPROC                pGLUniform1f;
        PFNVKGLUNIFORM1FVPROC               pGLUniform1fv;
        PFNVKGLUNIFORM1IPROC                pGLUniform1i;
        PFNVKGLUNIFORM1IVPROC               pGLUniform1iv;
        PFNVKGLUNIFORM2FPROC                pGLUniform2f;
        PFNVKGLUNIFORM2FVPROC               pGLUniform2fv;
        PFNVKGLUNIFORM2IPROC                pGLUniform2i;
        PFNVKGLUNIFORM2IVPROC               pGLUniform2iv;
        PFNVKGLUNIFORM3FPROC                pGLUniform3f;
        PFNVKGLUNIFORM3FVPROC               pGLUniform3fv;
        PFNVKGLUNIFORM3IPROC                pGLUniform3i;
        PFNVKGLUNIFORM3IVPROC               pGLUniform3iv;
        PFNVKGLUNIFORM4FPROC                pGLUniform4f;
        PFNVKGLUNIFORM4FVPROC               pGLUniform4fv;
        PFNVKGLUNIFORM4IPROC                pGLUniform4i;
        PFNVKGLUNIFORM4IVPROC               pGLUniform4iv;
        PFNVKGLUNIFORMMATRIX2FVPROC         pGLUniformMatrix2fv;
        PFNVKGLUNIFORMMATRIX3FVPROC         pGLUniformMatrix3fv;
        PFNVKGLUNIFORMMATRIX4FVPROC         pGLUniformMatrix4fv;
        PFNVKGLUSEPROGRAMPROC               pGLUseProgram;
        PFNVKGLVALIDATEPROGRAMPROC          pGLValidateProgram;
        PFNVKGLVERTEXATTRIB1DPROC           pGLVertexAttrib1d;
        PFNVKGLVERTEXATTRIB1DVPROC          pGLVertexAttrib1dv;
        PFNVKGLVERTEXATTRIB1FPROC           pGLVertexAttrib1f;
        PFNVKGLVERTEXATTRIB1FVPROC          pGLVertexAttrib1fv;
        PFNVKGLVERTEXATTRIB1SPROC           pGLVertexAttrib1s;
        PFNVKGLVERTEXATTRIB1SVPROC          pGLVertexAttrib1sv;
        PFNVKGLVERTEXATTRIB2DPROC           pGLVertexAttrib2d;
        PFNVKGLVERTEXATTRIB2DVPROC          pGLVertexAttrib2dv;
        PFNVKGLVERTEXATTRIB2FPROC           pGLVertexAttrib2f;
        PFNVKGLVERTEXATTRIB2FVPROC          pGLVertexAttrib2fv;
        PFNVKGLVERTEXATTRIB2SPROC           pGLVertexAttrib2s;
        PFNVKGLVERTEXATTRIB2SVPROC          pGLVertexAttrib2sv;
        PFNVKGLVERTEXATTRIB3DPROC           pGLVertexAttrib3d;
        PFNVKGLVERTEXATTRIB3DVPROC          pGLVertexAttrib3dv;
        PFNVKGLVERTEXATTRIB3FPROC           pGLVertexAttrib3f;
        PFNVKGLVERTEXATTRIB3FVPROC          pGLVertexAttrib3fv;
        PFNVKGLVERTEXATTRIB3SPROC           pGLVertexAttrib3s;
        PFNVKGLVERTEXATTRIB3SVPROC          pGLVertexAttrib3sv;
        PFNVKGLVERTEXATTRIB4BVPROC          pGLVertexAttrib4bv;
        PFNVKGLVERTEXATTRIB4DPROC           pGLVertexAttrib4d;
        PFNVKGLVERTEXATTRIB4DVPROC          pGLVertexAttrib4dv;
        PFNVKGLVERTEXATTRIB4FPROC           pGLVertexAttrib4f;
        PFNVKGLVERTEXATTRIB4FVPROC          pGLVertexAttrib4fv;
        PFNVKGLVERTEXATTRIB4IVPROC          pGLVertexAttrib4iv;
        PFNVKGLVERTEXATTRIB4NBVPROC         pGLVertexAttrib4Nbv;
        PFNVKGLVERTEXATTRIB4NIVPROC         pGLVertexAttrib4Niv;
        PFNVKGLVERTEXATTRIB4NSVPROC         pGLVertexAttrib4Nsv;
        PFNVKGLVERTEXATTRIB4NUBPROC         pGLVertexAttrib4Nub;
        PFNVKGLVERTEXATTRIB4NUBVPROC        pGLVertexAttrib4Nubv;
        PFNVKGLVERTEXATTRIB4NUIVPROC        pGLVertexAttrib4Nuiv;
        PFNVKGLVERTEXATTRIB4NUSVPROC        pGLVertexAttrib4Nusv;
        PFNVKGLVERTEXATTRIB4SPROC           pGLVertexAttrib4s;
        PFNVKGLVERTEXATTRIB4SVPROC          pGLVertexAttrib4sv;
        PFNVKGLVERTEXATTRIB4UBVPROC         pGLVertexAttrib4ubv;
        PFNVKGLVERTEXATTRIB4UIVPROC         pGLVertexAttrib4uiv;
        PFNVKGLVERTEXATTRIB4USVPROC         pGLVertexAttrib4usv;
        PFNVKGLVERTEXATTRIBPOINTERPROC      pGLVertexAttribPointer;

        /* GL 2.1 */
        PFNVKGLUNIFORMMATRIX2X3FVPROC pGLUniformMatrix2x3fv;
        PFNVKGLUNIFORMMATRIX2X4FVPROC pGLUniformMatrix2x4fv;
        PFNVKGLUNIFORMMATRIX3X2FVPROC pGLUniformMatrix3x2fv;
        PFNVKGLUNIFORMMATRIX3X4FVPROC pGLUniformMatrix3x4fv;
        PFNVKGLUNIFORMMATRIX4X2FVPROC pGLUniformMatrix4x2fv;
        PFNVKGLUNIFORMMATRIX4X3FVPROC pGLUniformMatrix4x3fv;

        /* GL 3.0 */
        PFNVKGLBEGINCONDITIONALRENDERPROC              pGLBeginConditionalRender;
        PFNVKGLBEGINTRANSFORMFEEDBACKPROC              pGLBeginTransformFeedback;
        PFNVKGLBINDBUFFERBASEPROC                      pGLBindBufferBase;
        PFNVKGLBINDBUFFERRANGEPROC                     pGLBindBufferRange;
        PFNVKGLBINDFRAGDATALOCATIONPROC                pGLBindFragDataLocation;
        PFNVKGLBINDFRAMEBUFFERPROC                     pGLBindFramebuffer;
        PFNVKGLBINDRENDERBUFFERPROC                    pGLBindRenderbuffer;
        PFNVKGLBINDVERTEXARRAYPROC                     pGLBindVertexArray;
        PFNVKGLBLITFRAMEBUFFERPROC                     pGLBlitFramebuffer;
        PFNVKGLCHECKFRAMEBUFFERSTATUSPROC              pGLCheckFramebufferStatus;
        PFNVKGLCLAMPCOLORPROC                          pGLClampColor;
        PFNVKGLCLEARBUFFERFIPROC                       pGLClearBufferfi;
        PFNVKGLCLEARBUFFERFVPROC                       pGLClearBufferfv;
        PFNVKGLCLEARBUFFERIVPROC                       pGLClearBufferiv;
        PFNVKGLCLEARBUFFERUIVPROC                      pGLClearBufferuiv;
        PFNVKGLCOLORMASKIPROC                          pGLColorMaski;
        PFNVKGLDELETEFRAMEBUFFERSPROC                  pGLDeleteFramebuffers;
        PFNVKGLDELETERENDERBUFFERSPROC                 pGLDeleteRenderbuffers;
        PFNVKGLDELETEVERTEXARRAYSPROC                  pGLDeleteVertexArrays;
        PFNVKGLDISABLEIPROC                            pGLDisablei;
        PFNVKGLENABLEIPROC                             pGLEnablei;
        PFNVKGLENDCONDITIONALRENDERPROC                pGLEndConditionalRender;
        PFNVKGLENDTRANSFORMFEEDBACKPROC                pGLEndTransformFeedback;
        PFNVKGLFLUSHMAPPEDBUFFERRANGEPROC              pGLFlushMappedBufferRange;
        PFNVKGLFRAMEBUFFERRENDERBUFFERPROC             pGLFramebufferRenderbuffer;
        PFNVKGLFRAMEBUFFERTEXTURE1DPROC                pGLFramebufferTexture1D;
        PFNVKGLFRAMEBUFFERTEXTURE2DPROC                pGLFramebufferTexture2D;
        PFNVKGLFRAMEBUFFERTEXTURE3DPROC                pGLFramebufferTexture3D;
        PFNVKGLFRAMEBUFFERTEXTURELAYERPROC             pGLFramebufferTextureLayer;
        PFNVKGLGENFRAMEBUFFERSPROC                     pGLGenFramebuffers;
        PFNVKGLGENRENDERBUFFERSPROC                    pGLGenRenderbuffers;
        PFNVKGLGENVERTEXARRAYSPROC                     pGLGenVertexArrays;
        PFNVKGLGENERATEMIPMAPPROC                      pGLGenerateMipmap;
        PFNVKGLGETBOOLEANI_VPROC                       pGLGetBooleani_v;
        PFNVKGLGETFRAGDATALOCATIONPROC                 pGLGetFragDataLocation;
        PFNVKGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC pGLGetFramebufferAttachmentParameteriv;
        PFNVKGLGETINTEGERI_VPROC                       pGLGetIntegeri_v;
        PFNVKGLGETRENDERBUFFERPARAMETERIVPROC          pGLGetRenderbufferParameteriv;
        PFNVKGLGETSTRINGIPROC                          pGLGetStringi;
        PFNVKGLGETTEXPARAMETERIIVPROC                  pGLGetTexParameterIiv;
        PFNVKGLGETTEXPARAMETERIUIVPROC                 pGLGetTexParameterIuiv;
        PFNVKGLGETTRANSFORMFEEDBACKVARYINGPROC         pGLGetTransformFeedbackVarying;
        PFNVKGLGETUNIFORMUIVPROC                       pGLGetUniformuiv;
        PFNVKGLGETVERTEXATTRIBIIVPROC                  pGLGetVertexAttribIiv;
        PFNVKGLGETVERTEXATTRIBIUIVPROC                 pGLGetVertexAttribIuiv;
        PFNVKGLISENABLEDIPROC                          pGLIsEnabledi;
        PFNVKGLISFRAMEBUFFERPROC                       pGLIsFramebuffer;
        PFNVKGLISRENDERBUFFERPROC                      pGLIsRenderbuffer;
        PFNVKGLISVERTEXARRAYPROC                       pGLIsVertexArray;
        PFNVKGLMAPBUFFERRANGEPROC                      pGLMapBufferRange;
        PFNVKGLRENDERBUFFERSTORAGEPROC                 pGLRenderbufferStorage;
        PFNVKGLRENDERBUFFERSTORAGEMULTISAMPLEPROC      pGLRenderbufferStorageMultisample;
        PFNVKGLTEXPARAMETERIIVPROC                     pGLTexParameterIiv;
        PFNVKGLTEXPARAMETERIUIVPROC                    pGLTexParameterIuiv;
        PFNVKGLTRANSFORMFEEDBACKVARYINGSPROC           pGLTransformFeedbackVaryings;
        PFNVKGLUNIFORM1UIPROC                          pGLUniform1ui;
        PFNVKGLUNIFORM1UIVPROC                         pGLUniform1uiv;
        PFNVKGLUNIFORM2UIPROC                          pGLUniform2ui;
        PFNVKGLUNIFORM2UIVPROC                         pGLUniform2uiv;
        PFNVKGLUNIFORM3UIPROC                          pGLUniform3ui;
        PFNVKGLUNIFORM3UIVPROC                         pGLUniform3uiv;
        PFNVKGLUNIFORM4UIPROC                          pGLUniform4ui;
        PFNVKGLUNIFORM4UIVPROC                         pGLUniform4uiv;
        PFNVKGLVERTEXATTRIBI1IPROC                     pGLVertexAttribI1i;
        PFNVKGLVERTEXATTRIBI1IVPROC                    pGLVertexAttribI1iv;
        PFNVKGLVERTEXATTRIBI1UIPROC                    pGLVertexAttribI1ui;
        PFNVKGLVERTEXATTRIBI1UIVPROC                   pGLVertexAttribI1uiv;
        PFNVKGLVERTEXATTRIBI2IPROC                     pGLVertexAttribI2i;
        PFNVKGLVERTEXATTRIBI2IVPROC                    pGLVertexAttribI2iv;
        PFNVKGLVERTEXATTRIBI2UIPROC                    pGLVertexAttribI2ui;
        PFNVKGLVERTEXATTRIBI2UIVPROC                   pGLVertexAttribI2uiv;
        PFNVKGLVERTEXATTRIBI3IPROC                     pGLVertexAttribI3i;
        PFNVKGLVERTEXATTRIBI3IVPROC                    pGLVertexAttribI3iv;
        PFNVKGLVERTEXATTRIBI3UIPROC                    pGLVertexAttribI3ui;
        PFNVKGLVERTEXATTRIBI3UIVPROC                   pGLVertexAttribI3uiv;
        PFNVKGLVERTEXATTRIBI4BVPROC                    pGLVertexAttribI4bv;
        PFNVKGLVERTEXATTRIBI4IPROC                     pGLVertexAttribI4i;
        PFNVKGLVERTEXATTRIBI4IVPROC                    pGLVertexAttribI4iv;
        PFNVKGLVERTEXATTRIBI4SVPROC                    pGLVertexAttribI4sv;
        PFNVKGLVERTEXATTRIBI4UBVPROC                   pGLVertexAttribI4ubv;
        PFNVKGLVERTEXATTRIBI4UIPROC                    pGLVertexAttribI4ui;
        PFNVKGLVERTEXATTRIBI4UIVPROC                   pGLVertexAttribI4uiv;
        PFNVKGLVERTEXATTRIBI4USVPROC                   pGLVertexAttribI4usv;
        PFNVKGLVERTEXATTRIBIPOINTERPROC                pGLVertexAttribIPointer;

        /* GL 3.1 */
        PFNVKGLCOPYBUFFERSUBDATAPROC         pGLCopyBufferSubData;
        PFNVKGLDRAWARRAYSINSTANCEDPROC       pGLDrawArraysInstanced;
        PFNVKGLDRAWELEMENTSINSTANCEDPROC     pGLDrawElementsInstanced;
        PFNVKGLGETACTIVEUNIFORMBLOCKNAMEPROC pGLGetActiveUniformBlockName;
        PFNVKGLGETACTIVEUNIFORMBLOCKIVPROC   pGLGetActiveUniformBlockiv;
        PFNVKGLGETACTIVEUNIFORMNAMEPROC      pGLGetActiveUniformName;
        PFNVKGLGETACTIVEUNIFORMSIVPROC       pGLGetActiveUniformsiv;
        PFNVKGLGETUNIFORMBLOCKINDEXPROC      pGLGetUniformBlockIndex;
        PFNVKGLGETUNIFORMINDICESPROC         pGLGetUniformIndices;
        PFNVKGLPRIMITIVERESTARTINDEXPROC     pGLPrimitiveRestartIndex;
        PFNVKGLTEXBUFFERPROC                 pGLTexBuffer;
        PFNVKGLUNIFORMBLOCKBINDINGPROC       pGLUniformBlockBinding;

        /* GL 3.2 */
        PFNVKGLCLIENTWAITSYNCPROC                  pGLClientWaitSync;
        PFNVKGLDELETESYNCPROC                      pGLDeleteSync;
        PFNVKGLDRAWELEMENTSBASEVERTEXPROC          pGLDrawElementsBaseVertex;
        PFNVKGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC pGLDrawElementsInstancedBaseVertex;
        PFNVKGLDRAWRANGEELEMENTSBASEVERTEXPROC     pGLDrawRangeElementsBaseVertex;
        PFNVKGLFENCESYNCPROC                       pGLFenceSync;
        PFNVKGLFRAMEBUFFERTEXTUREPROC              pGLFramebufferTexture;
        PFNVKGLGETBUFFERPARAMETERI64VPROC          pGLGetBufferParameteri64v;
        PFNVKGLGETINTEGER64I_VPROC                 pGLGetInteger64i_v;
        PFNVKGLGETINTEGER64VPROC                   pGLGetInteger64v;
        PFNVKGLGETMULTISAMPLEFVPROC                pGLGetMultisamplefv;
        PFNVKGLGETSYNCIVPROC                       pGLGetSynciv;
        PFNVKGLISSYNCPROC                          pGLIsSync;
        PFNVKGLMULTIDRAWELEMENTSBASEVERTEXPROC     pGLMultiDrawElementsBaseVertex;
        PFNVKGLPROVOKINGVERTEXPROC                 pGLProvokingVertex;
        PFNVKGLSAMPLEMASKIPROC                     pGLSampleMaski;
        PFNVKGLTEXIMAGE2DMULTISAMPLEPROC           pGLTexImage2DMultisample;
        PFNVKGLTEXIMAGE3DMULTISAMPLEPROC           pGLTexImage3DMultisample;
        PFNVKGLWAITSYNCPROC                        pGLWaitSync;

        DispatchTable();
    };

    typedef struct FramebufferAttachmentPointState
    {
        FramebufferAttachmentComponentType component_type;
        bool                               layered;
        uint32_t                           size_alpha;
        uint32_t                           size_blue;
        uint32_t                           size_depth;
        uint32_t                           size_green;
        uint32_t                           size_red;
        uint32_t                           size_stencil;
        TextureCubeMapFace                 texture_cube_map_face;
        uint32_t                           texture_layer;
        uint32_t                           texture_level;
        FramebufferAttachmentObjectType    type;
        bool                               uses_srgb_color_encoding;

        OpenGL::GLRenderbufferReferenceUniquePtr renderbuffer_reference_ptr;
        OpenGL::GLTextureReferenceUniquePtr      texture_reference_ptr;

        FramebufferAttachmentPointState           ();
        FramebufferAttachmentPointState           (const FramebufferAttachmentPointState&);
        FramebufferAttachmentPointState& operator=(const FramebufferAttachmentPointState&);

    } FramebufferAttachmentPointState;

    typedef struct FramebufferState
    {
        std::vector<OpenGL::DrawBuffer> draw_buffer_per_color_output;
        OpenGL::ReadBuffer              read_buffer;

        std::vector<FramebufferAttachmentPointState> color_attachments;
        FramebufferAttachmentPointState              depth_attachment;
        FramebufferAttachmentPointState              stencil_attachment;

        bool                        is_doublebuffer;
        bool                        is_stereo;
        uint32_t                    n_sample_buffers;
        uint32_t                    n_samples;
        std::vector<SamplePosition> sample_position;

        FramebufferState           ();
        explicit FramebufferState  (const uint32_t& in_n_color_attachments);

        FramebufferState& operator=(const FramebufferState& in_state);
    } FramebufferState;

    typedef struct RenderbufferState
    {
        uint32_t               height;
        OpenGL::InternalFormat internal_format;
        uint32_t               samples;
        uint32_t               size_alpha;
        uint32_t               size_blue;
        uint32_t               size_depth;
        uint32_t               size_green;
        uint32_t               size_red;
        uint32_t               size_stencil;
        uint32_t               width;

        RenderbufferState();
    } RenderbufferState;

    typedef struct ShaderState
    {
        bool               compile_status;
        bool               delete_status;
        std::string        info_log;
        std::string        source_code;
        OpenGL::ShaderType type;

        ShaderState();
    } ShaderState;

    typedef struct TextureMipState
    {
        uint32_t               binding_texture_buffer_data_store;
        uint32_t               compressed_image_size;
        bool                   fixed_sample_locations;
        uint32_t               depth;
        uint32_t               height;
        OpenGL::InternalFormat internal_format;
        uint32_t               samples;
        uint32_t               width;

        explicit TextureMipState(const OpenGL::InternalFormat& in_internal_format,
                                 const uint32_t&               in_width,
                                 const uint32_t&               in_height,
                                 const uint32_t&               in_depth,
                                 const uint32_t&               in_samples,
                                 const bool&                   in_fixed_sample_locations);
    } TextureMipState;

    typedef std::unique_ptr<TextureMipState> TextureMipStateUniquePtr;

    typedef struct TextureState
    {
        int32_t                         base_level;
        uint32_t                        border_color[4];
        OpenGL::TextureCompareFunction  compare_function;
        OpenGL::TextureCompareMode      compare_mode;
        OpenGL::DepthStencilTextureMode depth_stencil_texture_mode;
        float                           lod_bias;
        OpenGL::TextureMagFilter        mag_filter;
        int32_t                         max_level;
        float                           max_lod;
        OpenGL::TextureMinFilter        min_filter;
        float                           min_lod;
        OpenGL::TextureSwizzle          swizzle_a;
        OpenGL::TextureSwizzle          swizzle_b;
        OpenGL::TextureSwizzle          swizzle_g;
        OpenGL::TextureSwizzle          swizzle_r;
        OpenGL::TextureWrapMode         wrap_r;
        OpenGL::TextureWrapMode         wrap_s;
        OpenGL::TextureWrapMode         wrap_t;

        explicit TextureState(const OpenGL::TextureMinFilter& in_min_filter,
                              const OpenGL::TextureWrapMode&  in_wrap_s,
                              const OpenGL::TextureWrapMode&  in_wrap_t,
                              const OpenGL::TextureWrapMode&  in_wrap_r);
    } TextureState;

    typedef std::unique_ptr<TextureState> TextureStateUniquePtr;

    typedef struct TextureUnitState
    {
        GLuint binding_1d;
        GLuint binding_1d_array;
        GLuint binding_2d;
        GLuint binding_2d_array;
        GLuint binding_2d_multisample;
        GLuint binding_2d_multisample_array;
        GLuint binding_3d;
        GLuint binding_cube_map;
        GLuint binding_rectangle;
        GLuint binding_texture_buffer;

        TextureUnitState();
    } TextureUnitState;

    typedef std::unique_ptr<TextureUnitState> TextureUnitStateUniquePtr;

    typedef struct VertexArrayObjectState
    {
        GLBufferReferenceUniquePtr             element_array_buffer_binding_ptr;
        std::vector<VertexAttributeArrayState> vertex_attribute_arrays;

        VertexArrayObjectState(const uint32_t&               in_n_vertex_attribute_arrays);
        VertexArrayObjectState(const VertexArrayObjectState& in_vaa);

        VertexArrayObjectState& operator=(const VertexArrayObjectState&);
    } VertexArrayObjectState;

    typedef struct VertexAttributeArrayState
    {
        GLBufferReferenceUniquePtr buffer_binding_ptr;
        bool                       enabled;
        bool                       integer;
        bool                       normalized;
        const void*                pointer;
        uint64_t                   size;
        uint64_t                   stride;
        VertexAttributeArrayType   type;

        VertexAttributeArrayState();
        VertexAttributeArrayState(const VertexAttributeArrayState& in_vaa_state);

        VertexAttributeArrayState& operator= (const VertexAttributeArrayState&);
        bool                       operator==(const VertexAttributeArrayState& in_state);
    } VertexAttributeArrayState;


    /* Rendering context state */
    typedef struct GLContextStateBindingReferences
    {
        // todo: OpenGL::GLFramebufferReferenceUniquePtr  draw_framebuffer_reference_ptr;
        // todo: OpenGL::GLFramebufferReferenceUniquePtr  read_framebuffer_reference_ptr;
        // todo: OpenGL::GLRenderbufferReferenceUniquePtr renderbuffer_reference_ptr;

        // todo std::unordered_map<IndexedBufferTarget,  IndexedBufferBinding, IndexedBufferTargetHashFunction> indexed_buffer_binding_ptrs;
        // todo std::unordered_map<OpenGL::BufferTarget, OpenGL::GLBufferReferenceUniquePtr>                    nonindexed_buffer_binding_ptrs;
        OpenGL::GLProgramReferenceUniquePtr program_reference_ptr;
        OpenGL::GLVAOReferenceUniquePtr     vao_reference_ptr;

        GLContextStateBindingReferences(OpenGL::GLProgramReferenceUniquePtr in_program_reference_ptr,
                                        OpenGL::GLVAOReferenceUniquePtr     in_vao_reference_ptr)
            :program_reference_ptr(std::move(in_program_reference_ptr) ),
             vao_reference_ptr    (std::move(in_vao_reference_ptr)     )
        {
            /* Stub */
        }
    } GLContextStateBindingReferences;

    typedef std::unique_ptr<GLContextStateBindingReferences, std::function<void(GLContextStateBindingReferences*)> > GLContextStateBindingReferencesUniquePtr;

    typedef struct ContextState
    {
        bool    is_primitive_restart_enabled;
        int32_t primitive_restart_index;

        bool              is_depth_clamp_enabled;
        double            depth_range[2];
        std::vector<bool> user_clip_planes_enabled;
        int32_t           viewport   [4];

        OpenGL::ClampReadColorMode        clamp_read_color;
        OpenGL::ProvokingVertexConvention provoking_vertex;

        bool                           is_line_smooth_enabled;
        float                          line_width;
        float                          point_fade_threshold_size;
        float                          point_size;
        OpenGL::PointSpriteCoordOrigin point_sprite_coord_origin;

        OpenGL::CullMode             cull_face_mode;
        OpenGL::FrontFaceOrientation front_face;
        bool                         is_cull_face_enabled;
        bool                         is_polygon_offset_fill_enabled;
        bool                         is_polygon_offset_line_enabled;
        bool                         is_polygon_offset_point_enabled;
        bool                         is_polygon_smooth_enabled;
        float                        polygon_offset_factor;
        float                        polygon_offset_units;

        bool     is_multisample_enabled;
        bool     is_sample_alpha_to_coverage_enabled;
        bool     is_sample_alpha_to_one_enabled;
        bool     is_sample_coverage_enabled;
        bool     is_sample_coverage_invert_enabled;
        bool     is_sample_mask_enabled;
        float    sample_coverage_value;
        uint32_t sample_mask;

        uint32_t                      active_texture_unit;
        std::vector<TextureUnitState> texture_image_units;

        bool                     is_scissor_test_enabled;
        bool                     is_stencil_test_enabled;
        int32_t                  scissor_box[4];
        OpenGL::StencilFunction  stencil_function_back;
        OpenGL::StencilFunction  stencil_function_front;
        OpenGL::StencilOperation stencil_op_fail_back;
        OpenGL::StencilOperation stencil_op_fail_front;
        OpenGL::StencilOperation stencil_op_pass_depth_fail_back;
        OpenGL::StencilOperation stencil_op_pass_depth_fail_front;
        OpenGL::StencilOperation stencil_op_pass_depth_pass_back;
        OpenGL::StencilOperation stencil_op_pass_depth_pass_front;
        int32_t                  stencil_reference_value_back;
        int32_t                  stencil_reference_value_front;
        int32_t                  stencil_value_mask_back;
        int32_t                  stencil_value_mask_front;

        float                 blend_color[4];
        OpenGL::BlendEquation blend_equation_alpha;
        OpenGL::BlendEquation blend_equation_rgb;
        OpenGL::BlendFunction blend_func_dst_alpha;
        OpenGL::BlendFunction blend_func_dst_rgb;
        OpenGL::BlendFunction blend_func_src_alpha;
        OpenGL::BlendFunction blend_func_src_rgb;
        OpenGL::DepthFunction depth_function;
        bool                  is_blend_enabled;
        bool                  is_color_logic_op_enabled;
        bool                  is_depth_test_enabled;
        bool                  is_dither_enabled;
        bool                  is_framebuffer_srgb_enabled;
        OpenGL::LogicOpMode   logic_op_mode;

        float    color_clear_value[4];
        uint32_t color_writemask_for_draw_buffers; /* 4-bits per each draw buffer. */
        double   depth_clear_value;
        bool     depth_writemask;
        uint32_t stencil_clear_value;
        uint32_t stencil_writemask_back;
        uint32_t stencil_writemask_front;

        OpenGL::GLFramebufferReferenceUniquePtr  draw_framebuffer_proxy_reference_ptr;
        OpenGL::GLFramebufferReferenceUniquePtr  read_framebuffer_proxy_reference_ptr;
        OpenGL::GLRenderbufferReferenceUniquePtr renderbuffer_proxy_reference_ptr;

        uint32_t pack_alignment;
        uint32_t pack_image_height;
        bool     pack_lsb_first;
        uint32_t pack_row_length;
        uint32_t pack_skip_images;
        uint32_t pack_skip_pixels;
        uint32_t pack_skip_rows;
        bool     pack_swap_bytes;
        uint32_t unpack_alignment;
        uint32_t unpack_image_height;
        bool     unpack_lsb_first;
        uint32_t unpack_row_length;
        uint32_t unpack_skip_images;
        uint32_t unpack_skip_pixels;
        uint32_t unpack_skip_rows;
        bool     unpack_swap_bytes;

        std::unordered_map<IndexedBufferTarget,  IndexedBufferBinding, IndexedBufferTargetHashFunction> indexed_buffer_proxy_binding_ptrs;
        std::unordered_map<OpenGL::BufferTarget, OpenGL::GLBufferReferenceUniquePtr>                    nonindexed_buffer_proxy_binding_ptrs;
        OpenGL::GLProgramReferenceUniquePtr                                                             program_proxy_reference_ptr;
        std::unordered_map<TextureUnit, OpenGL::TextureUnitStateUniquePtr>                              texture_unit_to_state_ptr_map;
        OpenGL::GLVAOReferenceUniquePtr                                                                 vao_proxy_reference_ptr;

        OpenGL::HintMode hint_fragment_shader_derivative;
        OpenGL::HintMode hint_line_smooth;
        OpenGL::HintMode hint_polygon_smooth;
        OpenGL::HintMode hint_texture_compression;

        bool     is_texture_cube_map_seamless_enabled;

        GLuint active_any_samples_passed_query_id;
        GLuint active_primitives_generated_query_id;
        GLuint active_samples_passed_query_id;
        GLuint active_time_elapsed_query_id;
        GLuint active_timestamp_query_id;
        GLuint active_transform_feedback_primitives_written_query_id;

        bool        is_program_point_size_enabled;
        PolygonMode polygon_mode;

        explicit ContextState(IContextObjectManagers* in_frontend_object_managers_ptr,
                              const IGLLimits*        in_limits_ptr,
                              const int32_t*          in_viewport_ivec4_ptr,
                              const int32_t*          in_scissor_box_ivec4_ptr);

        ContextState           (const ContextState&           in_context_state,
                                const bool&                   in_convert_from_proxy_to_nonproxy,
                                const IContextObjectManagers* in_frontend_object_managers_ptr);
        ContextState& operator=(const ContextState&           in_context_state);

        ~ContextState();
    } ContextState;

    typedef std::unique_ptr<ContextState> ContextStateUniquePtr;

    typedef std::unordered_map<std::string, uint32_t> AttributeLocationBindingMap;
    typedef std::unordered_map<std::string, uint32_t> FragDataLocationMap;

    typedef struct ActiveAttributeProperties
    {
        int32_t      location;
        std::string  name;
        uint32_t     size; /* in units of attribute's type */
        VariableType type;

        ActiveAttributeProperties()
           :location(-1),
            size    (0),
            type    (VariableType::Unknown)
        {
            /* Stub */
        }

        ActiveAttributeProperties(const std::string&  in_name,
                                  const int32_t&      in_location,
                                  const uint32_t&     in_size,
                                  const VariableType& in_type)
            :location(in_location),
             name    (in_name),
             size    (in_size),
             type    (in_type)
        {
            /* Stub */
        }
    } ActiveAttributeProperties;

    typedef struct ActiveUniformProperties
    {
        int32_t      array_stride;  /* 0 for non array uniforms,                     -1 for default UB uniforms */
        int32_t      index;
        uint32_t     is_row_major;  /* 1 = true,                                      0 otherwise */
        int32_t      location;
        int32_t      matrix_stride; /* 0 for non matrix uniforms in non-default UBs, -1 for default UB uniforms */
        std::string  name;
        int32_t      offset;
        uint32_t     size; /* in units of attribute's type OR n of array items for arrayed uniforms */
        VariableType type;
        int32_t      uniform_block_index;

        ActiveUniformProperties()
           :array_stride       (-1),
            index              (GL_INVALID_INDEX),
            is_row_major       (UINT32_MAX),
            location           (-1),
            matrix_stride      (-1),
            offset             (-1),
            size               (0),
            type               (VariableType::Unknown),
            uniform_block_index(-1)
        {
            /* Stub */
        }

        ActiveUniformProperties(const std::string&  in_name,
                                const uint32_t&     in_size,
                                const VariableType& in_type,
                                const int32_t&      in_uniform_block_index,
                                const int32_t&      in_offset, /* -1 for default UBs */
                                const int32_t&      in_array_stride,
                                const int32_t&      in_matrix_stride,
                                const bool&         in_is_row_major,
                                const int32_t&      in_location,
                                const int32_t&      in_index)
            :array_stride       (in_array_stride),
             index              (in_index),
             is_row_major       ( (in_is_row_major) ? 1 : 0),
             location           (in_location),
             matrix_stride      (in_matrix_stride),
             name               (in_name),
             offset             (in_offset),
             size               (in_size),
             type               (in_type),
             uniform_block_index(in_uniform_block_index)
        {
            /* Stub */
        }
    } ActiveUniformProperties;

    typedef struct ActiveUniformBlock
    {
        std::vector<ActiveUniformProperties> active_uniforms;
        uint32_t                             binding_point;
        uint32_t                             data_size;
        int32_t                              index;
        std::string                          name;
        bool                                 referenced_by_fs;
        bool                                 referenced_by_gs;
        bool                                 referenced_by_vs;

        ActiveUniformBlock()
            :binding_point   (0),
             data_size       (0),
             index           (GL_INVALID_INDEX),
             referenced_by_fs(false),
             referenced_by_gs(false),
             referenced_by_vs(false)
        {
            /* Stub */
        }

        ActiveUniformBlock(const int32_t&     in_index,
                           const std::string& in_name)
            :binding_point   (0),
             data_size       (0),
             index           (in_index),
             name            (in_name),
             referenced_by_fs(false),
             referenced_by_gs(false),
             referenced_by_vs(false)
        {
            /* Stub */
        }
    } ActiveUniformBlock;

    typedef std::pair<int32_t, uint32_t> UniformBlockAndUniformIndexPair;

    typedef struct PostLinkData
    {
        std::unordered_map<std::string, uint32_t>                       active_attribute_name_to_location_map;
        std::vector<ActiveAttributeProperties>                          active_attributes;
        std::unordered_map<std::string, const ActiveUniformBlock*>      active_uniform_block_by_name_map;
        std::vector<ActiveUniformBlock>                                 active_uniform_blocks;
        std::unordered_map<std::string, const ActiveUniformProperties*> active_uniform_by_name_map;
        std::vector<ActiveUniformProperties>                            active_uniforms;
        FragDataLocationMap                                             frag_data_locations;
        std::unordered_map<uint32_t, UniformBlockAndUniformIndexPair>   index_to_ub_and_uniform_index_pair;
        std::string                                                     link_log;

        uint32_t active_attribute_max_length;
        uint32_t active_uniform_block_max_name_length;
        uint32_t active_uniform_max_length;
        int32_t  max_active_attribute_location; //< INT32_MAX => no active attributes.

        OpenGL::GeometryInputType  gs_input_type;
        OpenGL::GeometryOutputType gs_output_type;
        uint32_t                   n_max_gs_vertices_generated;

        PostLinkData();
        PostLinkData(const PostLinkData& in_data);

        PostLinkData& operator=(const PostLinkData& in_data);

    private:
        void init_ptr_valued_maps();
    } PostLinkData;

    typedef std::unique_ptr<PostLinkData> PostLinkDataUniquePtr;
};

#endif /* VKGL_TYPES_STRUCTS_H */