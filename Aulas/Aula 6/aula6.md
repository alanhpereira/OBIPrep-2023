# Gulosos e Two Pointers

## Gulosos

* Algoritmos que visam maximizar a resposta fazendo a escolha ótima localmente
* Esses algoritmos não voltam atrás nas escolhas
* Difícil provar que funciona

---

### Problema do Troco

Temos infinitas moedas de determinados valores, queremos o mínimo de moedas para dado valor.

m = {1, 2, 5, 10, 20, 50, 100, 200}

Pegamos o máximo possível da nota maior, e passamos para próxima nota

Para n = 523

2 * 200, 1 * 100, 1 * 20, 1 * 2, 1 * 3

m = {1, 5, 8}

Para n = 10

2 * 5

---

### Problema do agendamento

[Dentista](https://olimpiada.ic.unicamp.br/pratique/pj/2010/f2/dentista/)

#### Ideia 1

* Ordenamos por duração das tarefas
* Pegamos a mais curta possível que não tenha conflito com as já escolhidas

Não funciona
Contra-exemplo:
```
    [        ]
            [  ]
              [         ]
```

#### Ideia 2
* Ordenar pelo começo 
* Pegamos a que começa mais que possível que não tenha conflito com as já escolhidas


Não funciona
Contra-exemplo:
```
    [                             ]
      [] [         ]  [  ] [  ]
```


#### Ideia 3
* Ordenar pelo fim 
* Pegamos a que acaba mais que possível que não tenha conflito com as já escolhidas
* Funciona porque é ótimo acabar o mais cedo possível para já poder começar a próxima

---

## Two pointers

* Algoritmos que consistem em percorrer vetores com 2 apontadores
* Cada apontador pode se mover apenas uma direção para garantir eficiecia

### Soma de subarray

* Temos um vetor com n elementos positivos.
* Queremos um subarray contínuo com soma exatamente k

Solução:

* Temos 2 apontadores indicando o início e o fim do subarray, inicialmente em 0;
* Temos a variável soma que contém a soma do subarray;
* Repetir até achar resposta ou acabar elementos do vetor
    * Se a soma for menor do que k, adiciar elemento ao fim
    * Se a soma for maior do que k, remover elemento do começo

```c++
#include <stdio.h>
#define MAX 1123

int v[MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&v[i]);
    }
    int k;
    scanf("%d",&k);
    int i = 0, j = 0, s = 0;
    while (i < n){
        if(s < k){
            s+= v[j++];
        }
        else if(s > k){
            s -= v[i++];
        }
        else{
            printf("%d %d\n", i, j);
        }
    }
    return 0;
}
```