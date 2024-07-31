#include <iostream>
using namespace std;
// 가능하면 DFS 탐색 시에도 재귀 함수 호출 직전에 visited 표기를 하는 패턴으로 연습을 하는 것을 강력 추천드립니다.
int n,m;
int grid[101][101];
int visited[101][101];
bool canGo(int r, int c){
    if(r<0||c<0||r>=n||c>=m) return false;
    if(visited[r][c]) return false;
    if(!grid[r][c]) return false;
    return true;
}
bool res=false;
void dfs(int x, int y){
    if(x==n-1&&y==m-1) res=true;
    int dx[2]={1,0};
    int dy[2]={0,1};
    for(int i=0;i<2;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(canGo(nx,ny)){
            visited[nx][ny]=true;
            dfs(nx,ny);
        }
    }
}
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
            visited[i][j]=0;
        }
    }
    dfs(0,0);
    if(res){cout<<1<<'\n'; return 0;}
    cout<<0<<'\n';
    

    return 0;
}