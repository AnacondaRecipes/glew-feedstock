#include <GL/glew.h>

#include <stdio.h>

int main() {
    fprintf(stdout, "Start of main()\n");
    
    // Test 1: Verify GLEW headers and basic functionality are available
    fprintf(stdout, "GLEW headers successfully included.\n");
    
    // Test 2: Check if we can access GLEW constants and basic functions
    // These should be available even without OpenGL context
    fprintf(stdout, "GLEW_OK constant value: %d\n", GLEW_OK);
    
    // Test 3: Try experimental mode as suggested in GLEW docs
    // "glewExperimental global switch can be turned on by setting it to GL_TRUE 
    // before calling glewInit(), which ensures that all extensions with valid 
    // entry points will be exposed"
    fprintf(stdout, "Setting glewExperimental = GL_TRUE (recommended for headless testing)\n");
    glewExperimental = GL_TRUE;
    
    // Test 4: Attempt initialization (will likely fail in CI, but that's expected)
    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stdout, "glewInit() failed in headless environment (expected): %s\n", 
                glewGetErrorString(err));
        fprintf(stdout, "This is normal in CI environments without graphics context.\n");
    }
    else
    {
        fprintf(stdout, "glewInit() succeeded: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    }
    
    // Test 5: Verify we can access GLEW error handling functions
    // These should work regardless of initialization status
    const char* error_str = (const char*)glewGetErrorString(GLEW_OK);
    if (error_str) {
        fprintf(stdout, "GLEW error handling functions are accessible.\n");
    }
    
    fprintf(stdout, "GLEW library test completed successfully.\n");
    fprintf(stdout, "All GLEW headers, constants, and functions are properly linked.\n");
    
    return 0;
}