#include <iostream>
#include <algorithm>
using namespace std;

int A[6];
int R[6][6], M[6][6];
int res = 0;
int n, k;

void dfs(int day, int r, int m) {
    if(day > k) {
        res = max(res, r + m);
        return;
    }

    for(int i=1; i<=n; i++) {
        int nr = r;
        int nm = m;
        if(A[i] > 0) {
            A[i]--;
            nr += R[day][i];
            for(int j=1; j<=n; j++) {
                if (A[j] > 0) {
                    A[j]--;
                    nm += M[day][j];
                    dfs(day + 1, nr, nm);
                    nm -= M[day][j];
                    A[j]++;
                }
            }
            A[i]++;
        }
    }
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> A[i];
    }
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=n; j++) {
            cin >> R[i][j];
        }
    }
    for(int i=1; i<=k; i++) {
        for(int j=1; j<=n; j++) {
            cin >> M[i][j];
        }
    }

    dfs(1, 0, 0);

    cout << res;

    return 0;
}