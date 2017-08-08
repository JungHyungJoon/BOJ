
#include <iostream>
#include <queue>

using namespace std;

struct Pos{
    int x,y;
    Pos(int _x, int _y):x(_x),y(_y){}
};

int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int main(){
    queue<Pos> Q,WQ;
    char map[51][51];
    int visited[51][51] = {0};
    int C_size,R_size;
    
    cin>>C_size>>R_size;
    
    for(int i=0;i<C_size;i++)
        for(int j=0;j<R_size;j++){
            cin>>map[i][j];
            if(map[i][j] == '*')
                WQ.push(Pos(i,j));
            else if(map[i][j] == 'S')
                Q.push(Pos(i,j));
            else if(map[i][j] == 'D')
                Pos Dest(i,j);
            
        }
    
    int Q_num = 0;
    while(!Q.empty()){
        Q_num ++;
        //cout<<"-------[ "<<Q_num<<" ]------"<<endl;
        int q_size = WQ.size();
        for(int i=0; i<q_size; i++){//
            //물 이동
            int cx = WQ.front().x;
            int cy = WQ.front().y; WQ.pop();
            //cout<<"Water cx : "<<cx<<", cy : "<<cy<<endl;
            for(int dir=0;dir<4;dir++){
                int nx = cx + dr[dir];
                int ny = cy + dc[dir];
                //cout<<"\t nx : "<<nx<<", ny : "<<ny<<endl;
                if(nx < 0 && nx >=R_size && ny <0 && ny >= C_size) continue;
                
                if(map[nx][ny]=='.'){
                    WQ.push(Pos(nx,ny));
                    map[nx][ny] = '*';
                }
            }
        }
        
        q_size = Q.size();
        for(int i=0; i<q_size; i++){
            //고슴도치 탐색
            int cx = Q.front().x;
            int cy = Q.front().y; Q.pop();
            //cout<<"Gosum cx : "<<cx<<", cy : "<<cy<<endl;
            for(int dir=0;dir<4;dir++){
                int nx = cx + dr[dir];
                int ny = cy + dc[dir];
                //cout<<"\t nx : "<<nx<<", ny : "<<ny<<endl;
                if(nx < 0 && nx >=R_size && ny <0 && ny >= C_size) continue;
                
                if(map[nx][ny]=='.' && !visited[nx][ny]){
                    visited[nx][ny] = 1;
                    Q.push(Pos(nx,ny));
                }
                if(map[nx][ny]=='D'){
                    cout<<Q_num<<endl;
                    return 1;
                }
                
            }
        }//동시간에
    }
    cout<<"KAKTUS"<<endl;
    
    return 1;
}
