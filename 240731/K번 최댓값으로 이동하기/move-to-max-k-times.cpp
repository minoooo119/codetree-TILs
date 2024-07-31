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
    tuple<int,int,int> max_num=make_tuple(0,x,y);
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
            if(grid[nx][ny]>=num)continue;
            visited[nx][ny]=1;
            q.push(make_tuple(grid[nx][ny],nx,ny));
        }
    }
    // cout<<get<0>(max_num)<<'\n';
    // cout<<get<1>(max_num)<<' '<<get<2>(max_num)<<'\n';
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
    // cout<<get<0>(t)<<'\n';
    cout<<get<1>(t)+1<<' '<<get<2>(t)+1<<'\n';
    
    return 0;
}

/*
#include <iostream>
#include <tuple>
#include <queue>

#define MAX_N 100
#define DIR_NUM 4
#define NOT_EXISTS make_pair(-1, -1)

using namespace std;

int n, k;

int grid[MAX_N][MAX_N];

// 현재 위치
pair<int, int> curr_cell;

queue<pair<int, int> > bfs_q;
bool visited[MAX_N][MAX_N];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int target_num) {
    return InRange(x, y) && !visited[x][y] && 
           grid[x][y] < target_num;
}

// visited 배열을 초기화 해줍니다.
void InitializeVisited() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            visited[i][j] = false;
}

void BFS() {
    int dx[DIR_NUM] = {0, 1, 0, -1};
    int dy[DIR_NUM] = {1, 0, -1, 0};

    
    int curr_x, curr_y;
    tie(curr_x, curr_y) = curr_cell;
    visited[curr_x][curr_y] = true;
    bfs_q.push(curr_cell);
    
    int target_num = grid[curr_x][curr_y];
    
    // BFS 탐색을 수행합니다.
    while(!bfs_q.empty()) {
        pair<int, int> curr_pos = bfs_q.front();
        int curr_x, curr_y;
        tie(curr_x, curr_y) = curr_pos;
        bfs_q.pop();

        for(int i = 0; i < DIR_NUM; i++) {
            int new_x = curr_x + dx[i];
            int new_y = curr_y + dy[i];

            if(CanGo(new_x, new_y, target_num)) {
                bfs_q.push(make_pair(new_x, new_y));
                visited[new_x][new_y] = true;
            }
        }
    }
}

// best 위치를 새로운 위치로 바꿔줘야 하는지를 판단합니다.
bool NeedUpdate(pair<int, int> best_pos, pair<int, int> new_pos) {
    // 첫 도달 가능한 위치라면
    // update가 필요합니다.
    if(best_pos == NOT_EXISTS)
        return true;
    
    int best_x, best_y;
    tie(best_x, best_y) = best_pos;
    
    int new_x, new_y;
    tie(new_x, new_y) = new_pos;
    
    // 숫자, -행, -열 순으로 더 큰 곳이 골라져야 합니다.
    return make_tuple(grid[new_x][new_y], -new_x, -new_y) >
           make_tuple(grid[best_x][best_y], -best_x, -best_y);
}

// 가장 우선순위가 높은 위치를 찾아
// 위치를 이동합니다.
bool Move() {
    // BFS 탐색을 위한 초기화 작업을 수행합니다.
    InitializeVisited();
    
    // Step1. BFS를 진행하여 갈 수 있는 모든 위치를 탐색합니다.
    BFS();
    
    // Step2. 
    // 도달 할 수 있는 위치들 중
    // 가장 우선순위가 높은 위치를 구합니다.
    pair<int, int> best_pos = NOT_EXISTS;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            // 도달이 불가능하거나 현재 위치는 건너뜁니다.
            if(!visited[i][j] || 
                make_pair(i, j) == curr_cell)
                continue;
            
            pair<int, int> new_pos = make_pair(i, j);
            if(NeedUpdate(best_pos, new_pos))
                best_pos = new_pos;
        }
    
    // Step3. 위치를 이동합니다.
    
    // 만약 움직일 위치가 없다면 종료합니다.
    if(best_pos == NOT_EXISTS)
        return false;
    // 움직일 위치가 있다면 이동합니다.
    else {
        curr_cell = best_pos;
        return true;
    }
}

int main() {
    cin >> n >> k;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) 
            cin >> grid[i][j];
    
    // 초기 위치를 설정합니다.
    int r, c;
    cin >> r >> c;
    curr_cell = make_pair(r - 1, c - 1);
    
    // k번에 걸쳐 움직이는 것을 반복합니다.
    while(k--) {
        bool is_moved = Move();
        
        // 움직이지 못했다면 바로 종료합니다.
        if(!is_moved)
            break;
    }
    
    int final_x, final_y;
    tie(final_x, final_y) = curr_cell;
    cout << final_x + 1 << " " << final_y + 1;
}
*/