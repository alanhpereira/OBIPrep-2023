#include <stdio.h>

int main(){
    int n, r, p, c, d = 0;
    scanf("%d %d %d", &n, &r, &p);
    c = n;
    while(c < p){
        d++;
        n*=r;
        c += n;
    }
    printf("%d", d);
    return 0;
}