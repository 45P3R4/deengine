class element{
    public:
    
    char name[32];
    float height;
    float width;
    bool hover;
  
    bool is_hover(int x, int y){
        return (x > vert[0]) && (x < vert[4]) && 
               (y > vert[1]) && (y < vert[5]);
    }

    void draw_element(){
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(2, GL_FLOAT, 0, vert);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
        glDisableClientState(GL_VERTEX_ARRAY);
    }
    
    element(){
        const char *name = "unnamed\0";
        hover = false;

        vert[0] = 0;    vert[1] = 0;
        vert[2] = 0;    vert[3] = 30;
        vert[4] = 30;   vert[5] = 30;
        vert[6] = 30;   vert[7] = 0;
    }
    element(float w, float h, float pos_w, float pos_h){
        vert[0] = pos_w;        vert[1] = pos_h;
        vert[2] = pos_w;        vert[3] = h + pos_h;
        vert[4] = w + pos_w;    vert[5] = h + pos_h;
        vert[6] = w + pos_w;    vert[7] = pos_h;
    }

    ~element(){}

    private:
    float vert[8];
};

element test_panel(screen_width,30,0,screen_height - 30);
element box_e(30,30,screen_width-30, 0);

void draw_gui()
{
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,screen_width, screen_height,0, -1,1); //left-top = 0
    glColor3f(0,0,0);
    box_e.draw_element();
    test_panel.draw_element();
    glPopMatrix();
}