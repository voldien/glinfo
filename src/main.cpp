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

typedef struct capability_entry_t {
	GLenum capability;
	size_t nrValues;
} CapabilityEntry;

// TODO add support for multie dim
typedef struct extension_entry_t {
	std::string name;							  /*	*/
	std::map<std::string, CapabilityEntry> Int32; /*	*/
	std::map<std::string, CapabilityEntry> Int64; /*	*/
	std::map<std::string, CapabilityEntry> Float; /*	*/
} ExtensionEntry;

#define GLIF_MACRON(glenum, x)                                                                                         \
	{                                                                                                                  \
		#glenum, { glenum, x }                                                                                         \
	}

#define GLIF_MACRO(glenum)                                                                                             \
	{                                                                                                                  \
		#glenum, { glenum, 1 }                                                                                         \
	}

std::vector<ExtensionEntry> extensionList = {
	{"GL_VERSION_1_1",
	 {
		 GLIF_MACRO(GL_MAX_LIST_NESTING),
		 GLIF_MACRO(GL_MAX_EVAL_ORDER),
		 GLIF_MACRO(GL_MAX_LIGHTS),
		 GLIF_MACRO(GL_MAX_TEXTURE_SIZE),
		 GLIF_MACRO(GL_MAX_PIXEL_MAP_TABLE),
		 GLIF_MACRO(GL_MAX_ATTRIB_STACK_DEPTH),
		 GLIF_MACRO(GL_MAX_MODELVIEW_STACK_DEPTH),
		 GLIF_MACRO(GL_MAX_NAME_STACK_DEPTH),
		 GLIF_MACRO(GL_MAX_PROJECTION_STACK_DEPTH),
		 GLIF_MACRO(GL_MAX_TEXTURE_STACK_DEPTH),
		 GLIF_MACRO(GL_MAX_VIEWPORT_DIMS),
		 GLIF_MACRO(GL_MAX_CLIENT_ATTRIB_STACK_DEPTH),
	 },
	 {},
	 {}},
	{"GL_VERSION_1_2",
	 {
		 GLIF_MACRO(GL_MAX_3D_TEXTURE_SIZE),
		 GLIF_MACRO(GL_MAX_ELEMENTS_VERTICES),
		 GLIF_MACRO(GL_MAX_ELEMENTS_INDICES),
	 },
	 {},
	 {}},
	{"GL_VERSION_1_3", {GLIF_MACRO(GL_MAX_TEXTURE_UNITS), GLIF_MACRO(GL_MAX_CUBE_MAP_TEXTURE_SIZE)}, {}, {}},
	{"GL_VERSION_1_4", {}, {}, {GLIF_MACRO(GL_MAX_TEXTURE_LOD_BIAS)}},
	{"GL_VERSION_2_0",
	 {
		 GLIF_MACRO(GL_MAX_DRAW_BUFFERS),
		 GLIF_MACRO(GL_MAX_VERTEX_ATTRIBS),
		 GLIF_MACRO(GL_MAX_TEXTURE_COORDS),
		 GLIF_MACRO(GL_MAX_TEXTURE_IMAGE_UNITS),
		 GLIF_MACRO(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS),
		 GLIF_MACRO(GL_MAX_VERTEX_UNIFORM_COMPONENTS),
		 GLIF_MACRO(GL_MAX_VARYING_FLOATS),
		 GLIF_MACRO(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS),
		 GLIF_MACRO(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS),
	 },
	 {},
	 {}},
	{"GL_VERSION_3_0",
	 {GLIF_MACRO(GL_MAX_CLIP_DISTANCES), GLIF_MACRO(GL_MAX_CLIP_PLANES), GLIF_MACRO(GL_MAX_VARYING_COMPONENTS),
	  GLIF_MACRO(GL_MAX_VARYING_FLOATS), GLIF_MACRO(GL_NUM_EXTENSIONS), GLIF_MACRO(GL_MAX_ARRAY_TEXTURE_LAYERS),
	  GLIF_MACRO(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS),
	  GLIF_MACRO(GL_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS),
	  GLIF_MACRO(GL_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS), GLIF_MACRO(GL_MAX_PROGRAM_TEXEL_OFFSET),
	  GLIF_MACRO(GL_MIN_PROGRAM_TEXEL_OFFSET)},
	 {},
	 {}},
	{"GL_VERSION_3_1", {GLIF_MACRO(GL_MAX_RECTANGLE_TEXTURE_SIZE)}, {}, {}},
	{"GL_VERSION_3_2",
	 {
		 GLIF_MACRO(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS),
		 GLIF_MACRO(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS),
		 GLIF_MACRO(GL_MAX_GEOMETRY_OUTPUT_VERTICES),
		 GLIF_MACRO(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS),
		 GLIF_MACRO(GL_MAX_VERTEX_OUTPUT_COMPONENTS),
		 GLIF_MACRO(GL_MAX_GEOMETRY_INPUT_COMPONENTS),
		 GLIF_MACRO(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS),
		 GLIF_MACRO(GL_MAX_FRAGMENT_INPUT_COMPONENTS),
	 },
	 {},
	 {}},
	{"GL_VERSION_4_4", {GLIF_MACRO(GL_MAX_VERTEX_ATTRIB_STRIDE)}, {}, {}},
	{"GL_VERSION_4_6", {GLIF_MACRO(GL_NUM_SPIR_V_EXTENSIONS)}, {}, {}},
	{"GL_ARB_ES2_compatibility",
	 {
		 GLIF_MACRO(GL_NUM_SHADER_BINARY_FORMATS),
		 GLIF_MACRO(GL_MAX_VERTEX_UNIFORM_VECTORS),
		 GLIF_MACRO(GL_MAX_VARYING_VECTORS),
		 GLIF_MACRO(GL_MAX_FRAGMENT_UNIFORM_VECTORS),
	 },
	 {},
	 {}},
	{"GL_AMD_debug_output",
	 {GLIF_MACRO(GL_MAX_DEBUG_MESSAGE_LENGTH_AMD), GLIF_MACRO(GL_MAX_DEBUG_LOGGED_MESSAGES_AMD)},
	 {},
	 {}},
	{"GL_ARB_debug_output",
	 {GLIF_MACRO(GL_MAX_DEBUG_MESSAGE_LENGTH_ARB), GLIF_MACRO(GL_MAX_DEBUG_LOGGED_MESSAGES_ARB)},
	 {},
	 {}},
	{"GL_ARB_texture_multisample",
	 {GLIF_MACRO(GL_MAX_SAMPLE_MASK_WORDS), GLIF_MACRO(GL_MAX_COLOR_TEXTURE_SAMPLES),
	  GLIF_MACRO(GL_MAX_DEPTH_TEXTURE_SAMPLES), GLIF_MACRO(GL_MAX_INTEGER_SAMPLES)},
	 {},
	 {}},

	{"GL_AMD_sparse_texture",
	 {GLIF_MACRO(GL_MAX_SPARSE_TEXTURE_SIZE_AMD), GLIF_MACRO(GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS)},
	 {GLIF_MACRO(GL_MAX_SPARSE_3D_TEXTURE_SIZE_AMD)},
	 {}},
	{"GL_ARB_sparse_texture",
	 {GLIF_MACRO(GL_MAX_SPARSE_TEXTURE_SIZE_ARB), GLIF_MACRO(GL_MAX_SPARSE_3D_TEXTURE_SIZE_ARB),
	  GLIF_MACRO(GL_MAX_SPARSE_ARRAY_TEXTURE_LAYERS_ARB)},
	 {},
	 {}},
	{"GL_ANGLE_framebuffer_multisample", {GLIF_MACRO(GL_MAX_SAMPLES_ANGLE)}, {}, {}},
	{"GL_APPLE_clip_distance", {GLIF_MACRO(GL_MAX_CLIP_DISTANCES_APPLE)}, {}, {}},
	{"GL_APPLE_framebuffer_multisample", {GLIF_MACRO(GL_MAX_SAMPLES_APPLE)}, {}, {}},
	{"GL_APPLE_sync", {}, {GLIF_MACRO(GL_MAX_SERVER_WAIT_TIMEOUT_APPLE)}, {}},
	{"GL_APPLE_vertex_array_range", {GLIF_MACRO(GL_MAX_VERTEX_ARRAY_RANGE_ELEMENT_APPLE)}, {}, {}},
	{"GL_ARB_ES2_compatibility",
	 {GLIF_MACRO(GL_MAX_VERTEX_UNIFORM_VECTORS), GLIF_MACRO(GL_MAX_VARYING_VECTORS),
	  GLIF_MACRO(GL_MAX_FRAGMENT_UNIFORM_VECTORS)},
	 {},
	 {}},
	{"GL_ARB_ES3_compatibility", {GLIF_MACRO(GL_MAX_ELEMENT_INDEX)}, {}, {}},
	{"GL_ARB_blend_func_extended", {GLIF_MACRO(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS)}, {}, {}},
	{"GL_ARB_compute_shader",
	 {GLIF_MACRO(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE), GLIF_MACRO(GL_MAX_COMPUTE_UNIFORM_COMPONENTS),
	  GLIF_MACRO(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS), GLIF_MACRO(GL_MAX_COMPUTE_ATOMIC_COUNTERS),
	  GLIF_MACRO(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS), GLIF_MACRO(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS),
	  GLIF_MACRO(GL_MAX_COMPUTE_UNIFORM_BLOCKS), GLIF_MACRO(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS),
	  GLIF_MACRO(GL_MAX_COMPUTE_IMAGE_UNIFORMS), GLIF_MACRON(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 3),
	  GLIF_MACRON(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 3)},
	 {},
	 {}},
	{"GL_ARB_compute_variable_group_size",
	 {GLIF_MACRO(GL_MAX_COMPUTE_FIXED_GROUP_INVOCATIONS_ARB), GLIF_MACRON(GL_MAX_COMPUTE_FIXED_GROUP_SIZE_ARB, 3),
	  GLIF_MACRO(GL_MAX_COMPUTE_VARIABLE_GROUP_INVOCATIONS_ARB),
	  GLIF_MACRON(GL_MAX_COMPUTE_VARIABLE_GROUP_SIZE_ARB, 3)},
	 {},
	 {}},
	{"GL_ARB_cull_distance",
	 {GLIF_MACRO(GL_MAX_CULL_DISTANCES), GLIF_MACRO(GL_MAX_COMBINED_CLIP_AND_CULL_DISTANCES)},
	 {},
	 {}},
	{"GL_ARB_draw_buffers", {GLIF_MACRO(GL_MAX_DRAW_BUFFERS_ARB)}, {}, {}},
	{"GL_ARB_explicit_uniform_location", {GLIF_MACRO(GL_MAX_UNIFORM_LOCATIONS)}, {}, {}},
	{"GL_ARB_fragment_program",
	 {GLIF_MACRO(GL_MAX_TEXTURE_COORDS_ARB), GLIF_MACRO(GL_MAX_TEXTURE_IMAGE_UNITS_ARB)},
	 {},
	 {}},
	{"GL_ARB_fragment_shader", {GLIF_MACRO(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS_ARB)}, {}, {}},
	{"GL_ARB_framebuffer_no_attachments",
	 {GLIF_MACRO(GL_MAX_FRAMEBUFFER_WIDTH), GLIF_MACRO(GL_MAX_FRAMEBUFFER_HEIGHT),
	  GLIF_MACRO(GL_MAX_FRAMEBUFFER_LAYERS), GLIF_MACRO(GL_MAX_FRAMEBUFFER_SAMPLES)},
	 {},
	 {}},
	{"GL_ARB_viewport_array", {GLIF_MACRO(GL_MAX_VIEWPORTS), GLIF_MACRO(GL_VIEWPORT_SUBPIXEL_BITS)}, {}, {}},

	{"GL_EXT_framebuffer_multisample", {GLIF_MACRO(GL_MAX_SAMPLES_EXT)}, {}, {}},
	{"GL_ARB_framebuffer_object",
	 {GLIF_MACRO(GL_MAX_RENDERBUFFER_SIZE), GLIF_MACRO(GL_MAX_COLOR_ATTACHMENTS), GLIF_MACRO(GL_MAX_SAMPLES)},
	 {},
	 {}},
	{"GL_ARB_geometry_shader4",
	 {GLIF_MACRO(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_ARB), GLIF_MACRO(GL_MAX_GEOMETRY_VARYING_COMPONENTS_ARB),
	  GLIF_MACRO(GL_MAX_VERTEX_VARYING_COMPONENTS_ARB), GLIF_MACRO(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_ARB),
	  GLIF_MACRO(GL_MAX_GEOMETRY_OUTPUT_VERTICES_ARB), GLIF_MACRO(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_ARB)},
	 {},
	 {}},
	{"GL_ARB_gpu_shader5",
	 {GLIF_MACRO(GL_MAX_GEOMETRY_SHADER_INVOCATIONS), GLIF_MACRO(GL_MAX_FRAGMENT_INTERPOLATION_OFFSET),
	  GLIF_MACRO(GL_MAX_VERTEX_STREAMS)},
	 {},
	 {}},
	{"GL_ARB_matrix_palette",
	 {GLIF_MACRO(GL_MAX_MATRIX_PALETTE_STACK_DEPTH_ARB), GLIF_MACRO(GL_MAX_PALETTE_MATRICES_ARB)},
	 {},
	 {}},
	{"GL_ARB_multitexture", {GLIF_MACRO(GL_MAX_TEXTURE_UNITS_ARB)}, {}, {}},
	{"GL_ARB_parallel_shader_compile", {GLIF_MACRO(GL_MAX_SHADER_COMPILER_THREADS_ARB)}, {}, {}},
	{"GL_ARB_shader_atomic_counters",
	 {GLIF_MACRO(GL_MAX_VERTEX_ATOMIC_COUNTER_BUFFERS), GLIF_MACRO(GL_MAX_TESS_CONTROL_ATOMIC_COUNTER_BUFFERS),
	  GLIF_MACRO(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTER_BUFFERS), GLIF_MACRO(GL_MAX_GEOMETRY_ATOMIC_COUNTER_BUFFERS),
	  GLIF_MACRO(GL_MAX_FRAGMENT_ATOMIC_COUNTER_BUFFERS), GLIF_MACRO(GL_MAX_COMBINED_ATOMIC_COUNTER_BUFFERS),
	  GLIF_MACRO(GL_MAX_VERTEX_ATOMIC_COUNTERS), GLIF_MACRO(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS),
	  GLIF_MACRO(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS), GLIF_MACRO(GL_MAX_GEOMETRY_ATOMIC_COUNTERS),
	  GLIF_MACRO(GL_MAX_FRAGMENT_ATOMIC_COUNTERS), GLIF_MACRO(GL_MAX_COMBINED_ATOMIC_COUNTERS),
	  GLIF_MACRO(GL_MAX_ATOMIC_COUNTER_BUFFER_SIZE), GLIF_MACRO(GL_MAX_ATOMIC_COUNTER_BUFFER_BINDINGS)},
	 {},
	 {}},
	{"GL_ARB_shader_image_load_store",
	 {GLIF_MACRO(GL_MAX_IMAGE_UNITS), GLIF_MACRO(GL_MAX_COMBINED_IMAGE_UNITS_AND_FRAGMENT_OUTPUTS),
	  GLIF_MACRO(GL_MAX_IMAGE_SAMPLES), GLIF_MACRO(GL_MAX_VERTEX_IMAGE_UNIFORMS),
	  GLIF_MACRO(GL_MAX_TESS_CONTROL_IMAGE_UNIFORMS), GLIF_MACRO(GL_MAX_TESS_EVALUATION_IMAGE_UNIFORMS),
	  GLIF_MACRO(GL_MAX_GEOMETRY_IMAGE_UNIFORMS), GLIF_MACRO(GL_MAX_FRAGMENT_IMAGE_UNIFORMS),
	  GLIF_MACRO(GL_MAX_COMBINED_IMAGE_UNIFORMS)},
	 {},
	 {}},
	{"GL_ARB_uniform_buffer_object",
	 {GLIF_MACRO(GL_MAX_VERTEX_UNIFORM_BLOCKS), GLIF_MACRO(GL_MAX_GEOMETRY_UNIFORM_BLOCKS),
	  GLIF_MACRO(GL_MAX_FRAGMENT_UNIFORM_BLOCKS), GLIF_MACRO(GL_MAX_COMBINED_UNIFORM_BLOCKS),
	  GLIF_MACRO(GL_MAX_UNIFORM_BUFFER_BINDINGS), GLIF_MACRO(GL_MAX_UNIFORM_BLOCK_SIZE),
	  GLIF_MACRO(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS), GLIF_MACRO(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS),
	  GLIF_MACRO(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS), GLIF_MACRO(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT)},

	 {},
	 {}},
	{"GL_ARB_shader_storage_buffer_object",
	 {GLIF_MACRO(GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES), GLIF_MACRO(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS),
	  GLIF_MACRO(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS), GLIF_MACRO(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS),
	  GLIF_MACRO(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS), GLIF_MACRO(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS),
	  GLIF_MACRO(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS), GLIF_MACRO(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS),
	  GLIF_MACRO(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS), GLIF_MACRO(GL_MAX_SHADER_STORAGE_BLOCK_SIZE),
	  GLIF_MACRO(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT)},
	 {},
	 {}},
	{"GL_ARB_shader_subroutine",
	 {GLIF_MACRO(GL_MAX_SUBROUTINES), GLIF_MACRO(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS)},
	 {},
	 {}},
	{"GL_ARB_map_buffer_alignment", {GLIF_MACRO(GL_MIN_MAP_BUFFER_ALIGNMENT)}, {}, {}},
	{"GL_EXT_bindable_uniform",
	 {GLIF_MACRO(GL_MAX_VERTEX_BINDABLE_UNIFORMS_EXT), GLIF_MACRO(GL_MAX_FRAGMENT_BINDABLE_UNIFORMS_EXT),
	  GLIF_MACRO(GL_MAX_GEOMETRY_BINDABLE_UNIFORMS_EXT), GLIF_MACRO(GL_MAX_BINDABLE_UNIFORM_SIZE_EXT)},
	 {},
	 {}},
	{"GL_EXT_geometry_shader4",
	 {
		 GLIF_MACRO(GL_MAX_VARYING_COMPONENTS_EXT),
		 GLIF_MACRO(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS_EXT),
		 GLIF_MACRO(GL_MAX_GEOMETRY_VARYING_COMPONENTS_EXT),
		 GLIF_MACRO(GL_MAX_VERTEX_VARYING_COMPONENTS_EXT),
		 GLIF_MACRO(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS_EXT),
		 GLIF_MACRO(GL_MAX_GEOMETRY_OUTPUT_VERTICES_EXT),
		 GLIF_MACRO(GL_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS_EXT),
	 },
	 {},
	 {}},
	{"GL_EXT_framebuffer_object",
	 {
		 GLIF_MACRO(GL_MAX_RENDERBUFFER_SIZE_EXT),
		 GLIF_MACRO(GL_MAX_COLOR_ATTACHMENTS_EXT),
	 },
	 {},
	 {}},
	{"GL_EXT_texture3D", {GLIF_MACRO(GL_MAX_3D_TEXTURE_SIZE_EXT)}, {}, {}},
	{"GL_NV_parameter_buffer_object",
	 {GLIF_MACRO(GL_MAX_PROGRAM_PARAMETER_BUFFER_BINDINGS_NV), GLIF_MACRO(GL_MAX_PROGRAM_PARAMETER_BUFFER_SIZE_NV)},
	 {},
	 {}},
	{"GL_ARB_texture_compression", {GLIF_MACRO(GL_NUM_COMPRESSED_TEXTURE_FORMATS_ARB)}, {}, {}},
	{"GL_ARB_vertex_attrib_binding",
	 {GLIF_MACRO(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET), GLIF_MACRO(GL_MAX_VERTEX_ATTRIB_BINDINGS)},
	 {},
	 {}},
	{"GL_ARB_texture_buffer_range", {GLIF_MACRO(GL_TEXTURE_BUFFER_OFFSET_ALIGNMENT)}, {}, {}},
	{"GL_ARB_vertex_program",
	 {
		 GLIF_MACRO(GL_MAX_PROGRAM_MATRIX_STACK_DEPTH_ARB),
		 GLIF_MACRO(GL_MAX_PROGRAM_MATRICES_ARB),
		 GLIF_MACRO(GL_MAX_VERTEX_ATTRIBS_ARB),
	 },
	 {},
	 {}},
	{"GL_NVX_gpu_memory_info",
	 {},
	 {
		 GLIF_MACRO(GL_GPU_MEMORY_INFO_DEDICATED_VIDMEM_NVX),
		 GLIF_MACRO(GL_GPU_MEMORY_INFO_TOTAL_AVAILABLE_MEMORY_NVX),
		 GLIF_MACRO(GL_GPU_MEMORY_INFO_CURRENT_AVAILABLE_VIDMEM_NVX),
		 GLIF_MACRO(GL_GPU_MEMORY_INFO_EVICTION_COUNT_NVX),
		 GLIF_MACRO(GL_GPU_MEMORY_INFO_EVICTED_MEMORY_NVX),
	 },
	 {}},
	{"GL_NV_conservative_raster",
	 {
		 GLIF_MACRO(GL_MAX_SUBPIXEL_PRECISION_BIAS_BITS_NV),
	 },
	 {},
	 {}},
	{"GL_NV_draw_buffers",
	 {
		 GLIF_MACRO(GL_MAX_DRAW_BUFFERS_NV),
	 },
	 {},
	 {}},
	{"GL_NV_evaluators",
	 {},
	 {},
	 {
		 GLIF_MACRO(GL_MAX_MAP_TESSELLATION_NV),
		 GLIF_MACRO(GL_MAX_RATIONAL_EVAL_ORDER_NV),
	 }},
	{"GL_NV_explicit_multisample",
	 {
		 GLIF_MACRO(GL_MAX_SAMPLE_MASK_WORDS_NV),
	 },
	 {},
	 {}},
	{"GL_NV_fbo_color_attachments",
	 {
		 GLIF_MACRO(GL_MAX_COLOR_ATTACHMENTS_NV),
	 },
	 {},
	 {}},
	{"GL_NV_fragment_program",
	 {
		 GLIF_MACRO(GL_MAX_FRAGMENT_PROGRAM_LOCAL_PARAMETERS_NV),
		 GLIF_MACRO(GL_MAX_TEXTURE_COORDS_NV),
		 GLIF_MACRO(GL_MAX_TEXTURE_IMAGE_UNITS_NV),
	 },
	 {},
	 {}},
	{"GL_NV_gpu_program4",
	 {
		 GLIF_MACRO(GL_MIN_PROGRAM_TEXEL_OFFSET_NV),
		 GLIF_MACRO(GL_MAX_PROGRAM_TEXEL_OFFSET_NV),
	 },
	 {},
	 {}},
	{"GL_NV_light_max_exponent",
	 {},
	 {},
	 {
		 GLIF_MACRO(GL_MAX_SHININESS_NV),
		 GLIF_MACRO(GL_MAX_SPOT_EXPONENT_NV),
	 }},
	{"GL_NV_shading_rate_image",
	 {
		 GLIF_MACRO(GL_SHADING_RATE_IMAGE_PALETTE_SIZE_NV),
		 GLIF_MACRO(GL_SHADING_RATE_IMAGE_TEXEL_WIDTH_NV),
		 GLIF_MACRO(GL_SHADING_RATE_IMAGE_TEXEL_HEIGHT_NV),
		 GLIF_MACRO(GL_MAX_COARSE_FRAGMENT_SAMPLES_NV),
	 },
	 {},
	 {}},
	{"GL_EXT_raster_multisample", {}, {GLIF_MACRO(GL_MAX_RASTER_SAMPLES_EXT)}, {}},
	{"GL_OVR_multiview", {}, {GLIF_MACRO(GL_MAX_VIEWS_OVR)}, {}},
	{"GL_KHR_debug",
	 {GLIF_MACRO(GL_MAX_DEBUG_GROUP_STACK_DEPTH), GLIF_MACRO(GL_MAX_LABEL_LENGTH),
	  GLIF_MACRO(GL_MAX_DEBUG_MESSAGE_LENGTH), GLIF_MACRO(GL_MAX_DEBUG_LOGGED_MESSAGES)},
	 {},
	 {}},
	{"GL_KHR_shader_subgroup",
	 {},
	 {
		 GLIF_MACRO(GL_SUBGROUP_SIZE_KHR),
		 GLIF_MACRO(GL_SUBGROUP_SUPPORTED_STAGES_KHR),
		 GLIF_MACRO(GL_SUBGROUP_SUPPORTED_FEATURES_KHR),
		 GLIF_MACRO(GL_SUBGROUP_QUAD_ALL_STAGES_KHR),
	 },
	 {}},
	{"GL_ARB_sync", {}, {GLIF_MACRO(GL_MAX_SERVER_WAIT_TIMEOUT)}, {}},
	{"GL_NV_viewport_array", {}, {GLIF_MACRO(GL_MAX_VIEWPORTS_NV)}, {}},
	{"GL_NV_viewport_array", {}, {GLIF_MACRO(GL_MAX_SAMPLES_NV)}, {}},

	{"GL_SGIX_async_histogram", {}, {GLIF_MACRO(GL_MAX_ASYNC_HISTOGRAM_SGIX)}, {}},
	{"GL_ARB_polygon_offset_clamp", {}, {}, {GLIF_MACRO(GL_POLYGON_OFFSET_CLAMP)}},
	{"GL_PGI_vertex_hints",
	 {},
	 {
		 GLIF_MACRO(GL_MAX_VERTEX_HINT_PGI),
		 GLIF_MACRO(GL_MAX_RED_SGIS),
		 GLIF_MACRO(GL_MAX_GREEN_SGIS),
		 GLIF_MACRO(GL_MAX_BLUE_SGIS),
		 GLIF_MACRO(GL_MAX_ALPHA_SGIS),
		 GLIF_MACRO(GL_MAX_TEXTURES_SGIS),
		 GLIF_MACRO(GL_MAX_TEXTURE_COORD_SETS_SGIS),
		 GLIF_MACRO(GL_MAX_ASYNC_HISTOGRAM_SGIX),
		 GLIF_MACRO(GL_MAX_ASYNC_TEX_IMAGE_SGIX),
		 GLIF_MACRO(GL_MAX_ASYNC_DRAW_PIXELS_SGIX),
		 GLIF_MACRO(GL_MAX_ASYNC_READ_PIXELS_SGIX),
		 GLIF_MACRO(GL_MAX_FOG_LAYERS_POINTS_SGIX),
		 GLIF_MACRO(GL_MAX_MIPMAP_ANISOTROPY_SGIX),
		 GLIF_MACRO(GL_MAX_LUMINANCE_SGIS),
		 GLIF_MACRO(GL_MAX_INTENSITY_SGIS),
		 GLIF_MACRO(GL_MAX_COLOR_MATRIX_STACK_DEPTH_SGI),
		 GLIF_MACRO(GL_MAX_FFT_WIDTH_SGI),
	 },
	 {}},

};

