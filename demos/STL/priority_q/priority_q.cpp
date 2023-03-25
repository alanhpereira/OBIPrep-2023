#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int> pq;


int main(){
    int n;
    scanf("%d ", &n);
    for(int i = 0; i <n ; i++){
        int t;
        scanf("%d", &t);
        if(t == 0){
            pq.pop();
        }
        else{
            pq.push(t);
        }
        printf("%d\n", pq.top());
    }
}