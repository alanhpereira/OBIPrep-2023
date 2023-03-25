#include <stdio.h>
#include <stack>
using namespace std;

stack<int> stk;

int main(){
    int n;
    scanf("%d ", &n);
    for(int i = 0; i <n ; i++){
        int t;
        scanf("%d", &t);
        if(t == 0){
            stk.pop();
        }
        else{
            stk.push(t);
        }
        printf("%d\n", stk.top());
    }
}