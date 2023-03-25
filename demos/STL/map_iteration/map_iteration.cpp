#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;

int main(){
    int n;
    scanf("%d", &n);
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
    for(auto it = m.begin(); it != m.end(); it++){
        printf("m[%d] = %d\n", it -> first, it -> second);\
        // (*it).first => it->first
        // first é a chave, second o valor
    }
}