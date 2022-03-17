#include <stdio.h>

int main(){
    int temp = 1, count = 1;
    float even = 0, odd = 0, evenCnt = 0, oddCnt = 0;

    while (temp != 0){
        int input = 0, sum = 0, mod = 0;

        if (count == 1){
            printf("Please enter the 1st integer: ");
        }
        else if(count == 2){
            printf("Please enter the 2nd integer: ");
        }
        else if(count == 3){
            printf("Please enter the 3rd integer: ");
        }
        else{
            printf("Please enter the %dth integer: ", count);
        }

        scanf("%d", &input);
        temp = abs(input);

        while(temp != 0){
            mod = temp % 10;
            sum = sum + mod;
            temp = temp / 10;
        }

        sum = sum % 2;

        if(input == 0){
            sum = sum - 1;
        }

        if(sum == 1){
            odd = odd + (float)input;
            oddCnt = oddCnt + 1.0;
        }
        else if(sum == 0){
            even = even + (float)input;
            evenCnt = evenCnt + 1.0;
        }
        count = count + 1;
        temp = input;
    }


    float evenAvg = even / evenCnt;
    float oddAvg = odd / oddCnt;

    if(oddCnt == 0 && evenCnt == 0){
        printf("There is no average to compute.");
    }
    else if(oddCnt == 0){
        printf("Average of inputs whose digits sum up to be an even number: %.2f\n", evenAvg);
    }
    else if(evenCnt == 0){
        printf("Average of inputs whose digits sum up to be an odd number: %.2f", oddAvg);
    }
    else{
        printf("Average of inputs whose digits sum up to be an even number: %.2f\n", evenAvg);
        printf("Average of inputs whose digits sum up to be an odd number: %.2f", oddAvg);
    }
}