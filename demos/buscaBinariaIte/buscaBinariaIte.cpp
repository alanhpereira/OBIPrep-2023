#include <stdio.h>
#include <algorithm>
#define MAX 1024
using namespace std;

int v[MAX];

int bb(int i, int j, int e){
    int mid;
    while(i < j){
        mid = (i+j)/2;
        if(e > v[mid]) i = mid + 1;
        else j = mid; 
    }
    return mid;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    int q;
    sort(v, v+n);
    scanf("%d",&q);
    for(int i = 0; i < q; i++){
        int e;
        scanf("%d", &e);
        printf("%d\n", bb(0,n-1,e));
    }
    return 0;
}