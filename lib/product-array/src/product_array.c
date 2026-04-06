#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "product_array.h"

ProductArray ProductArray_create(size_t initial_size) {
  Product *data = calloc(initial_size, sizeof(Product));
  if (data == NULL) {
    exit(1);
  }
  ProductArray array = {.cap = initial_size, .data = data, .length = 0};
  return array;
}
void ProductArray_destroy(ProductArray *array) {
  free(array->data);
  array->data = NULL;
  array->cap = 0;
  array->length = 0;
}

void ProductArray_expand(ProductArray *array, size_t capacity) {
  if (capacity <= array->cap) {
    return;
  }
  Product *data = reallocarray(array->data, capacity, sizeof(Product));
  if (data == NULL) {
    exit(1);
  }
  array->data = data;
  array->cap = capacity;
}

void ProductArray_insert(ProductArray *array, Product item) {
  if (array->length == array->cap) {
    ProductArray_expand(array, array->length * 2);
  }
  array->data[array->length] = item;
  array->length += 1;
}
void ProductArray_remove(ProductArray *array) {
  size_t new_length = array->length - 1;
  memmove(array->data, array->data + 1, new_length * sizeof(Product));
  array->length = new_length;
}

size_t ProductArray_find(const ProductArray *array, uint64_t code) {
  int index = 0;
  for (index = 0; index < array->length; index++) {
    Product *product = &array->data[index];
    if (product->code == code) {
      return index;
    }
  }
  return -1;
}

void ProductArray_list(const ProductArray *array) {
  int index = 0;
  for (index = 0; index < array->length; index++) {
    Product *product = &array->data[index];
    printf("Produto %ld: %s\n", product->code, product->name);
  }
}
