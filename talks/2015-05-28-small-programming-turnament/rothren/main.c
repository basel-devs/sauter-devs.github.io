#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
    const char pattern[] = "31415926535897932385";//1415926535897932385";
    int found_key = 0;
    int i=0;
    int j=0;
    char ch=0;
    long int count=0;
    long int result = 0;

    FILE* file = fopen("big_pi_test_with_pi_test","r");
    int endOfFile=1;

    while(endOfFile>0 && !found_key)
    {
        i=0;
        ch=0;

        do
        {
            endOfFile = fread(&ch,1,1,file);
            count++;
            i+=j;
            j=0;
            if(ch == pattern[i])
            {
                if(i==(sizeof(pattern)-2))
                {
                    found_key = 1;
                    result = count-20;
                    break;
                }
                j=1;
            }
        } while(ch == pattern[i]);
    }
    fprintf(stderr,"idx:%li",result);

    return 0;
}


