#include <stdio.h>
#define MAX 100000

int v[MAX];

void merge(int i, int j){
    int mid = (i+j)/2;
    int p1 = i, p2 = mid + 1;
    int k = 0;
    int aux[MAX];
    while(p1 <= mid && p2 <= j){
        if(v[p1] < v[p2]){
            aux[k++] = v[p1++];
        }
        else{
            aux[k++] = v[p2++];
        }
    }
    while(p1<=mid){
        aux[k++] = v[p1++];
    }
    while(p2<=j){
        aux[k++] = v[p2++];
    }
    for(k = 0; k <= (j - i); k++){
        v[i+k] = aux[k];
    }
}

void mergeSort(int i, int j){
    if(j - i <1) return;
    int mid = (i+j)/2;
    mergeSort(i, mid);
    mergeSort(mid+1, j);
    merge(i,j);
}


int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    mergeSort(0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d ",v[i]);
    }
    printf("\n");
    return 0;
}