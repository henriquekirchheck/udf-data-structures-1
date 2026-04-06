#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define PRODUCT_NAME_MAX_SIZE 50

typedef struct Product {
  uint64_t code;
  char name[PRODUCT_NAME_MAX_SIZE];
} Product;

typedef struct ProductArray {
  size_t length;
  size_t cap;
  Product *data;
} ProductArray;

ProductArray ProductArray_create(size_t initial_size);
void ProductArray_destroy(ProductArray* array);

void ProductArray_insert(ProductArray* array, Product item);
void ProductArray_remove(ProductArray* array);

size_t ProductArray_find(const ProductArray* array, uint64_t code);
void ProductArray_list(const ProductArray* array);
