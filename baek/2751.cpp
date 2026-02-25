#include <iostream>
using namespace std;

int l[1000001];
int r[1000001];

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
	*a = *b;
    *b = temp;
	return ;
}

// merge sort 구현
// (1) left와 right 병합
// - mid가 있다고 생각해야함
// - 모든 개수에 맞춰서 작동되어햐함
void merge(int arr[], int left, int mid, int right)
{
	int nl = mid - left + 1;
	int nr = right - mid;

	for(int i = 0; i < nl; i++) l[i] = arr[left + i];
	for(int i = 0; i < nr; i++) r[i] = arr[mid + 1 + i];
	// 두 배열을 병합하기
	int i = 0, j = 0, k = left;
	while(i < nl && j < nr)
	{
		if (l[i] <= r[j])
			arr[k++] = l[i++];
		else
			arr[k++] = r[j++];
	}
	while(i < nl) arr[k++] = l[i++];
    while(j < nr) arr[k++] = r[j++];
}

// (2) 최종 merge sort 함수
void merge_sort(int arr[], int left, int right)
{
	if (left < right) // 같아지면 stop!
	{
		int mid = left + (right - left) / 2;
		merge_sort(arr, left, mid); // 왼쪽 정렬
		merge_sort(arr, mid + 1, right); // 오른쪽 정렬
		merge(arr, left, mid, right);
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    int n;
    int num[1000001];
    
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    // 정렬 함수
	merge_sort(num, 0, n -1);
    for(int i = 0; i < n; i++)
    {
        cout << num[i] << '\n';
    }
}