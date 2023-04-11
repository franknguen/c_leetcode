#include <stdio.h>
#include <string.h>

int romanToInt(char *s);

int main() {
    char* roman1 = "III";
    int num1 = romanToInt(roman1);
    printf("%s = %d\n", roman1, num1);

    char* roman2 = "IV";
    int num2 = romanToInt(roman2);
    printf("%s = %d\n", roman2, num2);

    char* roman3 = "IX";
    int num3 = romanToInt(roman3);
    printf("%s = %d\n", roman3, num3);

    char* roman4 = "LVIII";
    int num4 = romanToInt(roman4);
    printf("%s = %d\n", roman4, num4);

    char* roman5 = "MCMXCIV";
    int num5 = romanToInt(roman5);
    printf("%s = %d\n", roman5, num5);

    return 0;
}

int romanToInt(char * s){
    int roman_dict[26];
    roman_dict['I'-'A'] = 1;
    roman_dict['V'-'A'] = 5;
    roman_dict['X'-'A'] = 10;
    roman_dict['L'-'A'] = 50;
    roman_dict['C'-'A'] = 100;
    roman_dict['D'-'A'] = 500;
    roman_dict['M'-'A'] = 1000;

    int prev_val = 0;
    int total_val = 0;
    int len = strlen(s);

    for(int i = 0; i < len; i++){
        int curr_val = roman_dict[s[i]-'A'];
        if(curr_val > prev_val){
            total_val -= 2 * prev_val;
        }
        total_val += curr_val;
        prev_val = curr_val;
    }

    return total_val;
}