#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int box[101][101];
int n;
int block_num=1;
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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
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
                block_num=1;
                int num=box[i][j];
                box[i][j]=0;
                dfs(i,j,num);
                if(block_num>=4) boom_num++;
                max_block_num=max(max_block_num,block_num);
            }
        }
    }
    cout<<boom_num<<' '<<max_block_num;

    return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 100
#define DIR_NUM 4

using namespace std;

int n;
int grid[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];

int max_block;
int bomb_cnt;

int curr_block_num;

// 탐색하는 위치가 격자 범위 내에 있는지 여부를 반환합니다.
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 탐색하는 위치로 움직일 수 있는지 여부를 반환합니다.
bool CanGo(int x, int y, int color) {
    if(!InRange(x, y))
        return false;

    if(visited[x][y] || grid[x][y] != color)
        return false;

    return true;
}

void DFS(int x, int y) {
    //0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
    int dx[DIR_NUM] = {0, 1, 0, -1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    // 네 방향에 각각에 대하여 DFS 탐색을 합니다.
    for(int dir = 0; dir < DIR_NUM; dir++) {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if(CanGo(new_x, new_y, grid[x][y])){
            visited[new_x][new_y] = true;
            // 블럭이 하나 추가됩니다.
            curr_block_num++;
            DFS(new_x, new_y);
        }
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grid[i][j];

    // 격자의 각 위치에서 탐색을 시작할 수 있는 경우
    // 한 블럭에 대한 DFS 탐색을 수행합니다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!visited[i][j] && grid[i][j]) {
                // 해당 블럭을 방문할 수 있는 경우 visited 배열을 갱신하고
                // 새로운 블럭을 탐색한다는 의미로 curr_block_num을 1으로 갱신합니다.
                visited[i][j] = true;
                curr_block_num = 1;
                
                DFS(i, j);

                // 한 블럭 묶음에 대한 탐색이 끝난 경우 답을 갱신합니다.
                if(curr_block_num >= 4)
                    bomb_cnt++;
                
                max_block = max(max_block, curr_block_num);
            }
        }
    }
    
    cout << bomb_cnt << " " << max_block;
    return 0;
}
*/