#include <iostream> //21736
#include <queue>
using namespace std;

int n, m;
char map[601][601];
bool visited[601][601];
int cnt = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int a, int b) {
    visited[a][b] = true;
    queue<pair<int, int> > q;
    q.emplace(a, b);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && ny>=0 && nx<n && ny<m && !visited[nx][ny]) {
                if(map[nx][ny] == 'X') continue;
                if(map[nx][ny] == 'P') cnt++;
                visited[nx][ny] = true;
                q.emplace(nx, ny);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    int myX, myY;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j] == 'I') {
                myX = i;
                myY = j;
            }
        }
    }

    bfs(myX, myY);

    if(!cnt) cout << "TT";
    else cout << cnt;

    return 0;
}