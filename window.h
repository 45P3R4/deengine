int screen_width = 512;
int screen_height = 512;

short framerate = 144;

float buffer_color[3] = {0.6,0.8,1};

void window_size_callback(GLFWwindow* window, int width, int height)
{
    glfwGetWindowSize(window, &screen_width, &height);
    glViewport(0,0, screen_width, height);
    glLoadIdentity();
    float aspect = (float)screen_width / (float)height;
    glFrustum(-aspect, aspect, -1,1, 2,200);
}