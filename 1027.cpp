#include <iostream>
#include <algorithm>
using namespace std;

#define pii pair<long long, long long>

long long ccw(pii p1, pii p2, pii p3) {
    long long s = p1.first * p2.second + p2.first * p3.second + p3.first * p1.second;
    s -= (p1.second * p2.first + p2.second * p3.first + p3.second * p1.first);

    if (s > 0) return 1;
    else if (s == 0) return 0;
    else return -1;
}

bool isIntersect(pair<pii, pii> l1, pair<pii, pii> l2) {

    pii p1 = l1.first;
    pii p2 = l1.second;
    pii p3 = l2.first;
    pii p4 = l2.second;

    long long p1p2 = ccw(p1, p2, p3) * ccw(p1, p2, p4); // l1 기준
    long long p3p4 = ccw(p3, p4, p1) * ccw(p3, p4, p2); // l2 기준

    // 두 직선이 일직선 상에 존재
    if (p1p2 == 0 && p3p4 == 0) {
        // 비교를 일반화하기 위한 점 위치 변경
        if (p1 > p2) swap(p2, p1);
        if (p3 > p4) swap(p3, p4);

        return p3 <= p2 && p1 <= p4; // 두 선분이 포개어져 있는지 확인
    }

    return p1p2 <= 0 && p3p4 <= 0;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, cnt = 0, ans = 0;
    long long building[51] = {0, };

    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> building[i];
    }
    if(n==1) {
        cout << 0;
        return 0;
    }
    if(n==2) {
        cout << 1;
        return 0;
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            pii l1 = {i, building[i]};
            pii l2 = {j, building[j]};
            if(abs(j-i)>1) {
                bool flag = false;
                for(int k=min(i, j)+1; k<max(i,j); k++) {
                    pii l3 = {k, building[k]};
                    pii l4 = {k, 0};
                    if(!isIntersect({l1, l2}, {l3, l4})) {
                        flag = true;
                    } else {
                        flag = false;
                        break;
                    }
                }
                if(flag) cnt++;
            } else if(abs(j-i)==1){
                cnt++;
            } else continue;
        }
        ans = max(ans, cnt);
//        cout << i << ": " << ans << " " << cnt << endl;
        cnt = 0;
    }

    cout << ans;

    return 0;
}