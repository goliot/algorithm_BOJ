#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, m, k, a, b;
long long c;
long long *tree;
long long arr[1000001];

long long init(int node, int start, int end)  {
    if(start == end) return tree[node] = arr[start];
    int mid = (start + end)/2;
    return tree[node] = init(2*node, start, mid) * init(2*node+1, mid+1, end) % 1000000007;
}

long long mul(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 1;
    if(left <= start && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return mul(node*2, start, mid, left, right) * mul(node*2+1, mid+1, end, left, right) % 1000000007;
}

void update(int node, int start, int end, int idx, long long diff) {
    if(idx < start || idx > end) return;
    if(start == end) {
        tree[node] = diff;
        return;
    }
    int mid = (start+end)/2;

    update(node*2, start, mid, idx, diff);
    update(node*2+1, mid+1, end, idx, diff);

    tree[node] = (tree[node*2] * tree[node*2+1]) % 1000000007;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m >> k;
    int height = ceil(log2(n));
    tree = new long long[1 << (height+1)];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    init(1, 0, n-1);

    for(int i=0; i<m+k; i++) {
        cin >> a >> b >> c;
        if(a == 1) {
            update(1, 0, n-1, b-1, c);
        }
        else if(a == 2){
            cout << mul(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}