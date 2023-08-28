#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k;
    cin >> k;

    long long n;
    stack<long long> s;
    for (int i = 0; i < k; i++) {
        cin >> n;
        if (n == 0) {
            s.pop();
        } else {
            s.push(n);
        }
    }

    long long res = 0;
    int s_size = (int)s.size();
    for (int i=0; i<s_size; i++) {
        res += s.top();
        s.pop();
    }

    cout << res;

    return 0;
}