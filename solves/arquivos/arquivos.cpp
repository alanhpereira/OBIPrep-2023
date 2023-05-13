#include <stdio.h>
#include <algorithm>
#define MAX 112345
using namespace std;

int v[MAX];

int main(){
    int n, k;
    scanf("%d%d",&n,&k);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    sort(v, v+n);
    int i =0, j = n-1;
    int ans = 0;
    for(int i = 0 ; i <= j ; i++){
        while(v[i]+v[j] > k && j > i){
            ans++;
            j--;
        }
        ans++; j--;
    }
    printf("%d\n",ans);
    return 0;
}