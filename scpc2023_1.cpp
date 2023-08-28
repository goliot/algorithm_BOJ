#include <iostream>
using namespace std;

int main() {
    int T; // 테스트 케이스 개수
    cin >> T;

    for (int case_num = 1; case_num <= T; case_num++) {
        int N, A, B;
        cin >> N >> A >> B;

        int max_boxes = 0;
        for (int a_boxes = 0; a_boxes <= N / A; a_boxes++) {
            int remaining_apples = N - a_boxes * A;
            if (remaining_apples % B == 0) {
                int b_boxes = remaining_apples / B;
                max_boxes = max(max_boxes, a_boxes + b_boxes);
            }
        }

        cout << "Case #" << case_num << endl;
        cout << max_boxes << endl;
    }

    return 0;
}