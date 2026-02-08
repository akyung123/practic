#include <iostream>
#include <set>
using namespace std;
// 공집합  S가 주어졌을 때, 연산을 수행하는 프로그램을 작성함
// 가능한 연산은 add, remove, check, toggle, all, empty
// 첫째 줄에 수행해야 하는 연산의 수, 둘째줄부터 연산이 한줄 씩 주어진다.
// check는 S에 x가 있으면 1을, 없으면 0을 출력한다

// 비트 마스크를 이용하는 문제로 풀어야함
// 숫자 하나를 비트로 이요한다. 
// 1~20까지의 수를 이용하므로 20비트가 필요하다
// 각 비트별 숫자의 유무를 나타난다
// 비트는 보통 36개이다. 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int s = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            int x;
            cin >> x;
            s |= (1 << (x - 1));
            // s = s | (1 << (x - 1));와 같은 의미
            // | 는 or 연산자
            // 둘 중 하나라도 비트가 1이면 1로 바뀜
        }
        else if (str == "remove")
        {
            int x;
            cin >> x;
            s &= ~(1 << (x - 1));
            // s = s & ~(1 << (x - 1));와 같은 의미
            // ~ 는 비트 반전 연산자
            // & 는 and 연산자
            // 둘 다 1일 때만 1로 바뀜
        }
        else if (str == "check")
        {
            int x;
            cin >> x;
            if (s & (1 << (x - 1))) // s에 x가 포함되어 있는지 확인
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (str == "toggle")
        {
            int x;
            cin >> x;
            s ^= (1 << (x - 1));
        }
        else if (str == "all")
        {
            s = (1 << 20) - 1;
        }
        else if (str == "empty")
        {
            s = 0;
        }
    }
}