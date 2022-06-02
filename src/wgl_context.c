#pragma warning(disable : 4273) // 'function' : inconsistent DLL linkage

/* library  */
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "Glu32.lib")
#pragma comment(lib, "gdi32.lib")

#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/wglext.h>
#include <dwmapi.h>
#include <windows.h>
#include <winuser.h>

#define PIXATTOFFSET 8
int pixAtt[] = {WGL_DRAW_TO_WINDOW_ARB, GL_TRUE, WGL_SUPPORT_OPENGL_ARB, GL_TRUE, WGL_DOUBLE_BUFFER_ARB, GL_TRUE,
				WGL_PIXEL_TYPE_ARB, WGL_TYPE_RGBA_ARB,
				/*
				GLX_RENDER_TYPE, GLX_RGBA_BIT,
				GLX_X_RENDERABLE, True,
				GLX_X_VISUAL_TYPE, GLX_TRUE_COLOR,
				GLX_DRAWABLE_TYPE, GLX_WINDOW_BIT,
				*/
				/**/
				WGL_RED_BITS_ARB, 8, WGL_GREEN_BITS_ARB, 8, WGL_BLUE_BITS_ARB, 8, WGL_DEPTH_BITS_ARB, 16,
				WGL_ALPHA_BITS_ARB, 0, WGL_DOUBLE_BUFFER_ARB, 1, WGL_STENCIL_BITS_ARB, 0, WGL_ACCUM_RED_BITS_ARB, 0,
				WGL_ACCUM_GREEN_BITS_ARB, 0, WGL_ACCUM_BLUE_BITS_ARB, 0, WGL_ACCUM_ALPHA_BITS_ARB, 0,
				// GLX_
				WGL_STEREO_ARB, 0, WGL_SAMPLE_BUFFERS_ARB, 0, WGL_SAMPLES_ARB, 0, WGL_FRAMEBUFFER_SRGB_CAPABLE_ARB,
				TRUE, NULL, WGL_CONTEXT_MAJOR_VERSION_ARB, 3, WGL_CONTEXT_MINOR_VERSION_ARB, 3, WGL_CONTEXT_FLAGS_ARB,
				WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB, WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_DEBUG_BIT_ARB, NULL};

int giCreateMakeGLContext() {}

void giDeleteGLContext() {}
