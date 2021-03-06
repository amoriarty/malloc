/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlancar <dlancar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 15:55:54 by dlancar           #+#    #+#             */
/*   Updated: 2016/06/23 12:08:39 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <errno.h>
#include <stdio.h>
#include <strings.h>

#define RED        "\x1B[31m"
#define GREEN      "\x1B[32m"
#define YELLOW     "\x1B[33m"
#define RESET      "\033[0m"
#define CURSOR_UP  "\033[1A"
#define CLEAR_LINE "\033[K"

#define TRUE  1
#define FALSE 0
#define t_bool int

#define SSWAIT  (usleep(500))
#define SWAIT   (usleep(2500))
#define WAIT    (usleep(5000))
#define UP      (printf(CURSOR_UP))

#define MEDIUM_SIZE 4096

#define MRESET g_header.tiny = NULL; g_header.small = NULL;g_header.large = NULL

typedef struct 	s_header
{
	void		*tiny;
	void		*small;
	void		*large;
}				t_header;

t_header		g_header;

static t_bool	stress_test_malloc_small(void)
{
	int		*mem[201];

	printf("\nStress tests: malloc: small\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		mem[i] = malloc(sizeof(int));
		*mem[i] = i;
		printf("Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		if (*mem[i] != i)
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "]\n");
			return FALSE;
		}
		free(mem[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	return TRUE;
}


static t_bool	stress_test_malloc_medium(void)
{
	int		*mem[201];

	printf("\nStress tests: malloc: medium\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		mem[i] = malloc(1024);
		bzero(mem[i], 1024);
		printf("Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		SWAIT;
	}
	UP;
	printf(CLEAR_LINE "Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		for (unsigned long j = 0; j < 1024 / sizeof(int); j++)
		{
			if (mem[i][j])
			{
				UP;
				printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "]\n");
				return FALSE;
			}
		}
		free(mem[i]);
		SWAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	return TRUE;
}

static t_bool	stress_test_malloc_large(void)
{
	int		*mem[201];

	printf("\nStress tests: malloc: large\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		mem[i] = malloc(5000);

		printf("Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		SWAIT;
	}
	UP;
	printf(CLEAR_LINE "Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		bzero(mem[i], 5000);
		printf("Checking memory:\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		for (unsigned long j = 0; j < 5000 / sizeof(int); j++)
		{
			if (mem[i][j])
			{
				UP;
				printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "]\n");
				return FALSE;
			}
		}
		free(mem[i]);
		SWAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	return TRUE;
}

static t_bool	stress_test_free_small(void)
{
	int		*mem[201];

	printf("\nStress tests: free: small\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		mem[i] = malloc(sizeof(int));
		printf("Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Freeing:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		free(mem[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Freeing memory:\t\t[" GREEN "OK" RESET "]\n");
	return TRUE;
}

static t_bool	stress_test_free_medium(void)
{
	int		*mem[201];

	printf("\nStress tests: free: medium:\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		mem[i] = malloc(MEDIUM_SIZE / 99);
		printf("Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Freeing:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		free(mem[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Freeing memory:\t\t[" GREEN "OK" RESET "]\n");
	return TRUE;
}

static t_bool	stress_test_free_large(void)
{
	int		*mem[201];

	printf("\nStress tests: free: large:\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		mem[i] = malloc(7007);
		printf("Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Freeing:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		free(mem[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Freeing memory:\t\t[" GREEN "OK" RESET "]\n");
	return TRUE;
}

static t_bool	stress_test_realloc_smaller(void)
{
	int	*p[201];

	printf("\nStress tests: realloc: smaller:\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("(Re)Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		p[i] = malloc(sizeof(int) * 2);
		p[i][0] = 32;
		//p[i] = realloc(p[i], sizeof(int));
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "(Re)Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		if (!p[i] || p[i][0] != 32)
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "] i = %d\n", i);
			return (FALSE);
		}
		free(p[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

static t_bool	stress_test_realloc_same(void)
{
	int	*p[201];

	printf("\nStress tests: realloc: same size:\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("(Re)Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		p[i] = malloc(sizeof(int));
		p[i][0] = 32;
		p[i] = realloc(p[i], sizeof(int));
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "(Re)Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		if (!p[i] || p[i][0] != 32)
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "] i = %d\n", i);
			return (FALSE);
		}
		free(p[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

static t_bool	stress_test_realloc_larger(void)
{
	int	*p[201];

	printf("\nStress tests: realloc: larger:\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("(Re)Allocating:\t\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		p[i] = malloc(sizeof(int));
		p[i][0] = 32;
		p[i] = realloc(p[i], sizeof(int) * 2);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "(Re)Allocating:\t\t[" GREEN "OK" RESET "]\n\n");
	for (int i = 0; i < 201; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/201" RESET "]\n", i + 1);
		if (!p[i] || p[i][0] != 32)
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "] i = %d\n", i);
			return (FALSE);
		}
		free(p[i]);
		WAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

static t_bool	basic_test_malloc_small(void)
{
	int	*p;

	printf("Basic tests: malloc: small:\n");
	printf("Allocating:\t\t");
	p = malloc(sizeof(int));
	printf("[%s" RESET "]\n", (p ? GREEN "OK" : RED "FAIL"));
	printf("Checking memory:\t");
	*p = 418418;
	printf("[%s" RESET "]\n", (*p == 418418 ? GREEN "OK" : RED "FAIL"));

	free(p);
	return (TRUE);
}

static t_bool	basic_test_malloc_medium(void)
{
	int	*p;

	printf("\nBasic tests: malloc: medium:\n");
	printf("Allocating:\t\t");
	p = malloc(MEDIUM_SIZE);
	printf("[%s" RESET "]\n\n", (p ? GREEN "OK" : RED "FAIL"));
	bzero(p, MEDIUM_SIZE);
	for (unsigned long i = 0; i < MEDIUM_SIZE / sizeof(int); i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%lu/1024" RESET "]\n", i + 1);
		if (p[i])
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "]\n");
			return (FALSE);
		}
		SWAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	free(p);
	return (TRUE);
}

static t_bool	basic_test_malloc_large(void)
{
	int	*p;

	printf("\nBasic tests: malloc: large:\n");
	printf("Allocating:\t\t");
	p = malloc(MEDIUM_SIZE * sizeof(int));
	printf("[%s" RESET "]\n\n", (p ? GREEN "OK" : RED "FAIL"));
	bzero(p, MEDIUM_SIZE * sizeof(int));
	for (int i = 0; i < MEDIUM_SIZE; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/4096" RESET "]\n", i + 1);
		if (p[i])
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "]\n");
			return (FALSE);
		}
		SSWAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	free(p);
	return (TRUE);
}

static t_bool	basic_test_realloc_smaller(void)
{
	int	*p;

	printf("\nBasic tests: realloc: smaller:\n");
	printf("Allocating:\t\t");
	p = malloc(sizeof(int) * 2);
	*p = 32;
	p = realloc(p, sizeof(int));
	printf("[%s" RESET "]\n", (p ? GREEN "OK" : RED "FAIL"));
	printf("Checking memory:\t[%s" RESET "]\n", p[0] == 32 ? GREEN "OK" : RED "FAIL");
	free(p);
	return (TRUE);
}

static t_bool	basic_test_realloc_same(void)
{
	int	*p;

	printf("\nBasic tests: realloc: same size:\n");
	printf("Allocating:\t\t");
	p = malloc(sizeof(int));
	*p = 32;
	p = realloc(p, sizeof(int));
	printf("[%s" RESET "]\n", (p ? GREEN "OK" : RED "FAIL"));
	printf("Checking memory:\t[%s" RESET "]\n", p[0] == 32 ? GREEN "OK" : RED "FAIL");
	free(p);
	return (TRUE);
}

static t_bool	basic_test_realloc_larger(void)
{
	int	*p;

	printf("\nBasic tests: realloc: larger:\n");
	printf("Allocating:\t\t");
	p = malloc(sizeof(int));
	*p = 32;
	p = realloc(p, sizeof(int) * 2);
	printf("[%s" RESET "]\n", (p ? GREEN "OK" : RED "FAIL"));
	printf("Checking memory:\t[%s" RESET "]\n", p[0] == 32 ? GREEN "OK" : RED "FAIL");
	free(p);
	return (TRUE);
}

static t_bool	basic_test_realloc_overflow(void)
{
	int	*p;

	printf("\nBasic tests: realloc: overflow:\n");
	printf("Allocating:\t\t");
	p = malloc(sizeof(int) * 100);
	for (int i = 0; i < 10; i++)
		p[i] = i;
	if (!(p = realloc(p, sizeof(int) * 4000)))
		return (FALSE);
	printf("[%s" RESET "]\n\n", (p ? GREEN "OK" : RED "FAIL"));
	for (int i = 0; i < 10; i++)
	{
		UP;
		printf("Checking memory:\t[" YELLOW "%d/100" RESET "]\n", i + 1);
		if (p[i] != i)
		{
			UP;
			printf(CLEAR_LINE "Checking memory:\t[" RED "FAIL" RESET "] i = %d\n", i);
			return (FALSE);
		}
		WAIT;SWAIT;
	}
	UP;
	printf(CLEAR_LINE "Checking memory:\t[" GREEN "OK" RESET "]\n");
	free(p);
	return (TRUE);
}

static t_bool	basic_test_free_small(void)
{
	int	*p;

	printf("\nBasic tests: free: small:\n");
	p = malloc(sizeof(int));
	printf("Freeing memory:\t\t");
	errno = 0;
	free(p);
	if (errno)
	{
		printf("[" RED "FAIL" RESET "]\n");
		return (FALSE);
	}
	printf("[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

static t_bool	basic_test_free_medium(void)
{
	int	*p;

	printf("\nBasic tests: free: medium:\n");
	p = malloc(sizeof(int) * 100);
	printf("Freeing memory:\t\t");
	errno = 0;
	free(p);
	if (errno)
	{
		printf("[" RED "FAIL" RESET "]\n");
		return (FALSE);
	}
	printf("[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

static t_bool	basic_test_free_large(void)
{
	int	*p;

	printf("\nBasic tests: free: large:\n");
	p = malloc(sizeof(int) * 100000);
	printf("Freeing memory:\t\t");
	errno = 0;
	free(p);
	if (errno)
	{
		printf("[" RED "FAIL" RESET "]\n");
		return (FALSE);
	}
	printf("[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

static t_bool	advanced_test_malloc(void)
{
	void	*p;

	printf("\nAdvanced tests: malloc:\n");
	printf("malloc(0):\t\t");
	p = malloc(0);
	if (!p)
		printf("[" GREEN "OK" RESET "]\n");
	else
	{
		free(p);
		if (errno == EFAULT)
			printf("[" RED "FAIL" RESET "]\n");
		else
			printf("[" GREEN "OK" RESET "]\n");
	}
	/*printf("malloc(toomuch):\t");
	p = malloc(-1);
	if (p)
		printf("[" GREEN "OK" RESET "]\n");
	else
		printf("[" RED "FAIL" RESET "]\n");*/
	return (TRUE);
}

