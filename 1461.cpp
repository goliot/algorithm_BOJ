#include <iostream> //1461
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m;
    int loc[51] = {0, };
    cin >> n >> m;
    int cnt = 0;
    int res = 0;
    for(int i=0; i<n; i++) {
        cin >> loc[i];
        if(loc[i]<0) cnt++;
    }

    sort(loc, loc+n);

    for(int i=n-1; i>=cnt; i-=m) {
        res += (loc[i]*2);
    }

    for(int i=0; i<cnt; i+=m) {
        res+= abs(loc[i]*2);
    }

    res -= max(abs(loc[0]), abs(loc[n-1]));
    cout << res;

    return 0;
}