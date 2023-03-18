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