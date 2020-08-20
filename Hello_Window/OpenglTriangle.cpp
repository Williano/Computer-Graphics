#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

// Function prototypes

	/* Callback function to resize window when main changes */
void framebufferSizeCallback(GLFWwindow* window, int width, int height);


// Settings
const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

int main() {


	
	// Initialize glfw
	if (!glfwInit()) 
	{
		return -1;
	}
	
	// Setup glfw
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Create a window for rendering
	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "LeanOpenGL", NULL, NULL);
	
	if (window == NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

	//  glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// Setup the size of the window
	glViewport(0, 0, 800, 600);



	// Render to the window as long as the 
	while (!glfwWindowShouldClose(window)) {
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	

	// Delete all GLFW allocated resources when program is closed.
	glfwTerminate();
	

	return 0;
}

void framebufferSizeCallback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}