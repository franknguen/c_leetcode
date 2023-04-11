#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * longestCommonPrefix(char ** strs, int strsSize);

int main() {
    char * strs[] = {"flower", "flow", "flight"};
    int strsSize = sizeof(strs)/sizeof(strs[0]);
    char * prefix = longestCommonPrefix(strs, strsSize);
    printf("%s\n", prefix);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) {
        return "";
    }
    char* prefix = (char*) malloc(sizeof(char) * (strlen(strs[0]) + 1));
    strcpy(prefix, strs[0]);
    for (int i = 1; i < strsSize; i++) {
        int j = 0;
        while (prefix[j] && strs[i][j] && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
        if (j == 0) {
            return "";
        }
    }
    return prefix;
}