int main(int argc, char **argv) {

	try {
		readargument(argc, argv);

		Ref<GLRendererInterface> glRenderInterface = Ref<GLRendererInterface>(new GLRendererInterface(nullptr));
		glRenderInterface->setDebug(false);

		/*	Display information.	*/
		std::cout << "RENDERER: " << glGetString(GL_RENDERER) << std::endl;
		std::cout << "VENDOR: " << glGetString(GL_VENDOR) << std::endl;
		std::cout << "VERSION: " << glGetString(GL_VERSION) << std::endl;
		std::cout << "SHADING_LANGUAGE_VERSION: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
		std::cout << std::endl;

		/*	*/
		for (size_t i = 0; i < extensionList.size(); i++) {
			const ExtensionEntry &extension = extensionList[i];

			// Check if supported
			if (glewIsExtensionSupported(extension.name.c_str())) {

				/*	*/
				std::cout << extension.name << std::endl;

				for (auto it = extension.Int32.cbegin(); it != extension.Int32.cend(); it++) {
					const std::string &attributeName = (*it).first;
					const size_t nrParams = (*it).second.nrValues;
					GLenum enumV = (*it).second.capability;
					GLint Integervtmp = 0;

					/*	*/
					std::cout << "\t" << attributeName << " : ";

					if (nrParams > 1) {
						for (size_t i = 0; i < nrParams; i++) {
							glGetIntegeri_v(enumV, i, &Integervtmp);
							std::cout << Integervtmp;
							if (i < nrParams - 1) {
								std::cout << ",";
							}
						}
						std::cout << std::endl;
					} else {
						glGetIntegerv(enumV, &Integervtmp);
						std::cout << Integervtmp << std::endl;
					}
				}

				for (auto it = extension.Int64.cbegin(); it != extension.Int64.cend(); it++) {
					const std::string &attributeName = (*it).first;
					GLenum enumV = (*it).second.capability;
					GLint64 Integervtmp = 0;
					glGetInteger64v(enumV, &Integervtmp);
					std::cout << "\t" << attributeName << " : " << Integervtmp << std::endl;
				}
				for (auto it = extension.Float.cbegin(); it != extension.Float.cend(); it++) {
					const std::string &attributeName = (*it).first;
					GLenum enumV = (*it).second.capability;
					GLfloat Integervtmp = 0;
					glGetFloatv(enumV, &Integervtmp);
					std::cout << "\t" << attributeName << " : " << Integervtmp << std::endl;
				}
				std::cout << std::endl;
			} else {
				std::cout << extension.name << " : Not supported" << std::endl << std::endl;
			}
		}

		GLint NumCompressedTexture;
		glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &NumCompressedTexture);
		std::cout << std::endl
				  << "Number of Supported Compression Formats: " << NumCompressedTexture << std::endl
				  << std::endl;

		std::cout << "OpenGL Compressed Format GLenum Values:" << std::endl;
		std::vector<GLint> formats(NumCompressedTexture);
		glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, formats.data());
		for (GLint format : formats) {
			std::cout << std::hex << format << ", ";
		}
		std::cout << std::endl << std::endl;

		auto append_extension_if_supported = [](const char *extension, std::vector<std::string> &list) {
			if (glewIsExtensionSupported(extension)) {
				list.push_back(extension);
			}
		};

		auto check_extention_and_print = [&append_extension_if_supported](const char *compressionFamilyName,
																		  const std::vector<const char *> familyList) {
			std::vector<std::string> compression_supported_list;
			for (const char *ext : familyList) {
				append_extension_if_supported(ext, compression_supported_list);
			}

			const char *tab = "\t\t\t";
			std::cout << compressionFamilyName << ": " << (compression_supported_list.size() > 0 ? "Yes" : "No") << std::endl;
			for (std::string &ext : compression_supported_list) {
				std::cout << tab << ext << std::endl;
			}
			std::cout << std::endl;
		};

		const std::vector<const char *> dxt1Family = {"GL_ANGLE_texture_compression_dxt1",
													  "GL_ANGLE_texture_compression_dxt3",
													  "GL_ANGLE_texture_compression_dxt5",
													  "GL_EXT_texture_compression_dxt1",
													  "GL_EXT_texture_compression_s3tc",
													  "GL_COMPRESSED_SRGB_S3TC_DXT1_EXT",
													  "GL_EXT_texture_sRGB",
													  "GL_NV_sRGB_formats",
													  "GL_NV_texture_compression_s3tc"};

		const std::vector<const char *> dxt3Family = {
			"GL_ANGLE_texture_compression_dxt1",
			"GL_ANGLE_texture_compression_dxt3",
			"GL_ANGLE_texture_compression_dxt5",
			"GL_EXT_texture_compression_s3tc",
			"GL_EXT_texture_compression_s3tc_srgb",
			"GL_EXT_texture_sRGB",
			"GL_NV_sRGB_formats",
			"GL_NV_texture_compression_s3tc",

		};

		const std::vector<const char *> dxt5Family = {"GL_ANGLE_texture_compression_dxt1",
													  "GL_ANGLE_texture_compression_dxt3",
													  "GL_ANGLE_texture_compression_dxt5",
													  "GL_EXT_texture_compression_s3tc",
													  "GL_EXT_texture_compression_s3tc_srgb",
													  "GL_EXT_texture_sRGB",
													  "GL_NV_sRGB_formats",
													  "GL_NV_texture_compression_s3tc",
													  "GL_S3_s3tc"};

		const std::vector<const char *> bc4Family = {"GL_ARB_texture_compression_rgtc",
													 "GL_EXT_texture_compression_rgtc"};

		const std::vector<const char *> bc5Family = {
			"GL_ATI_texture_compression_3dc", "GL_ARB_texture_compression_rgtc", "GL_EXT_texture_compression_rgtc"};

		const std::vector<const char *> bptcFamily = {"GL_ARB_texture_compression_bptc",
													  "GL_EXT_texture_compression_bptc"};

		const std::vector<const char *> etc1Family = {
			"GL_EXT_compressed_ETC1_RGB8_sub_texture",
			"GL_ETC1_SRGB8_NV",
			"GL_OES_compressed_ETC1_RGB8_texture",
		};
		const std::vector<const char *> etc2Family = {"GL_ARB_ES3_compatibility"};
		const std::vector<const char *> astcFamily = {
			"GL_EXT_texture_compression_astc_decode_mode", "GL_EXT_texture_compression_astc_decode_mode_rgb9e5",
			"GL_KHR_texture_compression_astc_hdr",		   "GL_KHR_texture_compression_astc_ldr",
			"GL_KHR_texture_compression_astc_sliced_3d",   "GL_OES_texture_compression_astc"};

		const std::vector<const char *> pvrtFamily = {"GL_EXT_pvrtc_sRGB", "GL_IMG_texture_compression_pvrtc2"};
		const std::vector<const char *> fxt1Family = {"GL_3DFX_texture_compression_FXT1"};

		check_extention_and_print("DXT1 (BC1)", dxt1Family);
		check_extention_and_print("DXT3 (BC2)", dxt3Family);
		check_extention_and_print("DXT5 (BC3)", dxt5Family);
		check_extention_and_print("BC4", bc4Family);
		check_extention_and_print("BC5", bc5Family);
		check_extention_and_print("BPTC (BC7)", bptcFamily);
		check_extention_and_print("ETC1", etc1Family);
		check_extention_and_print("ETC2", etc2Family);
		check_extention_and_print("ASTC", astcFamily);
		check_extention_and_print("PVRTC", pvrtFamily);
		check_extention_and_print("FXT1", fxt1Family);

		// LATC
		//  VTC
		//  GL_EXT_texture_storage_compression

		GLint nrExtensions;
		glGetIntegerv(GL_NUM_EXTENSIONS, &nrExtensions);

		std::cout << std::endl << "Device Extensions: " << std::dec << nrExtensions << std::endl;
		for (GLint i = 0; i < nrExtensions; i++) {

			std::cout << "\t" << glGetStringi(GL_EXTENSIONS, i) << std::endl;
		}

	} catch (const std::exception &ex) {
		std::cerr << cxxexcept::getStackMessage(ex) << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
