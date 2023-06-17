#include <stdio.h>
#define MAX 1121345

int a[MAX], b[MAX];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0; i < m; i++){
        scanf("%d",&b[i]);
    }
    int j = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] == b[j]){
            j++;
            if(j>=m){
                printf("S\n");
                return 0;
            }
        }
    }
    printf("N\n");
    return 0;
}