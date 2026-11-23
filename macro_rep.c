#include"header.h"
char name[30][40],value[30][40],arg[30][40],line[200],word[30],actual[40];
char formal1[40],formal2[40],actual1[40],actual2[40];
int i,j,count=0,k,found=0;
void macro_rep(FILE * fp1,FILE * fp2)
{
    while(fgets(line,200,fp1))              //extracts each line from src file
    {
        if(strncmp("#define",line,7)==0)     //checks if there is any macro defined
        {
            i=8;                    
            j=0;
            while(line[i]!='('&&line[i]!=' '&&line[i]!='\n'&&line[i]!='\0')
                name[count][j++]=line[i++];          //copying the macroname into name array
            name[count][j]='\0';                 

            if(line[i]=='(')
            {
                arg[count][0]='F';                  
                arg[count][1]='\0';

                i++;
                j=0;

                while(line[i]!=',' && line[i]!=')')           
                    formal1[j++]=line[i++];                      //copying the 1st argument into formal1 array

                formal1[j]='\0';

                if(line[i]==',')
                {
                    i++;
                    j=0;

                    while(line[i]!=')')
                        formal2[j++]=line[i++];                   //coping the 2nd argument name of macro into formal2 array

                    formal2[j]='\0';
                }

                i++;

            }
            else
                arg[count][0]='\0';
            while(line[i]==' ')
                i++;
            j=0;

            while(line[i]!='\n' && line[i]!='\0' && j<39)
            {
                value[count][j]=line[i];                     //coping the macro value 
                j++;
                i++;
            }

            value[count][j]='\0';

            count++;
        }
        else                                    //if no macro found
        {
            i=0;
            while(line[i]!='\0')
            {
                if((line[i]>='A'&&line[i]<='Z')||(line[i]>='a'&&line[i]<='z')||(line[i]=='_'))
                {
                    j=0;
                    while((line[i]>='A'&&line[i]<='Z')||(line[i]>='a'&&line[i]<='z')||(line[i]=='_')||(line[i]>='0'&&line[i]<='9'))
                        word[j++]=line[i++];                      //find the word
                    word[j]='\0';
                    found=0;
                    for(k=0;k<count;k++)
                    {
                        if(strcmp(word,name[k])==0)                //if word matches to macro name
                        {
                            found=1;
                            break;
                        }
                    }
                    if(found==1 && arg[k][0]!='\0' && line[i]=='(')     //if word matches with macroname then replace the word with value
                    {
                        i++;
                        j=0;

                        while(line[i]!=',' && line[i]!=')')
                            actual1[j++]=line[i++];

                        actual1[j]='\0';

                        if(line[i]==',')
                        {
                            i++;
                            j=0;

                            while(line[i]!=')')
                                actual2[j++]=line[i++];

                            actual2[j]='\0';
                        }

                        i++;

                        j=0;

                        while(value[k][j]!='\0')
                        {
                            if(strncmp(&value[k][j],formal1,strlen(formal1))==0)
                            {
                                fputs(actual1,fp2);
                                j+=strlen(formal1);
                            }
                            else if(strncmp(&value[k][j],formal2,strlen(formal2))==0)
                            {
                                fputs(actual2,fp2);
                                j+=strlen(formal2);
                            }
                            else
                            {
                                fputc(value[k][j],fp2);
                                j++;
                            }
                        }
                    }
                    else if(found==1&&arg[k][0]=='\0')
                        fputs(value[k],fp2);
                    else
                    {
                        fputs(word,fp2);
                    }
                }
                else
                {
                    fputc(line[i],fp2);
                    i++;
                }
            }
        }
    }
}
