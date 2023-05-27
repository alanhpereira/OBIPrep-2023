#include <stdio.h>
#include <queue>
#include <utility>
#define F first
#define S second
#define MAX 512
using namespace std;
typedef pair<int, int> pii;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int m[MAX][MAX];
int dist[MAX][MAX];
int n, f;

void bfs(int y, int x){
    queue<pii> q;
    q.push({y,x});
    dist[y][x] = 0;
    while(!q.empty()){
        y = q.front().F;
        x = q.front().S;
        q.pop();
        for(int i = 0 ; i < 4; i++){
            int ty = y + dy[i];
            int tx = x + dx[i];
            if(ty >=0 && ty < n && tx >= 0 && tx < n )
                if(dist[ty][tx] == -1 && m[ty][tx] <= f){
                    dist[ty][tx] = dist[y][x]+1;
                    q.push({ty,tx});
                }
                
        }
    }
    
}

int main(){
    scanf("%d %d", &n, &f);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            scanf(" %c", &c);
            m[i][j] = c - '0';
        }
    }
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n ; j++){
            dist[i][j] = -1;
        }
    }
    if(m[0][0] <= f){
        bfs(0,0);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] != -1){
                printf("*");
            }
            else{
                printf("%d", m[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}