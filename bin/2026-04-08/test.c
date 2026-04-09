#include <linked_list.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

DEF_LINKED_LIST(IntList, int)

static void print_list(int val) {
  printf("%d", val);
}

int main(void) {
  IntListNode* list = IntList_new(0);

  for (int i = 1; i < 16; i++) IntList_push_back(list, i);
  for (size_t _ = 0; _ < 5; _++) {
    int val = IntList_pop_front(&list);
    printf("%d removed\n", val);
  };
  IntList_iterate(list, &print_list);

  IntList_destroy(list);
  return 0;
}
