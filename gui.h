typedef struct
{
   float vert[8];
   unsigned char state;
} gui_element;

bool is_hover(int x, int y, gui_element* element){
    return (x > element->vert[0]) && (x < element->vert[4]) && 
           (y >  element->vert[1]) && (y <  element->vert[5]);
}

gui_element create_element(float width, float height, float pos_x, float pos_y)
{
    gui_element box;
    box.vert[0] = pos_x;             box.vert[1] = pos_y;
    box.vert[2] = pos_x;             box.vert[3] = height + pos_y;
    box.vert[4] = width + pos_x;     box.vert[5] = height + pos_y;
    box. vert[6] = width + pos_x;    box.vert[7] = pos_y;
    return box;
}

void draw_element(gui_element* element){
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 0, element->vert);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

gui_element bottom_panel;

void gui_init()
{
    bottom_panel = create_element(screen_width,30,0,screen_height-30);
}

void draw_gui()
{
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,screen_width, screen_height,0, -1,1);
    glColor3f(0,0,0);
    draw_element(&bottom_panel);
    glPopMatrix();
}