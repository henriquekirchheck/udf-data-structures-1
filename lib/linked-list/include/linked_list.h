#pragma once
#include <stdlib.h>

#define DEF_LINKED_LIST(typename, type) \
  typedef struct typename##Node { \
    struct typename##Node *next; \
    type value; \
  } typename##Node; \
  \
  static typename##Node* typename##_new(type value) { \
    typename##Node* node = malloc(sizeof(typename##Node)); \
    if (node == NULL) return NULL; \
    node->next = NULL; \
    node->value = value; \
    return node; \
  } \
  static void typename##_destroy(typename##Node* curr) { \
    typename##Node* node = curr; \
    for (;;) { \
      typename##Node* next = node->next; \
      free(node); \
      if (next == NULL) break; \
      node = next; \
    } \
    curr = NULL; \
  } \
  static void typename##_iterate(typename##Node* curr, void (*callback)(type)) { \
    typename##Node* node = curr; \
    for (;;) { \
      callback(node->value);\
      if (node->next == NULL) break; \
      node = node->next; \
    } \
  } \
  static void typename##_push_front(typename##Node **curr, type new) { \
    typename##Node* next = *curr; \
    *curr = typename##_new(new); \
    (*curr)->next = next; \
  } \
  static void typename##_push_back(typename##Node* curr, type new) { \
    typename##Node* node = curr; \
    for (;;) { \
      if (node->next == NULL) break; \
      node = node->next; \
    } \
    node->next = typename##_new(new); \
  } \
  static type typename##_pop_front(typename##Node **curr) { \
    typename##Node* node = *curr; \
    *curr = node->next; \
    type value = node->value; \
    free(node); \
    return value; \
  } \
  static type typename##_pop_back(typename##Node *curr) { \
    typename##Node* node = curr; \
    for (;;) { \
      if (node->next->next == NULL) break; \
      node = node->next; \
    } \
    type value = node->next->value; \
    free(node->next); \
    node->next = NULL; \
    return value; \
  } \
  static void typename##_remove(typename##Node *curr, type val) { \
    typename##Node* prev = NULL; \
    typename##Node* node = curr; \
    while (node->value != val) { \
      node = node->next; \
      prev = node; \
    } \
    prev->next = node->next; \
    free(node); \
  }
