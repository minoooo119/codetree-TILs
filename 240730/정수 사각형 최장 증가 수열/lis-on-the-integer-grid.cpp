#include <iostream>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    int a[501][501];
    int dp[501][501];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            dp[i][j]=1;
        }
    }
    while(1){
        int change=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0||ny<0||nx>=n||ny>=n) continue;
                    if(a[i][j]<=a[nx][ny]) continue;
                    if(dp[i][j]>=dp[nx][ny]+1) continue;
                    dp[i][j]=dp[nx][ny]+1;change++;
                    
                }
            }
        }
        if(change==0) break;
    }

    int mxNum=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // cout<<dp[i][j]<<' ';
            mxNum=max(mxNum,dp[i][j]);
        }
        // cout<<'\n';
    }
    cout<<mxNum;
    return 0;
}