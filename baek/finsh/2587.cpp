// 다섯 개의 자연수가 주어질 때, 평균과 중앙값을 구하는 프로그램을 작성.
// 중앙값은 다섯 개의 수를 증가하는 순서로 나열했을 때, 가운데에 위치하는 값을 의미한다.
// 첫째 줄부터 다섯 번째 줄까지 한 줄에 하나씩 자연수가 주어진다.
// 주어지는 자연수는 100보다 작은 10의 배수이다.#
// 1. 정렬하기 
// 2. 중앙값과 평균 구하기

#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    // 정렬
    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << sum / 5 << "\n"; // 평균
    cout << arr[2] << "\n"; // 중앙값
}