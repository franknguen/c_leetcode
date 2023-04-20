#include <stdio.h> 
#include <stdlib.h> 

// Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };

/**/ 
struct ListNode* newListNode(int data){ 
    struct ListNode* head_result = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    head_result->val  = data; 
    head_result->next = NULL; 
    return head_result; 
} 

/**/ 
void printListNode(struct ListNode* list){ 
    printf("\n -------------------------------------");     
    while(list != NULL){ 
        printf("\n Linked List member: [%d]", list->val); 
        list = list->next; 
    }; 
    return; 
} 

/**/ 
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){ 
    struct ListNode* head_result = newListNode(0); 
    struct ListNode* head_cur    = head_result;  
    int i = 0; 

    while( (list1 != NULL) && (list2!=NULL) ){ 
        printf("\n@frk-debug: iter[%d]", i); 
        if (list1->val < list2->val){ 
            printf("\n@frk-debug: iter[%d], list1->val < list2->val", i); 
            head_cur->next = newListNode(list1->val); 
            list1 = list1->next; 
        } else { 
            printf("\n@frk-debug: iter[%d], list1->val >= list2->val", i); 
            head_cur->next = newListNode(list2->val); 
            list2 = list2->next; 
        } 
        i++; 
        head_cur = head_cur->next; 
    }; 
    head_cur->next = (list1 == NULL) ? (list2) : (list1);     
    return head_result->next; 
} 
 
/**/ 
int main() 
{ 
    struct ListNode* head_a = NULL; 
    struct ListNode* head_b = NULL; 
    struct ListNode* head_j = NULL; 
     
    head_a             = newListNode(1); 
    head_a->next       = newListNode(5); 
    head_a->next->next = newListNode(6); 

    head_b                               = newListNode(2); 
    head_b->next                         = newListNode(3); 
    head_b->next->next                   = newListNode(4); 
    head_b->next->next->next             = newListNode(6); 
    head_b->next->next->next->next       = newListNode(7); 
    head_b->next->next->next->next->next = newListNode(8); 

    head_j = mergeTwoLists(head_a, head_b); 
    printListNode(head_a); 
    printListNode(head_b); 
    printListNode(head_j); 

    printf("\n-----------------------------------------");  
    printf("\nPASS-TEST\n");   
    return 0; 
} 