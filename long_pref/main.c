#include<stdio.h>
#include <string.h>
#include <stdlib.h>

// char * longestCommonPrefix(char ** strs, int strsSize){
//     char* result = (char*) malloc(sizeof(char)*(strlen(strs[0])));
//     strcpy(result, strs[0]);
//     printf("\nfrk-debug: %s - %ld", result, strlen(result));
//     for (int i =0; i<strlen(result); i++){
//         int j = 0;
//         while((result[j] != '\0') && (strs[i][j] != '\0') && (result[j] == strs[i][j])){
//             j++;
//         }
//         result[j] ='\0';
//         if (j == 0){
//             return "";
//         }
//     }
//     return result;
// }

char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        // handle empty input
        char* result = (char*) malloc(sizeof(char));
        result[0] = '\0';
        return result;
    }

    char* result = (char*) malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(result, strs[0]);
    printf("\nfrk-debug: %s - %ld", result, strlen(result));

    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while ((result[j] != '\0') && (strs[i][j] != '\0') && (result[j] == strs[i][j])) {
            j++;
        }
        result[j] = '\0';
        if (j == 0) {
            // handle empty prefix
            free(result);
            char* empty_result = (char*) malloc(sizeof(char));
            empty_result[0] = '\0';
            return empty_result;
        }
    }

    return result;
}

int main()
{
    char* test_str1[] = {"flower","flow","flight"};
    char* test_str2[] = {"aaa","aaafl","aaaxxxx"};
    char* test_str3[] = {"dog","racecar","car"};

    printf("\n %s",longestCommonPrefix(test_str1,3));
    printf("\n %s",longestCommonPrefix(test_str2,3));
    printf("\n %s",longestCommonPrefix(test_str3,3));

    printf("\n---------------------------------------------"); 
    for (int i=0; i<3; i++){
        int j = strlen(test_str1[i]);
        printf("\n");
        for (int k=0; k<j; k++){
            printf("%c", test_str1[i][k]);    
        }
    }

    printf("\n---------------------------------------------"); 
    char test_str[]  = "Hallo";
    int length_str   = strlen(test_str);
    printf("\n %s: %d", test_str, length_str);
    for (int i=0; i<length_str; i++){
        printf("\n %c", test_str[i]);        
    }

    printf("\n---------------------------------------------");    
    printf("\n %d", '\0');

    printf("\n---------------------------------------------"); 
    printf("\nPASS-TEST\n"); 
    return 0; 
}