//
//  MC.cpp
//  Sort
//
//  Created by cdn on 17/4/26.
//  Copyright © 2017年 cdn. All rights reserved.
//
/*
 多重集组合数
 有n中物品，第i中物品有ai个，同种物品不以区分，从中挑选m个，有多少种取法？求方案数模M的余数
 1 <= n <= 1000
 1 <= m <= 1000
 1 <= ai <= 1000
 2 <= M <= 10000
 */
/*
 example: input
 n = 3,
 m = 3,
 a = {1,2,3}
 M = 10000;
 dp[i+1][j] 从前i种物品中选j个
 */
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int max_n = 1000;
int max_m = 1000;

int n = 3,m = 3,M = 10000;
int a[] = {1,2,3};

int main(){
    int dp[max_n + 1][max_m + 1];
    for (int i = 0;i <= n;i++) dp[i][0] = 1;
    
    for (int i = 0;i < n;i++){
        for (int j = 1;j <= m;j++){
            for (int k = 0;k <= min(a[i],j);k++){
                dp[i + 1][j] += dp[i][j - k];
            }
            dp[i + 1][j] %= M;
        }
    }
    cout << dp[n][m] << endl;
}