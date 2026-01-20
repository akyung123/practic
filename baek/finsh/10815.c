#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 시간 초과면 어떻게 풀어야하지?
int compare(const void *a, const void *b)
{
	int n1 = *(int *)a;
	int n2 = *(int *)b;

	if  (n1 < n2)
		return (-1);
	else if (n1 > n2)
		return (1);
	else
		return (0);
}

int search(int *n, int start, int end, int num)
{
	if (start > end)
		return (0);
	int middle = (start + end) / 2;
	if (n[middle] == num)
		return (1);
	else if (n[middle] > num)
		return (search(n, start, middle - 1, num));
	else
		return (search(n, middle + 1, end, num));
}

int main()
{
	int n_num, m_num;
	scanf("%d", &n_num);
	int *n = malloc(sizeof(int) * n_num);
	int i = 0;
	while (i < n_num)
	{
		scanf("%d", &n[i]);
		i++;
	}
	qsort(n, n_num, sizeof(int), compare);
	scanf("%d", &m_num);
	int *m = malloc(sizeof(int) * m_num);
	i = 0;
 	while (i < m_num)
	{       
		scanf("%d", &m[i]);
                i++;
	}
	i = 0;
	// 이진 탐색으로 구현해야함
	// 시간 초과 문제가 있음
	// 보통 퀵소트 + 이진 탐색을 이용하니 그대로 진행
	while (i < m_num)
	{
		printf("%d ", search(n, 0, n_num -1, m[i]));
		i++;
	}
	free(n);
	free(m);
	return (0);
}