static t_bool	advanced_test_realloc(void)
{
	int		*p;

	printf("\nAdvanced tests: realloc:\n");
	printf("realloc(NULL, %d):\t", (int)sizeof(int));
	p = realloc(NULL, sizeof(int));
	if (p)
		printf("[" GREEN "OK" RESET "]\n");
	else
		printf("[" RED "FAIL" RESET "]\n");
	printf("realloc(pointer, 0):\t");
	p = malloc(sizeof(int));
	p = realloc(p, 0);
	if ((p && malloc(0)) || (!p && !malloc(0)))
		printf("[" GREEN "OK" RESET "]\n");
	else
		printf("[" RED "FAIL" RESET "]\n");
	printf("realloc(toomuch):\t");
	p = malloc(sizeof(int));
	p = realloc(p, -1);
	if (!p)
		printf("[" GREEN "OK" RESET "]\n");
	else
		printf("[" RED "FAIL" RESET "]\n");
	free(p);
	return (TRUE);
}

static t_bool	advanced_test_free(void)
{

	printf("\nAdvanced tests: free:\n");
	printf("malloc(NULL):\t\t");
	free(NULL);
	if (errno == EFAULT)
		printf("[" RED "FAIL" RESET "]\n");
	else
		printf("[" GREEN "OK" RESET "]\n");
	return (TRUE);
}

