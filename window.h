int w = 512;
int h = 512;

float buffer_color[3] = {0.6,0.8,1};

void window_size_callback(GLFWwindow* window, int width, int height)
{
    glfwGetWindowSize(window, &w, &h);
    glViewport(0,0, w, h);
    glLoadIdentity();
    float aspect = (float)w / (float)h;
    glFrustum(-aspect, aspect, -1,1, 2,200);
}