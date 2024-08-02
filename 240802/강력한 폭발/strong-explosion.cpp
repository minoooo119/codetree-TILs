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

/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define MAX_N 20
#define BOMB_TYPE_NUM 3

using namespace std;

int n;
int bomb_type[MAX_N][MAX_N];
bool bombed[MAX_N][MAX_N];

int ans;

vector<pair<int, int> > bomb_pos;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Bomb(int x, int y, int b_type) {
    // 폭탄 종류마다 터질 위치를 미리 정의합니다.
    pair<int, int> bomb_shapes[BOMB_TYPE_NUM + 1][5] = {
        {},
        { {-2, 0}, {-1, 0}, {0, 0},  {1, 0}, {2, 0}},
        { {-1, 0},  {1, 0}, {0, 0}, {0, -1}, {0, 1}},
        {{-1, -1}, {-1, 1}, {0, 0}, {1, -1}, {1, 1}}
    };
    
    // 격자 내 칸에 대해서만 영역을 표시합니다.
    for(int i = 0; i < 5; i++) {
        int dx, dy;
        tie(dx, dy) = bomb_shapes[b_type][i];
        
        int nx = x + dx, ny = y + dy;
        if(InRange(nx, ny))
            bombed[nx][ny] = true;
    }
}

int Calc() {
    // Step1. 폭탄이 터진 위치를 표시하는 배열을
    // 초기화합니다.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			bombed[i][j] = false;
	
    // Step2. 각 폭탄의 타입에 따라 
    // 초토화 되는 영역을 표시합니다.
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            if(bomb_type[i][j])
                Bomb(i, j, bomb_type[i][j]);
	
    // Step3. 초토화된 영역의 수를 구합니다.
	int cnt = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
            if(bombed[i][j])
                cnt++;
    
	return cnt;
}

void FindMaxArea(int cnt) {
	if(cnt == (int) bomb_pos.size()) {
		ans = max(ans, Calc());
		return;
	}
	for(int i = 1; i <= 3; i++) {
        int x, y;
        tie(x, y) = bomb_pos[cnt];
        
		bomb_type[x][y] = i;
		FindMaxArea(cnt + 1);
		bomb_type[x][y] = 0;
	}
}

int main() {
	cin >> n;
	
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
            int bomb_place;
			cin >> bomb_place;
			if(bomb_place)
				bomb_pos.push_back(make_pair(i, j));
		}
	
	FindMaxArea(0);
	
	cout << ans;
	return 0;
}
*/