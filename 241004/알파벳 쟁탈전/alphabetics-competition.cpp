#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int N, K;
vector<tuple<char, int, int>> conditions;  // 조건 (S 또는 D, 학생 a, 학생 b)
int result = 0;  // 가능한 배치의 수

// 현재까지의 배치가 조건을 만족하는지 확인하는 함수
bool isValid(const vector<char>& assignment, int student) {
    for (const auto& condition : conditions) {
        char c;
        int a, b;
        tie(c, a, b) = condition;

        // 아직 배정되지 않은 학생들은 조건 검사를 건너뜀
        if (a >= student || b >= student) continue;

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

// 백트래킹으로 가능한 모든 배치를 확인하는 함수
void backtrack(vector<char>& assignment, int student) {
    if (student == N) {
        // 모든 학생에게 문자가 배정되었고 조건이 모두 만족된 경우
        result++;
        return;
    }

    // 학생에게 'A', 'B', 'C' 중 하나를 할당
    for (char c : {'A', 'B', 'C'}) {
        assignment[student] = c;

        // 현재 배치가 조건을 만족하면 다음 학생으로 진행
        if (isValid(assignment, student + 1)) {
            backtrack(assignment, student + 1);
        }
    }
}

int main() {
    cin >> N >> K;

    // 조건 입력받기
    for (int i = 0; i < K; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        conditions.push_back({c, a - 1, b - 1});  // 0-based 인덱스
    }

    vector<char> assignment(N);  // 학생들의 문자 배치

    // 백트래킹을 사용하여 가능한 배치 수를 계산
    backtrack(assignment, 0);

    // 결과 출력
    cout << result << endl;

    return 0;
}