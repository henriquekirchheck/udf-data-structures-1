add_library(ProductArray)
target_sources(ProductArray
  PRIVATE src/product_array.c
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS include
    FILES
      include/product_array.h
)
