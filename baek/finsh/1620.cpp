#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// 나는야 포켓몬 마스터 이다솜
// 문제가 왜이렇게 웃기지
// 문제 읽기 싫어

int main()
{
    int n, m;
    cin >> n >> m;
    map<string, int> mp;
    // map 컨테이너 사용하기
    // 자료를 key-value 쌍으로 저장
    // 내부적으로 key를 정렬하여 저장
    // unordered_map 도 있음
    // 내부적으로 key를 정렬하지 않음
    /* 기본적인 사용법
    map<string, int> test;
    - test라는 이름을 가진 맵을 생성함
    - key는 string, value는 int형으로 생성
    */
    string arr[100001];
    for (int i = 1; i <= n; i++)
    {
        string str;
        cin >> str;
        mp[str] = i;
        arr[i] = str;
    }
    vector<string> result; // 결과를 담을 벡터
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (mp.count(str)) // 맵 탐색, 키가 존재하지않으면 mp.end() 반환함
            result.push_back(to_string(mp[str])); // 정수를 문자열로 변환
        else
        {
           result.push_back(arr[stoi(str)]); // 문자열을 정수로 변환
        }
    }
    for (string s : result)
    {
        cout << s << '\n';
    }
    return 0;
}