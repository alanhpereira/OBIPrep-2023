#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, mx, s;
    scanf("%d %d %d",&n,&mx,&s);
    srand(s);
    printf("%d\n",n);
    for(int i = 0; i <n ;i++){
        printf("%d ",rand()%mx);
    }
    printf("\n");
}