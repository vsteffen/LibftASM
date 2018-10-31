/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfts.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:26:22 by vsteffen          #+#    #+#             */
/*   Updated: 2018/10/31 22:20:19 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTS_H
# define LIBFTS_H

# include <stddef.h>

int			ft_atoi(const char *s);
void		ft_bzero(void *s, size_t n);
int			ft_cat(int fd);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		ft_putchar(char c);
void		ft_putnbr(long long int nb);
void		ft_puts(const char *s);
void		ft_putstr(const char *c);
char		*ft_strcat(char *restrict s1, const char *restrict s2);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char *s);
int			ft_tolower(int c);
int			ft_toupper(int c);

#endif
