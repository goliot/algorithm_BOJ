#include <iostream> //1159
#include <string>
using namespace std;

int N;
int alphabet[26];
string s = "abcdefghijklmnopqrstuvwxyz";

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        alphabet[input[0] - 'a']++;
    }
    bool predaja = true;
    for (int i = 0; i < 26; i++) {
        if (alphabet[i] >= 5) {
            cout << s[i];
            predaja = false;
        }
    }
    if (predaja) cout << "PREDAJA";
}