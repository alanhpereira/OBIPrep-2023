# Buscas

## Busca simples

* Itera-se o vetor elemento a elemento
* Simples
* Lento
* O(n)

```c++
int buscaSimples(int e){
    for(int i = 0; i < n; i++){
        if(v[i] == e){
            return i;
        }
    }
}
```

---

## Busca binária

* Suponha um vetor ordenado
* Compare o elemento do meio do vetor com o elemento procurado
* Selecione a metade que deve conter o elemento
* Repita até sobrar apenas um elemento
* O(log n)

### Implementação recursiva
```c++
int bb(int i, int j, int e){
    int mid = (i+j)/2;
    if(i >= j) return v[mid]==e ? mid : -1;
    if(e > v[mid])return bb(mid+1, j, e);
    return bb(i, mid , e);
}
```

### Implementação iterativa

```c++
int bb(int i, int j, int e){
    int mid;
    while(i < j){
        mid = (i+j)/2;
        if(e > v[mid]) i = mid + 1;
        else j = mid; 
    }
    return mid;
}
```

### Exercícios

[BSEARCH1 - Binary search](https://www.spoj.com/problems/BSEARCH1/)  
[Ogros](https://olimpiada.ic.unicamp.br/pratique/p2/2008/f1/ogros/)  
[Pão a metro](https://olimpiada.ic.unicamp.br/pratique/p1/2007/f2/metro/)  
[AGGRCOW - Aggressive cows](https://www.spoj.com/problems/AGGRCOW/)