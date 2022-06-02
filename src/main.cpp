/*
 *	OpenGL Capability information.
 *	Copyright (C) 2016  Valdemar Lindberg
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <GL/glew.h>
#include <GLRendererInterface.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

using namespace fragcore;

/**
 *	Forward declared functions.
 */
extern void readargument(int argc, char **argv);

/*
 *	Converting character into a constant string in the precompiling stage.
 */
#define GLIF_STR_HELPER(x) #x
#define GLIF_STR(x) GLIF_STR_HELPER(x)
#define GLIF_TMP_VARI(x) tmp##x

GLenum err;
GLint Integervtmp;
#define GLIF_CONSTANTI_PRINT(glenum)                                                                                   \
	glGetIntegerv(glenum, &Integervtmp);                                                                               \
	printf(#glenum " : %d\n", Integervtmp);                                                                            \
	err = glGetError();

GLint64 Integervtmp64;
#define GLIF_CONSTANTI64_PRINT(glenum)                                                                                 \
	glGetInteger64v(glenum, &Integervtmp64);                                                                           \
	printf(#glenum " : %ld\n", Integervtmp64);

GLfloat glGetFloatvtmp;
#define GLIF_CONSTANTF_PRINT(glenum)                                                                                   \
	glGetFloatv(glenum, &glGetFloatvtmp);                                                                              \
	printf(#glenum " : %f\n", glGetFloatvtmp);

int main(int argc, char **argv) {

	readargument(argc, argv);

	Ref<GLRendererInterface> glRenderInterface = Ref<GLRendererInterface>(new GLRendererInterface(nullptr));

	/*	Display information.	*/
	printf("RENDERER %s\n", glGetString(GL_RENDERER));
	printf("VENDOR %s\n", glGetString(GL_VENDOR));
	printf("VERSION %s\n", glGetString(GL_VERSION));
	printf("SHADING_LANGUAGE_VERSION %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("\n");

	printf("OpenGL 2.0");

	/*	*/
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_WORK_GROUP_COUNT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_WORK_GROUP_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_GROUP_STACK_DEPTH);

	/*	*/
	GLIF_CONSTANTI_PRINT(GL_NUM_COMPRESSED_TEXTURE_FORMATS);
	GLIF_CONSTANTI_PRINT(GL_COMPRESSED_TEXTURE_FORMATS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_3D_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_ARRAY_TEXTURE_LAYERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_CLIP_DISTANCES);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_TEXTURE_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEPTH_TEXTURE_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_DRAW_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS);
	GLIF_CONSTANTI64_PRINT(GL_MAX_ELEMENTS_INDICES);
	GLIF_CONSTANTI64_PRINT(GL_MAX_ELEMENTS_VERTICES);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_INPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_VECTORS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_WIDTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_HEIGHT);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_LAYERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_INPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_INTEGER_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MIN_MAP_BUFFER_ALIGNMENT);
	GLIF_CONSTANTI_PRINT(GL_MAX_LABEL_LENGTH);
	GLIF_CONSTANTI_PRINT(GL_MIN_PROGRAM_TEXEL_OFFSET);
	GLIF_CONSTANTI_PRINT(GL_MAX_RECTANGLE_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_RENDERBUFFER_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLE_MASK_WORDS);
	GLIF_CONSTANTI64_PRINT(GL_MAX_SERVER_WAIT_TIMEOUT);

	/*	*/
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_BUFFER_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_LOD_BIAS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_UNIFORM_BUFFER_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_UNIFORM_BLOCK_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_UNIFORM_LOCATIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_VECTORS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_FLOATS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIBS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_VECTORS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VIEWPORT_DIMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VIEWPORTS);

	/*	*/
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIB_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_ELEMENT_INDEX);

	// GL_VIEWPORT
	// GL_VIEWPORT_BOUNDS_RANGE
	// GL_VIEWPORT_SUBPIXEL_BITS
	// GL_VIEWPORT_INDEX_PROVOKING_VERTEX
	// GL_VIEWPORT_SUBPIXEL_BITS

	GLIF_CONSTANTI_PRINT(GL_MAX_LIST_NESTING);
	GLIF_CONSTANTI_PRINT(GL_MAX_EVAL_ORDER);
	GLIF_CONSTANTI_PRINT(GL_MAX_LIGHTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_CLIP_PLANES);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_PIXEL_MAP_TABLE);
	GLIF_CONSTANTI_PRINT(GL_MAX_ATTRIB_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_MODELVIEW_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_NAME_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROJECTION_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_VIEWPORT_DIMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_3D_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_ELEMENTS_VERTICES);
	GLIF_CONSTANTI_PRINT(GL_MAX_ELEMENTS_INDICES);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_CUBE_MAP_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_LOD_BIAS);
	GLIF_CONSTANTI_PRINT(GL_MAX_DRAW_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIBS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_COORDS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_FLOATS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_CLIP_DISTANCES);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_ARRAY_TEXTURE_LAYERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXEL_OFFSET);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS);
	GLIF_CONSTANTI_PRINT(GL_MAX_RECTANGLE_TEXTURE_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_BUFFER_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_VERTICES);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_INPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_INPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIB_STRIDE);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_MAX_ANISOTROPY);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_MESSAGE_LENGTH_AMD);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_LOGGED_MESSAGES_AMD);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_TEXTURE_SIZE_AMD);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLES_ANGLE);
	GLIF_CONSTANTI_PRINT(GL_MAX_CLIP_DISTANCES_APPLE);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLES_APPLE);
	GLIF_CONSTANTI_PRINT(GL_MAX_SERVER_WAIT_TIMEOUT_APPLE);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_VECTORS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_VECTORS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_VECTORS);
	GLIF_CONSTANTI_PRINT(GL_MAX_ELEMENT_INDEX);
	GLIF_CONSTANTI_PRINT(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_WORK_GROUP_COUNT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_WORK_GROUP_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_CULL_DISTANCES);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_MESSAGE_LENGTH_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_LOGGED_MESSAGES_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_DRAW_BUFFERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_UNIFORM_LOCATIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_ALU_INSTRUCTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEX_INSTRUCTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEX_INDIRECTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_ALU_INSTRUCTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_TEX_INSTRUCTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_TEX_INDIRECTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_COORDS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_IMAGE_UNITS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_WIDTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_HEIGHT);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_LAYERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_RENDERBUFFER_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_ATTACHMENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_VARYING_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_INVOCATIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_STREAMS);
	GLIF_CONSTANTI_PRINT(GL_MAX);
	GLIF_CONSTANTI_PRINT(GL_MAX_CONVOLUTION_WIDTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_CONVOLUTION_HEIGHT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_MATRIX_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_WIDTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_HEIGHT);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_LAYERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_DIMENSIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PALETTE_MATRICES_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_UNITS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_COMPILER_THREADS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_NAME_LENGTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_NUM_ACTIVE_VARIABLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_NUM_COMPATIBLE_SUBROUTINES);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_ATOMIC_COUNTERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_IMAGE_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_IMAGE_UNIFORMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_STORAGE_BLOCK_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_SUBROUTINES);
	GLIF_CONSTANTI_PRINT(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_TEXTURE_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_SERVER_WAIT_TIMEOUT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_PATCH_VERTICES);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_GEN_LEVEL);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_PATCH_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_TOTAL_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_BUFFER_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_CUBE_MAP_TEXTURE_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_MAX_ANISOTROPY);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXTURE_GATHER_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLE_MASK_WORDS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_TEXTURE_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEPTH_TEXTURE_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_INTEGER_SAMPLES);
	GLIF_CONSTANTI_PRINT(GL_MAX_RECTANGLE_TEXTURE_SIZE_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_STREAMS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_UNIFORM_BLOCKS);
	GLIF_CONSTANTI_PRINT(GL_MAX_UNIFORM_BUFFER_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_UNIFORM_BLOCK_SIZE);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIB_BINDINGS);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNITS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_MATRICES_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ATTRIBS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_INSTRUCTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_INSTRUCTIONS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEMPORARIES_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_TEMPORARIES_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_PARAMETERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_PARAMETERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_ATTRIBS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_ATTRIBS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_ADDRESS_REGISTERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_NATIVE_ADDRESS_REGISTERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_LOCAL_PARAMETERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_ENV_PARAMETERS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_UNIFORM_COMPONENTS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_FLOATS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS_ARB);
	GLIF_CONSTANTI_PRINT(GL_MAX_VIEWPORTS);
	GLIF_CONSTANTI_PRINT(GL_MAX_DRAW_BUFFERS_ATI);
	GLIF_CONSTANTI_PRINT(GL_MAX_PN_TRIANGLES_TESSELATION_LEVEL_ATI);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_STREAMS_ATI);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_BINDABLE_UNIFORM_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_CLIP_DISTANCES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_CULL_DISTANCES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_CONVOLUTION_WIDTH_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_CONVOLUTION_HEIGHT_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_DRAW_BUFFERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_ATTACHMENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_ELEMENTS_VERTICES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_ELEMENTS_INDICES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_LIGHTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_ACTIVE_LIGHTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_RENDERBUFFER_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_ATTACHMENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_BLOCKS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_INVOCATIONS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_IMAGE_UNIFORMS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_INPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_LAYERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_BLOCKS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_INVOCATIONS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_IMAGE_UNIFORMS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_INPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_ATOMIC_COUNTERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAMEBUFFER_LAYERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VARYING_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_VARYING_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_MULTIVIEW_BUFFERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_PIXEL_TRANSFORM_2D_STACK_DEPTH_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_RASTER_SAMPLES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_IMAGE_UNITS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_IMAGE_SAMPLES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_PIXEL_LOCAL_STORAGE_FAST_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_PIXEL_LOCAL_STORAGE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_COMBINED_LOCAL_STORAGE_FAST_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_COMBINED_LOCAL_STORAGE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_TEXTURE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_3D_TEXTURE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_3D_TEXTURE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_ARRAY_TEXTURE_LAYERS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_BUFFER_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_CUBE_MAP_TEXTURE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_LOD_BIAS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_RECTANGLE_TEXTURE_SIZE_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_INSTRUCTIONS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_VARIANTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_INVARIANTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_LOCAL_CONSTANTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_SHADER_LOCALS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_OPTIMIZED_VERTEX_SHADER_INSTRUCTIONS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_OPTIMIZED_VERTEX_SHADER_VARIANTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_OPTIMIZED_VERTEX_SHADER_INVARIANTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCAL_CONSTANTS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_OPTIMIZED_VERTEX_SHADER_LOCALS_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_WINDOW_RECTANGLES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_GROUP_STACK_DEPTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_LABEL_LENGTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_MESSAGE_LENGTH);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEBUG_LOGGED_MESSAGES);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_COMPILER_THREADS_KHR);
	GLIF_CONSTANTI_PRINT(GL_MAX_LGPU_GPUS_NVX);
	GLIF_CONSTANTI_PRINT(GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEEP_3D_TEXTURE_WIDTH_HEIGHT_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_DEEP_3D_TEXTURE_DEPTH_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_DRAW_BUFFERS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_MAP_TESSELLATION_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_RATIONAL_EVAL_ORDER_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLE_MASK_WORDS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_ATTACHMENTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_COORDS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_IMAGE_UNITS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_CALL_DEPTH_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_IF_DEPTH_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_LOOP_DEPTH_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_LOOP_COUNT_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_RASTER_SAMPLES_EXT);
	GLIF_CONSTANTI_PRINT(GL_MAX_SAMPLES_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_MULTISAMPLE_COVERAGE_MODES_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_OUTPUT_VERTICES_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TOTAL_OUTPUT_COMPONENTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXEL_OFFSET_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_ATTRIB_COMPONENTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_RESULT_COMPONENTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_GENERIC_ATTRIBS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_GENERIC_RESULTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_GEOMETRY_PROGRAM_INVOCATIONS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_TEXTURE_GATHER_OFFSET_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHININESS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_SPOT_EXPONENT_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_GENERAL_COMBINERS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_SHADER_BUFFER_ADDRESS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_PATCH_ATTRIBS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_ARRAY_TEXTURE_LAYERS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_RECTANGLE_TEXTURE_SIZE_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRACK_MATRIX_STACK_DEPTH_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_TRACK_MATRICES_NV);
	// GL_NV_vertex_program2_option
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_EXEC_INSTRUCTIONS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_PROGRAM_CALL_DEPTH_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_VIEWPORTS_NV);
	GLIF_CONSTANTI_PRINT(GL_MAX_VIEWS_OVR);

	GLIF_CONSTANTI_PRINT(GL_MAX_VERTEX_HINT_PGI);
	GLIF_CONSTANTI_PRINT(GL_MAX_RED_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_GREEN_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_BLUE_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_ALPHA_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURES_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_TEXTURE_COORD_SETS_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_ASYNC_HISTOGRAM_SGIX);
	GLIF_CONSTANTI_PRINT(GL_MAX_ASYNC_TEX_IMAGE_SGIX);
	GLIF_CONSTANTI_PRINT(GL_MAX_ASYNC_DRAW_PIXELS_SGIX);
	GLIF_CONSTANTI_PRINT(GL_MAX_ASYNC_READ_PIXELS_SGIX);
	GLIF_CONSTANTI_PRINT(GL_MAX_FOG_LAYERS_POINTS_SGIX);
	GLIF_CONSTANTI_PRINT(GL_MAX_MIPMAP_ANISOTROPY_SGIX);
	GLIF_CONSTANTI_PRINT(GL_MAX_LUMINANCE_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_INTENSITY_SGIS);
	GLIF_CONSTANTI_PRINT(GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI);
	GLIF_CONSTANTI_PRINT(GL_MAX_FFT_WIDTH_SGI);

	// GL_SGIX_async_histogram
	// GL_SGI_complex_type

	return EXIT_SUCCESS;
}
