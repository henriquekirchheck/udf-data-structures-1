#include "product_array.h"
#include <stdio.h>

int main(void) {
  ProductArray array = ProductArray_create(4);
  printf("Array:\n\tSize: %ld\n\tCapacity: %ld\n", array.length, array.cap);
  
  ProductArray_insert(&array, (Product){.code = 10, .name = "Agua"});
  ProductArray_insert(&array, (Product){.code = 12, .name = "Detergente"});
  ProductArray_insert(&array, (Product){.code = 15, .name = "Escova"});
  ProductArray_insert(&array, (Product){.code = 6, .name = "Refrigerante"});
  ProductArray_insert(&array, (Product){.code = 2, .name = "Fosforo"});

  printf("Array:\n\tSize: %ld\n\tCapacity: %ld\n", array.length, array.cap);
  ProductArray_list(&array);
  
  ProductArray_remove(&array);
  ProductArray_remove(&array);
  
  printf("Array:\n\tSize: %ld\n\tCapacity: %ld\n", array.length, array.cap);
  ProductArray_list(&array);
  
  ProductArray_insert(&array, (Product){.code = 20, .name = "Feijão"});
  ProductArray_insert(&array, (Product){.code = 13, .name = "Pedra"});
  ProductArray_insert(&array, (Product){.code = 23, .name = "Mouse"});
  ProductArray_insert(&array, (Product){.code = 56, .name = "Arroz"});
  ProductArray_insert(&array, (Product){.code = 99, .name = "Quadro"});
  
  printf("Array:\n\tSize: %ld\n\tCapacity: %ld\n", array.length, array.cap);

  ProductArray_insert(&array, (Product){.code = 95, .name = "Computador"});
  
  printf("Array:\n\tSize: %ld\n\tCapacity: %ld\n", array.length, array.cap);
  
  size_t index = ProductArray_find(&array, 13);
  if (index == -1) {
    exit(1);
  }
  Product* product = &array.data[index];
  printf("Produto %ld: %s\n", product->code, product->name);
  
  ProductArray_destroy(&array);
  printf("Array:\n\tSize: %ld\n\tCapacity: %ld\n", array.length, array.cap);
  
  return 0;
}
