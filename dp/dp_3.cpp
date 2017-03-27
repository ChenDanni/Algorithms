//
//  dp_3.cpp
//  Sort
//
//  Created by cdn on 17/3/27.
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
//多重部分和问题，有n种不同大小的数字ai，每个各mi种，判断是否可以从这些数字中取出若干个使它们的和为k
int max_k = 100000;
int n = 3;
int a[3] = {3,5,8};
int m[3] = {3,3,2};
int K = 17;

int main(){
    int dp[max_k + 1];
    //dp[j] : 加到j时前最多还剩多少个数字
    
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j <= K;j++){
            if (dp[j] >= 0){
                dp[j] = m[i];
            }else if(j < a[i] || dp[j - a[i]] <= 0){
                dp[j] = -1;
            }else {
                dp[j] = dp[j - a[i]] - 1;
            }
        }
    }
    if (dp[K] >= 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    
}