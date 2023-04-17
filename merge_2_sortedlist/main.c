#include <stdio.h> 
#include <stdlib.h> 

/**/ 
struct ListNode{ 
    int infor; 
    struct ListNode* link; 
}; 

/**/ 
struct ListNode* newListNode(int data){ 
    struct ListNode* head_result = (struct ListNode*)malloc(sizeof(struct ListNode)); 
    head_result->infor  = data; 
    head_result->link = NULL; 
    return head_result; 
} 

/**/ 
void printListNode(struct ListNode* list){ 
    printf("\n -------------------------------------");     
    while(list != NULL){ 
        printf("\n Linked List member: [%d]", list->infor); 
        list = list->link; 
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
        if (list1->infor < list2->infor){ 
            printf("\n@frk-debug: iter[%d], list1->infor < list2->infor", i); 
            head_cur->link = newListNode(list1->infor); 
            list1 = list1->link; 
        } else { 
            printf("\n@frk-debug: iter[%d], list1->infor >= list2->infor", i); 
            head_cur->link = newListNode(list2->infor); 
            list2 = list2->link; 
        } 
        i++; 
        head_cur = head_cur->link; 
    }; 
    head_cur->link = (list1 == NULL) ? (list2) : (list1);     
    return head_result->link; 
} 
 
/**/ 
int main() 
{ 
    struct ListNode* head_a = NULL; 
    struct ListNode* head_b = NULL; 
    struct ListNode* head_j = NULL; 
     
    head_a             = newListNode(1); 
    head_a->link       = newListNode(5); 
    head_a->link->link = newListNode(6); 

    head_b                               = newListNode(2); 
    head_b->link                         = newListNode(3); 
    head_b->link->link                   = newListNode(4); 
    head_b->link->link->link             = newListNode(6); 
    head_b->link->link->link->link       = newListNode(7); 
    head_b->link->link->link->link->link = newListNode(8); 

    head_j = mergeTwoLists(head_a, head_b); 
    printListNode(head_a); 
    printListNode(head_b); 
    printListNode(head_j); 

    printf("\n-----------------------------------------");  
    printf("\nPASS-TEST\n");   
    return 0; 
} 