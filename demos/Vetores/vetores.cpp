#include <stdio.h>
#define MAX 60

int vetora[MAX],vetorb[MAX],vetorc[MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vetora[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &vetorb[i]);
    }
    for(int i = 0; i < n; i++){
        vetorc[i] = vetora[i]*vetorb[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", vetorc[i]);
    }
    return 0;
}