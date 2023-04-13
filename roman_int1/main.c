#include <stdio.h> 
#include <string.h> 

int char_to_int(char s){ 
    int value; 
    value = (s == 'I') ? 1    : 
            (s == 'V') ? 5    : 
            (s == 'X') ? 10   : 
            (s == 'L') ? 50   : 
            (s == 'C') ? 100  : 
            (s == 'D') ? 500  : 
            (s == 'M') ? 1000 : 0 ; 
    return value; 
} 

void tf_char_to_int(void){ 
    printf("\n@frk_debug [%d]", char_to_int('I')); 
    printf("\n@frk_debug [%d]", char_to_int('V')); 
    printf("\n@frk_debug [%d]", char_to_int('X')); 
    printf("\n@frk_debug [%d]", char_to_int('L')); 
    printf("\n@frk_debug [%d]", char_to_int('C')); 
    printf("\n@frk_debug [%d]", char_to_int('D')); 
    printf("\n@frk_debug [%d]", char_to_int('M')); 
    printf("\n@frk_debug [%d]", char_to_int('a')); 
} 
 
int romanToInt(char * s){ 
    printf("\n---------------------------------------------"); 
    int length = strlen(s); 
    printf("\n@frk_debug length = %d", length); 
    int result = 0; 
    for (register int i=0; i<length; i=(char_to_int(s[i]) < char_to_int(s[i+1])) \
    ? (i+2) : (i+1) ) 
    { 
        printf("\n@frk_debug s[%d]=%d",i,char_to_int(s[i])); 
        printf("\n@frk_debug i=[%d]", i); 
        printf("\n@frk_debug char_to_int(s[%d]) = %d", i, char_to_int(s[i])); 
        result = ( char_to_int(s[i]) < char_to_int(s[i+1]) ) ? (result + \
        char_to_int(s[i+1]) - char_to_int(s[i])) : (result + char_to_int(s[i]));  
        printf("\n@frk_debug result = [%d]", result); 
    } 
    return result; 
} 

int main() 
{ 
    tf_char_to_int(); 
    printf("\n result = %d", romanToInt("III")); 
    printf("\n result = %d", romanToInt("LVIII")); 
    printf("\n result = %d", romanToInt("MCMXCIV")); 

    printf("\n---------------------------------------------"); 
    printf("\nPASS-TEST\n"); 
    return 0; 
} 
