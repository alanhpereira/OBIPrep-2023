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