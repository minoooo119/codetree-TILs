#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int grid[26][26];
int visited[26][26];
bool canGo(int r,int c){
    if(grid[r][c]==0||visited[r][c]==1) return false;
    return true;
}
int dfs(int x, int y, int c){
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(canGo(nx,ny)){
            visited[nx][ny]=true;
            return dfs(nx,ny,c+1);
        }
    }
    return c;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            visited[i][j]=0;
        }
    }
    int city_num=0;
    vector<int> city_people_num;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1&&visited[i][j]==0){
                city_num++;
                visited[i][j]=1;
                city_people_num.push_back(dfs(i,j,1));
            }
        }
    }
    sort(city_people_num.begin(),city_people_num.end());

    cout<<city_num<<'\n';
    for(auto x: city_people_num){
        cout<<x<<'\n';
    }

    return 0;
}