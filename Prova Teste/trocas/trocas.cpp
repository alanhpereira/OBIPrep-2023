#include <stdio.h>
#define MAX 112345

int v[MAX][2];
int giros[MAX];

int main(){
    int n, t;
    scanf("%d %d",&n,&t);
    for(int k = 0; k < 2; k++){
        for(int i =0 ; i < n; i++){
            scanf("%d",&v[i][k]);
        }
    }
    for(int i = 0; i < t; i++){
        int l, r;
        scanf("%d %d",&l, &r);
        giros[l-1]++;
        giros[r]++;
    }
    int troca = 0;
    for(int i = 0 ; i < n ; i++){
        troca += giros[i];
        printf("%d ", v[i][troca%2]);
    }
    printf("\n");
    return 0;
}
