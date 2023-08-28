#include <iostream> //11501
#include <vector>
using namespace std;

int main() {
    int t, n;
    vector<int> v;

    cin >> t;
    while(t--) {
        cin >> n;
        long long res = 0;

        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            v.push_back(x);
        }

        int max = v.back();
        for(int i=(int)v.size()-1; i>=0; i--) {
            if(v[i] > max) {
                max = v[i];
            } else {
                res += (max-v[i]);
            }
        }

        cout << res << '\n';
        v.clear();
    }

    return 0;
}