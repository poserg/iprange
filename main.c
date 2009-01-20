#include <stdio.h>
struct IPAddress {
	int A, B, C, D;
};

int main()
{
	IPAddress adrs;
	adrs.A = 10;
	printf ("%d\n", adrs.A);
	return 0;
}

