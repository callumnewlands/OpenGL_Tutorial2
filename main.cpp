#include "main.h"

int main()
{
	// Initilise GLFW with OpenGL version 3.3 core
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a window
	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "windowTitle", NULL, NULL);
	if (window == NULL) 
	{
		std::cout << "ERROR creating window";
		glfwTerminate();
		return -1; 
	}
	glfwMakeContextCurrent(window);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(window, onWindowResize); // Set window resize callback

	// Initialise GLEW
	// Has to be called after window is created
	GLenum errorCode = glewInit();
	if (errorCode != GLEW_OK)
	{
		std::cout << "ERROR initialising GLEW";
		glfwTerminate();
		return -1;
	}

	// Main render loop
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Exit OpenGL
	glfwTerminate();
	return 0;
}

void onWindowResize(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}