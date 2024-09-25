cmake_minimum_required(VERSION 3.11...3.25)

include(FetchContent)

add_executable(App main.cpp)

project(
		WEBGPU-CPP
    VERSION 0.1.0 
		LANGUAGES CXX C
	)

set_target_properties(App PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR ON
)

# Windows
if (MSVC)
    target_compile_options(App PRIVATE /W4)
else()
    target_compile_options(App PRIVATE -Wall -Wextra -pedantic)
endif()

# MacOS
if (XCODE)
    set_target_properties(App PROPERTIES
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ENABLE_GPU_FRAME_CAPTURE_MODE "Metal"
    )
endif()

# WebGPU
FetchContent_Declare(
  webgpu
  GIT_REPOSITORY https://github.com/eliemichel/WebGPU-distribution.git
  GIT_TAG dawn
)

# Link Librarys
target_link_libraries(App PRIVATE webgpu glfw)
target_copy_webgpu_binaries(App)
