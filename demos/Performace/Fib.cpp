#include <stdio.h>
#define MOD 100000009

long long fib(int a){
    if (a <= 1) return 1;
    return (fib(a-1) + fib(a-2))%MOD;
}

int main(){
    printf("%lld\n", fib(35));
}