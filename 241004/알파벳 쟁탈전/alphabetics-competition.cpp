#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int N, K;
vector<tuple<char, int, int>> conditions;  // 조건 (S 또는 D, 학생 a, 학생 b)

// 재귀적으로 가능한 모든 배치를 확인하는 함수
int solve(vector<char>& assignment, int student) {
    // 모든 학생의 배치가 완료된 경우
    if (student == N) {
        // 조건을 전부 확인
        for (auto& condition : conditions) {
            char type;
            int a, b;
            tie(type, a, b) = condition;

            // 동일(S) 조건
            if (type == 'S' && assignment[a] != assignment[b]) {
                return 0;  // 조건을 만족하지 않으면 이 배치는 실패
            }
            // 다름(D) 조건
            if (type == 'D' && assignment[a] == assignment[b]) {
                return 0;  // 조건을 만족하지 않으면 이 배치는 실패
            }
        }
        return 1;  // 모든 조건을 만족했으면 1을 반환 (성공적인 배치)
    }

    // 세 가지 문자(A, B, C)를 할당
    int result = 0;
    for (char c : {'A', 'B', 'C'}) {
        assignment[student] = c;
        result += solve(assignment, student + 1);  // 다음 학생으로 진행
    }

    return result;
}

int main() {
    cin >> N >> K;

    // 조건 입력받기
    for (int i = 0; i < K; i++) {
        char c;
        int a, b;
        cin >> c >> a >> b;
        a--; b--;  // 0-based 인덱스 처리
        conditions.push_back({c, a, b});
    }

    // 각 학생의 문자 배치 (N명의 학생에 대해 할당할 공간을 만듦)
    vector<char> assignment(N);

    // 가능한 배치 수를 재귀적으로 계산
    int result = solve(assignment, 0);

    // 결과 출력
    cout << result << endl;

    return 0;
}