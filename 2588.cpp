#include <iostream>
#include <cstdlib>  // atoi 함수가 선언된 헤더파일

using namespace std;

int main() {
    int A;
    char B[4];

    cin >> A;
    cin >> B;

    cout << A * (B[2] - '0') << "\n";
    cout << A * (B[1] - '0') << "\n";
    cout << A * (B[0] - '0') << "\n";
    cout << A * atoi(B) << "\n";

    return 0;
}