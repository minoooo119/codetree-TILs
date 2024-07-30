#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[101][101];

int bfs(){
    queue<pair<int,pair<int,int>>> q;
    q.push({a[0][0],{0,0}});
    int min_mx_num=-1;
    while(!q.empty()){
        int m=q.front().first;
        int x=q.front().second.first;
        int y=q.front().second.second;
        // cout<<x<<y<<'\n';
        q.pop();
        if(m<min_mx_num)continue;
        if(x==n-1&&y==n-1){
            min_mx_num=max(min_mx_num,m);
            continue;
        }
        if(x+1<n) q.push({min(m,a[x+1][y]),{x+1,y}});
        if(y+1<n) q.push({min(m,a[x][y+1]),{x,y+1}});
    }
    return min_mx_num;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    int dp[101][101];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            // if(i==0&&j==0) dp[i][j]=a[i][j];
            // else if(i==0) dp[i][j]=min(dp[i][j-1],a[i][j]);
            // else if(j==0) dp[i][j]=min(dp[i-1][j],a[i][j]);
        }
    }
    cout<<bfs()<<'\n';
    return 0;
}