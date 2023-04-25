/*
//**************************************************************
//**************************************************************
*/
#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* addBinary(char * a, char * b);
void printChar(char* s); 

//**************************************************************
int main()
{
    char a[] = "11111111";
    char b[] =    "10011";
    addBinary(a,b);

    printf("\n---------------------------------------------"); 
    printf("\nPASS-TEST\n"); 
    return 0; 
}
//**************************************************************
void printChar(char* s)
{
    int lengs = strlen(s);
    for(int i=0; i<lengs; i++)
    {
        printf("%c", s[i]);
    }
}
#endif

char* addBinary(char* a, char* b) {
    int lenga   = strlen(a);
    int lengb   = strlen(b);
    int lengmax = (lenga >= lengb) ? lenga : lengb;
    int rem = 0;
    int sum;

    char* result = (char*) malloc((lengmax + 2) * sizeof(char));
    *(result + lengmax + 1) = '\0';

    for (int i = 0; i < lengmax; i++)
    {
        printf("\n --------------------------------------------");
        printf("\n i     = [%d]",i  );
        printf("\n rem   = [%d]",rem);
        sum = rem;
        printf("\n sum1  = [%d]",sum);

        if ( (i < lenga) && *(a + lenga - i -1) == '1' ){
            sum++;
            printf("\n *(a + %d)  = [%c]", lenga - i -1, *(a + lenga - i -1));
            printf("\n sum2       = [%d]",sum);
        }

        if ( (i < lengb) && *(b + lengb - i -1) == '1' ){
            sum++;
            printf("\n *(b + %d)  = [%c]", lengb - i -1, *(b + lengb - i -1));
            printf("\n sum3       = [%d]",sum);
        }

        *(result + lengmax - i) = (sum%2) ? ('1') : ('0');
        
        printf("\n *(result + %d)  = [%c]", lengmax - i, *(result + lengmax - i));

        rem = (sum > 1) ? (1) : (0);
    }

    if(rem == 1){
        *result = '1';
    } else {
        result++;
    }
    printf("\n      a = %10s", a);
    printf("\n      b = %10s", b);
    printf("\n result = %10s", result);

    return result;
}
//**************************************************************

/*
char * addBinary(char * a, char * b)
{
    int lenga = strlen(a);
    int lengb = strlen(b);
    int lengmax = (lenga >= lengb) ? (lenga) : (lengb);
    int lengmin = (lenga <= lengb) ? (lenga) : (lengb);

    char* result = (char*)malloc((lengmax+1)*sizeof(char));
    int *rem     = (int*)malloc((lengmax+1)*sizeof(int));
    *(result+lengmax) = '\0';
    *(rem+lengmax) = 0;

    for(int i=0; i<lengmax; i++)
    {
        printf("\n --------------------------------------------"  );
        printf("\n         i=[%d]", i                             );
        printf("\n ----------------"                              );    
        printf("\n    *(rem+%d)=[%d]", lengmax-i, *(rem+lengmax-i));
        printf("\n      *(a+%d)=[%c]", lenga-1-i, *(a+lenga-1-i)  );
        printf("\n      *(b+%d)=[%c]", lengb-1-i, *(b+lengb-1-i)  );

        *(result+lengmax-1-i) =
            ((*(a+lenga-1-i) == *(b+lengb-1-i)) && (*(rem+lengmax-i) == 0))                  ? ('0') :
            ((*(a+lenga-1-i) == *(b+lengb-1-i)) && (*(rem+lengmax-i) == 1))                  ? ('1') :
            (((*(a+lenga-1-i)=='1') && (*(b+lengb-1-i)=='0')) && (*(rem+lengmax-i) == 0))    ? ('1') :
            (((*(a+lenga-1-i)=='0') && (*(b+lengb-1-i)=='1')) && (*(rem+lengmax-i) == 0))    ? ('1') :
            (((*(a+lenga-1-i)=='1') && (*(b+lengb-1-i)=='0')) && (*(rem+lengmax-i) == 1))    ? ('0') :
            (((*(a+lenga-1-i)=='0') && (*(b+lengb-1-i)=='1')) && (*(rem+lengmax-i) == 1))    ? ('0') :
            ((strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '1')  && (*(rem+lengmax-i) == 1)) ? ('0') :
            ((strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '1')  && (*(rem+lengmax-i) == 0)) ? ('1') :
            ((strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '0')  && (*(rem+lengmax-i) == 0)) ? ('0') :
            ((strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '0')  && (*(rem+lengmax-i) == 1)) ? ('1') :
            ((*(a+lenga-1-i) == '1') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 0)) ? ('1') :
            ((*(a+lenga-1-i) == '1') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 1)) ? ('0') :
            ((*(a+lenga-1-i) == '0') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 0)) ? ('0') :
            ((*(a+lenga-1-i) == '0') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 1)) ? ('1') : ('0');
        printf("\n ----------------");    
        printf("\n *(result+%d)= [%c]", lengmax-1-i, *(result+lengmax-1-i));

        *(rem+lengmax-1-i)  =
             ((*(a+lenga-1-i) == '1') && (*(b+lengb-1-i) == '1') )                            ? (1) :
             ((*(a+lenga-1-i) == '0') && (*(b+lengb-1-i) == '0') )                            ? (0) :
             (((*(a+lenga-1-i)=='1') && (*(b+lengb-1-i)=='0')) && (*(rem+lengmax-i) == 0))    ? (0) :
             (((*(a+lenga-1-i)=='0') && (*(b+lengb-1-i)=='1')) && (*(rem+lengmax-i) == 0))    ? (0) :
             (((*(a+lenga-1-i)=='1') && (*(b+lengb-1-i)=='0')) && (*(rem+lengmax-i) == 1))    ? (1) :
             (((*(a+lenga-1-i)=='0') && (*(b+lengb-1-i)=='1')) && (*(rem+lengmax-i) == 1))    ? (1) :
             ( (strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '1') && (*(rem+lengmax-i) == 1)) ? (1) :
             ( (strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '1') && (*(rem+lengmax-i) == 0)) ? (0) :
             ( (strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '0') && (*(rem+lengmax-i) == 0)) ? (0) :
             ( (strlen(a) < strlen(b)) && (*(b+lengb-1-i) == '0') && (*(rem+lengmax-i) == 1)) ? (0) :
             ((*(a+lenga-1-i) == '1') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 0)) ? (0) :
             ((*(a+lenga-1-i) == '1') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 1)) ? (1) :
             ((*(a+lenga-1-i) == '0') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 0)) ? (0) :
             ((*(a+lenga-1-i) == '0') && (strlen(a) >= strlen(b)) && (*(rem+lengmax-i) == 1)) ? (0) : (0);

        printf("\n *(rem+%d)= [%d]", lengmax-1-i, *(rem+lengmax-1-i));

    }
    printf("\n String a = ");
    printf("%10s",a);
    printf("\n String b = ");
    printf("%10s",b);

    if(*rem == 0){
        free(rem);
        printf("\n Result   = ");
        printf("%10s",result);
        return result;
    } else {
        free(rem);
        char* result_1 = (char*)malloc((lengmax+2)*sizeof(char));
        *result_1                 =  '1';
        *(result_1 + lengmax + 1) = '\0';
        for(int i=1; i<lengmax + 1; i++)
        {
            *(result_1 + i) = result[i-1];
        }
        free(result);
        printf("\n Result   = ");
        printf("%10s",result_1);
        return result_1;
    }
}
//**************************************************************
*/