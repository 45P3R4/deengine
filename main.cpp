#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#include "draw_primitives.h"
#include "window.h"
#include "gui.h"
#include "input.h"
#include "camera.h"

const unsigned int SCR_WIDTH = 512;
const unsigned int SCR_HEIGHT = 512;


void draw_world()
{
    draw_axis();
    draw_plane();
    draw_pyramid();
}

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(w, h, "Deengine", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);

    glEnable(GL_DEPTH_TEST);

    glFrustum(-1,1, -1,1, 2,200);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(buffer_color[0], buffer_color[1], buffer_color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
            move_camera();
            draw_world();
            draw_gui();
        glPopMatrix();

        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

