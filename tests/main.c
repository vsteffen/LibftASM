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
#include <fcntl.h>

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
	setvbuf(stdout, NULL, _IONBF, 0);
	puts("════════════════════════════════════════════════════════════════");

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

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   strlen(\"Hello world!\") -> length = [%lu]\n", strlen("Hello world!"));
	arrow_y();printf("ft_strlen(\"Hello world!\") -> length = [%lu]\n", ft_strlen("Hello world!"));
	arrow_g();printf("   strlen(\"\") -> length = [%lu]\n", strlen(""));
	arrow_y();printf("ft_strlen(\"\") -> length = [%lu]\n", ft_strlen(""));

	puts("════════════════════════════════════════════════════════════════");

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

	puts("════════════════════════════════════════════════════════════════");

	memcpy(str1, "Allow", 5);
	ft_memcpy(str2, "Allow", 5);
	arrow_g();printf("   memcpy(str1, \"Allow\", 5) -> str1 = [%s]\n", str1);
	arrow_y();printf("ft_memcpy(str2, \"Allow\", 5) -> str2 = [%s]\n", str2);

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   strdup(\"Hello Marvin\") -> str1 = [%s]\n", (str1 =    strdup("Hello Marvin")));
	arrow_y();printf("ft_strdup(\"Hello Marvin\") -> str2 = [%s]\n", (str2 = ft_strdup("Hello Marvin")));
	arrow_g();printf("   strdup(\"Hello Marvin\") -> str1 = [%s]\n",    strdup("Hello Marvin"));
	arrow_y();printf("ft_strdup(\"Hello Marvin\") -> str2 = [%s]\n", ft_strdup("Hello Marvin"));

	puts("════════════════════════════════════════════════════════════════");

	   bzero(str1 + 6, 5);
 	ft_bzero(str2 + 6, 5);
	arrow_g();printf("   bzero(str1 + 6, 5) -> str1 = [%s]\n", str1);
	arrow_y();printf("ft_bzero(str2 + 6, 5) -> str2 = [%s]\n", str2);

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   strcat(str1, \"Otters\") -> str1 = [%s]\n",    strcat(str1, "Otters"));
	arrow_y();printf("ft_strcat(str2, \"Otters\") -> str2 = [%s]\n", ft_strcat(str2, "Otters"));

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   isalpha(42) [*] -> res = [%d]\n",    isalpha(42));
	arrow_y();printf("ft_isalpha(42) [*] -> res = [%d]\n", ft_isalpha(42));
	arrow_g();printf("   isalpha(52) [4] -> res = [%d]\n",    isalpha(52));
	arrow_y();printf("ft_isalpha(52) [4] -> res = [%d]\n", ft_isalpha(52));
	arrow_g();printf("   isalpha(70) [F] -> res = [%d]\n",    isalpha(70));
	arrow_y();printf("ft_isalpha(70) [F] -> res = [%d]\n", ft_isalpha(70));
	arrow_g();printf("   isalpha(94) [^] -> res = [%d]\n",    isalpha(94));
	arrow_y();printf("ft_isalpha(94) [^] -> res = [%d]\n", ft_isalpha(94));
	arrow_g();printf("   isalpha(116) [t] -> res = [%d]\n",    isalpha(116));
	arrow_y();printf("ft_isalpha(116) [t] -> res = [%d]\n", ft_isalpha(116));
	arrow_g();printf("   isalpha(124) [|] -> res = [%d]\n",    isalpha(124));
	arrow_y();printf("ft_isalpha(124) [|] -> res = [%d]\n", ft_isalpha(124));

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   isalnum(42) [*] -> res = [%d]\n",    isalnum(42));
	arrow_y();printf("ft_isalnum(42) [*] -> res = [%d]\n", ft_isalnum(42));
	arrow_g();printf("   isalnum(52) [4] -> res = [%d]\n",    isalnum(52));
	arrow_y();printf("ft_isalnum(52) [4] -> res = [%d]\n", ft_isalnum(52));
	arrow_g();printf("   isalnum(70) [F] -> res = [%d]\n",    isalnum(70));
	arrow_y();printf("ft_isalnum(70) [F] -> res = [%d]\n", ft_isalnum(70));
	arrow_g();printf("   isalnum(94) [^] -> res = [%d]\n",    isalnum(94));
	arrow_y();printf("ft_isalnum(94) [^] -> res = [%d]\n", ft_isalnum(94));
	arrow_g();printf("   isalnum(116) [t] -> res = [%d]\n",    isalnum(116));
	arrow_y();printf("ft_isalnum(116) [t] -> res = [%d]\n", ft_isalnum(116));
	arrow_g();printf("   isalnum(124) [|] -> res = [%d]\n",    isalnum(124));
	arrow_y();printf("ft_isalnum(124) [|] -> res = [%d]\n", ft_isalnum(124));

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   isdigit(42) [*] -> res = [%d]\n",    isdigit(42));
	arrow_y();printf("ft_isdigit(42) [*] -> res = [%d]\n", ft_isdigit(42));
	arrow_g();printf("   isdigit(52) [4] -> res = [%d]\n",    isdigit(52));
	arrow_y();printf("ft_isdigit(52) [4] -> res = [%d]\n", ft_isdigit(52));
	arrow_g();printf("   isdigit(70) [F] -> res = [%d]\n",    isdigit(70));
	arrow_y();printf("ft_isdigit(70) [F] -> res = [%d]\n", ft_isdigit(70));
	arrow_g();printf("   isdigit(94) [^] -> res = [%d]\n",    isdigit(94));
	arrow_y();printf("ft_isdigit(94) [^] -> res = [%d]\n", ft_isdigit(94));
	arrow_g();printf("   isdigit(116) [t] -> res = [%d]\n",    isdigit(116));
	arrow_y();printf("ft_isdigit(116) [t] -> res = [%d]\n", ft_isdigit(116));
	arrow_g();printf("   isdigit(124) [|] -> res = [%d]\n",    isdigit(124));
	arrow_y();printf("ft_isdigit(124) [|] -> res = [%d]\n", ft_isdigit(124));

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   isascii(42) [*] -> res = [%d]\n",    isascii(42));
	arrow_y();printf("ft_isascii(42) [*] -> res = [%d]\n", ft_isascii(42));
	arrow_g();printf("   isascii(52) [4] -> res = [%d]\n",    isascii(52));
	arrow_y();printf("ft_isascii(52) [4] -> res = [%d]\n", ft_isascii(52));
	arrow_g();printf("   isascii(70) [F] -> res = [%d]\n",    isascii(70));
	arrow_y();printf("ft_isascii(70) [F] -> res = [%d]\n", ft_isascii(70));
	arrow_g();printf("   isascii(94) [^] -> res = [%d]\n",    isascii(94));
	arrow_y();printf("ft_isascii(94) [^] -> res = [%d]\n", ft_isascii(94));
	arrow_g();printf("   isascii(116) [t] -> res = [%d]\n",    isascii(116));
	arrow_y();printf("ft_isascii(116) [t] -> res = [%d]\n", ft_isascii(116));
	arrow_g();printf("   isascii(124) [|] -> res = [%d]\n",    isascii(124));
	arrow_y();printf("ft_isascii(124) [|] -> res = [%d]\n", ft_isascii(124));
	arrow_g();printf("   isascii(142) [∅] -> res = [%d]\n",    isascii(142));
	arrow_y();printf("ft_isascii(142) [∅] -> res = [%d]\n", ft_isascii(142));

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   toupper(42) [*] -> res = [%d]\n",    toupper(42));
	arrow_y();printf("ft_toupper(42) [*] -> res = [%d]\n", ft_toupper(42));
	arrow_g();printf("   toupper(52) [4] -> res = [%d]\n",    toupper(52));
	arrow_y();printf("ft_toupper(52) [4] -> res = [%d]\n", ft_toupper(52));
	arrow_g();printf("   toupper(70) [F] -> res = [%d]\n",    toupper(70));
	arrow_y();printf("ft_toupper(70) [F] -> res = [%d]\n", ft_toupper(70));
	arrow_g();printf("   toupper(94) [^] -> res = [%d]\n",    toupper(94));
	arrow_y();printf("ft_toupper(94) [^] -> res = [%d]\n", ft_toupper(94));
	arrow_g();printf("   toupper(116) [t] -> res = [%d]\n",    toupper(116));
	arrow_y();printf("ft_toupper(116) [t] -> res = [%d]\n", ft_toupper(116));
	arrow_g();printf("   toupper(124) [|] -> res = [%d]\n",    toupper(124));
	arrow_y();printf("ft_toupper(124) [|] -> res = [%d]\n", ft_toupper(124));
	arrow_g();printf("   toupper(142) [∅] -> res = [%d]\n",    toupper(142));
	arrow_y();printf("ft_toupper(142) [∅] -> res = [%d]\n", ft_toupper(142));

	puts("════════════════════════════════════════════════════════════════");

	arrow_g();printf("   tolower(42) [*] -> res = [%d]\n",    tolower(42));
	arrow_y();printf("ft_tolower(42) [*] -> res = [%d]\n", ft_tolower(42));
	arrow_g();printf("   tolower(52) [4] -> res = [%d]\n",    tolower(52));
	arrow_y();printf("ft_tolower(52) [4] -> res = [%d]\n", ft_tolower(52));
	arrow_g();printf("   tolower(70) [F] -> res = [%d]\n",    tolower(70));
	arrow_y();printf("ft_tolower(70) [F] -> res = [%d]\n", ft_tolower(70));
	arrow_g();printf("   tolower(94) [^] -> res = [%d]\n",    tolower(94));
	arrow_y();printf("ft_tolower(94) [^] -> res = [%d]\n", ft_tolower(94));
	arrow_g();printf("   tolower(116) [t] -> res = [%d]\n",    tolower(116));
	arrow_y();printf("ft_tolower(116) [t] -> res = [%d]\n", ft_tolower(116));
	arrow_g();printf("   tolower(124) [|] -> res = [%d]\n",    tolower(124));
	arrow_y();printf("ft_tolower(124) [|] -> res = [%d]\n", ft_tolower(124));
	arrow_g();printf("   tolower(142) [∅] -> res = [%d]\n",    tolower(142));
	arrow_y();printf("ft_tolower(142) [∅] -> res = [%d]\n", ft_tolower(142));

	puts("════════════════════════════════════════════════════════════════");

	int fd = open("srcs/ft_cat.s", O_RDONLY);
	arrow_y();printf("ft_cat(fd) -> [");
	ft_cat(fd);
	printf("]\n");

	puts("════════════════════════════════════════════════════════════════");

	printf("\n\tBONUS PART\n\n");

	puts("════════════════════════════════════════════════════════════════");

	arrow_y();printf("ft_putchar('4') -> res = [");ft_putchar('4');printf("]\n");
	printf("\n");
	arrow_y();printf("ft_putstr(\"Born and raise in 42's school\") -> res = [");ft_putstr("Born and raise in 42's school");printf("]\n");
	arrow_y();printf("ft_putstr(\"\") -> res = [");ft_putstr("");printf("]\n");
	arrow_y();printf("ft_putstr(NULL) -> res = [");ft_putstr(NULL);printf("]\n");
	printf("\n");
	arrow_y();printf("ft_putnbr(42) -> res = [");ft_putnbr(42);printf("]\n");
	arrow_y();printf("ft_putnbr(42) -> res = [");ft_putnbr(-42);printf("]\n");
	arrow_y();printf("ft_putnbr(42) -> res = [");ft_putnbr(0);printf("]\n");
	arrow_y();printf("ft_putnbr(42) -> res = [");ft_putnbr(-9223372036854775807);printf("]\n");
	arrow_y();printf("ft_putnbr(42) -> res = [");ft_putnbr(9223372036854775807);printf("]\n");
	printf("\n");
	arrow_g();printf("   strcmp(\"Marvin\", \"Marvel\") -> res = [%d]\n",    strcmp("Marvin", "Marvel"));
	arrow_y();printf("ft_strcmp(\"Marvin\", \"Marvel\") -> res = [%d]\n", ft_strcmp("Marvin", "Marvel"));
	arrow_g();printf("   strcmp(\"42\", \"4\") -> res = [%d]\n",    strcmp("42", "4"));
	arrow_y();printf("ft_strcmp(\"42\", \"4\") -> res = [%d]\n", ft_strcmp("42", "4"));
	arrow_g();printf("   strcmp(\"42\", \"\") -> res = [%d]\n",    strcmp("42", ""));
	arrow_y();printf("ft_strcmp(\"42\", \"\") -> res = [%d]\n", ft_strcmp("42", ""));
	arrow_g();printf("   strcmp(\"21 + 21\", \"21 + \\\") -> res = [%d]\n",    strcmp("21 + 21", "21 + \\"));
	arrow_y();printf("ft_strcmp(\"21 + 21\", \"21 + \\\") -> res = [%d]\n", ft_strcmp("21 + 21", "21 + \\"));
	return (0);
}
