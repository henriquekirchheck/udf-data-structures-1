add_library(LinkedList)
target_sources(LinkedList
  PRIVATE src/linked_list.c
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/linked_list.h
)
