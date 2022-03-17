#include <stdio.h> 
 
int main() { 
    int x = 0, y = 0, *px, *py; 
    int arr[10];

    for (int i = 0; i < 10; i++){
        arr[i] = i;
    }

    px = &x;
    py = &y;

    printf("x = %d, y = %d\n", x, y);

    printf("value of px = %d, address of px = %d\n", px, &px);
    printf("value of py = %d, address of py = %d\n", py, &py);
    printf("address of x = %d, address of y = %d\n",&x, &y );

    for(int i = 0; i < 10; i = i + 1){
        printf("%d\n", *(arr + i));
    }

    printf("value of arr = %d, address of first value of array = %d", arr, &arr[0]);

    return 0; 
}