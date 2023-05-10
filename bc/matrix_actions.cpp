#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

float scale = 1;
bool mouse_left = false;

float m_x = 0;
float m_y = 0;
float translation_x = 0;
float translation_y = 0;

void draw_axis()
{
    glLineWidth(3);
    glBegin(GL_LINES);
        glColor3f(1,0,0);
            glVertex3f(0,0,0);
            glVertex3f(1,0,0);

        glColor3f(0,1,0);
            glVertex3f(0,0,0);
            glVertex3f(0,1,0);

        glColor3f(0,0,1);
            glVertex3f(0,0,0);
            glVertex3f(0,0,1);
    glEnd(); 
    glLineWidth(1);
}

void draw_grid()
{
    for(int i = 0; i < 100; i++)
    {
        glPushMatrix();
        glTranslatef(-1,0,0);
        glColor3f(0.3,0.3,0.3);
        glBegin(GL_LINES);
            glVertex2f((i-50), 100);
            glVertex2f((i-50), -100);
        glEnd();
        glPopMatrix();
    }
    for(int i = 0; i < 100; i++)
    {
        glPushMatrix();
        glTranslatef(0,-1,0);
        glBegin(GL_LINES);
            glVertex2f(100, i-50);
            glVertex2f(-100, i-50);
        glEnd();
        glPopMatrix();
    }
}

void origin_scale(float scale)
{
    glScalef(scale, scale, scale); 
}

void origin_translate(float x, float y)
{
    glTranslatef(x, y, 1);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

int main()
{
    float points_x[100][100];
    glfwInit();
    
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL", NULL, NULL);

    glfwSetKeyCallback(window, key_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    
    glfwMakeContextCurrent(window);  

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glLineWidth(3);
        glBegin(GL_LINE_STRIP);
        glColor3f(0.7,0.4,0.0);
        
        for (float i = -100; i < 100; i+=0.1)
        {
            glVertex2f(i, sin(i));
        }
        glEnd();

        draw_axis();
        draw_grid();
        glFlush();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(key == GLFW_KEY_U && action == GLFW_PRESS)
        glPushMatrix();
    if(key == GLFW_KEY_O && action == GLFW_PRESS)
        glPopMatrix();
    if(key == GLFW_KEY_I && action == GLFW_PRESS)
        glLoadIdentity();

    if(key == GLFW_KEY_T && action == GLFW_PRESS)
        glTranslatef(0.1,0.1,1);
    if(key == GLFW_KEY_R && action == GLFW_PRESS)
        glRotatef(10, 0,0,1);
    if(key == GLFW_KEY_S && action == GLFW_PRESS)
        glScalef(0.7,0.7,0.7);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    (yoffset > 0) ? scale += 0.05 : scale -= 0.05;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        mouse_left = true;
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        mouse_left = false;
}