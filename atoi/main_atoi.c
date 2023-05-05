#if 1
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

int check_digit(char c);
int myAtoi(char * s);

int main(){
    char *s1 = "  Hallo world  -123.";
    char *s2 = "  -123 hallo.";
    char *s3 = "123.";
    
    myAtoi(s1);
    myAtoi(s2);
    myAtoi(s3);

    printf("\n ---------------------------- \n");
    printf("\n PASS-TEST \n");
    return 0;
}
#endif

int check_digit(char c){
    int result;
    result = (c == '0') ? (0) :
             (c == '1') ? (1) : 
             (c == '2') ? (2) : 
             (c == '3') ? (3) : 
             (c == '4') ? (4) : 
             (c == '5') ? (5) : 
             (c == '6') ? (6) : 
             (c == '7') ? (7) :
             (c == '8') ? (8) : 
             (c == '9') ? (9) : -1;
    //printf("\n check digit [%c] = %d", c, result);
    return result;
}

int check_space(char c){
    return c==' ';
}

int myAtoi(char * s){
    int result=0;
    int len = strlen(s);
    int sign = 1;
    int i = 0;
    
    // Skip whitespace characters
    while (i < len && check_space(s[i])) {
        i++;
    }
    
    // Check for optional sign character
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }
    
    // Process digits
    while (i < len && (check_digit(s[i]) != -1)) 
    {
        if (result > (INT_MAX - check_digit(s[i])) / 10) 
        {
            result = (sign == 1) ? INT_MAX : INT_MIN;
            return result;
        }
        result = result * 10 + check_digit(s[i]);
        i++;
    }

    result = result * sign;
    printf("\n result = %d", result);
    
    return result;
}


int myAtoi1(char * s){
    int result=0;
    int len = strlen(s);
    int sign = 1;
    for (int i=0; i<len; i++){
        if(s[i] == '-'){
            sign = -1;
            break;
        }
    }

    for (int i=0; i<len; i++){
        if(check_digit(s[i]) != -1){
            result = result*10 + check_digit(s[i]);
        }
    }

    printf("\n string = [%s]", s);
    printf("\n string length = [%d]", len);
    for (int i = 0; i < len; i++){
        check_digit(s[i]);
    }

    result = result*sign;

    printf("\n result = %d", result);
    return result;    
}

/*
Valid examples:
" -345"
" +111"
" 1245 gggg"

Invalid "words and 987" because there is words before the number
*/