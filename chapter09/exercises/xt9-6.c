#include <stdio.h>
#define N 13

struct person
{
	int number;
	int next_p;
} link[N + 1];

int main()
{
	int i, count, h;
	for (i = 1; i <= N; i++)
	{
		if (i == N)
			link[i].next_p = 1;
		else
			link[i].next_p = i + 1;
		link[i].number = i;
	}
	printf("\n");
	count = 0;
	h = N;
	printf("sequence that persons leave the circle:\n");
	while (count < N - 1)
	{
		i = 0;
		while (i != 3)
		{
			h = link[h].next_p;
			if (link[h].number)
				i++;
		}
		printf("%4d", link[h].number);
		link[h].number = 0;
		count++;
	}
	printf("\nThe last one is ");
	for (i = 1; i <= N; i++)
		if (link[i].number)
			printf("%3d", link[i].number);
	printf("\n");
	return 0;
}