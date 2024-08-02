#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int grid[21][21];
int bomb[21][21];
int gold[21][21];
vector<int> temp;
vector<pair<int,int>> bomb_pos;

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            bomb[i][j]=0;
        }
    }
}
int count(){
    int res=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(bomb[i][j]) res++;
        }
    }
    return res;
}
void bomb_bomb(int r, int c,int seq){
    bomb[r][c]=1;
    int d1x[4]={2,1,-1,-2};
    int d1y[4]={0,0,0,0};
    int dx[4]={-1,0,0,1};
    int dy[4]={0,1,-1,0};
    int ddx[4]={-1,-1,1,1};
    int ddy[4]={1,-1,1,-1};
    switch(temp[seq]){
        case 1:
            for(int i=0;i<4;i++){
                int nx=r+d1x[i];
                int ny=c+d1y[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                bomb[nx][ny]=1;
            }
            break;
        case 2:
            for(int i=0;i<4;i++){
                int nx=r+dx[i];
                int ny=c+dy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                bomb[nx][ny]=1;
            }
            break;
        case 3:
            for(int i=0;i<4;i++){
                int nx=r+ddx[i];
                int ny=c+ddy[i];
                if(nx<0||ny<0||nx>=n||ny>=n) continue;
                bomb[nx][ny]=1;
            }
            break;
    }
}

int func(){
    int seq=0;
    init();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                bomb_bomb(i,j,seq++);
            }
        }
    }
    return count();
    
}
int mx_num=0;
void backtracking(int num,int cnt){
    if(num==cnt){
        int res=func();
        if(res>mx_num){
            mx_num=res;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    gold[i][j]=bomb[i][j];
                }
            }
        }
        return;
    }
    for(int i=1;i<=3;i++){
        temp.push_back(i);
        backtracking(num+1,cnt);
        temp.pop_back();
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]) {
                bomb_pos.push_back({i,j});
                cnt++;
            }
        }
    }
    backtracking(0,cnt);
    cout<<mx_num<<'\n';
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         cout<<gold[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }

    return 0;
}