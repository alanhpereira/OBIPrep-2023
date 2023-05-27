#include <stdio.h>
#define MAX 112345

int v[MAX], md[MAX], me[MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n ; i++){
        scanf("%d", &v[i]);
    }
    int m = v[0];
    for(int i = 0; i < n; i++){
        if(v[i] > m) m = v[i];
        me[i] = m;
    }
    m = v[n - 1];
    for(int i = n-1; i >= 0; i--){
        if(v[i] > m) m = v[i];
        md[i] = m;
    }
    int ans = 0;
    
    for(int i = 0; i < n; i++)
        if(md[i] > v[i] && me[i] > v[i])
            ans ++;

    printf("%d\n",ans);
    return 0;
}