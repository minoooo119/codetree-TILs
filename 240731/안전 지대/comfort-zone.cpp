#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int grid[51][51];
int visited[51][51];
void init();
void dfs(int x, int y, int K);
bool CanGo(int x, int y, int K);
bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.second==p2.second) return p1.first<p2.first;
    return p1.second>p2.second;
}
int n,m;
int main() {
    // 여기에 코드를 작성해주세요.
    int max_height=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            max_height=max(max_height, grid[i][j]);
        }
    }
    vector<pair<int,int> > v;
    for(int k=1;k<=max_height;k++){
        init();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>k&&!visited[i][j]){ 
                    visited[i][j]=1;
                    dfs(i,j,k);
                    cnt++;
                }
            }

        }
        v.push_back(make_pair(k,cnt));
    }
    sort(v.begin(), v.end(), compare);
    cout<<v[0].first<<" "<<v[0].second;
    return 0;
}

void init(){
    for(int i=0;i<50;i++){
        fill(visited[i], visited[i]+50, 0);
    }
}
bool CanGo(int x, int y, int K){
    if(x<0 || y<0 || x>=n || y>=m) return false;
    if(visited[x][y]) return false;
    if(grid[x][y]<=K) return false;
    return true;
}

void dfs(int x, int y, int K){
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        // cout<<"x: "<<x<<" y: "<<y<<endl;
        // cout<<"nx: "<<nx<<" ny: "<<ny<<endl;
        if(CanGo(nx,ny,K)){
            // cout<<"nx: "<<nx<<" ny: "<<ny<<endl;
            visited[nx][ny]=1;
            dfs(nx,ny,K);
        }
    }
}