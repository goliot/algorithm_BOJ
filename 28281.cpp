#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    int val[100001];
    cin >> n >> x;
    int minCnt = INT_MAX;
    for(int i=1; i<=n; i++) {
        cin >> val[i];
        if(i > 1) minCnt = min(val[i] + val[i-1], minCnt);
    }

    cout << minCnt * x;

    return 0;
}