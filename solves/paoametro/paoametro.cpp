#include <stdio.h>
#define MAX 10010

int m[MAX],k;

int contaFatia(int t){
    int f = 0;
    for(int i = 0 ; i < k; i++){
        f += m[i]/t; 
    }
    return f;
}

int bb(int i, int j, int n){
    int mid;
    while(i < j){
        mid = (i+j+1)/2;
        if(contaFatia(mid) < n)j = mid - 1;
        else i = mid;
    }
    return i;
}

int main(){
    int n;
    scanf("%d",&n);
    scanf("%d",&k);
    for(int i = 0; i < k; i++){
        scanf("%d",&m[i]);
    }
    printf("%d\n",bb(1,MAX,n));
    return 0;
}