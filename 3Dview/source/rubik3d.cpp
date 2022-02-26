#include <rubik3d.h>


// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;

bool initGLFW()
{
  if ( 0 != glfwInit() )
  {
    clog( "failed to initialize GLFW" );
    return false;
  }
  // Set all the required options for GLFW
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
  return true;
}

bool initGLEW()
{
  // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
  glewExperimental = GL_TRUE;
  // Initialize GLEW to setup the OpenGL Function pointers
  if (glewInit() != GLEW_OK)
  {
    clog( "Failed to initialize GLEW" );
    return false;
  }
  return true;
}

GLFWwindow * createWindow()
{
  GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
  if ( nullptr == window )
  {
    clog( "Failed to create GLFW window" );
    glfwTerminate();
    return nullptr;
  }

  // Create a GLFWwindow object that we can use for GLFW's functions
  glfwMakeContextCurrent( window );

  return window;
}

void setViewport( GLFWwindow * window )
{
  // Define the viewport dimensions
  int width, height;
  glfwGetFramebufferSize( window, &width, &height );
  glViewport(0, 0, width, height);
}

// The MAIN function, from here we start the application and run the game loop
int init3D()
{
  if ( false == initGLFW() )
  {
    return -1;
  }

  if ( false == initGLEW() )
  {
    return -2;
  }

  auto window = createWindow();
  if ( nullptr == window )
  {
    return -3;
  }

  // Set the required callback functions
  glfwSetKeyCallback( window, key_callback );

  setViewport( window );
  // Game loop
  while ( ! glfwWindowShouldClose( window ) )
  {
    // Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
    glfwPollEvents();

    // Render
    // Clear the colorbuffer
    glClearColor( 0.2f, 0.3f, 0.3f, 1.0f );
    glClear( GL_COLOR_BUFFER_BIT );

    // Swap the screen buffers
    glfwSwapBuffers( window );
  }

  // Terminate GLFW, clearing any resources allocated by GLFW.
  glfwTerminate();
  return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GL_TRUE);
}
