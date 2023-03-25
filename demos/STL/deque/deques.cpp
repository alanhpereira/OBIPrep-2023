#include <deque>
#include <stdio.h>
using namespace std;

deque<int> dq;

int main(){
    int n;
    scanf("%d ", &n);
    for(int i = 0; i <n ; i++){
        int t, p;
        scanf("%d %d", &t, &p);
        if(t == 0){
            if(p == 0) //frente do deque
                dq.pop_front();
            else 
                dq.pop_back();
        }
        else{
            if(p == 0) //frente do deque
                dq.push_front(t);
            else 
                dq.push_back(t);
        }
        printf("%d %d %d\n", dq.front(), dq.back(), dq.size());
    }
}