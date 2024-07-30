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