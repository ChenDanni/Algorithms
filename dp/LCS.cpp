//
//  LCS.cpp
//  Sort
//
//  Created by cdn on 17/3/24.
//  Copyright © 2017年 cdn. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
//Longest Common Subsequence
//4 4 abcd becd

int max_n = 1000;
int max_m = 1000;

void lcs(){
    int n,m;
    char s[max_n];
    char t[max_m];
    cin >> n >> m >> s >> t;
    
    int dp[max_n + 1][max_m + 1];
    for (int i = 0;i < max_n + 1;i++)
        for (int j = 0; j < max_m + 1; j++)
            dp[i][j] = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i] == t[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }else {
                dp[i + 1][j + 1] = max(dp[i + 1][j],dp[i][j + 1]);
            }
        }
    }
    cout << dp[n][m] << endl;
    
}

int main(){
    lcs();
}
