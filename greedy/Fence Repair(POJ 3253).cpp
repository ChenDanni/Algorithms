//
//  Fence Repair(POJ 3253).cpp
//  Sort
//
//  Created by cdn on 17/3/22.
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

typedef long long ll;
int max_n = 20000;

int main (){
    int n;
    int l[max_n];
    
    cin >> n;
    for (int i = 0;i < n;i++){
        cin >> l[i];
    }
    
    ll ans = 0;
    
    while(n > 1){
        int min1 = 0,min2 = 1;
        if (l[min1] > l[min2])
            swap(min1, min2);
        for (int i = 2;i < n;i++){
            if (l[i] < l[min1]){
                min2 = min1;
                min1 = i;
            }else if (l[i] < l[min2]){
                min2 = i;
            }
        }
        
        int t = l[min1] + l[min2];
        ans += t;
        
        if(min1 == n - 1)
            swap(min1,min2);
        l[min1] = t;
        l[min2] = l[n - 1];
        n--;
    }
    cout << ans << endl;
}