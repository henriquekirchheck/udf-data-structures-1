#include <stdio.h>
#include <stdlib.h>

const int MEANING_OF_LIFE = 42; // Definindo constante 42

int main(void) {
  // Alocação de memoria para o int
  int *number = (int *)malloc(sizeof(int));

  // Caso alocação falhe, retorne erro
  if (number == NULL) {
    return 1;
  }

  // Escrevendo constante 42 para a memoria do ponteiro
  *number = MEANING_OF_LIFE;

  // Colocando o valor na tela junto com o ponteiro
  printf("%p: %d\n", number, *number);

  // Dealocando a memoria alocada
  free(number);

  return 0; // Retornando como sucesso
}

// Resultados:
// 1. 0x55e4b4bc0310: 42
// 2. 0x5622f50b8310: 42