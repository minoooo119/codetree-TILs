#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// 학생들의 배치가 주어진 조건을 만족하는지 확인하는 함수
bool isValid(const vector<char>& assignment, const vector<tuple<char, int, int>>& conditions) {
    for (const auto& condition : conditions) {
        char c;
        int a, b;
        tie(c, a, b) = condition;

        // 동일(S) 조건: a번 학생과 b번 학생이 같은 문자를 가져야 함
        if (c == 'S' && assignment[a] != assignment[b]) {
            return false;
        }

        // 다름(D) 조건: a번 학생과 b번 학생이 다른 문자를 가져야 함
        if (c == 'D' && assignment[a] == assignment[b]) {
            return false;
        }
    }
    return true;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<tuple<char, int, int>> conditions(K);

    // 조건 입력
    for (int i = 0; i < K; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        conditions[i] = {c, a - 1, b - 1};  // 0-based 인덱스
    }

    int count = 0;

    // 모든 학생의 배치를 브루트포스로 시도 (3^N 가지 경우)
    vector<char> assignment(N);  // 학생들의 문자 배치

    // 3^N 번 반복 (학생들에게 A, B, C 중 하나를 배정하는 경우)
    for (int i = 0; i < pow(3, N); i++) {
        int num = i;
        // 각 학생에게 'A', 'B', 'C' 배정
        for (int j = 0; j < N; j++) {
            assignment[j] = 'A' + (num % 3);
            num /= 3;
        }

        // 조건을 만족하는지 확인
        if (isValid(assignment, conditions)) {
            count++;
        }
    }

    // 결과 출력
    cout << count << endl;

    return 0;
}