#include <iostream>
#include <cstdlib>
using namespace std;

int t;
int v[100001];
long long odd = 0;//홀수
long long even = 0;
//분명 맞는데 아니면 문제에서 숫자 범위 잘보자

int main() {
    cin >> t;
    for(int i=1; i<=t; i++) {
        cin >> v[i];
        if(i % 2 != 0) {
            odd += v[i];
        } else {
            even += v[i];
        }
    }

    if(t==3 && odd > even) {
        cout << -1;
    } else {
        cout << abs(odd - even);
    }

    return 0;
}