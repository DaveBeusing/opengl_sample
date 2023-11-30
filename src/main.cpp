#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

using namespace std; 

void framebuffer_size_callback( GLFWwindow* window, int width, int height ){
    glViewport( 0, 0, width, height );
}


void myKeyCallback( GLFWwindow* window, int key, int scancode, int action, int mods ){

    if( key == GLFW_KEY_E && action == GLFW_PRESS ){
        printf("You pressed the e key!\n");
    }

}

int main(){

    if( !glfwInit() ){
        cout << "Failed to initialize GLFW" << endl;
        return -1;
    }

    glfwWindowHint( GLFW_SAMPLES, 4 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );

    const int windowWidth = 1280;
    const int windowHeight = 720;
    const char* windowTitle = "GLFW GLAD OpenGL Sample";

    GLFWwindow* window; 
    window = glfwCreateWindow( 
        windowWidth,
        windowHeight,
        windowTitle,
        NULL, 
        NULL 
    );

    if( window == NULL ){
        cout << "Failed to open GLFW window" << endl;
        return -1;
    }
    glfwMakeContextCurrent( window );

    if( !gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) ){
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }

    //Register Key Callback -> glfwPollEvents
    glfwSetKeyCallback( window, myKeyCallback);

    glViewport( 0, 0, windowWidth, windowHeight );

    glfwSetFramebufferSizeCallback( window, framebuffer_size_callback );

    while( !glfwWindowShouldClose(window) ){

        //Clear the screen
        glClearColor( 250.0f / 255.0f, 119.0f / 255.0f, 110.0f / 255.0f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT );

        glfwSwapBuffers(window);
        glfwPollEvents();    
    }

    glfwTerminate();
    return 0;
}