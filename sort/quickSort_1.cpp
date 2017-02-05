//
//  quickSort_1.cpp
//  Sort
//
//  Created by user on 17/2/5.
//  Copyright © 2017年 cdn. All rights reserved.
//

#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

void printList(int *a,int len){
    for (int i = 0;i < len;i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}

int partition(int* a,int s,int e){
    int x = a[e];
    int i = s - 1;
    for (int j = s;j < e;j++){
        if (a[j] < x){
            i++;
            swap(a[i], a[j]);
        }
    }
    i++;
    swap(a[i], a[e]);
    return i;
}

void quickSort(int* a,int s,int e){
    if (s < e){
        int q = partition(a, s, e);
        quickSort(a, s, q - 1);
        quickSort(a, q + 1, e);
    }
}

int main(){
    int a[] = {-111,9,8,7,6,5,4,3,21};
    int len = sizeof(a)/sizeof(a[0]);
    quickSort(a,0,len - 1);
    printList(a, len);
}
