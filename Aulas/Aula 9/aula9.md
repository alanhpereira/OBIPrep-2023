# SegTree e BIT

## Pra que usar?

Fazer consultas em um intervalo, como consulta de mínimo, máximo e soma. Estratégias para como se fazer isso:  
* Usar um vetor normal e fazer a operação no intervalo inteiro toda consulta:  
    * Complexidade para fazer atualização: O(1)
    * Complexidade para consultar O(n)
* Usar um vetor de soma do prefixo (Não aplicável para máximo mínimo), e refazer sempre que atulizar um valor, mas na consulta fazer uma simples subtração para obter a soma do intervalo:  
    * Complexidade para fazer atualização: O(n)
    * Complexidade para consultar O(1)

## BIT

* Serve para obter a soma do prefixo em O(log n) e atualizações em O(log n)
* Operações de atualização não settam o novo de uma posição, mas sim relativo ao valor anterior, em caso que se quer deixar uma posição da BIT com um valor específico usa-se o valor anterior como base da atualização.
* Exemplos de código da BIT
```c++
int sum(int k) {
    int s = 0;
    while (k >= 1) {
        s += tree[k];
        k -= k&-k;
    }
    return s;
}

void add(int k, int x) {
    while (k <= n) {
        tree[k] += x;
        k += k&-k;
    }
}
```

## Segment Tree

* É mais versátil que a BIT
* Suporta operações como mínimo, máximo além da soma.
* Usa mais memoria que a BIT, e mais chato de implementar

```c++
void update(int idx, int l, int r, int i, int v){
    if(i > r || i < l) return; // valor atualizado fora do intervalo
    if(l == r){ // condição de parada, intervalo unitário
        seg[idx] = v;
        return;
    }
    int mid = (l+r)/2; //meio do intervalo do indice atual
    update(2*idx, l , mid, i, v); // atualiza a metade esquerda, caso não seja necessário, será retornara logo após entrar na função
    update(2*idx+1, mid + 1, r, i, v); // mesmo coisa para direita
    seg[idx] = min(seg[2*idx], seg[2*idx+1]); // atualiza a posição atual com base nos dois filhos
}

long long query(int idx, int l, int r, int i, int j){
    if(i > r || j < l){ //intervalos totalmente disjuntos
        return INF; // retorna elemento neutro da operação da segTree
    }
    if(l>=i && r <= j){ // intervalo atual totalmente contido no intervalo da quary
        return seg[idx]; // retorna valor precalculado para o intervalo atual
    }
    int mid = (l+r)/2; //meio do intervalo do indice atual
    return min(query(2*idx, l, mid, i, j), query(2*idx+1, mid+1, r, i, j)); //recorre as duas metades para obeter a resposta
}
```
