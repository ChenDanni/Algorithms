//
//  LIS.cpp
//  Sort
//
//  Created by cdn on 17/4/1.
//  Copyright © 2017年 cdn. All rights reserved.
//
//最长上升子序列
#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

int max_n = 10000;
int main(){
    int n;
    int a[max_n];
    int dp[max_n]; //dp[i] 以a[i]为结尾的最长上升子序列
    int res = 0;
    cin >> n;
    for (int i = 0;i < n;i++)
        cin >> a[i];
    for (int i = 0;i < n;i++){
        dp[i] = 1;
        for (int j = 0;j < i;j++){
            if (a[i] > a[j]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        res = max(0,dp[i]);
    }
    cout << res << endl;
}
