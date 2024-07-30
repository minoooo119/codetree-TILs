#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
int main() {
    // 여기에 코드를 작성해주세요.
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int m3=10e8;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            m3=min(m3,a[i][j]);
        }
    }
    int m3_1=min(m3,a[n-2][n-1]);
    int m3_2=min(m3,a[n-1][n-2]);

    int m1=10e8;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n;j++){
            m1=min(m1,a[i][j]);
        }
    }
    int m2=10e8;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            m2=min(m2,a[i][j]);
        }
    }
    cout<<max(m1,max(m2,max(m3_1,m3_2)))<<'\n';
    return 0;
}