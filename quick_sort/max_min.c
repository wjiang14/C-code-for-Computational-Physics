#include <stdio.h>

#define N 10

void max_min(int a[], int n, int *max, int *min){
	*max = *min = a[0];

	for (int i = 0; i < n; ++i)
	{
		if (*max < a[i])
		{
			*max = a[i];
		}
		else if (*min > a[i])
		{
			*min = a[i];
		}
	}
}

int main(int argc, char const *argv[])
{
	int a[N], i, big, small;

	printf("input 10 datas\n");
	for (i = 0; i < N; ++i)
	{
		scanf("%d", &a[i]);
	}

	max_min(a[N], N, &big, &small);

	printf("largest number is: %d\n", big);
	printf("smallest number is: %d\n", small);

	return 0;
}
