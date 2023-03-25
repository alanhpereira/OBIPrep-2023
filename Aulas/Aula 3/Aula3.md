# Aula 3 - STL(continuação) e Complexidade

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
### Iterar map(passar por todos elementos válidos)
* Complexidade O(n log n)
```c++
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
        printf("m[%d] = %d\n", it -> first, it -> second);
        // (*it).first => it->first
        // first é a chave, second o valor
    }
```
 * A partir do c++11 da pra usar o auto invés de `map<int, int>::iterator`


```c++
    for(auto it = m.begin(); it != m.end(); it++){
        printf("m[%d] = %d\n", it -> first, it -> second);
    }
```
---
# Complexidade

## Notação O

* Notação que representa quanto tempo o algoritmo demora para rodar em função da entrada
* Complexidade comuns
    * O($1$) - Tempo constante, não depende da entrada
    * O($log_2n$) - Tempo logarítmico, entrada, tempo aumenta em 1
    * O($n$) - Tempo linear, entrada dobra, tempo dobra
    * O($n^2$) - Tempo quadrático, entrada dobra, tempo quadruplica
    * O($2^n$) - Tempo exponecial, entrada aumenta em 1, tempo dobra
    * O($n!$) - Tempo fatorial, entrada aumenta em 1, tempo é multiplicado por n
* É possível multiplicar complexidades
    * Um algoritmo que faz n operações O(log n) tem complexidade O(n * log n)
* Quando se soma duas complexidades, prevalece a maior
    * Roda-se um algoritmo complexidade O($n^2$) e em seguida outro de O($n$), a complexidade total é O($n^2$)
    * Complexiade de um polinómio resulta apenas no elemento de maior ordem
* Ignora-se constantes multiplicando O(2*n) => O(n)
* Em geral assume-se que o computador roda $10^8$ operações por segundo, e na OBI em geral o código tem tempo limite de 1s para rodar pra uma determina entrada
    * Um código O($n!$) pode passar com limite de n até 10
    * Um código O($2^n$) pode passar com limite de n até 20
    * Um código O($n^4$) pode passar com limite de n até 100
    * Um código O($n^3$) pode passar com limite de n até 500 mas não 1000
    * Um código O($n^2 * logn$) pode passar com limite de n até 1000
    * Um código O($n^2$) pode passar com limite de n até 1000
    * Um código O($n * logn$) pode passar com limite de n até $10^6$
    * Um código O($n$) pode passar com limite de n até $10^8$
    * Um código O($log n$) pode passar com limite de n até $10^{3000000}$, mas por limites de tamanho de váriável, em geral se limita a $10^{18}$ limite do long long

### Algoritmos comuns
* Acessar uma posição de um vetor ou matriz
    * O(1)
    ```c++
    a = v[i]
    ```
* Leitura de vetor
    * O($n$)
    ```c++
    for(int i = 0; i < n; i++){
        scanf("%d", &v[i]);
    }
    ```
* Leitura de matrix n*n
    * O($n^2$)
    ```c++
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &n[i][j]);
        }
    }
    ```
* Ordenação por sort de biblioteca
    * O($n log n$)
    ```c++
    sort(v.begin(), v.end());
    ```
    
* Busca binária
    * O($log n$)

### O que é log?
* O inverso da exponecial
* $2^x = a$ => $log_2a = x$
* Cada vez mais lento pra crescer
