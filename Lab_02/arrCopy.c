#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void printArr(int *a, int size, char *name){
    if (name == "Original"){
        printf("\nOriginal array's contents: ");
        for(int k = 0; k < size; k++){
            printf("%d ", *(a + k));
        }
    }
    if (name == "Copied"){
        printf("\nCopied array's contents: ");
        for(int k = 0; k < size; k++){
            printf("%d ", *(a + k));
        }

    }
}

int* arrCopy(int *a, int size){
	for (int k = 0; k < size / 2; k++){
        int temp = *(a + (size - (k + 1)));
        *(a + (size - (k + 1))) = *(a + k);
        *(a + k) = temp;
    }
    return a;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter the size of array you wish to create: ");
    scanf("%d", &n);

    //Dynamically create an int array of n items
    //Your code here
    arr = (int*)malloc(n * sizeof(int));

    //Ask user to input content of array
	//Your code here
    for (i = 0; i < n; i++){
        printf("Enter array element #%d: ", (i + 1));
        scanf("%d", (arr + i));
    }
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n, "Original");

	//Copy array with contents in reverse order
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n, "Copied");

    printf("\n");

    return 0;
}