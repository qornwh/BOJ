#include <stdio.h>
int main()
{
    int number[4] = {0,2,3,1};
	int *nptr;
	nptr = number;

	printf("%p : number 주소", number);

	printf("%p : number 주소", &number[0]);


	return 0;
}