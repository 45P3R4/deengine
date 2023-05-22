GLfloat* obj_vert = NULL;
GLuint* obj_face_v = NULL;
float* obj_random_colors = NULL;
unsigned int obj_v_count = 0;
unsigned int obj_f_count = 0;

char path[256] = "models\\duck_v.obj\0";

void open_obj(char* path)
{
    char cv[100] = {0};
    char cn[100] = {0};
    char ct[100] = {0};
    char cf[100] = {0};
    char cs[100] = {0};
    char c;

    float v_x;
    float v_y;
    float v_z;

    int f_x;
    int f_y;
    int f_z;

    
    if(fopen(path,"r")){
        FILE* obj;
        
        unsigned int i = 0;
        obj_vert = malloc(sizeof(GLfloat));
        obj_face_v = malloc(sizeof(GLuint));

        obj = fopen(path,"r");
        while(fscanf(obj, "%s %g %g %g", cv, &v_x, &v_y, &v_z) != EOF)
        {
            if(strcmp(cv, "v") == 0){
                obj_v_count += 3; 
                obj_vert = realloc(obj_vert, obj_v_count * sizeof(GLfloat));
                *(obj_vert+i) = v_x;
                *(obj_vert+i+1) = v_y;
                *(obj_vert+i+2) = v_z;
                i = i+3;
            }
            else
                if(i > 0)
                    break; 
                    
        }


        i=0;

        while(fscanf(obj, "%s %d %d %d", cs, &f_x, &f_y, &f_z) != EOF)
        {
            obj_f_count +=3;
            obj_face_v = realloc(obj_face_v, obj_f_count * sizeof(GLuint));

            *(obj_face_v+i) = f_x-1;
            *(obj_face_v+i+1) = f_y-1;
            *(obj_face_v+i+2) = f_z-1;
            i += 3;
        }


        fclose(obj);
    } 


    obj_random_colors = malloc(sizeof(float)*obj_f_count);

    for (int i = 0; i < obj_f_count; i++)
    {
        *(obj_random_colors+i) = rand() % 2;
    }
    

    printf("vertices:\n");


    for (int i = 0; i < obj_v_count; i+=3){
        printf("%5g %5g %5g\n", *(obj_vert+i), *(obj_vert+i+1), *(obj_vert+i+2));
    }
    
    printf("faces:\n");

    for (int i = 0; i < obj_f_count; i+=3){
        printf("%5d %5d %5d\n", *(obj_face_v+i), *(obj_face_v+i+1), *(obj_face_v+i+2));
    }
    
    
    printf("\n%s\n", path);
    printf("vertices: %u\n", obj_v_count/3);
    printf("faces: %u\n", (obj_f_count)/3);
}