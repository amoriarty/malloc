//
// Created by Alexandre LEGENT on 31/05/2016.
//

#ifndef MALLOC_H
# define MALLOC_H
# include "libft.h"
# include <sys/mman.h>
# include <sys/resource.h>

/*
** DEFINES
*/

# define TINY_SIZE (128)
# define SMALL_SIZE (1024)

# define PRELOAD_ITERATE (100)
# define VIRTUAL_HEAP(S) (page_align(HEAP_SIZE + PRELOAD_ITERATE * (BLOCK_SIZE + S)))
# define LARGE_HEAP(S) (page_align(HEAP_SIZE + BLOCK_SIZE + S))
# define PRELOAD_TINY (VIRTUAL_HEAP(TINY_SIZE))
# define PRELOAD_SMALL (VIRTUAL_HEAP(SMALL_SIZE))

# define TINY ('t')
# define SMALL ('s')
# define LARGE ('l')

# define PTR_SIZE (sizeof(void *))
# define HEAP_SIZE (sizeof(t_heap))
# define BLOCK_SIZE (sizeof(t_block))

# define PROT_CONF (PROT_READ | PROT_WRITE)
# define FLAG_CONF (MAP_ANON | MAP_PRIVATE)

/*
** TYPEDEF
*/

typedef char 					t_bool;
typedef char 					t_type;
typedef struct s_heap			t_heap;
typedef struct s_block			t_block;

/*
** STRUCTURE
*/

struct 							s_heap
{
	t_type 						type;
	t_bool						lock;
	t_block						*block;
	t_heap						*prev;
	t_heap						*next;
};

struct 							s_block
{
	t_bool						free;
	size_t 						size;
	void						*ptr;
	t_block						*prev;
	t_block						*next;
};

/*
** BASE FUNCTIONS
*/

void							*malloc(size_t size);
void							free(void *ptr);
void							*realloc(void *ptr, size_t size);
void							show_alloc_mem(void);

/*
** ALIGNERS
*/

size_t 							page_align(size_t size);
size_t 							ptr_align(size_t size);

/*
** ALLOCATING
*/

t_block							*new_block(t_block *new, size_t size, t_bool free);
t_heap							*new_heap(t_heap *new, t_bool lock, size_t size, t_type type);
void 							*new_alloc(size_t size, t_type type);
void							split_block(t_block *block, size_t size);

/*
** CHECKER
*/

void							check_free_block(t_block *block);
void							check_free_heap(t_heap *heap);

/*
** LISTING
*/

void 							push_block(t_block *block, t_block *new);
void							push_heap(t_heap *heap, t_heap *new);
t_heap							*find_by_type(t_type type);
t_block							*find_free(t_type type, size_t size);
t_heap							*find_last_heap(void);
t_block							*find_by_ptr(void *ptr);
void							delete_block(t_block *block);
void							delete_heap(t_heap *heap);

/*
** TOOLS
*/

t_heap							*singleton(void);
void							*ft_malloc(size_t size);
void							putnbr(int n);
size_t							get_preload(size_t size);
void							print_addr(void *ptr);

#endif
