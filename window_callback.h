void window_size_callback(GLFWwindow* window, int width, int height)
{
    glfwGetWindowSize(window, &screen_width, &screen_height);
    glViewport(0,0, screen_width, height);
    glLoadIdentity();
    aspect = (float)screen_width / (float)height;
    gui_init();
    glFrustum(-aspect, aspect, -1,1, 2,200);
}