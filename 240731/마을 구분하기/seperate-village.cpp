#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int grid[26][26];
int visited[26][26];
bool canGo(int r,int c){
    if(r<0||c<0||r>=n||c>=n) return false;
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
            c = dfs(nx,ny,c+1);
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
                int num=dfs(i,j,1);
                city_people_num.push_back(num);
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
/*
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_NUM 25
#define DIR_NUM 4

using namespace std;

int n;
int grid[MAX_NUM][MAX_NUM];
bool visited[MAX_NUM][MAX_NUM];
vector<int> people_nums;
int people_num;

// 탐색하는 위치가 격자 범위 내에 있는지 여부를 반환합니다.
bool InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

// 탐색하는 위치로 움직일 수 있는지 여부를 반환합니다.
bool CanGo(int x, int y) {
    if(!InRange(x, y))
        return false;

    if(visited[x][y] || grid[x][y] == 0)
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

        if(CanGo(new_x, new_y)){
            visited[new_x][new_y] = true;
            // 마을에 존재하는 사람을 한 명 추가해줍니다.
            people_num++;
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
    // 한 마을에 대한 DFS 탐색을 수행합니다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(CanGo(i, j)) {
                // 해당 위치를 방문할 수 있는 경우 visited 배열을 갱신하고
                // 새로운 마을을 탐색한다는 의미로 people_num을 1으로 갱신합니다.
                visited[i][j] = true;
                people_num = 1;

                DFS(i, j);

                // 한 마을에 대한 탐색이 끝난 경우 마을 내의 사람 수를 저장합니다.
                people_nums.push_back(people_num);
            }
        }
    }

    // 각 마을 내 사람의 수를 오름차순으로 정렬합니다.
    sort(people_nums.begin(), people_nums.end());

    cout << (int) people_nums.size() << endl;
    for(int i = 0; i < (int) people_nums.size(); i++)
        cout << people_nums[i] << endl;

    return 0;
}
*/