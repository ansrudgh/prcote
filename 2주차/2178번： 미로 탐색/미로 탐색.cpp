/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2178                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: rudghrnt12 <boj.kr/u/rudghrnt12>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2178                           #+#        #+#      #+#    */
/*   Solved: 2024/07/26 13:44:25 by rudghrnt12    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, M;
vector<vector<int>>map;
vector<vector<bool>>visited;
vector<vector<int>>dist;

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};

void bfs(){
    queue<pair<int,int>>q;
    q.push({0,0});
    visited[0][0]=true;
    dist[0][0]=1;
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if((x==N-1)&&(y==M-1)) break;
        for(int i=0;i<4;i++){
            int X=x+dx[i];
            int Y=y+dy[i];
            if((X>=0)&&(X<N)&&(Y>=0)&&(Y<M)){
                if(!visited[X][Y]&&(map[X][Y]==1)){
                    visited[X][Y]=true;
                    dist[X][Y]=dist[x][y]+1;
                    q.push({X,Y});
                }
            }
        }
    }
}

int main(){
    cin>>N>>M;
    map.resize(N,vector<int>(M));
    visited.resize(N,vector<bool>(M,false));
    dist.resize(N,vector<int>(M,0));
    for(int i=0;i<N;i++){
        string row;
        cin>>row;
        for(int j=0;j<M;j++) map[i][j]=row[j]-48;
    }
    bfs();
    cout<<dist[N-1][M-1]<<endl;
}