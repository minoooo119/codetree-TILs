#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int n,k;
int grid[101][101];
int visited[101][101];
void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=0;
        }
    }
}
tuple<int,int,int> max_t(tuple<int,int,int> t1, tuple<int,int,int> t2){
    if(get<0>(t1) < get<0>(t2)) {return (t2);}
    else if(get<0>(t1) == get<0>(t2)){
        if(get<1> (t1) < get<1>(t2)){
            return (t1);
        }
        else if(get<1> (t1) == get<1>(t2)){
            if(get<2>(t1) < get<2>(t2)){
                return (t1);
            }
            else if(get<2>(t1) == get<2>(t2)){
                return (t1);
            }
            else{
                return (t2);
            }
        }
        else{
            return (t2);
        }
    }
    else{
        return t1;
    }
}
tuple<int,int,int> bfs(int x, int y, int num){
    queue<tuple<int,int,int>> q;
    visited[x][y]=1;
    q.push(make_tuple(grid[x][y],x,y));
    tuple<int,int,int> max_num=make_tuple(0,101,101);
    while(!q.empty()){
        int val=get<0>(q.front());
        int x=get<1>(q.front());
        int y=get<2>(q.front());
        // cout<<val<<" "<<x<<' '<<y<<'\n';
        if(val!=num) max_num=max_t(max_num, q.front());
        q.pop();
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx<0||ny<0||nx>=n||ny>=n) continue;
            if(visited[nx][ny]) continue;
            if(grid[nx][ny]>num)continue;
            visited[nx][ny]=1;
            q.push(make_tuple(grid[nx][ny],nx,ny));
        }
    }
    // cout<<get<0>(max_num)<<'\n';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<visited[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    return max_num;
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    //시작 위치
    int r, c;
    cin>>r>>c;
    //r-1, c-1
    //행, 열이 가장 작은게 좋은 것
    tuple<int,int,int> t=bfs(r-1,c-1,grid[r-1][c-1]);
    for(int i=1;i<k;i++){
        init();
        t=bfs(get<1>(t),get<2>(t),get<0>(t));
    }
    cout<<get<1>(t)<<' '<<get<2>(t)<<'\n';
    
    return 0;
}