/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:18:20 by jle-corr          #+#    #+#             */
/*   Updated: 2021/04/10 12:27:35 by jle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/errno.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# ifndef MAX_FD
#  define MAX_FD 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*
**	memory
*/

void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/*
**	ascii
*/

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

/*
**	string
*/

void		ft_strdel(char **s);
char		*ft_strnew(int size);
void		*ft_freetab(char **tab);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strncpy(char *dst, const char *src, size_t len);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			join_newstr(char **str, const char *src);
int			get_next_line(int fd, char **line);

/*
**	convert
*/

char		*ft_itoa(int n);
char		*ft_utoa(unsigned int n);
char		*ft_utox(unsigned int n);
char		*ft_utobx(unsigned int n);
char		*ft_ltoa(long n);
char		*ft_ultoa(unsigned long int n);
char		*ft_ultox(unsigned long int n);
int			ft_atoi(const char *str);
long long	ft_strtoll(const char *str, char **endptr);
int			ft_strtoimax(const char *str, char **endptr);

/*
**	compute
*/

long		ft_pow(int base, int power);

/*
**	fd write
*/

void		ft_putstr(char *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/*
**	linked lists
*/

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

#endif
