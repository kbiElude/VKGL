/* VKGL (c) 2018 Dominik Witczak
 *
 * This code is licensed under MIT license (see LICENSE.txt for details)
 */
#ifndef VKGL_TYPES_STRUCTS_H
#define VKGL_TYPES_STRUCTS_H

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

    typedef struct ActiveAttributeState
    {
        std::string  name;
        uint32_t     size;
        VariableType type;

        ActiveAttributeState();
    } ActiveAttributeState;

    typedef struct ActiveUniformBlock
    {
        std::vector<uint32_t> active_uniform_indices;
        uint32_t              binding;
        uint32_t              data_size;
        bool                  referenced_by_fragment_shader;
        bool                  referenced_by_geometry_shader;
        bool                  referenced_by_vertex_shader;

        ActiveUniformBlock();
    } ActiveUniformBlock;

    typedef struct ActiveUniformState
    {
        bool         is_row_major;
        uint32_t     location;
        std::string  name;
        uint32_t     size;
        VariableType type;
        uint32_t     uniform_array_stride;
        uint32_t     uniform_block_index;
        uint32_t     uniform_block_offset;
        uint32_t     uniform_matrix_stride;
        UniformValue value;

        ActiveUniformState();
    } ActiveUniformState;

    typedef struct BufferState
    {
        OpenGL::BufferAccess access;
        uint64_t             map_size;
        uint64_t             map_start_offset;
        bool                 mapped;
        uint64_t             size;
        OpenGL::BufferUsage  usage;

        BufferState();
    } BufferState;

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
        GLuint                             name;
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


        FramebufferAttachmentPointState();
    } FramebufferAttachmentPointState;

    typedef struct FramebufferState
    {
        std::vector<uint32_t> draw_buffer_per_color_output;
        uint32_t              read_buffer;

        std::vector<FramebufferAttachmentPointState> color_attachments;
        FramebufferAttachmentPointState              depth_attachment;
        FramebufferAttachmentPointState              stencil_attachment;

        bool                        is_doublebuffer;
        bool                        is_stereo;
        uint32_t                    n_sample_buffers;
        uint32_t                    n_samples;
        std::vector<SamplePosition> sample_position;

        explicit FramebufferState(const uint32_t& in_n_color_attachments);
    } FramebufferState;

    typedef struct ProgramState
    {
        uint32_t                            active_attribute_max_length;
        uint32_t                            active_uniform_block_max_length;
        uint32_t                            active_uniform_max_length;
        std::vector<ActiveUniformBlock>     active_uniform_blocks;
        std::vector<ActiveUniformState>     active_uniforms;
        std::vector<GLuint>                 attached_shaders;
        bool                                delete_status;
        std::string                         info_log;
        bool                                link_status;
        uint32_t                            n_geometry_vertices_out;
        uint32_t                            n_transform_feedback_varyings;
        OpenGL::GeometryInputType           geometry_input_type;
        OpenGL::GeometryOutputType          geometry_output_type;
        OpenGL::TransformFeedbackBufferMode transform_feedback_buffer_mode;
        uint32_t                            transform_feedback_varying_max_length;
        RangedBufferBinding                 uniform_buffer_binding_generic;
        std::vector<RangedBufferBinding>    uniform_buffer_binding_indexed;
        bool                                validate_status;

        ProgramState(const uint32_t& in_n_max_indexed_uniform_buffer_bindings);
    } ProgramState;

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

    typedef struct TextureImageState
    {
        uint32_t               binding_texture_buffer_data_store;
        uint32_t               compressed_image_size;
        bool                   fixed_sample_locations;
        uint32_t               depth;
        uint32_t               height;
        OpenGL::InternalFormat internal_format;
        uint32_t               samples;
        uint32_t               width;

        explicit TextureImageState(const OpenGL::InternalFormat& in_internal_format);
    } TextureImageState;

    typedef std::unique_ptr<TextureImageState> TextureImageStateUniquePtr;

    typedef struct TextureState
    {
        int32_t                        base_level;
        uint32_t                       border_color[4];
        OpenGL::TextureCompareFunction compare_function;
        OpenGL::TextureCompareMode     compare_mode;
        float                          lod_bias;
        OpenGL::TextureMagFilter       mag_filter;
        int32_t                        max_level;
        float                          max_lod;
        OpenGL::TextureMinFilter       min_filter;
        float                          min_lod;
        OpenGL::TextureWrapMode        wrap_r;
        OpenGL::TextureWrapMode        wrap_s;
        OpenGL::TextureWrapMode        wrap_t;

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
        GLuint                                 element_array_buffer_binding;
        std::vector<VertexAttributeArrayState> vertex_attribute_arrays;

        VertexArrayObjectState(const uint32_t&               in_n_vertex_attribute_arrays);
        VertexArrayObjectState(const VertexArrayObjectState& in_vaa) = default;
    } VertexArrayObjectState;

    typedef struct VertexAttributeArrayState
    {
        GLReferenceUniquePtr     buffer_binding_ptr;
        bool                     enabled;
        bool                     integer;
        bool                     normalized;
        const void*              pointer;
        uint64_t                 size;
        uint64_t                 stride;
        VertexAttributeArrayType type;

        VertexAttributeArrayState();
        VertexAttributeArrayState(const VertexAttributeArrayState& in_vaa_state);

        VertexAttributeArrayState& operator= (const VertexAttributeArrayState&);
        bool                       operator==(const VertexAttributeArrayState& in_state);
    } VertexAttributeArrayState;


    /* Rendering context state */
    typedef struct ContextState
    {
        bool    is_primitive_restart_enabled;
        int32_t primitive_restart_index;

        std::string version;

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
        uint32_t              is_blend_enabled_for_draw_buffers; /* n-th bit corresponds to n-th draw buffer */
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

        uint32_t binding_draw_framebuffer;
        uint32_t binding_read_framebuffer;
        uint32_t binding_renderbuffer;

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

        GLuint current_program_id;

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

        explicit ContextState(const IGLLimits* in_limits_ptr,
                              const int32_t*   in_viewport_ivec4_ptr,
                              const int32_t*   in_scissor_box_ivec4_ptr);

    } ContextState;

    typedef std::unique_ptr<ContextState> ContextStateUniquePtr;
};

#endif /* VKGL_TYPES_STRUCTS_H */