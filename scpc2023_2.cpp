#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

ll sol(ll d, vector<ll>& strawberries) {
    sort(strawberries.begin(), strawberries.end());

    int maxS = 0;
    int n = (int)strawberries.size();
    int left = 0, right = 0;

    if(abs(strawberries[0]) > d && abs(strawberries[n-1]) > d) {
        return 0;
    }
    while(d > 0 && right < n && left < n) {
        
    }

    return maxS;
}

int main() {
    int t;
    ll n, d;
    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n >> d;
        vector<ll> strawberries(n);
        for(int j=0; j<n; j++) {
            cin >> strawberries[j];
        }
        cout << "Case #" << i+1 << '\n';
        cout << sol(d, strawberries) << '\n';
    }

    return 0;
}