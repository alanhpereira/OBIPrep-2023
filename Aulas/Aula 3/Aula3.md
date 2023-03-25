# Aula 3 - STL, continuação

## Priority queue

* `#include <queue>`
* `priorit_queue<int> pq;`
* A topo da fila é sempre o maior elemento
* .top() elemento do topo da fila(O maior elemento) - O(1)
* .push(e) adiciona elemento na fila - O(log n)
* .pop() remove o topo da fila - O(log n)
* .size() retorna o número de elementos na fila
* .clear() esvazia
* .empty() retorna true se a pilha está vazia
* Pode-se inserir o oposto do elemento pra ter uma fila em que o topo é o menor
```c++
#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<int> pq;

int main(){
    int n;
    scanf("%d ", &n);
    for(int i = 0; i <n ; i++){
        int t;
        scanf("%d", &t);
        if(t == 0){
            pq.pop();
        }
        else{
            pq.push(t);
        }
        printf("%d\n", pq.top());
    }
}
```
---
## Map
* `#include <map>`
* `map<int, int> mp;`
* Similar o dict do Python, só que o tipo da chave é definido(O primeiro elemento da declaração do map)
* Pode-se usar qualquer tipo comparável(o operador < é válido>)
* .size() retorna o número de elementos no map
* .clear() esvazia
* .empty() retorna true se o map está vazio
* .find(k) retorna iterador pra posição que o elemento se encontra(nulo caso não exista) - O(log n)
* Acesso como um vetor normal usando [] - O(log n)
```c++
#include <stdio.h>
#include <map>
using namespace std;

map<int, int> m;

int main(){
    int n;
    for(int i = 0; i < n; i++){
        int p, v;
        scanf("%d %d", &p, &v);
        if(v == 0){
            printf("m[%d] = %d\n",p, m[p]);
        }
        else{
            m[p] = v;
        }
    }
}
```



