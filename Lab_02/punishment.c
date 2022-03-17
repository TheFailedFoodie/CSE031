#include <stdio.h>

int main(){
    int p = 0;

    while(p < 1){
        printf("Enter the number of times to repeat the punishment phrase: ");
        scanf("%d", &p);

        if(p < 1){
            printf("\nYou entered an incorrect value for the number of repetitions!\n");
        }
        else{
            break;
        }
    }

    int t = 0;
    
    while(t < 1 || t > p){
        printf("Enter the repetition line where you want to introduce the typo: ");
        scanf("%d", &t);

        if(t < 1 || t > p){
            printf("You entered an incorrect value for the typo placement!\n");
        }
        else{
            break;
        }
    }
    t = t - 1;
    for(int i = 0; i < p; i = i + 1){
        if(i == t){
            printf("Programming in C is phun!\n");
        }
        else{
            printf("Programming in C is fun!\n");
        }
    }
    return 0;
}