#include <text_output.h>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// function prototypes
void key_callback( GLFWwindow* window, int key, int scancode, int action, int mode );

bool initGLFW();
bool initGLEW();

GLFWwindow * createWindow();
int init3D();

