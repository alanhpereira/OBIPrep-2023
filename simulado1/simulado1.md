# Simulado 1

## 1. [Fissura](https://olimpiada.ic.unicamp.br/pratique/p2/2020/f1/fissura/)

1. Ler números como carácteres
2. Converter caracteres em números fazendo c - '0'
3. Espalhar lava enquanto a altura for menor q a entrada
4. Imprimir o mapa original substituindo pontos com lava por '*'

---

## 2. [Tesouro](https://olimpiada.ic.unicamp.br/pratique/p2/2011/f1/tesouro/)

1. Ler as pistas
2. Para cada posição, conferir se é válida para o tesouro usando usando as pistas
3. Guardar a primeira posição válida encontrada
4. Caso ache uma segunda posição, imprimir -1 -1 e retornar
5. Caso seja achado uma segunda, imprimir a posição válida encontrada

---

## 3. [Chuva](https://olimpiada.ic.unicamp.br/pratique/p2/2016/f1/chuva/)

1. Criar dois vetores auxiliares  
    1. Máximo à esquerda  
    2. Máximo à direita
2. Para cada um desses vetores se percorre em uma das direções e mantemos um máximo até agora que é atualizado quando encontramos um elemento maior, em cada posição salvamos oa max atual.
3. Para cada posição conferir se os dois max são maiores que a posição atual, isso quer dizer que há parede dois dois lados para reter água na posição atual.

---