#include <stdio.h>

int main(int argc, char** argv)
{
	int x = 0;
	for (int i = 0; i < 10000; ++i)
	{
		x = x + 1;
		printf("x = %d\n", x);
	}
	
	return 0;
}