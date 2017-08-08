//
//  1012.cpp
//  Practice
//
//  Created by JungHyungJoon on 07/08/2017.
//  Copyright © 2017 JungHyungJoon. All rights reserved.
//

#include <iostream>

using namespace std;
void dfs(int row, int col, bool visited[]);

int dr[4] = {-1,1,0,0}; //상,하,좌,우
int dc[4] = {0,0,-1,1}; //상,하,좌,우
//bool visited[50][50];
int M,N,K; //M:가로길이, N:세로길이, K:배추갯수

void dfs(int row, int col, bool visited[50][50]){
    int nr,nc;
    //cout<<"ROW : "<<row<<", COL : "<<col<<endl;
    visited[row][col] = true;
    for(int i=0;i<4;i++){
        nr = row+dr[i];
        nc = col+dc[i];
        if(visited[nr][nc] == false && nr>=0 && nr<N && nc >=0 && nc<M )
            dfs(nr,nc,visited);
    }
    
    return;
}

int main(){
    int T; //Test 개수
    cin >> T;
    while(T--){
        //cout<<"TEST CASE "<<T<<endl;

        int map [50][50];
        bool visited [50][50];
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++){
                //map[i][j]=0;
                visited[i][j]=true;
            }
    
        cin >> M >> N >> K;
        for(int i=0;i<K;i++){
            int r, c;
            cin >> c >> r;
            //map[r][c] = 1;
            visited[r][c] = false;
        }
        
        int count = 0;
        for(int r=0;r<N;r++){
            for(int c=0;c<M;c++){
                if(visited[r][c]==false && (r>=0 && c>=0) ){
                    //cout<<"R : "<<r<<", C : "<<c<<endl;
                    dfs(r,c,visited);
                    count ++;
                }
            }
        }
        cout <<count<<endl;
        
    }
    
    return 1;
}

