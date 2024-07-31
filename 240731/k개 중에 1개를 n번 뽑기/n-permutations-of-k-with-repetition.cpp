#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//K중 하나를 N번 선택하기!!


//1. K개 중에 N개 뽑기 -> permutation 이다.

int n,k;
vector<int> answer;
void Print(){
    for(auto x: answer){
        cout<<x<<' ';
    }
    cout<<'\n';
}
void permutation(int curr_num){
    if(curr_num==k+1){
        Print();
        return;
    }
    for(int i=1;i<=n;i++){
        answer.push_back(i);
        permutation(curr_num+1);
        answer.pop_back();
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    
    cin>>n>>k;

    permutation(1);


    return 0;
}

/*
    2진수 출력하기 해보자 => n 자리 수 이진수 출력해보기
    아래와 같이 활용해서 할 수 있다.

    void Choose(int curr_num){
        if(curr_num == n+1){
            Print();
            return;
        }
        answer.push_back(0);
        Choose(curr_num+1);
        answer.pop_back();

        answer.push_back(1);
        Choos(curr_num+1);
        answer.pop_back();
    }
*/