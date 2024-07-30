#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max (int a, int b){
    return a>b? a:b;
}
int main() {
    // 여기에 코드를 작성해주세요.
    int grid[101][101];
    int dp[101][101];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    dp[0][n-1]=grid[0][n-1];
    for(int i=n-2;i>=0;i--){
        dp[0][i]=dp[0][i+1]+grid[0][i];
    }
    for(int i=1;i<n;i++){
        dp[i][n-1]=dp[i-1][n-1]+grid[i][n-1];
    }
    for(int i=1;i<n;i++){
        for(int j=n-2;j>=0;j--){
            // cout<<grid[i][j]<<' ';
            dp[i][j]=min(dp[i-1][j],dp[i][j+1])+grid[i][j];
        }
        // cout<<'\n';
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<dp[i][j]<<' ';
    //     }   
    //     cout<<'\n';
    // }
    cout<<dp[n-1][0];
    return 0;
}
// #include <iostream>
// #include <algorithm>

// #define MAX_N 1000

// using namespace std;

// // 변수 선언
// int n;
// int num[MAX_N][MAX_N];
// int dp[MAX_N][MAX_N];

// void Initialize() {
//     // 시작점의 경우 dp[0][n - 1] = num[0][n - 1]으로 초기값을 설정해줍니다
//     dp[0][n - 1] = num[0][n - 1];

//     // 최우측 열의 초기값을 설정해줍니다.
//     for(int i = 1; i < n; i++)
//         dp[i][n - 1] = dp[i - 1][n - 1] + num[i][n - 1];

//     // 최상단 행의 초기값을 설정해줍니다.
//     for(int j = n - 2; j >= 0; j--)
//         dp[0][j] = dp[0][j + 1] + num[0][j];
// }

// int main() {
//     // 입력:
//     cin >> n;

//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             cin >> num[i][j];

//     // 초기값 설정
//     Initialize();

//     // 탐색하는 위치의 위에 값과 우측 값 중에 작은 값에
//     // 해당 위치의 숫자를 더해줍니다. 
//     for(int i = 1; i < n; i++)
//         for(int j = n - 2; j >= 0; j--) 
//             dp[i][j] = min(dp[i - 1][j], dp[i][j + 1]) + num[i][j];

//     cout << dp[n - 1][0];
//     return 0;
// }