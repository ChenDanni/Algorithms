//
//  coin.cpp
//  Sort
//
//  Created by cdn on 17/3/20.
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

//
const int v[6] = {1,5,10,50,100,500};

int c[6] = {3,2,1,3,0,2};

int a = 620;

int solution(){
    int use = 0;
    for (int i = 5;i >=0;i--){
        int t = min(a/v[i],c[i]);
        a -= t*v[i];
        use += t;
    }
    return use;
}

int main(){
    
    cout << solution() << endl;
    
}


