#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h> 
#include <malloc.h> 
#include "Struct.h"
#pragma warning(disable : 4996)

int main(int argc, const char * argv[])
{
	struct BigInt A;
	struct BigInt B;
	struct BigInt Res;
	if (argc < 5 || argc>7)
	{
		printf("Incorrect arguments!\n");
		printf("[1file] [operation] [2file] [3file] [-b| 4 file] [4file]\n");
		printf("4 file is needed for the degree!\n");		
	}
		
	if (argc == 5)
	{
		A = ReadText(argv[1]);
		B = ReadText(argv[3]);
	}
	else
	{
		if (!strcmp(argv[5], "-b"))
		{
			A = ReadBin(argv[1]);
			B = ReadBin(argv[3]);
		}
		else
		{
			A = ReadText(argv[1]);
			B = ReadText(argv[3]);
		}
	}

	if (argv[2][0] == '+')
		Res = A + B;
	if (argv[2][0] == '-')
		Res = A - B;
	if (argv[2][0] == '*')
		Res = A * B;
	if (argv[2][0] == '/')
		Res = A / B;
	if (argv[2][0] == '%')
		Res = A % B;
	if (argv[2][0] == '^')
	{
		BigInt C;
		if (!strcmp(argv[5], "-b"))
			C = ReadBin(argv[6]);
		else
			C = ReadText(argv[5]);

		Res = deg(A, B, C);
		C = freeindex(C);
	}

	if (argc == 5)
		WriteText(argv[4], Res);

	else
	{
		if (!strcmp(argv[5], "-b"))
			WriteBin(argv[4], Res);
		else
			WriteText(argv[4], Res);
	}
	A = freeindex(A);
	B = freeindex(B);
	Res = freeindex(Res);

	return 0;
}
