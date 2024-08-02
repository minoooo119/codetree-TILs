#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n;
vector<pair<int,int> > v;
vector<pair<int,int> > res;
int visited[16];

int check_line(){
    // int x=res[0].first;
    int y=res[0].second;
    int result=1;
    for(int i=1;i<res.size();i++){
        if(res[i].first>y) result++;
        y=res[i].second;
    }

    return result;
}
int mx=0;
void backtracking(int cnt){
    if(cnt == n){    
        // for(auto p: res){
        //     cout<<p.first<<' '<<p.second<<"\n";
        // }
        // return;
        mx=max(mx,check_line());
        return ;
    }
    for(int i=0;i<v.size();i++){
        if(!visited[i]){
            // cout<<"=>>"<<i<<": "<<v[i].first<<' '<<v[i].second<<" cnt: "<<cnt<<"\n";
            visited[i]=1;
            res.push_back(v[i]);
            backtracking(cnt+1);
            res.pop_back();
            visited[i]=0;
        }
        // else{
        //     cout<<"중복 금지"<<i<<": "<<v[i].first<<' '<<v[i].second<<" cnt: "<<cnt<<"\n";
        // }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
        visited[i]=0;
    }
    // cout<<"-------------------\n";
    backtracking(0);
    cout<<mx;

    return 0;
}