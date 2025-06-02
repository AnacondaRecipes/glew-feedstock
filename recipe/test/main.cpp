#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Test GLEW headers and constants
    printf("GLEW_OK = %d\n", GLEW_OK);
    
    // Set experimental mode as recommended
    glewExperimental = GL_TRUE;
    
    // Try to initialize GLEW
    GLenum err = glewInit();
    if (GLEW_OK != err) {
        printf("glewInit failed: %s\n", glewGetErrorString(err));
    } else {
        printf("glewInit succeeded: GLEW %s\n", glewGetString(GLEW_VERSION));
    }
    
    // Test error handling function
    glewGetErrorString(GLEW_OK);
    
    printf("GLEW test completed\n");
    return 0;
} 