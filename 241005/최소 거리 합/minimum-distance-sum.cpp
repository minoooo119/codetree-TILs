#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int res=0;
int dx[2]={-1,1};
map<int,int> m;
void bfs(){
    while(!q.empty()){
        int pos=q.top().second;
        int val=q.top().first;
        // cout<<pos-100000000<<'\n';
        if(val!=0)
            res+=val;
        q.pop();
        if(--k==-n)return;
        for(int i=0;i<2;i++){
            int nx=pos+dx[i];
            if(nx<0||nx>=200000000) continue;
            if(++m[nx]>=2){
                m[nx]--;
                continue;
            }
            m[nx]=1;
            q.push({val+1,nx});
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n>>k;
    for(int i=0;i<n;i++){
        int pos;
        cin>>pos;
        q.push({0,pos+100000000});
    }
    bfs();
    cout<<"res: "<<res<<'\n';


    return 0;
}