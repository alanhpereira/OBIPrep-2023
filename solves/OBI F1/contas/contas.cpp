#include <stdio.h>
#include <algorithm>
#define N 3
using namespace std;

int c[N];

int main(){
    int d, ans = 0;
    scanf("%d", &d);
    for(int i = 0; i < N; i++){
        scanf("%d", &c[i]);
    }
    sort(c, c+N);
    for(int i = 0; i < N; i++){
        if(d >= c[i]){
            d-=c[i];
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}