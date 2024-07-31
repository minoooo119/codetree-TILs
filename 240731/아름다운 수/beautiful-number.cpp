#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//K중 하나를 N번 선택하기!!

int n;
int res=0;
vector<int> answer;
bool isBeautifulNum(){
    // cout<<'\n';
    for(int i=0;i<n;i++){
        int num=answer[i];
        // cout<<num<<'\n';
        if(num==1) continue;
        else if(num==2){
            if(i+1>=n) return false;
            if(answer[i+1]!=2) return false;
            i++;
        }
        else if(num==3){
            if(i+1>=n||i+2>=n) return false;
            if(answer[i+1]!=3||answer[i+2]!=3) return false;
            i+=2;
        }
        else if(num==4){
            if(i+1>=n||i+2>=n||i+3>=n) return false;
            if(answer[i+1]!=4||answer[i+2]!=4||answer[i+3]!=4) return false;
            i+=3;
        }
    }
    return true;
}
void Print(){
    for(auto x: answer){
        cout<<x<<' ';
    }
    cout<<'\n';
}
void permutation(int curr_num){
    if(curr_num==n+1){
        if(isBeautifulNum()) {
            // Print();
            res++;
        }
        return;
    }
    for(int i=1;i<=4;i++){
        answer.push_back(i);
        permutation(curr_num+1);
        answer.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin>>n;

    permutation(1);
    cout<<res<<'\n';


    return 0;
}