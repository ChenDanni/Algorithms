//
//  POJ3617.cpp
//  Sort
//
//  Created by cdn on 17/3/21.
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

int max_n = 2000;

int main(){
    int n;
    char s[max_n + 1];
    
    cin >> n >> s;
    int a = 0,b = n - 1;
    bool left = false;
    
    while(a <= b){
        for (int i = 0;a + i <= b;i++){
            if (s[a + i] < s[b - i]){
                left = true;
                break;
            }
            if (s[a + i] > s[b - i]){
                left = false;
                break;
            }
        }
        if (left){
            putchar(s[a++]);
        }else {
            putchar(s[b--]);
        }
    }
    putchar('\n');
}
