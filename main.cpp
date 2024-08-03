#include "Window.h"
#include "Vulkan.h"

int main() {

	Window window;
	window.run();
	Vulkan vulkan(window.get());


	return 0;
}