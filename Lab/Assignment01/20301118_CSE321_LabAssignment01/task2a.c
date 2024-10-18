#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int first_number, second_number;
	char operand[50];
	printf("Enter two numbers and operand: ");
	scanf("%d %d %s", &first_number, &second_number, operand);
	
	if (first_number > second_number){
		int result = first_number - second_number;
		printf("%d %s %d = %d\n", first_number, operand, second_number, result);
	}
	else if (first_number < second_number){
		int result = first_number + second_number;
		printf("%d %s %d = %d\n", first_number, operand, second_number,result);
	}
	else if (first_number == second_number){
		int result = first_number * second_number;
		printf("%d %s %d = %d\n", first_number, operand, second_number, result);
	}
	return 0;
}
	
	
	
