#include <iostream>
using namespace std;

int main() {
    int n;
    int dp[1001] = {0, };

    cin >> n;

    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;
    for(int i=4; i<=n; i++) {
        if(dp[i-1]==0 || dp[i-3]==0) dp[i] = 1;
        else dp[i] = 0;
    }

    if(dp[n] == 1) cout << "SK";
    else cout << "CY";

    return 0;
}