#include <stdio.h>
#define MAX 1024

int v[MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    int e;
    scanf("%d", &e);
    
    for(int i = 0; i < n; i++){
        if(v[i] == e){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",-1);
    return 0;
}