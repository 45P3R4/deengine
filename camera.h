float rotation_x = 45;
float rotation_y = 0;
float rotation_z = 0;

float position_x = 0;
float position_y = -2;
float position_z = 2;

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