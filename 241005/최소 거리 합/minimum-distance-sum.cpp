#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,k;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
int res=0;
int dx[2]={-1,1};
set<int> s;
void bfs(){
    while(!q.empty()){
        int pos=q.top().second;
        int val=q.top().first;
        // cout<<pos<<'\n';
        if(val!=0)
            res+=val;
        q.pop();
        if(--k==-n)return;
        for(int i=0;i<2;i++){
            int nx=pos+dx[i];
            if(nx<-100000000||nx>100000000) continue;
            if(s.find(nx)!=s.end()) continue;
            s.insert(nx);
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
        q.push({0,pos});
    }
    bfs();
    cout<<res<<'\n';


    return 0;
}