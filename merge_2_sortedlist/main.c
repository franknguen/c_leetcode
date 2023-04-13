#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* newListNode(int data){
    struct ListNode* result_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if(result_node == NULL){
        printf("\n @frk-debug(newListNode): Mem allocation failed.");
        return NULL;
    }
    result_node->val  = data;
    result_node->next = NULL;
    return result_node;
}

void printNode(struct ListNode* list){
    printf("\n --------------------------------");
    while(list != NULL){
        printf("\n List data: [%d]", list->val);
        list = list->next;
    };
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){

    struct ListNode* result_node = newListNode(0);
    struct ListNode* current_node = result_node;
    if(result_node == NULL){
        printf("\n @frk-debug(mergeTwoLists): Mem allocation failed.");
        return NULL;
    }

    int i = 0;
    while((list1 != NULL) && (list2 != NULL)){
        printf("\n@frk-debug: iter = [%d]", i);
        if(list1->val < list2->val){
            printf("\n@frk-debug: iter-list1 = [%d]", i);
            current_node->next = newListNode(list1->val);
            list1 = list1->next;
        } else {
            printf("\n@frk-debug: iter-list2 = [%d]", i);
            current_node->next = newListNode(list2->val);
            list2 = list2->next;
        }
        current_node = current_node->next;
        i++;
    };
    current_node->next = (list1 != NULL) ? list1 : list2;

    return result_node->next;
}

int main()
{
    struct ListNode* a1 = NULL;
    struct ListNode* a2 = NULL;
    struct ListNode* a3 = NULL;

    a1                     = newListNode(1);
    a1->next               = newListNode(2);
    a1->next->next         = newListNode(4);
    a1->next->next->next   = newListNode(5);

    a2               = newListNode(0);
    a2->next         = newListNode(3);
    a2->next->next   = newListNode(5);
    
    a3 = mergeTwoLists(a1,a2);

    printNode(a1);
    printNode(a2);
    printNode(a3);

    printf("\n ----------------------------------------");
    printf("\n @Frank: PASS-TEST.\n");
    return 0;
}