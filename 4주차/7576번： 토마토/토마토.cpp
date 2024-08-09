/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 7576                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: rudghrnt12 <boj.kr/u/rudghrnt12>            +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/7576                           #+#        #+#      #+#    */
/*   Solved: 2024/08/09 23:47:48 by rudghrnt12    ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N,M;
vector<vector<int>> box;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

bool __clock(queue<pair<int,int>> &q){
    int size=q.size();
    bool rt=false;
    while(size--){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int j=0;j<4;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx<0||ny<0||nx>=N||ny>=M) continue;
            if(box[nx][ny]!=0) continue;
            box[nx][ny]=1;
            q.push({nx,ny});
            rt=true;
        }
    }
    return rt;
}

int bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(box[i][j]==1) q.push({i,j});
    int days=0;
    while(!q.empty()) days+=__clock(q);
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) if(box[i][j]==0) return -1;
    return days;
}

int main(){
    cin>>M>>N;
    box.resize(N, vector<int>(M));
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) cin>>box[i][j];
    cout<<bfs()<<endl;
}