int				main(void)
{
	basic_test_malloc_small();
	MRESET;
	basic_test_malloc_medium();
	MRESET;
	basic_test_malloc_large();
	MRESET;
	basic_test_realloc_smaller();
	MRESET;
	basic_test_realloc_same();
	MRESET;
	basic_test_realloc_larger();
	MRESET;
	basic_test_realloc_overflow();
	MRESET;
	basic_test_free_small();
	MRESET;
	basic_test_free_medium();
	MRESET;
	basic_test_free_large();
	MRESET;
	advanced_test_malloc();
	MRESET;
	advanced_test_realloc();
	MRESET;
	advanced_test_free();
	MRESET;
	stress_test_malloc_small();
	MRESET;
	stress_test_malloc_medium();
	MRESET;
	stress_test_malloc_large();
	MRESET;
	stress_test_realloc_smaller();
	MRESET;
	stress_test_realloc_same();
	MRESET;
	stress_test_realloc_larger();
	MRESET;
	stress_test_free_small();
	MRESET;
	stress_test_free_medium();
	MRESET;
	stress_test_free_large();
	MRESET;


	/*
	 * TEST CALLOC
	 */
	void *ptr = calloc(sizeof(int), 8);
	free(ptr);

	ptr = malloc(4);
	ptr = reallocf(ptr, 8);
	free(ptr);


	/*
	printf("\n\n");
	void *p;
	for (int i = 0; i < 100000000; i++)
	{
		UP;
		printf("ULTIMATE\t[" YELLOW "%d/10000000" RESET "]\n", i);
		p = malloc(i % 50000);
	 	free(p);
	}
	UP;
	printf(CLEAR_LINE "ULTIMATE\t[" GREEN "OK" RESET "]\n");
	*/
	return (0);
}
