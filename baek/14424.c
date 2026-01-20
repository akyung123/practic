#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 문자열 비교 함수
// 크기와 모양 모두 같아야함
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return s1[i] - s2[i];
}

int cmp(const void *a, const void *b)
{
    return ft_strcmp(*(char **)a, *(char **)b);
}

// 문자열의 이분 탐색을 짜야함
// 바이너리 서치

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    char **s = malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++)
        s[i] = malloc(sizeof(char) * 501);
    char **k = malloc(sizeof(char *) * m);
    for (int i = 0; i < m; i++)
        k[i] = malloc(sizeof(char) * 501);
    int i = 0;
    while (i < n)
    {
        scanf("%s", s[i]);
        i++;
    }
    i = 0;
    while (i < m)
    {
        scanf("%s", k[i]);
        i++;
    }
    i = 0;
    int j = 0;
    int num = 0;
    while (i < m)
    {
        j = 0;
        while(j < n)
        {
            if(ft_strstmp(k[i], s[j]))
                num++;
            j++;
        }
        i++;
    }
    printf("%d", num);
    free(s);
    free(k);
}