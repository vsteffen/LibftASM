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
#include <ctype.h>

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

void	reset_str(char **str1, char **str2)
{
	free(*str1);
	free(*str2);
	*str1 = strdup("Hello world!3");
	*str2 = strdup("Hello world!4");
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

	char *str1 = strdup("Hello world!1");
	char *str2 = strdup("Hello world!2");
	printf("str1 and str2 equals to \"Hello world!X\"\n");
	memset(str1, 42, 5);
	ft_memset(str2, 42, 5);
	arrow_g();printf("   memset(str1, 42, 5) -> str1 = [%s]\n", str1);
	arrow_y();printf("ft_memset(str2, 42, 5) -> str2 = [%s]\n", str2);
	reset_str(&str1, &str2);
	memset(str1, 64, 5);
	ft_memset(str2, 64, 5);
	arrow_g();printf("   memset(str1, 64, 5) -> str1 = [%s]\n", str1);
	arrow_y();printf("ft_memset(str2, 64, 5) -> str2 = [%s]\n", str2);

	puts("═══════════════════════════════════════════════");

	memcpy(str1, "Allow", 5);
	ft_memcpy(str2, "Allow", 5);
	arrow_g();printf("   memcpy(str1, \"Allow\", 5) -> str1 = [%s]\n", str1);
	arrow_y();printf("ft_memcpy(str2, \"Allow\", 5) -> str2 = [%s]\n", str2);

	puts("═══════════════════════════════════════════════");

	arrow_g();printf("   strdup(\"Hello Marvin\") -> str1 = [%s]\n", (str1 =    strdup("Hello Marvin")));
	arrow_y();printf("ft_strdup(\"Hello Marvin\") -> str2 = [%s]\n", (str2 = ft_strdup("Hello Marvin")));

	puts("═══════════════════════════════════════════════");

	   bzero(str1 + 6, 5);
 	ft_bzero(str2 + 6, 5);
	arrow_g();printf("   bzero(str1 + 6, 5) -> str1 = [%s]\n", str1);
	arrow_y();printf("ft_bzero(str2 + 6, 5) -> str2 = [%s]\n", str2);

	puts("═══════════════════════════════════════════════");

	arrow_g();printf("   strcat(str1, \"Otters\") -> str1 = [%s]\n",    strcat(str1, "Otters"));
	arrow_y();printf("ft_strcat(str2, \"Otters\") -> str2 = [%s]\n", ft_strcat(str2, "Otters"));

	puts("═══════════════════════════════════════════════");

	arrow_g();printf("   isalpha(-42) -> res = [%d]\n",    isalpha(-42));
	arrow_y();printf("ft_isalpha(-42) -> res = [%d]\n", ft_isalpha(-42));
	arrow_g();printf("   isalpha(42) -> res = [%d]\n",    isalpha(42));
	arrow_y();printf("ft_isalpha(42) -> res = [%d]\n", ft_isalpha(42));
	arrow_g();printf("   isalpha(81) -> res = [%d]\n",    isalpha(81));
	arrow_y();printf("ft_isalpha(81) -> res = [%d]\n", ft_isalpha(81));
	arrow_g();printf("   isalpha(93) -> res = [%d]\n",    isalpha(93));
	arrow_y();printf("ft_isalpha(93) -> res = [%d]\n", ft_isalpha(93));
	arrow_g();printf("   isalpha(113) -> res = [%d]\n",    isalpha(113));
	arrow_y();printf("ft_isalpha(113) -> res = [%d]\n", ft_isalpha(113));
	arrow_g();printf("   isalpha(124) -> res = [%d]\n",    isalpha(124));
	arrow_y();printf("ft_isalpha(124) -> res = [%d]\n", ft_isalpha(124));

	puts("═══════════════════════════════════════════════");

	return (0);
}
