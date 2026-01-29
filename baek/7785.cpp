#include <iostream>

// 백준 7785번: 회사에 있는 사람
// https://www.acmicpc.net/problem/7785
// 해시맵을 사용하여 회사에 있는 사람들을 관리하는 문제

// 뭐라도 적아야 git push 하지
// C++17 표준을 사용합니다.
// g++ -std=c++17 -o baek7785 baek/7785.cpp
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, bool> company; // 이름과 회사에 있는지 여부를 저장

    for (int i = 0; i < n; ++i) {
        string name, action;
        cin >> name >> action;
        if (action == "enter") {
            company[name] = true; // 회사에 들어옴
        } else if (action == "leave") {
            company.erase(name); // 회사에서 나감
        }
    }

    vector<string> employees;
    for (const auto& entry : company) {
        employees.push_back(entry.first);
    }

    sort(employees.rbegin(), employees.rend()); // 내림차순 정렬

    for (const string& name : employees) {
        cout << name << '\n';
    }

    return 0;
}