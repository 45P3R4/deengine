#include <GLFW/glfw3.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

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

    open_obj(path);

    
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(buffer_color[0], buffer_color[1], buffer_color[2], 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glPushMatrix();
        glPointSize(2);
            move_camera();
            
            draw_gui();
            //draw_axis();

            glColor3f(1,1,0);

            glVertexPointer(3, GL_FLOAT, 0, &obj_vert[0]);
            glEnableClientState(GL_VERTEX_ARRAY);
                glColor3f(1,1,1);
                glDrawArrays(GL_POINTS, 0, obj_v_count/3);
                // glColor3f(0.9,0.9,0.9);
                // glDrawArrays(GL_LINE_LOOP, 0, obj_v_count/3);
                glColor3f(0.8,0.8,0.8);
                // glDrawArrays(GL_TRIANGLE_FAN, 0, obj_v_count/3);
                glDrawElements(GL_LINE_STRIP, obj_f_count/3, GL_UNSIGNED_INT, &obj_face_v[0]);
            glDisableClientState(GL_VERTEX_ARRAY);

        glPopMatrix();

        glFlush();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free(obj_vert);
    obj_vert = NULL;
    glfwTerminate();
    return 0;
}

