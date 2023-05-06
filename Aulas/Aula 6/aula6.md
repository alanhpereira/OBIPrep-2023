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