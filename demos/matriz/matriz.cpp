#include <stdio.h>
#define MAX 20

int matriza[MAX][MAX], matrizb[MAX][MAX] ,matrizc[MAX][MAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriza[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrizb[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrizc[i][j] = matriza[i][j] + matrizb[i][m-j-1];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrizc[i][j]);
        }
        printf("\n");
    }
    return 0;
}