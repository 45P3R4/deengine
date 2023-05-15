GLfloat* obj_vert = NULL;
unsigned int obj_v_count = 0;


void open_obj(char* path)
{
    char c[1000] = {0};
    float v_x;
    float v_y;
    float v_z;
    
    
    if(fopen(path,"r")){
        FILE* obj;
        
        unsigned int i = 0;
        obj_vert = malloc(sizeof(GLfloat));

        obj = fopen(path,"r");
        while(fscanf(obj, "%s %g %g %g", c, &v_x, &v_y, &v_z) != EOF)
        {
            if(strcmp(c, "v") == 0){
                obj_v_count += 3; 
                obj_vert = realloc(obj_vert, obj_v_count * sizeof(GLfloat));
                *(obj_vert+i) = v_x;
                *(obj_vert+i+1) = v_z;
                *(obj_vert+i+2) = v_y;
                i = i+3;
            }
            else
                if(i > 0)
                    break;
        }
        fclose(obj);
    } 
    printf("vertices: %u\n", obj_v_count/3);
}