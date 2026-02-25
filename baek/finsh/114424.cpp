// 오랜만에 cpp로 해봐야징
#include  <bits/stdc++.h>
using namespace std;

// 바이너리 서치
int binarysearch(const vector<string>& arr, string target)
{
	int left = 0;
	int right = arr.size()-1;
	while(left <= right)
	{
		int mid = (left+right) / 2;
		if(arr[mid] == target)
		{
			return mid;
		} else if (arr[mid] < target){
			left = mid + 1;
		} else right = mid -1;
	}
	return (-1);
}

int main()
{
	//c++의 iostream과 c의 stdio와 동기화 해제
	// 기본값은 true라서 서로 맞추느라 느려짐
	// false로 하면 속도가 빨라짐

	// c++는 두 개의 입력 시스템을 가짐
	// c계열의 stdio와 c++계열의 iostream이 존재함
	// 그러나 입출력을 섞어서 써도 출력 순서가 맞아야한다고 c++ 표준이 요구함
	// 아래처럼 입출력 시스텝을 분리함
	// 대신 둘의 섞어쓰면 출력 순가 달라질 수 있음
	ios_base::sync_with_stdio(false);

	// cin은 원래 cout에 묶여잇으ㅏㅁ
	// cin하기 전에 자동으로 cout.flush()가 실행됨
	// 풀면 -> 불필요한 flush 제거 -> 속도 증가

	// 기본값 : cin.tie(&cout)
	// tie? : 이 스트림을 쓰기전에 저 스트림을 flush해라
	// tie(nullptr)하면 cin과 cout 연결 해제
	// cin전에는 flush 안함 -> 입력이 많은 문제에서 속력이 압도적으로 좋아짐
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	vector<string> str(m);
	
	for(int i=0; i < n; i++)
		cin >> s[i];
	for(int i=0; i < m; i++)
		cin >> str[i];
	
	// 정렬
	sort(s.begin(), s.end());
	// 중복 제거
	// unique로 중복 숫자 정리, erase로 삭제
	s.erase(unique(s.begin(), s.end()), s.end());
	// 바이너리 서치
	int count = 0;
	for(int i = 0; i < m; i++)
	{
		if (binarysearch(s, str[i]) != -1){
			count++;
		}
	}
	cout << count;
}