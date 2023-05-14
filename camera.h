float rotation_x = 45;
float rotation_y = 0;
float rotation_z = 0;

float position_x = 0;
float position_y = -2;
float position_z = 2;

float turn_speed = 0.2;
float move_speed = 0.05;

void move_camera()
{
    if(key_up) rotation_x = ++rotation_x > 180 ? 180 : rotation_x;
    if(key_down) rotation_x = --rotation_x < 0 ? 0 : rotation_x;
    if(key_left) rotation_z = ++rotation_z;
    if(key_right) rotation_z = --rotation_z;
     
    if(mouse_right){
        rotation_z = -drag_x * turn_speed + rotation_z;
        rotation_x = -drag_y * turn_speed + rotation_x;
        if(rotation_x > 180)
            rotation_x = 180;
        if(rotation_x < 0)
            rotation_x = 0;
        std::cout << rotation_x << "\n";
    } 

    float angle = -rotation_z / 180 * M_PI;
    float turn_speed = 0;
    if(key_w) turn_speed = move_speed;
    if(key_s) turn_speed = -move_speed;
    if(key_a) {turn_speed = move_speed; angle -= M_PI*0.5;}
    if(key_d) {turn_speed = move_speed; angle += M_PI*0.5;}
    if(turn_speed != 0){
        position_x += sin(angle) * turn_speed;
        position_y += cos(angle) * turn_speed;
    }
    if(key_r) position_z += move_speed;
    if(key_f) position_z -= move_speed;

    glRotatef(-rotation_x,1,0,0);
    glRotatef(-rotation_z, 0,0,1);
    glTranslatef(-position_x, -position_y, -position_z);
}