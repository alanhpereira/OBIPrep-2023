#include <stdio.h>
#include <queue>
#define MAX 512
using namespace std;

int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
int m[MAX][MAX];
int vis[MAX][MAX];
int n, f;

void dfs(int y, int x){
    if(vis[y][x])return;
    vis[y][x] = true;
    for(int i = 0 ; i < 4; i++){
        int ty = y + dy[i];
        int tx = x + dx[i];
        if(ty >=0 && ty < n && tx >= 0 && tx < n && m[ty][tx] <= f)
            dfs(ty,tx);
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
    if(m[0][0] <= f){
        dfs(0,0);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j]){
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