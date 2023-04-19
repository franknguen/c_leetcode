#include<stdio.h>
#include<stdbool.h>
#include <math.h>
#include <string.h>

bool isPalindrome(int x){
    char s[20];
    sprintf(s, "%d", x); // Convertir x a cadena

    printf("\n@frk-dbg: x=%d",x);
    printf("\n@frk-dbg: s=%s",s);

    int n = strlen(s);
    
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-1-i]) {
            return 0;
        }
    }    

    return 1;
}

bool isPalindrome_0(int x)
{
    if (x < 0) return false;
    int tem = x;
    int reverse = 0;
    while (tem!=0)
    {
        // need to account for int overflow
        if(reverse > (0x7fffffff - tem%10) / 10) return false;
        reverse = reverse*10 + tem%10;
        tem /=10;
    }
    printf("\n x=%d",x);
    printf("\n reverse=%d",reverse);

    return x==reverse;
}

bool isPalindrome_1(int x)
{
    int length=0;
    int tem = x;
    int tem1 = x;
    int reverse=0;
    while (tem!=0)
    {
        tem /= 10;
        length++;
    }
    printf("\n@frk-deg: x=[%d]", x);
    printf("\n@frk-deg: length=[%d]", length);
    for(int i=1; i <= length; i++)
    {
        reverse += (tem1%10)*pow(10,length-i);
        tem1 /= 10;
    }
    printf("\n@frk-deg: reverse=[%d]", reverse);
    return (x<0) ? (false) : (x==reverse);
}

int main()
{
    printf("\n %d", -123);
    printf("\n--------------------------");
    //isPalindrome(-123);
    printf("\n %d",isPalindrome(12321)==true);
    isPalindrome(12321);
    printf("\n--------------------------");
    printf("\nPASS TEST\n");    
    return 0;
}