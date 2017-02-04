//
//  heapSort.cpp
//  sort
//
//  Created by user on 17/2/4.
//
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
    for (int i = 1;i <= len;i++){
        cout << a[i] << "  ";
    }
    cout << endl;
}

void maxHeapify(int *a,int i,int len){
    int left = 2*i;
    int right = 2*i + 1;
    int largest;
    
    if (2*i > len){
        largest = i;
    }else{
        if (2*i + 1 > len){
            if (a[i] > a[left]){
                largest = i;
            }else {
                largest = left;
            }
            
        }else if ((a[i] > a[left])&&(a[i] > a[right])){
            largest = i;
        }else{
            if (a[left] > a[right]){
                largest = left;
            }else {
                largest = right;
            }
        }
    }
//    cout << a[i] << " " << a[left] << " " << a[right] << endl;
    if (largest != i){
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
//        printList(a,len);
        maxHeapify(a,largest,len);
    }
}

void heapSort(int *a,int len){
    //build max heap O(n)
    int i;
    for (i = len/2;i >= 1;i--){
        maxHeapify(a,i,len);
    }
    //heap sort
    for (i = len;i >= 2;i--){
        int temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        maxHeapify(a,1,i - 1);
    }
}

int main(){
    int a[] = {-111,9,8,7,6,5,4,3,21};
    int len = sizeof(a)/sizeof(a[0]) - 1;
    heapSort(a,len);
    printList(a,len);
}

