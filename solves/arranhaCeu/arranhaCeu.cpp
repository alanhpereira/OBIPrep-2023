#include <stdio.h>
#define MAX 112345

int seg[4 * MAX];
int v[MAX];

void update(int idx, int l, int r, int i, int vl) {
	if (i < l || i > r) return;	 // valor atualizado fora do intervalo
	if (l == r) {				 // condição de parada, intervalo unitário
		seg[idx] = vl;
		return;
	}
	int mid = (l + r) / 2;						 // meio do intervalo do indice atual
	update(2 * idx, l, mid, i, vl);				 // atualiza a metade esquerda, caso não seja necessário, será retornara logo após entrar na função
	update(2 * idx + 1, mid + 1, r, i, vl);		 // mesmo coisa para direita
	seg[idx] = seg[2 * idx] + seg[2 * idx + 1];	 // atualiza a posição atual com base nos dois filhos
}

int query(int idx, int l, int r, int i, int j) {
	if (i > r || j < l) {  // intervalos totalmente disjuntos
		return 0;		   // retorna elemento neutro da operação da segTree
	}
	if (l >= i && r <= j) {	 // intervalo atual totalmente contido no intervalo da quary
		return seg[idx];	 // retorna valor precalculado para o intervalo atual
	}
	int mid = (l + r) / 2;														 // meio do intervalo do indice atual
	return query(2 * idx, l, mid, i, j) + query(2 * idx + 1, mid + 1, r, i, j);	 // recorre as duas metades para obeter a resposta
}

int main() {
	int n, q;
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &v[i]);
		update(1, 1, n, i, v[i]);
	}
	for (int i = 0; i < q; i++) {
		int t, k;
		scanf("%d%d ", &t, &k);
		if (t == 0) {
			int p;
			scanf("%d ", &p);
			v[k] = p;
			update(1, 1, n, k, p);
		}
		else {
			printf("%d\n", query(1, 1, n, 1, k));
		}
	}
	return 0;
}