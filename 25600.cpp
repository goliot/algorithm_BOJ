#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, d, g, n;
    cin >> n;
    int res = 0;
    for(int i=0; i<n; i++) {
        cin >> a >> d >> g;
        int cal;
        if(a == d + g) cal = 2 * a * (d + g);
        else cal = a * (d + g);
        res = max(res, cal);
    }
    cout << res;

    return 0;
}