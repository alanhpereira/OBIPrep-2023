# Buscas

## Busca simples

* Itera-se o vetor elemento a elemento
* Simples
* Lento

```c++
int buscaSimples(int e){
    for(int i = 0; i < n; i++){
        if(v[i] == e){
            return i;
        }
    }
}
```