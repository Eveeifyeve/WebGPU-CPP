#include <iostream>
#include <webgpu/webgpu.h>
#include <GLFW/glfw3.h>
#include "glfw3webgpu.h"


int main (int, char**) {
	WGPUInstanceDescriptor desc = {};
	desc.nextInChain = nullptr;

	WGPUInstance instance = wgpuCreateInstance(&desc);

	if (!instance) {
		std::cerr << "Could not initalize WebGpu" << std::endl;
		return 1;
	}

	glfwInit();
	
	if (!glfwInit()) {
		std::cerr <<  "Could not initalize Glfw" << std::endl;
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 640, "WebGPU", nullptr, nullptr);


	if (!window) {
    std::cerr << "Could not open window!" << std::endl;
    glfwTerminate();
    return 1;
	}

	WGPUSurface surface = glfwGetWGPUSurface(instance, window);
	
	WGPUSurfaceConfiguration config = {};
	config.nextInChain = nullptr;

	config.width = 640;
	config.height = 480;

	wgpuSurfaceConfigure(surface, &config);

  while (!glfwWindowShouldClose(window)) glfwPollEvents();
	wgpuSurfaceRelease(surface);
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}
