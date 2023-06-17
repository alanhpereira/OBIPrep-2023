#include <stdio.h>
#define MAX 512

int estoque[MAX][MAX];

int main(){
    int n, m, p, ans = 0;
    scanf("%d%d",&m, &n);
    for(int i = 1; i <= m ; i++){
        for(int j = 1; j <= n ; j++){
            scanf("%d",&estoque[i][j]);
        }
    }
    scanf("%d", &p);
    for(int i = 0; i < p; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if(estoque[a][b] > 0){
            ans++;
            estoque[a][b]--;
        }
    }
    printf("%d\n", ans);
    return 0;
}