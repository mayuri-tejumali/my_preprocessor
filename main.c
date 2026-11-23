#include"header.h"
int main(int argc,char ** argv)
{
    if(argc!=2)
    {
        printf("USAGE:./mypreprecessor filename\n");
        return 0;
    }
    FILE *f1, *f2, *f3;
char output[50];
int len;
f1 = fopen(argv[1], "r");
if(f1==0)
{
printf("file is not present\n");
return 0;
}
strcpy(output, argv[1]);
len = strlen(output);
output[len-1] = 'i';

f2 = fopen("temp1.i", "w");

comment_rem(f1, f2);

fclose(f1);
fclose(f2);
f2 = fopen("temp1.i", "r");
{
if(f2==0)
{
printf("file not found\n");
return 0;
}
}
    f3 = fopen("temp2.i", "w");

    header_inc(f2, f3);

    fclose(f2);
    fclose(f3);

f2 = fopen("temp2.i", "r");
if(f2==0)
{
printf("file not found\n");
return 0;
}
f3 = fopen(output, "w");

macro_rep(f2, f3);

fclose(f2);
fclose(f3);
//remove("temp1.i");
//remove("temp2.i");
}
