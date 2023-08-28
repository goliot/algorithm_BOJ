#include <iostream> //20529
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int t, n;

vector<int> toInt(string s) {
    vector<int> nMbti;
    if(s[0] == 'E') nMbti.push_back(1);
    else nMbti.push_back(2);

    if(s[1] == 'N') nMbti.push_back(1);
    else nMbti.push_back(2);

    if(s[2] == 'T') nMbti.push_back(1);
    else nMbti.push_back(2);

    if(s[3] == 'P') nMbti.push_back(1);
    else nMbti.push_back(2);

    return nMbti;
}

int getDistance(vector<vector<int> > v) {
    int dis = 0;

    for(int i=0; i<4; i++) {
        dis += abs(v[0][i] - v[1][i]);
    }
    for(int i=0; i<4; i++) {
        dis += abs(v[1][i] - v[2][i]);
    }
    for(int i=0; i<4; i++) {
        dis += abs(v[2][i] - v[0][i]);
    }

    return dis;
}

int sol(vector<vector<int> > mbti) {
    int cnt = INT_MAX;
    for(int i=0; i<n-2; i++) {
        for(int j=i+1; j<n-1; j++) {
            for(int k=j+1; k<n; k++) {
                vector<vector<int> > v;
                v.push_back(mbti[i]);
                v.push_back(mbti[j]);
                v.push_back(mbti[k]);
                cnt = min(cnt, getDistance(v));
            }
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> t;
    for(int i=0; i<t; i++) {
        cin >> n;
        vector<vector<int> > mbti;
        for (int j = 0; j < n; j++) {
            string tmp;
            cin >> tmp;
            mbti.push_back(toInt(tmp));
        }
        if(n>32) cout << 0 << '\n';
        else cout << sol(mbti) << '\n';
    }

    return 0;
}