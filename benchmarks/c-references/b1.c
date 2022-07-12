#include <stdio.h>

int main(int argc, char** argv)
{
	int x = 0;
	for (int i = 0; i < 100000; ++i)
	{
		x = x + 1;
	}
	
	printf("x = %ld", x);
	return 0;
}