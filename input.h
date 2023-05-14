float mouse_x = 0;
float mouse_y = 0;
float scroll_y = 0;

float drag_x = 0;
float drag_y = 0;

bool mouse_left = false;
bool key_up = false;
bool key_down = false;
bool key_left = false;
bool key_right = false;

bool key_w = false;
bool key_a = false;
bool key_s = false;
bool key_d = false;

bool key_r = false;
bool key_f = false;

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    scroll_y = yoffset;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        mouse_left = true;
    }
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE){
        mouse_left = false;
    }
}

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    if(mouse_left){
        drag_x = (xpos - mouse_x);
        drag_y = (ypos - mouse_y);
    }

    mouse_x = xpos;
    mouse_y = ypos;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action == GLFW_PRESS){
        if(key == GLFW_KEY_UP)
            key_up = true;
        if(key == GLFW_KEY_DOWN)
            key_down = true;

        if(key == GLFW_KEY_LEFT)
            key_left = true;
        if(key == GLFW_KEY_RIGHT)
            key_right = true;

        if(key == GLFW_KEY_W)
            key_w = true;
        if(key == GLFW_KEY_S)
            key_s = true;

        if(key == GLFW_KEY_A)
            key_a = true;
        if(key == GLFW_KEY_D)
            key_d = true;

        if(key == GLFW_KEY_R)
            key_r = true;
        if(key == GLFW_KEY_F)
            key_f = true;
    }
    if(action == GLFW_RELEASE){
        if(key == GLFW_KEY_UP)
            key_up = false;
        if(key == GLFW_KEY_DOWN)
            key_down = false;

        if(key == GLFW_KEY_LEFT)
            key_left = false;
        if(key == GLFW_KEY_RIGHT)
            key_right = false;

        if(key == GLFW_KEY_W)
            key_w = false;
        if(key == GLFW_KEY_S)
            key_s = false;

        if(key == GLFW_KEY_A)
            key_a = false;
        if(key == GLFW_KEY_D)
            key_d = false;
        
        if(key == GLFW_KEY_R)
            key_r = false;
        if(key == GLFW_KEY_F)
            key_f = false;
    }
}