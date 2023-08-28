#include <iostream> //1019
using namespace std;

typedef long long ll;

ll n;
ll cnt[10] = {0, };

void subCounting(int num, int tenPower) {
    while(num) {
        cnt[num%10] += tenPower;
        num /= 10;
    }
}

void sol(int end) {
    int start = 1;
    int tenPower = 1;

    while(start <= end) {
        while(0 != start%10 && start <= end) {
            subCounting(start, tenPower);
            start++;
        }
        if(end < start) return;
        while(9 != end%10 && start <= end) {
            subCounting(end, tenPower);
            end--;
        }
        start /= 10;
        end /= 10;

        for(long long & i : cnt) {
            i += (end - start + 1) * tenPower;
        }
        tenPower *= 10;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    sol((int)n);

    for(ll i : cnt) {
        cout << i << " ";
    }

    return 0;
}