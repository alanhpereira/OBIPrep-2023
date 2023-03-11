#include <stdio.h>

int main(){
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if(a < b && c < d){
        printf("ambos menores\n");
    }
    else if(a < b || c < d){
        printf("um menor\n");
    }
    else{
        printf("nenhum menor");
    }
    return 0;
}