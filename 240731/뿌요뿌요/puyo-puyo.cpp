#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int box[101][101];
int n;
int block_num=0;
bool CanGo(int x, int y, int num){
    if(x<0||y<0||x>=n||y>=n) return false;
    if(box[x][y]!=num) return false;
    return true;
}
void dfs(int x, int y, int num){
    int dx[4]={0,1,-1,0};
    int dy[4]={1,0,0,-1};
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(CanGo(nx,ny,num)){
            block_num++;
            box[nx][ny]=0;
            dfs(nx,ny,num);
        }
    }
    
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>box[i][j];
        }
    }
    int boom_num=0;
    int max_block_num=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(box[i][j]){
                block_num=0;
                dfs(i,j,box[i][j]);
                if(block_num>=4) boom_num++;
                max_block_num=max(max_block_num,block_num);
            }
        }
    }
    cout<<boom_num<<' '<<max_block_num;

    return 0;
}