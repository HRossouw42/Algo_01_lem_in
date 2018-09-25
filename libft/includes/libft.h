/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 10:08:21 by hrossouw          #+#    #+#             */
/*   Updated: 2018/09/17 17:21:07 by hrossouw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# define BUFF_SIZE 1
# define MAX_FD 1025
# define MAX_BUF 10000000
# define LINE '\n'

typedef struct			s_node
{
	struct s_node		*next;
	int					data;
	struct s_node		*prev;
}						t_node;

typedef struct			s_list
{
	size_t				len;
	struct s_list		*node;
	struct s_list		*prev;
	struct s_node		*data;
	void				*content;
	size_t				content_size;
	struct s_list		*next;
	t_node				*head;
	t_node				*tail;
}						t_list;

void					*ft_memset(void *b, int c, size_t len);
void					ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c, \
	size_t n);
void					*ft_memmove(void *dst, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memrchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t n);
char					*ft_strcat(char *dst, const char *src);
char					*ft_strncat(char *dst, const char *src, size_t n);
size_t					ft_strlcat(char *dst, const char *src, size_t n);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
char					*ft_strstr(const char *big, const char *little);
char					*ft_strnstr(const char *big, const char *little, \
	size_t n);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_atoi(const char *s);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
char					ft_isspace(int i);
int						ft_toupper(int c);
int						ft_tolower(int c);
int						ft_get_next_line(int const fd, char **line);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s, \
	char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start, \
	size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
long long				ft_atol(const char *str);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					*ft_memrcpy(void *dst, const void *src, size_t n);
size_t					ft_iterative_power(size_t base, size_t exponent);
int						ft_amount_of_num(int num);
int						ft_amount_of_words(char const *s, char c);
size_t					ft_min(size_t a, size_t b);
void					*ft_memrchrn(const void *s, int c, size_t n);
void					ft_lstadd(t_list **head, t_list *new);
char					*ft_strndup(const char *s1, size_t n);
char					*ft_strnjoin(const char *s1, const char *s2, \
	size_t len);
void					ft_exit_error_malloc(void);
void					ft_freezero(void *mem, size_t size);
char					*ft_strmove(char *dest, char **src);
size_t					ft_strlchr(char *str, char c);
t_list					*ft_lstnew(const void *content, size_t content_size);
t_list					*ft_lst_new(void);
t_list					*ft_lst_append(t_list *lst, int data);
t_list					*ft_lst_prefix(t_list *lst, int value);
t_list					*ft_lst_del(t_list *lst, t_node *node);
size_t					ft_lst_len(t_list *begin_list);
#endif
