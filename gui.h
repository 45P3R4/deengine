typedef struct{
    char name[16];
    float vert[8];
    bool pressed;
} TButton;

TButton test_button = {"Test", {0,0, 30,0, 30,30, 0,30}, false};

void draw_TButton(TButton b)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    if(b.pressed)
        glColor3f(0.6,0.8,1);
    else
        glColor3f(0,0,0);
    glVertexPointer(2, GL_FLOAT, 0, b.vert);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void draw_gui()
{
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,w,h,0, -1,1); //окно теперь совпадает с координатами окна
    draw_TButton(test_button);
    glPopMatrix();
}

bool in_button(int x, int y, TButton button)
{
    return (x > button.vert[0]) && (x < button.vert[4]) &&
           (y > button.vert[1]) && (y < button.vert[5]);
}