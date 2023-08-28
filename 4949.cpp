#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> small;
    stack<char> big;
    string s;
    do {
        cin >> s;
        for(char c : s) {
            if(c == '(') {
                small.push(c);
            } else if(c==')' && (int)small.size() > 0) {
                small.pop();
            }
        }
    } while(s != ".");

    return 0;
}