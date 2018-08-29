#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char *env[])
{
	int a = 5;
	int *b = 5;
	printf("&b = %8x\n",&b);
	printf("b = %d\n",b);
	printf(b);
}
