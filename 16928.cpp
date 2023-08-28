#include <iostream> //16928
#include <algorithm>
#include <queue>
using namespace std;

int map[102] = {0, };
bool visited[102] = {false, };

void bfs(int x, int c) {
    queue<pair<int, int> > q;
    q.emplace(x, c);
    while(!q.empty()) {
        int loc = q.front().first;
        int cnt = q.front().second;
        q.pop();

        for(int i=1; i<=6; i++) {
            int nx = loc + i;
            if(nx == 100) {
                cout << cnt + 1;
                return;
            }
            else if(nx < 100) {
                while(map[nx] != 0) {
                    nx = map[nx];
                }
                if(!visited[nx]) {
                    q.emplace(nx, cnt + 1);
                    visited[nx] = true;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        map[x] = y;
    }

    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        map[u] = v;
    }

    bfs(1, 0);

    return 0;
}