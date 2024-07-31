#include <iostream>
#include <vector>
using namespace std;
bool visited[1001];
vector<vector<int>> vertex(1001,vector<int>());
int res=0;
void dfs(int n){
    visited[n]=true;
    res++;
    for(int i=0;i<vertex[n].size();i++){
        int nv=vertex[n][i];
        if(!visited[nv]){
            dfs(nv);
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        vertex[a].push_back(b);
        vertex[b].push_back(a);
    }
    dfs(1);
    cout<<res-1;
    return 0;
}