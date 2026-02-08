#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

// 백준 10816번: 숫자 카드 2
// https://www.acmicpc.net/problem/10816
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;
    unordered_map<int, int> np;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        np[num]++;
    }
    cin >> m;
    unordered_map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        cout << np[num] << ' ';
    }
    return (0);
}