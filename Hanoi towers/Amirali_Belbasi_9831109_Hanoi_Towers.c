#include <stdio.h>
#include <math.h>

char switch_C_and_B(char x);
char switch_A_and_B(char x);

int main()
{
	int n;
	char from[100000], to[100000], tmp_from[100000], tmp_to[100000];
	scanf("%d", &n);
	for (int m = 1; m <= n; m++)
	{
		int counter;
		for (int l = 1; l < pow(2, m - 1); l++)
		{
			tmp_from[l] = from[l];
			tmp_to[l] = to[l];
		}
		counter = 1;
		for (int j = 1; j < pow(2, m - 1); j++)
		{
			from[j] = switch_C_and_B(tmp_from[counter]);
			to[j] = switch_C_and_B(tmp_to[counter]);
			counter++;
		}
		from[(int)pow(2, m - 1)] = 'A';
		to[(int)pow(2, m - 1)] = 'C';
		counter = 1;
		for (int k = pow(2, m - 1) + 1; k < pow(2, m); k++)
		{
			from[k] = switch_A_and_B(tmp_from[counter]);
			to[k] = switch_A_and_B(tmp_to[counter]);
			counter++;
		}
	}
	for (int i = 1; i < pow(2, n); i++)
	{
		printf("step %d: move upper disc of peg %c to peg %c\n", i, from[i], to[i]);
	}
	return 0;
}
char switch_C_and_B(char x)
{
	if (x == 'C') return 'B';
	if (x == 'B') return 'C';
	return x;
}
char switch_A_and_B(char x)
{
	if (x == 'A') return 'B';
	if (x == 'B') return 'A';
}
