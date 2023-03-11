MOD = 1000000009

def fib (a):
    if (a<=1):
        return 1
    return (fib(a-1)+fib(a-2))%MOD

print(fib(35))