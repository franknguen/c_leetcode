#include <stdio.h>  
#include <stdlib.h>  

/* 
ListNode data structure 
*/ 
struct ListNode{ 
    int val; 
    struct ListNode* next; 
}; 

/* 
print ListNode func() 
*/ 
void printListNode(struct ListNode* list){  
    while(list != NULL){  
        printf("\nfrk-printListNode: List: %d", list->val);  
        list = list->next;  
    }  
}  

/* 
add new Node into ListNode func() 
*/ 
struct ListNode* newListNode(int data){  
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));  
    result->val  = data;  
    result->next = NULL;  
    return result;  
}  

/* 
Add two numbers (display by ListNode) 
*/ 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){  
    struct ListNode *head_result = newListNode(0); 
    struct ListNode* head_cur = head_result; 
    int sum;
    int rem = 0; 
    int i = 0;
    while ( (l1 != NULL) || (l2 != NULL) || (rem != 0)) 
    {
        printf("\n@frk: iter=[%d]",i); 
        sum = rem + ((l1 == NULL) ? 0 : (l1->val)) + ((l2 == NULL) ? 0 : (l2->val)); 
        rem = sum/10; 
        printf("\n@frk: sum = [%d]",sum);
        printf("\n@frk: rem = [%d]",rem);
        sum %= 10; 
        head_cur->next = newListNode(sum); 
        head_cur = head_cur->next; 
        l1 = (l1 == NULL) ? 0 : (l1->next); 
        //printf("\n@frk: l1==0 = %d",l1==0); 
        l2 = (l2 == NULL) ? 0 : (l2->next); 
        //printf("\n@frk: l2==0 = %d",l2==0); 
        printf("\n-----------------------------------------");
    }  
    return head_result->next; 
}  
 
int main(){  
    printf("\n-----------------------------------------");   
    struct ListNode* myList1  = NULL;  
    myList1 = newListNode(5);  
    myList1->next = newListNode(6);  
    myList1->next->next = newListNode(4);  
    // myList1->next->next->next = newListNode(4);  
    printListNode(myList1);  

    printf("\n-----------------------------------------");   
    struct ListNode* myList2  = NULL;  
    myList2 = newListNode(0);  
    myList2->next = newListNode(0);  
    myList2->next->next = newListNode(7);  
    myList2->next->next->next = newListNode(5); 
    printListNode(myList2);  

    printf("\n-----------------------------------------");   
    printListNode(addTwoNumbers(myList1, myList2));  

    printf("\n-----------------------------------------");    
    printf("\nPASS-TEST\n");  
    return 0;  
} 

 