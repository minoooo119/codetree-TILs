#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int grid[101][101];
int visited[101][101];
int n,m;
bool CanGo(int x, int y){
    if(x<0||y<0||x>=n||y>=n) return false;
    if(visited[x][y]||grid[x][y]==1) return false;
    return true;
}
queue<pair<int,int>> q;
int num=0;
int BFS(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(CanGo(nx,ny)){
                // cout<<"push";
                num++;
                visited[nx][ny]=1;
                q.push({nx,ny});
            }
        }

    } 
    // cout<<"fin\n";
    return num;
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            visited[i][j]=0;
        }
    }
    vector<pair<int,int>> p;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        q.push({a-1,b-1});
        visited[a-1][b-1]=1;
        num++;
    }
    cout<<BFS();
    return 0;
}