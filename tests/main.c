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
#include <unistd.h>
#include <string.h>

#define ARROW_GREEN "\033[32m-->\033[0m "
#define ARROW_YELLOW "\033[33m-->\033[0m "

void arrow_g(void)
{
	write(1, ARROW_GREEN, strlen(ARROW_GREEN));
}

void arrow_y(void)
{
	write(1, ARROW_YELLOW, strlen(ARROW_YELLOW));
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

	return (0);
}
