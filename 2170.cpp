#include <iostream> //2170
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
int n;
ll x, y;
vector<pair<ll, ll> > v;
ll cnt = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        if(x > y) swap(x, y);
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end());
    ll start = v[0].first, end = v[0].second;
    for(int i=1; i<n; i++) {
        if(end > v[i].first) {
            if(v[i].second > end) end = v[i].second;
        } else {
            cnt += end - start;
            start = v[i].first;
            end = v[i].second;
        }
    }
    cnt += (end - start);

    cout << cnt;
    return 0;
}