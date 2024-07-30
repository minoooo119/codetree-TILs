#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main() {
    // 여기에 코드를 작성해주세요.
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    int a[501][501];
    int dp[501][501];
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            dp[i][j]=0;
            pq.push({a[i][j],{i,j}});
        }
    }

    while(!pq.empty()){
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        int val=pq.top().first;
        pq.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(a[nx][ny]>a[x][y]){
                dp[nx][ny]=max(dp[nx][ny],dp[x][y]+1);
            }
        }
    }
    int mx_num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mx_num = max(mx_num,dp[i][j]);
            // cout<<dp[i][j]<<' ';
        }
        // cout<<'\n';
    }
    cout<<mx_num+1<<"\n";
    return 0;
}