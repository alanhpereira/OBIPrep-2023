# Complexidade - exemplos

## Bubble Sort

* Pra cada elemento do vetor não ordenado
    * Percorre do elemento até o final
    * Toda vez que um elemento for maior que próximo durante o percurso troque os dois elementos

| 8 | 2 | 6 | 3 | 1 |

| 2 | 8 | 6 | 3 | 1 |  
| 2 | 6 | 8 | 3 | 1 |  
| 2 | 6 | 3 | 8 | 1 |  
| 2 | 6 | 3 | 1 | *8* |

| 2 | 6 | 3 | 1 | *8* |  
| 2 | 3 | 6 | 1 | *8* |  
| 2 | 3 | 1 | *6* | *8* | 

| 2 | 3 | 1 | *6* | *8* |  
| 2 | 1 | *3* | *6* | *8* |

| *1* | *2* | *3* | *6* | *8* |  

O($n*(n-1)/2$) -> O($n^2$)

![Bubble Sort](https://upload.wikimedia.org/wikipedia/commons/c/c8/Bubble-sort-example-300px.gif)

---
## Merge Sort

1. Partindo do pressuposto que existe uma função mágica que ordene um vetor dado.  
2. Divide-se o vetor em 2 partes e passa cada parte individualmente pra função mágica
3. Há 2 vetores ordenados, junta-se os 2 vetores de forma que tenha-se um único vetor ordenado

### Exemplo: juntar 2 vetores ordenados

| 1 | 3 | 5 | 7 | 9 |  
| 2 | 4 | 6 | 8 |

Usamos 3 iteradores, 2 para os vetores originais(p1, p2) e um para o de saída (i)

p1 = p1 = i = 0

Pra cada iteração, seleciona-se o menor dentre os elementos apontados por p1 e p2, e o coloca no vetor de saída, e avança o respectivo ponteiro


| 1 | 3 | 5 | 7 |  
| 2 | 4 | 6 | 8 |  
| | 

| 3 | 5 | 7 |  
| 2 | 4 | 6 | 8 |  
| 1 |  

| 3 | 5 | 7 |  
| 4 | 6 | 8 |  
| 1 | 2 |  

| 5 | 7 |  
| 4 | 6 | 8 |   
| 1 | 2 | 3 |  

| 5 | 7 |  
| 6 | 8 |  
| 1 | 2 | 3 | 4 |  

| 7 |  
| 6 | 8 |  
| 1 | 2 | 3 | 4 | 5 |

| 7 |  
| 8 |  
| 1 | 2 | 3 | 4 | 5 | 6 |

| 7 |  
| 8 |  
| 1 | 2 | 3 | 4 | 5 | 6 |

| |  
| 8 |  
| 1 | 2 | 3 | 4 | 5 | 6 | 7 |

| |  
| |  
| 1 | 2 | 3 | 4 | 5 | 6 | 7 | 9 |  

## A função mágica
* Agora que consigos juntar dois vetores ordenados em um único vetor ordenados, precisamos da função mágica que ordena os vetores.
* A função é o própio merge sort, ordena cada uma das partes com merge sort, e depois fazemos o merge das duas partes. 
* Quando o tamanho do vetor a ser ordenado é 1, não é necessário ordenar

Divide-se k vezes o vetor em 2 até chegar nos elementos unitários, $\frac{n}{2^k} = 1$ -> $2^k = n$ $ k = log_2n$, e pra cada vez dividida, é necessário fazer o merge mais vezes, mas com vetores cada vez menores, e tamnaho total n


### O(n log n)


![Merge Sort](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)  

---

## Sort da algorithm

* `#include <algorithm>`
* Para vetores normais
    * `sort(v, v+n)` onde v é o vetor a ser ordenado e n o número de elementos a ser ordenado
* Para vectors
    * `sort(v.begin(), v.end())` onde v é o vector ser ordenado;
    * `sort(v.rbegin(), v.rend())` onde v é o vector ser ordenado reversamente
    * `sort(v.begin(), v.end(), greater<int>())` onde v é o vector ser ordenado reversamente
    
---

## Pairs
* Juntam dois elementos em uma única variavel `pair<int, int>`
* Podem ser dois tipos distintos `pair<int, vector<int> >`, `pair<pair<int, int> ,int>` 
* Pode-se encadear os pair a vontade `pair<pair<pair<int , int>, int >, pair<int, int> >`
* Acesso usando `.first` e `.second`
* Tambem se encadeia `.first` e `.second` para acessar pair complexo `.first.fisrt.second`
* Na ordenação de pairs, quando o primeiro é igual desempate pelo segundo : (1, 1) < (1, 2)
* Frequentemente usado defines para abreviar o .first e .second como por exemplo `#define X first` ,`#define Y second`, `#define F first`, `#define S second`
* Usado o typedef abreviar a definação futura de pairs:
    * `typedef pair<int, int> pii;`
    * `typedef pair<int, pii> piii;`
    * `typedef pair<pii, pii> piiii;`
    * `pii a` -> `pair<int, int> a`
    * `a = pii(4, 3)`
    * `piii b = piii(3, pii(4, 2))`