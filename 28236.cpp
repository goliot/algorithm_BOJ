#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    pair<int, int> p[100001];
    int n, m, k;
    cin >> n >> m >> k;
    int res = 0;
    int resClass = 0;
    for(int i=1; i<=k; i++) {
        cin >> p[i].first >> p[i].second;
        if(i == 1) {
            res = (p[i].first - 1) + ((m+1) - p[i].second);
            resClass = i;
        }
        if(res > (p[i].first - 1) + ((m+1) - p[i].second)) {
            res = (p[i].first - 1) + ((m+1) - p[i].second);
            resClass = i;
            //cout << "res change to " << i << '\n';
        }
    }

    cout << resClass;
    return 0;
}