#include <iostream>
#include <vector>

using namespace std;

namespace 입국심사 {
    long long solution(int n, vector<int> times);
}

int main()
{
    int n = 6;
    vector<int> times = { 7, 10 };

    long long answer = 입국심사::solution(n, times);

    return 0;
}