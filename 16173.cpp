#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int map[4][4] = {0, };
bool visited[4][4] = {false, };
int dy[] = {1, 0};
int dx[] = {0, 1};
int n;
bool flag = false;

bool bfs() {
    queue<pair<int, int> > q;
    visited[0][0] = true;
    q.emplace(0, 0);
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(map[x][y] == -1) return true;
        for(int i=0; i<2; i++) {
            int nx = x + dx[i] * map[x][y];
            int ny = y + dy[i] * map[x][y];

            if(nx >= 0 && nx <= n-1 && 0 <= ny && ny <= n-1) {
                if(!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    return false;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    flag = bfs();
    if(flag) cout << "HaruHaru";
    else cout << "Hing";

    return 0;
}