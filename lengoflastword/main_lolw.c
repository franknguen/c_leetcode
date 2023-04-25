#if 1
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char * s);

int main()
{   
    char *s  = " hallo world     ";
    char *s1 = "a ";
    char *s2 = " a";
    char *s3 = "abc";
    printf("\n-----------------------------------");
    printf("\n result = [%d]", lengthOfLastWord(s));
    printf("\n-----------------------------------");
    printf("\n result = [%d]", lengthOfLastWord(s1));
    printf("\n-----------------------------------");
    printf("\n result = [%d]", lengthOfLastWord(s2));
    printf("\n-----------------------------------");
    printf("\n result = [%d]", lengthOfLastWord(s3));
    printf("\n-----------------------------------");
    printf("\n PASS-TEST \n");
    return 0;
}
#endif

int lengthOfLastWord(char * s)
{
    int result    = 0;
    int leng      = strlen(s);
    if((leng == 1) && (s[0] != ' ')){
        return 1;
    }
    int start     = 0;
    int stop      = 0;
    //--------------------------------------------
    printf("\n string = [%s], length = [%d]",s,leng);
    for(int i=leng-1; i>=0; i--){
        printf("\n [%d] = [%c]",i, s[i]);
        if((s[i] != ' ') || (i==0) ){
            start = i;
            for(int j=i;j>=0;j--){
                if(s[j] == ' '){
                    stop = j;
                    break;
                }
            }
            break;
        }
    }
    printf("\n start = [%d], stop = [%d]",start,stop);
    //--------------------------------------------
    result =     (start == stop)              ?          1  : 
                 ((stop == 0)&&(s[0] != ' ')) ? (start + 1) :(start - stop);
    return result;
}
