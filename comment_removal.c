#include"header.h"
void comment_rem(FILE * f1,FILE * f2)
{
    char ch,next;
    while((ch=fgetc(f1))!=-1)
    {
        if(ch=='/')
        {
            next=fgetc(f1);
            if(next=='/')           //for sinle line coment
            {
                while(((ch=fgetc(f1))!=-1)&&(ch!='\n'));
                if(ch=='\n')
                    fputc('\n',f2);
            }
            else if(next=='*')       // for double line comment
{
    while((ch=fgetc(f1))!=-1)
    {
        if(ch=='\n')
            fputc(ch,f2);

        if(ch=='*')
        {
            next=fgetc(f1);

            if(next=='/')
                break;

            if(next=='\n')
                fputc(next,f2);
        }
    }
}
            else
            {
                fputc(ch,f2);
                if(next!=-1)
                    fputc(next,f2);
            }
        }
        else
            fputc(ch,f2);
    }
}





