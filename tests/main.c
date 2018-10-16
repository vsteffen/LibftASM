/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 18:27:30 by vsteffen          #+#    #+#             */
/*   Updated: 2018/09/17 18:42:57 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfts.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define ARROW_GREEN "\033[32m-->\033[0m "
#define ARROW_YELLOW "\033[33m-->\033[0m "

void	arrow_g(void)
{
	write(1, ARROW_GREEN, strlen(ARROW_GREEN));
}

void	arrow_y(void)
{
	write(1, ARROW_YELLOW, strlen(ARROW_YELLOW));
}

void	reset_ptr(void **ptr1, void **ptr2)
{
	free(*ptr1);
	free(*ptr2);
	*ptr1 = strdup("Hello world!3");
	*ptr2 = strdup("Hello world!4");
}

int		main(int ac, char **av)
{
	puts("═══════════════════════════════════════════════");

	arrow_g();puts("puts(\"Hello world!\"):");
	puts("Hello world!");
	arrow_y();puts("ft_puts(\"Hello world!\"):");
	ft_puts("Hello world!");
	arrow_g();puts("puts(\"\"):");
	puts("");
	arrow_y();puts("ft_puts(\"\"):");
	ft_puts("");
	arrow_g();puts("puts(NULL):");
	puts(NULL);
	arrow_y();puts("ft_puts(NULL):");
	ft_puts(NULL);

	puts("═══════════════════════════════════════════════");

	arrow_g();printf("   strlen(\"Hello world!\") -> length = [%lu]\n", strlen("Hello world!"));
	arrow_y();printf("ft_strlen(\"Hello world!\") -> length = [%lu]\n", ft_strlen("Hello world!"));
	arrow_g();printf("   strlen(\"\") -> length = [%lu]\n", strlen(""));
	arrow_y();printf("ft_strlen(\"\") -> length = [%lu]\n", ft_strlen(""));

	puts("═══════════════════════════════════════════════");

	void *ptr1 = strdup("Hello world!1");
	void *ptr2 = strdup("Hello world!2");
	printf("ptr1 and ptr2 equals to \"Hello world!X\"\n");
	memset(ptr1, 42, 5);
	ft_memset(ptr2, 42, 5);
	arrow_g();printf("   memset(ptr1, 42, 5) -> ptr1 = [%s]\n", ptr1);
	arrow_y();printf("ft_memset(ptr2, 42, 5) -> ptr2 = [%s]\n", ptr2);
	reset_ptr(&ptr1, &ptr2);
	memset(ptr1, 64, 5);
	ft_memset(ptr2, 64, 5);
	arrow_g();printf("   memset(ptr1, 64, 5) -> ptr1 = [%s]\n", ptr1);
	arrow_y();printf("ft_memset(ptr2, 64, 5) -> ptr2 = [%s]\n", ptr2);

	puts("═══════════════════════════════════════════════");

	memcpy(ptr1, "Allow", 5);
	ft_memcpy(ptr2, "Allow", 5);
	arrow_g();printf("   memcpy(ptr1, \"Allow\", 5) -> ptr1 = [%s]\n", ptr1);
	arrow_y();printf("ft_memcpy(ptr2, \"Allow\", 5) -> ptr2 = [%s]\n", ptr2);

	puts("═══════════════════════════════════════════════");

	arrow_g();printf("   strdup(\"Hello Marvin\") -> ptr1 = [%s]\n", (ptr1 =    strdup("Hello Marvin")));
	arrow_y();printf("ft_strdup(\"Hello Marvin\") -> ptr2 = [%s]\n", (ptr2 = ft_strdup("Hello Marvin")));

	puts("═══════════════════════════════════════════════");

	return (0);
}
