#include <stdio.h>
#define MAXN 11234
#define MAXS 20

char nomes[MAXN][MAXS];
int lances[MAXN];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", nomes[i]);
        scanf("%d", &lances[i]);
    }
    int lg = 0;
    for(int i = 1; i < n; i++)
        if(lances[i] > lances[lg])
            lg = i;
    printf("%s\n%d\n",nomes[lg],lances[lg]);
    return 0;

}