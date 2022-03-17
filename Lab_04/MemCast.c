#include <stdio.h>

int main() {
	int i;
	int four_ints[4];
	char* four_c;

	for(i = 0; i < 4; i++){
        four_ints[i] = 2;
	}
	printf("%x\n", four_ints[0]);
	
    four_c = (char*)four_ints;

	printf("%x\n", four_ints[0]);
	printf("%x\n", four_c[0]);

	for(i = 0; i < 5; i++){
        four_c[i] = 'A' + i;
		printf("value of four_ints: %x\n", four_ints[i]);
		printf("address of four_ints: %p\n", &four_ints[i]);
		printf("value of four_c: %x\n", four_c[i]);
		printf("address of four_c: %p\n", &four_c[i]); 
		printf("value of four_ints[1]: %x\n", four_ints[1]);
		// ASCII value of 'A' is 65 or 0x41 in Hex.
	}
    // Add your code for the exercises here:
	printf("%x\n", four_ints[0]);
	printf("%x\n", four_ints[1]);
	
	return 0;
}