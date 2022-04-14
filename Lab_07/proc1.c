#include <stdio.h>
#include <stdlib.h>

int main(){
    int m = 10;
    int n = 5;

    int r = sum(m, n);

    printf("%d", r);
    
    return 0;
}

int sum(int x, int y){
    return x + y;
}