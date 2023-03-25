#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;

int main(){
    int n;
    for(int i = 0; i < n; i++){
        int p, v;
        scanf("%d %d", &p, &v);
        if(v == 0){
            printf("m[%d] = %d\n",p, m[p]);
        }
        else{
            m[p] = v;
        }
    }
}