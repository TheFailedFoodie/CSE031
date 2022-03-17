
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct Node {
    int iValue;
    float fValue;
    struct Node *next;
};

int main() {

    struct Node *head = (struct Node*) malloc(sizeof(struct Node));
    head->iValue = 5;
    head->fValue = 3.14;
	
	// Insert extra code here
	
    printf("value of head: %p\n", head);
    printf("address of head: %p\n", &head);
    printf("value of iValue: %d\n", head -> iValue);
    printf("value of fValue: %d\n", head -> fValue);
    printf("address of next: %p\n", &(head -> next));
    printf("address of fValue: %p\n", &(head -> fValue));
    printf("address of iValue: %p\n", &(head -> iValue));
	
	return 0;
}