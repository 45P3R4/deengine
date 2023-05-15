GLfloat* obj_vert = NULL;
GLfloat* obj_index = NULL;
unsigned int obj_v_count = 0;


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

    int index[30] = {0};
    const char MAX_INDEXES = 10;
    char index0[MAX_INDEXES];
    char index1[MAX_INDEXES];
    char index2[MAX_INDEXES];
    char index3[MAX_INDEXES];

    
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
            printf("%s\n", cn);
        }
        printf("\n");

        while(fscanf(obj, "%s", ct) != EOF)
        {
            if(strcmp(ct, "s") == 0)
                break;
            printf("%s\n", ct);
        }
        printf("\n");

        fscanf(obj, "%s", cs);

        while(fscanf(obj, "%s %s %s %s %s", cf, index0, index1, index2, index3) != EOF)
        {
            printf("%s %s %s %s %s\n", cf, index0, index1, index2, index3);
            unsigned int counter = 0;
            for (int i = 0; i < MAX_INDEXES; i++)
            {
                if(isdigit(index0[i])){
                    index[counter] = (index0[i] - '0');
                }
                else if(isdigit(index0[i]) && index[counter] != 0){
                    index[counter] = 10 * index[counter] + index0[i];
                }
                else if(index0[i] = '/')
                    continue;
                
                printf("\n%d\n", index[i]);
            }
        }
        fclose(obj);
    } 
    printf("vertices: %u\n", obj_v_count/3);
}