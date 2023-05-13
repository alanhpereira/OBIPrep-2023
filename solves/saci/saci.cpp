#include <stdio.h>
#include <queue>
#include <utility>
#define MAX 1123
#define F first
#define S second
using namespace std;
typedef pair<int, int> pii;

int toca[MAX][MAX];
int dist[MAX][MAX];
int n, m;

void bfs(int y, int x){
    queue<pii> q;
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            dist[i][j] = -1;
    dist[y][x] = 1;
    q.push({y, x});
    while(q.size()){
        y = q.front().F;
        x = q.front().S;
        q.pop();
        if(y>0 && toca[y-1][x]!= 0 && dist[y-1][x] == -1){
            dist[y-1][x] = dist[y][x] + 1;
            q.push({y-1, x});
        }
        if(x>0 && toca[y][x-1]!= 0 && dist[y][x-1] == -1){
            dist[y][x-1] = dist[y][x] + 1;
            q.push({y, x-1});
        }
        if(y<n-1 && toca[y+1][x]!= 0 && dist[y+1][x] == -1){
            dist[y+1][x] = dist[y][x] + 1;
            q.push({y+1, x});
        }
        if(x<m-1 && toca[y][x+1]!= 0 && dist[y][x+1] == -1){
            dist[y][x+1] = dist[y][x] + 1;
            q.push({y, x+1});
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);

    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &toca[i][j]);
    
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            if(toca[i][j] == 2)bfs(i,j);
    
    for(int i = 0 ; i < n; i++)
        for(int j = 0; j < m; j++)
            if(toca[i][j] == 3)printf("%d\n",dist[i][j]);
    return 0;     
}