CMAKE_MINIMUM_REQUIRED(VERSION 3.3)
PROJECT(malloc)

SET(CMAKE_C_COMPILER "/usr/bin/clang")
SET(CMAKE_C_FLAGS "-Wall -Wextra -Werror")

SET(LIB_FILES
		sources/malloc.c
		sources/tools/singleton.c
		sources/tools/ft_malloc.c
		sources/aligners/page_align.c
		sources/aligners/ptr_align.c
		sources/listing/push_block.c
		sources/listing/push_heap.c
		sources/allocating/new_block.c
		sources/allocating/new_heap.c
		sources/allocating/new_alloc.c
		sources/listing/find_by_type.c
		sources/listing/find_free.c
		sources/tools/putnbr.c
		sources/allocating/split_block.c
		sources/tools/get_preload.c
		sources/listing/find_last_heap.c
		sources/free.c
		sources/listing/delete_block.c
		sources/listing/delete_heap.c
		sources/realloc.c
		sources/listing/find_by_ptr.c
		sources/checker/check_free_block.c
		sources/checker/check_free_heap.c
		sources/show_alloc_mem.c
		sources/tools/print_addr.c)

INCLUDE_DIRECTORIES(includes)
INCLUDE_DIRECTORIES(libft)

ADD_CUSTOM_COMMAND(
		OUTPUT ${PROJECT_SOURCE_DIR}/libft/libft.a
		COMMAND make
		WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/libft
)

ADD_CUSTOM_TARGET(
		libft
		DEPENDS ${PROJECT_SOURCE_DIR}/libft/libft.a
)

ADD_EXECUTABLE(main tests/main.c)
ADD_EXECUTABLE(unit tests/main_tests.c)
ADD_EXECUTABLE(show tests/show_test.c)
ADD_EXECUTABLE(test3 tests/test3.c)
ADD_EXECUTABLE(test1 tests/test1.c)

ADD_LIBRARY(malloc SHARED ${LIB_FILES})

ADD_DEPENDENCIES(malloc libft)

TARGET_LINK_LIBRARIES(malloc ${PROJECT_SOURCE_DIR}/libft/libft.a)
TARGET_LINK_LIBRARIES(main malloc)
TARGET_LINK_LIBRARIES(show malloc)
TARGET_LINK_LIBRARIES(test3 malloc)
TARGET_LINK_LIBRARIES(test1 malloc)
