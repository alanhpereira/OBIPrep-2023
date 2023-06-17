#include <stdio.h>
#define MAX 512

int chinelos[MAX];

int main(){
    int n, p, ans = 0;;
    scanf("%d",&n);
    for(int i = 1; i <= n ; i++){
        scanf("%d",&chinelos[i]);
    }
    scanf("%d", &p);
    for(int i = 0; i < p; i++){
        int t;
        scanf("%d", &t);
        if(chinelos[t] > 0){
            ans++;
            chinelos[t]--;
        }
    }
    printf("%d\n", ans);
    return 0;
}