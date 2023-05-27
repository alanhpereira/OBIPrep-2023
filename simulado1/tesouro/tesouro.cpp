#include <stdio.h>
#define MAX 112

int py[MAX], px[MAX], pd[MAX];

int abs(int a){
    return a >= 0 ? a : -a;
}

int dist(int y1, int x1, int y2, int x2){
    return abs(y1-y2) + abs(x1-x2);
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%d %d %d", &px[i], &py[i], &pd[i]);
    }
    int tx = -1, ty = -1;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0; j < n ; j++){
            int poss = 1;
            for(int l = 0; l < k; l++){
                if(dist(i,j,py[l],px[l]) != pd[l]) poss = 0;
            }
            if(poss){
                //printf("c: %d %d\n", i,j);
                if(tx != -1){
                    printf("-1 -1\n");
                    return 0;
                }
                tx = j; ty = i;
            }
        }
    }
    printf("%d %d\n", tx, ty);
    return -0;
}