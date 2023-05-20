GLfloat* obj_vert = NULL;
GLuint* obj_face = NULL;
GLuint* obj_face_v = NULL;
unsigned int obj_v_count = 0;
unsigned int obj_f_count = 0;

char path[256] = "models\\star.obj\0";
//int index[72] = {0};

void open_obj(char* path)
{
    char cv[100] = {0};
    char cn[100] = {0};
    char ct[100] = {0};
    char cf;
    char cs[100] = {0};
    char c;

    float v_x;
    float v_y;
    float v_z;

    
    if(fopen(path,"r")){
        FILE* obj;
        
        unsigned int i = 0;
        obj_vert = malloc(sizeof(GLfloat));

        obj = fopen(path,"r");
        while(fscanf(obj, "%s %g %g %g", cv, &v_x, &v_y, &v_z) != EOF)
        {
            if(strcmp(cv, "v") == 0){
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

        while(fscanf(obj, "%s", cn) != EOF)
        {
            if(strcmp(cn, "vt") == 0)
                break;
        }

        while(fscanf(obj, "%s", ct) != EOF)
        {
            if(strcmp(ct, "s") == 0)
                break;
        }

        fscanf(obj, "%s", cs);

        int digits = 0;
        cf = getc(obj);
        cf = getc(obj);
        cf = getc(obj);
        obj_face = malloc(sizeof(GLuint));
        char last_symbol;

        while(cf != EOF)
        {
            cf = getc(obj);

            if(cf  == '/' || (cf == ' ')){
                obj_f_count++;
                digits = 0;
                obj_face = realloc(obj_face, (obj_f_count + 1) * sizeof(GLuint));
            }

            if(isdigit(cf) && digits == 0){
                *(obj_face + obj_f_count ) = cf - '0';
                digits++;
            }

            else if((isdigit(cf)) && digits > 0){
                *(obj_face + obj_f_count) = (*(obj_face + obj_f_count)*10) + (cf - '0');
                digits++;
            } 

            last_symbol = cf;
            
        }

        obj_f_count++;
        obj_face_v = malloc((sizeof(GLuint) * (obj_f_count/3)));

        int ii = 0;

        for (int i = 0; i < obj_f_count; i+=3)
        {
            *(obj_face_v+ii) = *(obj_face+i);
            ii++;
            obj_face_v = realloc(obj_face_v, sizeof(GLuint)*(ii+1));
        }

        for (int i = 0; i < obj_f_count/3; i++)
        {
            printf("%d\n", *(obj_face_v+i));
        }
        

        fclose(obj);
    } 
    
    printf("\n%s\n", path);
    printf("vertices: %u\n", obj_v_count/3);
    printf("faces: %u\n", (obj_f_count)/9);
}