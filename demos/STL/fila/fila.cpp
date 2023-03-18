#include <queue>
#include <stdio.h>
using namespace std;

queue<int> q;

int main(){
    int n;
    scanf("%d ", &n);
    for(int i = 0; i <n ; i++){
        int t;
        scanf("%d", &t);
        if(t == 0){
            q.pop();
        }
        else{
            q.push(t);
        }
        printf("%d\n", q.front());
    }
}