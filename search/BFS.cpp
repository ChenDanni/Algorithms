//
//  BFS.cpp
//  Sort
//
//  Created by cdn on 17/3/19.
//  Copyright © 2017年 cdn. All rights reserved.
//
//#S######.#
//......#..#
//.#.##.##.#
//.#........
//##.##.####
//....#....#
//.#######.#
//....#.....
//.####.###.
//....#...G#
//n = 10,M = 10

#include<iostream>
#include<cstdio>
#include<string>
#include<set>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

int const INF = 100000000;
typedef pair<int,int> P;

//char maze[100][100];
int n = 10,m = 10;
int sx = 0,sy = 1;
int gx = 9,gy = 8;

int d[100][100];
char maze[10][11] = {"#S######.#",
    "......#..#",
    ".#.##.##.#",
    ".#........",
    "##.##.####",
    "....#....#",
    ".#######.#",
    "....#.....",
    ".####.###.",
    "....#...G#"};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int bfs(){
    queue<P> que;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            d[i][j] = INF;
        }
    }
    
    que.push(P(sx,sy));
    d[sx][sy] = 0;
    
    while(que.size()){
        P p = que.front();
        que.pop();
        if (p.first == gx && p.second == gy)
            break;
        for (int i = 0;i < 4;i++){
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            
            if (0 <= nx && nx < n && 0 <= ny && ny < m
                && maze[nx][ny] != '#' && d[nx][ny] == INF){
                d[nx][ny] = d[p.first][p.second] + 1;
                que.push(P(nx,ny));
            }
            
        }
    }
    return d[gx][gy];
}

int main(){
    
    cout << bfs() << endl;
    
}
    



