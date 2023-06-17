#include <stdio.h>

int main(){
    int p, d, b, s;
    scanf("%d %d %d",&p, &d, &b);
    s = p+2*d+b*3;
    if(s>=150)
        printf("B\n");
    else if(s>=120)
        printf("D\n");
    else if(s>=100)
        printf("P\n");
    else
        printf("N\n");
    return 0;
}