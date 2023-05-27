#include <stdio.h>

int main(){
    int x, n;
    scanf("%d %d",&x, &n);
    int ans = x*(n+1);
    for(int i = 0; i < n; i++){
        int m;
        scanf("%d",&m);
        ans -=m;
    }
    printf("%d\n", ans);
    return 0;
}