#include <iostream> //1182
using namespace std;

int n, s, cnt=0;
int arr[30];

void func(int cur, int tot) {
    if(cur==n) {
        if(tot==s) cnt++;
        return;
    }
    func(cur+1, tot);
    func(cur+1, tot+arr[cur]);
}

int main() {
    cin >> n >> s;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    func(0, 0);
    if(s==0) cnt--;

    cout << cnt;
    return 0;
}