#include <stdio.h>
#include <vector>
#include <algorithm>
#define MAX 1123
using namespace std;

vector<int> adj[MAX];
int c[MAX];

int main(){
    int n, m, p, pn, ans = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d",&u , &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i<=n; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    scanf("%d", &p);
    for(int i = 0 ; i < p; i++){        
        scanf("%d", &pn);
        for(int j = 0; j < pn; j++){
            scanf("%d", &c[j]);
        }
        int ps = 1;
        
        for(int j = 1; j < pn; j++){
            if(!binary_search(adj[c[j-1]].begin(), adj[c[j-1]].end(), c[j]))
                ps = 0;
        }
        ans += ps;
    }
    printf("%d\n", ans);
    return 0;
}