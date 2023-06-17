# Subsequencia

## Ideia básica

* Resolução baseada em 2 ponteiros, um para cada vetor;
* O primeiro percorre o vetor A normalmente. (i)
* O segundo percorre B conforme vai achando os elementos no ponteiro que percorre A; (j)
* ou seja Quando A[i] == b[j], j++, mas só uma vez por i;
