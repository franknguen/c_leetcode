#include <stdio.h>
#include <string.h>

int strStr(char * haystack, char * needle){
    int result = -1;

    int leng1 = strlen(haystack);
    int leng2 = strlen(needle);
    printf("\n leng1 = [%d]", leng1);
    printf("\n leng2 = [%d]", leng2);
    if (leng1 < leng2){
        return result;
    }

    printf("\n---------------------------");
    for(int i=0; i<leng1; i++){
        printf("\n@frk-dbg: = [%c]", haystack[i]);
    }
    printf("\n---------------------------");
    for(int i=0; i<leng2; i++){
        printf("\n@frk-dbg: = [%c]", needle[i]);
    }

    for (int i=0; i<= (leng1 - leng2); i++)
    {
        int tem=0;
        for (int j=0; j<leng2; j++){
            if(haystack[i+j] != needle[j]){
                tem = 1;
            }
        }
        if (tem == 0){
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    char *str1 = "leetcode!";
    char *str2 = "leet";
    int leng1  = strlen(str1);
    int leng2  = strlen(str2);

    printf("\n result=%d",strStr(str1, str2));

    printf("\n---------------------------");
    printf("\nPASS-TEST");

    return 0;
}
