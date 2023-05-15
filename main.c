#include <GLFW/glfw3.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "draw_primitives.h"
#include "window.h"
#include "gui.h"
#include "input.h"
#include "camera.h"
#include "window_callback.h"
#include "model_obj.h"

const unsigned int SCR_WIDTH = 512;
const unsigned int SCR_HEIGHT = 512;

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(screen_width, screen_height, "Deengine", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    glfwSetKeyCallback(window, key_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetWindowSizeCallback(window, window_size_callback);

    gui_init();

    glEnable(GL_DEPTH_TEST);

    glFrustum(-1,1, -1,1, 1,100);

    open_obj("models\\robo.obj");
    // for (int i = 0; i < obj_v_count; i++)
    // {
    //     printf("%u %g\n",i, obj_vert[i]);
    // }

    
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(buffer_color[0], buffer_color[1], buffer_color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        glPointSize(2);
            move_camera();
            
            draw_gui();
            draw_axis();
            draw_plane();

            glColor3f(1,1,0);

            glVertexPointer(3, GL_FLOAT, 0, &obj_vert[0]);
            glEnableClientState(GL_VERTEX_ARRAY);
            glColor3f(1,1,1);
                glDrawArrays(GL_POINTS, 0, obj_v_count/3);
            glDisableClientState(GL_VERTEX_ARRAY);

            // glBegin(GL_TRIANGLE_FAN);
            //     glVertex3f(obj_vert[0],obj_vert[1],obj_vert[2]);
            //     glVertex3f(obj_vert[3],obj_vert[4],obj_vert[5]);
            //     glVertex3f(obj_vert[6],obj_vert[7],obj_vert[8]);
            //     glVertex3f(obj_vert[9],obj_vert[10],obj_vert[11]);
            //     glVertex3f(obj_vert[12],obj_vert[13],obj_vert[14]);
            //     glVertex3f(obj_vert[15],obj_vert[16],obj_vert[17]);
            //     glVertex3f(obj_vert[18],obj_vert[19],obj_vert[20]);
            //     glVertex3f(obj_vert[21],obj_vert[22],obj_vert[23]);
            // glEnd();

        glPopMatrix();

        //glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free(obj_vert);
    obj_vert = NULL;
    glfwTerminate();
    return 0;
}

