#include <stdio.h>

int main(){
    int r,g,b,s;
    s = 0;
    scanf("%d%d%d", &r, &g, &b);
    s = (g/b)*(g/b);
    s++;
    s *= (r/g)*(r/g);
    s++;
    printf("%d\n",s);
    return 0;
}