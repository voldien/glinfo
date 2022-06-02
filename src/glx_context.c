#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glx.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *	Global variables.
 */
Display *display = NULL;
GLXContext glc_context = NULL;
Window glc_window = NULL;

int giCreateMakeGLContext() {

	XSetWindowAttributes winAttribs = {0};

	GLXFBConfig *config;
	GLint nelements;
	int maj, min;
	XVisualInfo *vi;
	Colormap cmap;
	int screen;
	Window root;
	int winmask = CWBackPixmap | CWColormap | CWBorderPixel | CWEventMask;
	int i;

	/*	Create OpenGL context.	*/
	display = XOpenDisplay(getenv("DISPLAY"));
	if (!display) {
		return 0;
	}

	/*	Get GLX version.	*/
	if (!glXQueryVersion(display, &maj, &min)) {
		return 0;
	}

	screen = DefaultScreen(display);
	root = RootWindow(display, screen);

	config = glXGetFBConfigs(display, screen, &nelements);

	/*	TODO improve to something that works for all drivers.	*/
	for (i = 0; i < nelements; i++) {
		vi = (XVisualInfo *)glXGetVisualFromFBConfig(display, config[i]);
		if (!vi) {
			continue;
		}
		if (vi->screen == screen) {
			break;
		}
	}

	/*	*/
	cmap = XCreateColormap(display, root, vi->visual, AllocNone);

	winAttribs.colormap = cmap;
	winAttribs.event_mask = 0;
	winAttribs.border_pixmap = None;
	winAttribs.border_pixel = 0;
	winAttribs.bit_gravity = ForgetGravity;

	/*	*/
	glc_window = XCreateWindow(display, root, 0, 0, 1, 1, 0, vi->depth, InputOutput, vi->visual, winmask, &winAttribs);

	if (min >= 3) {
		glc_context = glXCreateNewContext(display, config[i], GLX_RGBA_TYPE, 0, 1);
		if (!glc_context) {
			return 0;
		}

		if (!glXMakeContextCurrent(display, glc_window, glc_window, glc_context)) {
			return 0;
		}
	} else {
		glc_context = glXCreateContext(display, vi, NULL, True);
		if (!glc_context) {
			return 0;
		}
		if (!glXMakeCurrent(display, glc_window, glc_context)) {
			return 0;
		}
	}

	return 1;
}

void giDeleteGLContext() {
	glXMakeCurrent(display, None, None);
	glXDestroyContext(display, glc_context);
	XDestroyWindow(display, glc_window);
	XCloseDisplay(display);
}
