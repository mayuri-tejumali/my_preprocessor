#include"header.h"
void header_inc(FILE * fp1, FILE * fp2)
{
    char line[200], filename[100], path[150];
    int i, j, ch;
    FILE *fp;

    while(fgets(line, 200, fp1))
    {
        if(strncmp(line, "#include", 8) == 0)           //if preprocessor direcitive #include is found in a line
        {
            i = 8;

            while(line[i] == ' ')
                i++;

            if(line[i] == '<')
            {
                i++;
                j = 0;

                while(line[i] != '>' && line[i] != '\0')
                    filename[j++] = line[i++];

                filename[j] = '\0';

                strcpy(path, "/usr/include/");
                strcat(path, filename);                         

                fp = fopen(path, "r");                       //open standard header file

                if(fp != NULL)
                {
                    while((ch = fgetc(fp)) != EOF)
                        fputc(ch, fp2);

                    fclose(fp);
                }
            }
        }
        else
        {
            fputs(line, fp2);
        }
    }
}

