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

void draw_plane()
{
    const GLfloat vert[] = {
        -1,-1,0, 
        -1,1,0,
        1,1,0,
        1,-1,0};
    glColor3f(0.7,0.7,0.7);
    glVertexPointer(3, GL_FLOAT, 0, &vert);
    glEnableClientState(GL_VERTEX_ARRAY);
        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void draw_pyramid()
{
    GLfloat vert[] = {
        -0.2, -0.2, 0,
        -0.2, 0.2,  0,
        0.2, -0.2,  0,
        0.2, 0.2,   0,
        0,   0,     0.35
    };
    GLuint index[] = {0,1,4, 0,2,4, 1,3,4, 3,2,4};
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, &vert);
        glColor3f(1,0.4,0.4);
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, &index);
    glDisableClientState(GL_VERTEX_ARRAY);
}