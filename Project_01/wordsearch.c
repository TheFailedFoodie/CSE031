#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarations of the two functions you will implement
// Feel free to declare any helper functions or global variables
void printPuzzle(char** arr);
void searchPuzzle(char** arr, char* word);
int bSize;
int** fArr;
int wordSize = 0;
int wordNum = 0;
int isFound = 0;

// Main function, DO NOT MODIFY 	
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <puzzle file name>\n", argv[0]);
        return 2;
     }
    int i, j;
    FILE *fptr;

    // Open file for reading puzzle
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open Puzzle File!\n");
        return 0;
    }

    // Read the size of the puzzle block
    fscanf(fptr, "%d\n", &bSize);
    
    // Allocate space for the puzzle block and the word to be searched
    char **block = (char**)malloc(bSize * sizeof(char*));
    char *word = (char*)malloc(20 * sizeof(char));

    // Read puzzle block into 2D arrays
    for(i = 0; i < bSize; i++) {
        *(block + i) = (char*)malloc(bSize * sizeof(char));
        for (j = 0; j < bSize - 1; ++j) {
            fscanf(fptr, "%c ", *(block + i) + j);            
        }
        fscanf(fptr, "%c \n", *(block + i) + j);
    }
    fclose(fptr);

    printf("Enter the word to search: ");
    scanf("%s", word);
    
    // Print out original puzzle grid
    printf("\nPrinting puzzle before search:\n");
    printPuzzle(block);
    
    // Call searchPuzzle to the word in the puzzle
    searchPuzzle(block, word);
    
    return 0;
}

void printPuzzle(char** arr) {
	// This function will print out the complete puzzle grid (arr). 
    // It must produce the output in the SAME format as the samples 
    // in the instructions.
    // Your implementation here...
	for (int i = 0; i < bSize; i++){
		for(int j = 0; j < bSize; j++){
			printf("%c ", *(*(arr + i) + j));
		}
		printf("\n");
	}
    printf("\n");
}
// A second function to print 2D integer arrays
void printIntPuzzle(int** arr) {
	for (int i = 0; i < bSize; i++){
		for(int j = 0; j < bSize; j++){
			printf("%d      ", *(*(arr + i) + j));
		}
		printf("\n");
	}
    printf("\n\n");
}

// Adding a function to try and recursively check for letters
// Make sure to recieve the 2D matrix, the string containing the word you're looking for, and the location of the character you are starting at. This will let the program narrow it's search area once the first letter is found
int puzzleLoop(char** cArr, char* word, int row, int col){
    // First, set the total size of the word

    wordSize = strlen(word);

    // Check to make sure that the letter you are looking at is the first letter in the string
    if (wordNum == 0){
        // Begin searching the 2D array for the first character of the string
        for (int i = 0; i < bSize; i++){
            for (int j = 0;  j < bSize; j++){
                // Check to see if the character at given point *(*(cArr + i) + j) is the first character of the string
                if (*(*(cArr + i) + j) == *(word + wordNum)){
                    // If the character is correct, move the letter being looked at to the next one in the string
                    wordNum++;
                    // Then recursively call the function again, checking to see if the next character in the string is touched by the found first value
                    if ((puzzleLoop(cArr, word, i, j)) != -1){
                        // If you reach this point, this means that the recursion has found its way back after succeeding all other test cases. The value in the final integer array is set to itself times 10 plus the character location so that the output is correct.
                        *(*(fArr + i) + j) = *(*(fArr + i) + j) * 10 + wordNum;
                        // wordNum is decreased so that it can return to the previous recursion without being messed up
                        wordNum--;
                        // This allows you to find multiple answers in the same array by checking all other values in the 2D array after finding one successful route
                        isFound = 1;
                    }
                } 
            }
        }
    }
    // If this is not the first character of the string, begin searching within the paramaters given after finding the first letter
    else {
        // Search all characters in a 3x3 cube around the found character for the next character in the string
        for (int i = (row - 1); i <= (row + 1); i++) {
            for (int j = (col - 1);  j <= (col + 1); j++) {
                // If the final character in the string is reached, the function outputs a success and continues
                if (wordNum >= wordSize){
                    return 1;
                }
                // This if statement checks to make sure that the values around the found character are actually in the 2D array, thereby avoiding the segmentation faults that looking in those locations would cause
                if (i >= 0 && i < bSize && j >= 0 && j < bSize && !(i == row && j == col)) {
                    // Checks to see if the character being looked at is the one we want
                    if (*(*(cArr + i) + j) == *(word + wordNum)) {
                        // If it is, increase the size of wordNum to look at the next character in the string
                        wordNum++;
                        // Then recursively call the function again to look for the next value
                        if ((puzzleLoop(cArr, word, i, j)) != -1) {
                            // After finding a path, this will set the integer matrix to the right values, decreases wordNum so that you can place values at the previous location in the final matrix, and returns a 1 to pass the if statement in the previous recursion case
                            *(*(fArr + i) + j) = *(*(fArr + i) + j) * 10 + wordNum;
                            wordNum--;
                            return 1;
                        }
                        
                    }
                }  
            }
        }
    }
    // If the function passes all the way through without finding any letters that it is looking for, it subtracts from wordNum to look for another pathway, then returns a -1 to fail the previous recursive if statement to keep looking.
    wordNum--;
    return -1;
}

void searchPuzzle(char** arr, char* word) {
    // This function checks if arr contains the search word. If the 
    // word appears in arr, it will print out a message and the path 
    // as shown in the sample runs. If not found, it will print a 
    // different message as shown in the sample runs.
    // Your implementation here...
    // Allocate space for the finished array
    fArr = (int**)malloc(bSize * sizeof(int*));
    // Fill the new array with 0's
    for (int i = 0; i < bSize; i++){
		*(fArr + i) = (int*)malloc(bSize * sizeof(int));
		for(int j = 0; j < bSize; j++){
			*(*(fArr + i) + j) = 0;
		}
	}
    // Makes word uppercase
    // word = strupr(word);
    for (int i = 0; i < strlen(word); i++){
        if (*(word + i) >= 'a' && *(word + i) <= 'z'){
            *(word + i) = *(word + i) - 32;
        }
    }
    // Begin looking for the first letter of the first word by calling recursive search function
    puzzleLoop(arr, word, 0, 0);

    // If the string is found, the global variable isFound will have been changed to 1 and the function will print the correct output, that being word found, then printing the search path

    if (isFound == 1){
        printf("Word Found!\n");
        printf("Printing the search path: \n");
        printIntPuzzle(fArr);
    }

    // Alternatively, if the string was not found, the function prints word not found and ends

    else {
        printf("Word not found! \n");
    }
}