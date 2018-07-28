#ifndef VKGL_TYPES_STRUCTS_H
#define VKGL_TYPES_STRUCTS_H

namespace VKGL
{
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

        DispatchTable();
    };
};

#endif /* VKGL_TYPES_STRUCTS_H */