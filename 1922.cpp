#include <iostream> //1197
#include <vector>
#include <algorithm>
using namespace std;

//크루스칼 알고리즘 사용
//그러나 최소 순으로 정렬하는게 아닌 큰 순서로 내림차순 정렬
//즉 최대 신장 트리

struct bridge { //에지
    int s, e, user;
}; //시작점, 도착점, 사용자 수

struct city { //노드
    int parent, num; //부모, 집합의 높이
};

bool cmp(const bridge& a, const bridge& b) {
    return a.user < b.user;
} //내림차순 배열 비교함수

//부모 찾는 함수(속한 그룹의 루트: 가장 큰 거)
int find(vector<city>& cities, int i) {
    if(cities[i].parent != i) {
        cities[i].parent = find(cities, cities[i].parent);
    }
    return cities[i].parent;
}

//집합 합치기
void mergeGroup(vector<city>& cities, int a, int b) {
    int aRoot = find(cities, a);
    int bRoot = find(cities, b);

    //집합이 높이 낮은쪽 -> 높은쪽 으로 붙음
    if(cities[aRoot].num < cities[bRoot].num) {
        cities[aRoot].parent = bRoot;
    } else if(cities[aRoot].num > cities[bRoot].num) {
        cities[bRoot].parent = aRoot;
    } else {
        cities[bRoot].parent = aRoot;
        cities[aRoot].num++;
    }
}

//최대 신장 트리를 만드는 함수
vector<bridge> makeMST(vector<bridge>& bridges, int n) {
    vector<bridge> maxTree; //리턴할 최대 신장 트리
    vector<city> cities(n+1); //노드 벡터

    //노드 부모 자기 자신으로 초기화, 높이 초기화
    for(int i=0; i<n; i++) {
        cities[i].parent = i;
        cities[i].num = 0;
    }

    sort(bridges.begin(), bridges.end(), cmp);

    for(const auto& bridge : bridges) {
        int sParent = find(cities, bridge.s);
        int eParent = find(cities, bridge.e);

        if(sParent != eParent) {
            maxTree.push_back(bridge);
            mergeGroup(cities, sParent, eParent);
        }
    }

    return maxTree;
}

int main() {
    int n, m; //노드 수, 에지 수
    int deletedCounter = 0; //출력용 카운터, 폭파된 다리 이용자 수 총 합
    cin >> n >> m;

    vector<bridge> bridges(m); //입력받을 다리

    for(int i=0; i<m; i++) {
        cin >> bridges[i].s >> bridges[i].e >> bridges[i].user;
        //deletedCounter += bridges[i].user; //일단 모든 다리의 이용자수를 구해놓고
        //최대 신장 트리 만들어 거기에 속한 다리의 이용자 수의 총 합을 뺴면 답
    }

    vector<bridge> maxTree = makeMST(bridges, n); //필요없는 다리 폭파

    for(auto& i : maxTree) {
//        cout << i.s << " " << i.e << " " << i.user << endl;
        deletedCounter += i.user;
    } //원래있던 다리의 이용자 수 총 합 - 폭파되고 남은 다리의 이용자 수 총 합

    cout << deletedCounter;

    return 0;
}