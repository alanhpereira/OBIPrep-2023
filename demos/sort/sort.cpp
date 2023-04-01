#include <stdio.h>
#include <algorithm>
#include <vector>
#define MAX 100000
using namespace std;

vector<int> vc;
int v[MAX];

int main(){

    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
        vc.push_back(v[i]);
    }
    sort(v, v+n);
    // sort(vc.begin(), vc.end()); // ordenação normal
    // sort(vc.begin(), vc.end(), greater<int>()); // ordenação reversa
    sort(vc.rbegin(), vc.rend()); // ordenação reversa
    printf("Array\n");
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\n\nVector\n");
    for(int i = 0; i < n; i++){
        printf("%d ",vc[i]);
    }
    printf("\n");
    return 0;

}