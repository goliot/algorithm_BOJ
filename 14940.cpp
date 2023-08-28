#include <iostream> //14940
#include <queue>
using namespace std;

int n, m;
int map[1001][1001];
bool visited[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

queue<pair<int, int> > q;

void bfs() {
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m) {
                if(!visited[nx][ny]) {
                    map[nx][ny] = map[x][y]+1;
                    visited[nx][ny] = true;
                    q.emplace(nx, ny);
                }
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j]==2) {
                map[i][j] = 0;
                q.emplace(i, j);
                visited[i][j] = true;
            } else if(map[i][j]==0) {
                visited[i][j] = true;
            }
        }
    }
    bfs();

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j]) {
                cout << -1 << " ";
            } else {
                cout << map[i][j] << " ";
            }
        }
        cout << '\n';
    }

    return 0;
}