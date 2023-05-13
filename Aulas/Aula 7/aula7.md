# Grafos

## O que é um grafo?

Podemos pensar em bolinhas ligadas por linhas, pode tambem ser a representação das ruas de uma cidade, um labirinto a ser percorrido, uma rede de amigos e muitas outras coisas.

---

## Elementos de um grafo

### Nós (nodes)

O nó seria a representação de um ponto. Como por exemplo, a junção de duas ruas, uma cidade em uma malha rodoviaria, basicamente a bolinha.

### Arestas (edges)

A aresta representa a ligação entre **dois** nós, pode ou não ter peso, e direcionalidade. Pode representar ruas, amizades, e outras coisa. 
O peso pode significar a distância entre os dois nós que a aresta liga. Uma rede de amizades do facebook é um grafo não direcionado, já a rede do Instagram, twitter e outros modelos baseado em seguidores, são direcionados, já que quando uma pessoa segue a outra não implíca o contrário

---

## Representações de um grafo

Existem diversas maneiras de representar um grafo, mas a mais comum para os nossos algoritmos é a lista de adjacências.

* ### Lista de adjacências

Para cada nó existe um lista que representa a ligação com os seus vizinhos. Em geral é usado um vetor de vectors para guardar a lista de adjacência de todos os nós.

```c++
vector <int> adj[MAX];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i > m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v); 
        adj[v].push_back(u); // esta linha representa que o grafo é não direcional
    }
}

```

* ### Adjacências implícitas

Vamos supor que temos um tabuleiro quadriculado(estilo xadrez), em que cada casa pode ser considerada vizinha das casas com qual compartilha uma aresta(a casa (i, j) é vizinha as casa (i+1, j), (i, j+1), (i-1, j), (i, j-1)), nesses casos não é necessário guardar uma lista de adjacências, já que as ligações são prefinidas com cordenadas relativas conhecidas.

* ### Matriz de adjacências

A existencia de uma aresta entre u e v é dada pela existencia ou não de um elemento de uma matriz, na posição u, v, então se existe elemento na posição u, v da matriz, logo existe a aresta u, v. Essa representação e rara de ser usada pois é ineficiente.

* ### Lista de Arestas

São guardadas todas as arestas de um grafo em uma única lista. Usadado normalmente em algoritmos de construção de grafos.

--- 
