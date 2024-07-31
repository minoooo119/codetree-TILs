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
/*
#include <iostream>
#include <algorithm>

#define MAX_N 50
#define MAX_M 50
#define MAX_HEIGHT 100
#define DIR_NUM 4

using namespace std;

int n, m;
int grid[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int zone_num;

// visited 배열을 초기화해줍니다.
void InitializeVisited() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            visited[i][j] = false;
}

// 탐색하는 위치가 격자 범위 내에 있는지 여부를 반환합니다.
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// 탐색하는 위치로 움직일 수 있는지 여부를 반환합니다.
bool CanGo(int x, int y, int k) {
    if(!InRange(x, y)) 
        return false;

    if(visited[x][y] || grid[x][y] <= k)
        return false;

    return true;
}

void DFS(int x, int y, int k) {
    //0: 오른쪽, 1: 아래쪽, 2: 왼쪽, 3: 위쪽
    int dx[DIR_NUM] = {0, 1, 0, -1};
    int dy[DIR_NUM] = {1, 0, -1, 0};
    
    // 네 방향에 각각에 대하여 DFS 탐색을 합니다.
    for(int dir = 0; dir < DIR_NUM; dir++) {
        int new_x = x + dx[dir];
        int new_y = y + dy[dir];

        if(CanGo(new_x, new_y, k)){
            visited[new_x][new_y] = true;
            DFS(new_x, new_y, k);
        }
    }
}

void GetZoneNum(int k) {
    // 새로운 탐색을 시작한다는 의미로 zone_num를 0으로 갱신하고 
    // visited 배열을 초기화해줍니다.
    zone_num = 0;
    InitializeVisited();
    
    // 격자의 각 위치에 대하여 탐색을 시작할 수 있는 경우
    // 해당 위치로부터 시작한 DFS 탐색을 수행합니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            if(CanGo(i, j, k)) {
                // 해당 위치를 탐색할 수 있는 경우 visited 배열을 갱신하고
                // 안전 영역을 하나 추가해줍니다.
                visited[i][j] = true;
                zone_num++;

                DFS(i, j, k);
            }
        }
}

int main() {
    // 가능한 안전 영역의 최솟값이 0이므로 다음과 같이 초기화 해줄 수 있습니다.
    int max_zone_num = -1; 
    int answer_k = 0;

    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    // 각 가능한 비의 높이에 대하여 안전 영역의 수를 탐색합니다.
    for(int k = 1; k <= MAX_HEIGHT; k++){
        GetZoneNum(k);

        // 기존의 최대 영역의 수보다 클 경우 이를 갱신하고 인덱스를 저장합니다.
        if(zone_num > max_zone_num) {
            max_zone_num = zone_num;
            answer_k = k;
        }
    }

    cout << answer_k << " " << max_zone_num;
    return 0;
}
*/