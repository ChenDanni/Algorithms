//
//  Knapsack Problem.cpp
//  Sort
//
//  Created by cdn on 17/3/23.
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

//test
//4 5
//2 1 3 2
//3 2 4 2
//ans = 7 (0, 1, 3)

//最多n件商品
int max_n = 100;
int max_w = 10000;

void solve(){
    int n,weight;
    int w[max_n],v[max_n]; //weight and value
    
    cin >> n >> weight;
    for (int i = 0;i < n;i++)
        cin >> w[i];
    for (int i = 0;i < n;i++)
        cin >> v[i];
    
    int dp[max_n + 1][max_w + 1];
    for (int i = 0;i < max_n + 1;i++){
        for (int j = 0;j < max_w + 1;j++){
            dp[i][j] = 0;
        }
    }
    
    
    for (int i = n - 1;i >= 0;i--){
        for (int j = 0;j <= weight;j++){
            if (w[i] > j)
                dp[i][j] = dp[i + 1][j];
            else{
                dp[i][j] = max(dp[i + 1][j],dp[i + 1][j - w[i]] + v[i]);
            }
//            cout << "dp[" << i << "][" << j << "]  " << dp[i][j] << endl;
        }
    }
    cout << dp[0][weight] << endl;
}

int main(){
    solve();
}