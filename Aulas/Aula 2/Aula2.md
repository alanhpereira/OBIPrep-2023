# Aula 2 - Vetores, Matrizes e STL

## Vetores

* Listas de elementos acessados por índice
* Tamanho fix (Pode usar o #define para definir o tamanho)
* Indexado de 0
* Leitura com for

```c++
#include <stdio.h>
#define MAX 60

int vetora[MAX],vetorb[MAX],vetorc[MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &vetora[i]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &vetorb[i]);
    }
    for(int i = 0; i < n; i++){
        vetorc[i] = vetora[i]*vetorb[i];
    }
    for(int i = 0; i < n; i++){
        printf("%d\n", vetorc[i]);
    }
    return 0;
}
```

--- 

## Matrizes

* Vetores bidimensionais
* Delarados com dois conjuntos [] `int matriz[10][20]`
* Não acessado com ~~[5, 10]~~ mas sim [5][10]
* Leitura com 2 fors encadeados

```c++
#include <stdio.h>
#define MAX 20

int matriza[MAX][MAX], matrizb[MAX][MAX] ,matrizc[MAX][MAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriza[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matrizb[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrizc[i][j] = matriza[i][j] + matrizb[i][m-j-1];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrizc[i][j]);
        }
        printf("\n");
    }
    return 0;
}
```
---

## Vetores n-dimensionais

* É Só boltar mais [] pra aumentar as dimensões do array
* Vários fors para ler

```c++
#include <stdio.h>
#define MAX 20

int array4d[MAX][MAX][MAX][MAX];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    scanf("%d", &array4d[i][j][k][l]);
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    printf("%d ", array4d[i][j][k][l]);
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
```

---

# STL - Standard Template Library

[CPP Refeference](https://cplusplus.com/reference/)

* Em geral as bibliotecas da STL não tem o .h no final do nome
* Botar `using namespace std;` para depois dos includes e defines
* `#include <bits/stdc++.h>` inclui todas da STL
    * Demora mais para compilar
    * Arquivo executável maior
---
## Vector

* Tamanho dinâmico
* Similar ao list do python
* Escolhe-se o tipo do conteudo dentro dos <>
* Declaração: `vector<int> v;`
* Vetores de vectors `vector<int> v[MAX]`
* Vector de vectors `vector< vector<int> > v`
* .push_back(a) similar ao append do Python
* .size() retorna o número de elementos
* .empty() retorna true se o vector está vazio
* Acesso é como em um vetor normal usando [] (v[10])
* .clear() esvazia
```c++
#include <vector>
#include <stdio.h>
#include <utility> //pair
#define MAX 50
using namespace std;

vector<int> vec;
vector<pair<int, int> > adj[MAX];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        vec.push_back(a);
    }
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++){
        printf("%d ", vec[i]);
        vec[i] = i*i;
    }
    printf("\n");
    printf("%d\n", vec.size());
    for(int i = 0; i < vec.size(); i++){
        printf("%d ", vec[i]);
        vec[i] = i*i;
    }
    printf("\n");
    return 0;
}    
```
---

## Pilhas

* `#include <stack>`
* `stack<int> stk;`
* LIFO (Ultimo a entrar, primeiro a sair)
* .push(a) adiciona ao topo
* .size() retorna o número de elementos na pilha
* .empty() retorna true se a pilha está vazia
* .pop() tira do topo da pilha
* .top() retorna o elemento do topo
* .clear() esvazia

```c++
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
```
---

## Filas

* `#include <queue>`
* `queue<int> q;`
* LIFO (primeiro a entrar, primeiro a sair)* .push(a) adiciona ao fim da fila
* .size() retorna o número de elementos na fila
* .empty() retorna true se a fila está vazia
* .pop() tira da frente da fila
* .front() retorna elemtento na frente da fila
* .clear() esvazia
```c++
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
```

---

## Deque

* `#include <deque>`
* `deque <int> dq;`
* Double ended queue
* Pode remover ou adicionar elementos as duas pontas
* .push_back(a) adiciona elemento ao final
* .push_front(a) adiciona elemento ao começo
* .pop_back(a) remove elemento do final
* .pop_front(a) remove elemento do começo
* .size() retorna o número de elementos no deque
* .empty() retorna true se o deque está vazio
* .clear() esvazia