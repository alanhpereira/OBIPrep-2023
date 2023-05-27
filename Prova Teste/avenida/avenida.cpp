#include <stdio.h>
#define MAX 512

int mtx[MAX][MAX];

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d",&mtx[i][j]);
        }
    }
    int best = 100000;
    for(int i = 0; i < n; i++){
        int sum = 0;
        for(int j = 0; j < m; j++){
            sum += mtx[i][j];
        }
        if(sum < best) best = sum;
    }
    for(int j = 0; j < m; j++){
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += mtx[i][j];
        }
        if(sum < best) best = sum;
    }
    printf("%d\n",best);
    return 0;
}