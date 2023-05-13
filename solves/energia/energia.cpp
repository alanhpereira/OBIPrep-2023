#include <stdio.h>
#include <vector>
#define MAX 1124
using namespace std;

vector<int> adj[MAX];
int vis[MAX];

void dfs(int a){
    if(vis[a]) return;
    vis[a] = 1;
    for(int i = 0; i < adj[a].size();i++){
        dfs(adj[a][i]);
    }
}

int main(){
    int n, m;
    int t = 1;
    scanf("%d%d",&n, &m);
    while (n != 0){
        for(int i = 0; i <= n; i++){
            adj[i].clear();
            vis[i] = 0;
        }
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d",&u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1);
        int normal = true;
        for(int i = 1; i <= n; i++){
            if(!vis[i])normal = false;
        }
        printf("Teste %d\n", t++);
        if(normal){
            printf("normal\n\n");
        }
        else{
            printf("falha\n\n");
        }
        scanf("%d %d",&n, &m);
    }
    return 0;
}