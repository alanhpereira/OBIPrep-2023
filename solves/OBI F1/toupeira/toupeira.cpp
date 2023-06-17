#include <stdio.h>
#define MAX 1123

int mtx_adj[MAX][MAX];
int c[MAX];

int main(){
    int n, m, p, pn, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d",&u , &v);
        mtx_adj[u][v] = 1;
        mtx_adj[v][u] = 1;
    }
    scanf("%d", &p);
    for(int i = 0 ; i < p; i++){        
        scanf("%d", &pn);
        for(int j = 0; j < pn; j++){
            scanf("%d", &c[j]);
        }
        int ps = 1;
        
        for(int j = 1; j < pn; j++){
            if(!mtx_adj[c[j-1]][c[j]])
                ps = 0;
        }
        ans += ps;
    }
    printf("%d\n", ans);
}