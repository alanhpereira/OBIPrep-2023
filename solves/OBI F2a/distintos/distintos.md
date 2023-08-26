# Distintos

## Ideia básica

* Temos um ponteiro para o começo do intervalo sendo considerado
* Temos um vetor com ocorrencia mais recente de cada numero
* Para cada elemento do vetor
    * Adicionamos o novo elemento ao vetor
    * Verificamos se esse numero já estava presente
    * Se estiver presente, atualizar o começo para logo após
    * atualizar o vetor de ocorrencia mais recente
* A resposta final é máximo tamanho encontrado durante essa busca

## Cuidado