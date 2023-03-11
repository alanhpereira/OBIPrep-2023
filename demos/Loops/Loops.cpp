#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n ; i++){
        printf("%d ", i);
    }
    printf("\n");
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    while(a != b){
        printf("%d\n", b);
        
        scanf("%d", &b);
    }
    return 0;
}