#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include <windows.h>

#include "draw_primitives.h"
#include "window.h"
#include "gui.h"
#include "input.h"

const unsigned int SCR_WIDTH = 512;
const unsigned int SCR_HEIGHT = 512;

float rotation_x = 0;
float rotation_y = 0;
float rotation_z = 0;

float position_x = 0;
float position_y = 0;
float position_z = 0;

void draw_world()
{
    draw_axis();
    draw_plane();
    draw_pyramid();
}

void move_camera()
{
    if(key_up) rotation_x = ++rotation_x > 180 ? 180 : rotation_x;
    if(key_down) rotation_x = --rotation_x < 0 ? 0 : rotation_x;
    if(key_left) rotation_z = ++rotation_z;
    if(key_right) rotation_z = --rotation_z;

    float angle = -rotation_z / 180 * M_PI;
    float speed = 0;
    if(key_w) speed = 0.1;
    if(key_s) speed = -0.1;
    if(key_a) {speed = 0.1; angle -= M_PI*0.5;}
    if(key_d) {speed = 0.1; angle += M_PI*0.5;}
    if(speed != 0){
        position_x += sin(angle) * speed;
        position_y += cos(angle) * speed;
    }
    if(key_r) position_z += 0.1;
    if(key_f) position_z -= 0.1;

    glRotatef(-rotation_x,1,0,0);
    glRotatef(-rotation_z, 0,0,1);
    glTranslatef(-position_x, -position_y, -position_z);
}

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(w, h, "OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

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

