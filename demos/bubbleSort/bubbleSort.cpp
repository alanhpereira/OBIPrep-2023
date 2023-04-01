#include <stdio.h>
#define MAX 100000

int v[MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 1; j < n - i; j++){
            if(v[j] < v[j-1]){
                int aux = v[j];
                v[j] = v[j-1];
                v[j-1] = aux;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}