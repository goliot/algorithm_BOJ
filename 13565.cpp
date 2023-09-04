#include <iostream> //13565
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

int n, m;
int map[1001][1001] = {0, };
bool visited[1001][1001] = {false, };
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
queue<pair<int, int> > q;

//void bfs(int y, int x) {
//    visited[y][x] = true;
//    q.emplace(y, x);
//    while(!q.empty()) {
//        y = q.front().first;
//        x = q.front().second;
//        q.pop();
//
//        for(int i=0; i<4; i++) {
//            int ny = y + dy[i];
//            int nx = x + dx[i];
//
//            if(ny<0 || nx<0 || ny>=m || nx>=n) {
//                continue;
//            }
//            if(map[ny][nx]==0 && !visited[ny][nx]) {
//                visited[ny][nx] = true;
//                q.emplace(ny, nx);
//            }
//        }
//    }
//}

void dfs(int y, int x) {
    visited[y][x] = true;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny < 0 || nx < 0 || ny >= m || nx >= n) {
            continue;
        }
        if(map[ny][nx]==0 && !visited[ny][nx]) {
            visited[ny][nx] = true;
            dfs(ny, nx);
        }
    }
}

int main() {
    //scanf 쓸때는 sync_with_stdio 쓰지 말자
    cin >> m >> n;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            scanf("%1d", &map[i][j]);
        }
    }

    for(int i=0; i<n; i++) {
        if(map[0][i]==0 && !visited[0][i]) {
//            bfs(0, i);
            dfs(0, i);
        }
    }

    bool flag = false;
    for(int i=0; i<n; i++) {
        if(visited[m-1][i]) {
            flag = true;
        }
    }

    if(flag) cout << "YES";
    else cout << "NO";

    return 0;
}