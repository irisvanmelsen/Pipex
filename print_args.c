#include <stdio.h>

int main(int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
	{printf("arg [%d] : %s argc=%d\n", i, argv[i], argc);}
	return (0);
}