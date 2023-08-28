#include <iostream>
#include <algorithm>
using namespace std;

int t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;

    int res = 0;
    int fir[2];
    int sec[5];
    for(int i=0; i<t; i++) {
        for(int & j : fir) {
            cin >> j;
        }
        for(int & j : sec) {
            cin >> j;
        }
        sort(fir, fir+2);
        sort(sec, sec+5);
        res = max(res, (fir[1] + sec[3] + sec[4]));
    }
    cout << res;

    return 0;
}