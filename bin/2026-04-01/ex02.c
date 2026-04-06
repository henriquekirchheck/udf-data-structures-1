#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Definição do constante de numero de argumentos necessarios
const int REQUIRED_ARGUMENTS = 2;

int main(int argc, char **argv) {
  // Se não for incluido um numero de bytes nos argumentos do programa, retorne
  // um erro
  if (argc != REQUIRED_ARGUMENTS) {
    (void)fprintf(stderr, "Erro de argumento: ex02 [numero]");
    return 1;
  }

  // Adiquirindo o input do usuario dos argumentos e tranformando ele em um
  // numero
  uint64_t num_arg = strtoul(argv[1], NULL, 0);

  // Alocando o buffer do tamanho requisitado
  char *buffer = (char *)malloc((num_arg + 1) * sizeof(char));

  // Retornando erro se alocação falhar
  if (buffer == NULL) {
    return 1;
  }

  // Coloque um prompt na tela
  printf("Digite uma string de até %ld caracteres: ", num_arg);
  // Adquire um input do usuario, retorna erro se ocorrer uma falha
  if (fgets(buffer, (int)(num_arg + 1), stdin) == NULL) {
    // Dealocando o buffer
    free(buffer);
    return 1;
  }

  // Print do input recebido
  printf("%s\n", buffer);

  // Dealocando o buffer
  free(buffer);

  return 0; // Retornando como sucesso
}

// Resultados:
// 1. > ./ex02 8 ~/src/udf-data_structuresvia △ v4.1.2  22:27
//    Digite uma string de até 8 caracteres: Piquinique
//    Henrique
// 2. > ./ex02 2
//    Digite uma string de até 2 caracteres: Oi
//    Oi
