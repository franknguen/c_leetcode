#include <stdio.h>
#include <stdlib.h>
#include <math.h>       // gcc main.c -o tb -lm

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

void printListNode(struct ListNode* list){
    while(list != NULL){
        printf("\nfrk-printListNode: List: %d", list->val);
        list = list->next;
    }
}

struct ListNode* newListNode(int data){
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->val  = data;
    result->next = NULL;
    return result;
}

unsigned __int128 ListToInt(struct ListNode* list){
    unsigned __int128 result = 0;
    int length = 0;
    while(list != NULL){
        printf("\nfrk-ListToInt: List: %d", list->val);
        result = result*10 + list->val;
        printf("\nfrk-ListToInt: result: %llu", (unsigned long long) result);
        length++;
        list = list->next;
    }
    printf("\nfrank-ListToInt length = %d", length);
    printf("\nfrk-ListToInt: Integer = %llu", (unsigned long long) result);
    unsigned __int128 reverse = 0;
    unsigned __int128 multiplier = 1;
    for (int i=length-1; i>=0; i--){
        reverse += (result%10)*multiplier;
        multiplier *= 10;
        printf("\nfrk-ListToInt: %llu", (unsigned long long) reverse);
        result /= 10;
    }
    printf("\nfrk-ListToInt: reverse Integer = %llu", (unsigned long long) reverse);
    return reverse;
}

unsigned __int128 ListToInt(struct ListNode* list){
    unsigned __int128 result=0;
    int length = 0;
    while(list != NULL){
        printf("\nfrk-ListToInt: List: %d", list->val);
        result = result*10 + list->val;
        printf("\nfrk-ListToInt: result: %llu", result);
        length ++;
        list = list->next;
    }
    printf("\nfrank-ListToInt length = %d", length);
    printf("\nfrk-ListToInt: Integer = %llu", result);
    unsigned __int128 reverse = 0;

    for (int i=length-1; i>=0; i--){
        reverse += (result%10)*pow(10, i);
        printf("\nfrk-ListToInt: %llu", reverse);
        result /= 10;
    }

    printf("\nfrk-ListToInt: reverse Integer = %llu", reverse);
    return reverse;
}

struct ListNode* IntToLink(unsigned __int128 data){
    struct ListNode* head_result = newListNode(0);
    struct ListNode* head_cur    = head_result;
    printf("\n frk-IntToLink: data = %llu", data);
    if(data == 0){
        return head_result;
    } else {
        while(data != 0){
            printf("\n frk-IntToLink: data modulo 10 = %llu", data%10);
            head_cur->next = newListNode(data%10);
            data = data/10;
            printf("\n frk-IntToLink: data = %llu", data);
            head_cur = head_cur->next;
        } 
    }
    return head_result->next;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    printf("\n frk-addTwoNumbers: sum = %llu", ListToInt(l1) + ListToInt(l2));
    return IntToLink(ListToInt(l1) + ListToInt(l2));
}

int main(){
    struct ListNode* myList1  = NULL;
    myList1 = newListNode(5);
    myList1->next = newListNode(6);
    myList1->next->next = newListNode(4);
    // myList1->next->next->next = newListNode(4);
    printListNode(myList1);
    unsigned __int128 a1 = ListToInt(myList1);

    struct ListNode* myList2  = NULL;
    myList2 = newListNode(1);
    myList2->next = newListNode(0);
    myList2->next->next = newListNode(0);
    myList2->next->next->next = newListNode(0);
    myList2->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);    
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(0);
    myList2->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next->next = newListNode(1);    

    printListNode(myList2);
    unsigned __int128 a2 = ListToInt(myList2);

    unsigned __int128 a3 = a1 + a2;
    printf("\n sum = %llu", a3);
    printf("\n-----------------------------------------");  

    printListNode(IntToLink(a3));
    printf("\n-----------------------------------------");  

    printListNode(addTwoNumbers(myList1, myList2));
    printf("\n-----------------------------------------");  

/*
main.c:116:13: warning: overflow in conversion from ‘long int’ to ‘int’ changes value from ‘9999999991’ to ‘1410065399’ [-Woverflow]
  116 |     int x = 9999999991;
      |             ^~~~~~~~~~
*/
    unsigned __int128 x = 9999999991;         
    printListNode(IntToLink(x));

    printf("\n-----------------------------------------");  
    printf("\nPASS-TEST\n");
    return 0;
}