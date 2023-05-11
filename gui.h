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
    element(float w, float h){
        vert[0] = 0;    vert[1] = 0;
        vert[2] = 0;    vert[3] = h;
        vert[4] = w;    vert[5] = h;
        vert[6] = w;    vert[7] = 0;
    }

    ~element(){}

    private:
    float vert[8];
};

element test_panel;

void draw_gui()
{
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0,w,h,0, -1,1); //окно теперь совпадает с координатами окна
    glColor3f(1,1,1);
    test_panel.draw_element();
    glPopMatrix();
}