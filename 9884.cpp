#include <iostream> //9884
using namespace std;

int gcd(int a, int b) {
    if(a < b) return gcd(b, a);
    else if(b == 0) return a;
    else return gcd(b, a % b);
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b);

    return 0;
}
