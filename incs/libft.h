/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bfranco <bfranco@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 08:11:44 by bfranco       #+#    #+#                 */
/*   Updated: 2023/03/10 15:48:22 by bfranco       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_print
{
	va_list	args;
	int		wdt;
	int		prc;
	int		zero;
	int		pnt;
	int		dash;
	int		len;
	int		sign;
	int		hash;
	int		spc;
	char	type;
}	t_print;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dlist
{
	int				content;
	int				index;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

/*ps*/ /*doubly linked lists*/
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void	ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void	ft_dlstclear(t_dlist **lst);
void	ft_dlstdelone(t_dlist *lst);
void	ft_dlstiter(t_dlist *lst, int (*f)(int));
int		ft_dlstsize(t_dlist *lst);
t_dlist	*ft_dlstmap(t_dlist *lst, int (*f)(int));
t_dlist	*ft_dlstlast(t_dlist *lst);
t_dlist	*ft_dlstfirst(t_dlist *lst);
t_dlist	*ft_dlstnew(int content);

/*bonus*/ /*linked lists*/
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*checks*/
int		ft_isalnum(int n);
int		ft_isalpha(int n);
int		ft_isdigit(int n);
int		ft_isascii(int n);
int		ft_isprint(int n);
int		ft_isspace(int n);
int		ft_isnumber(char *str);

/*conversion*/
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
char	*ft_itoa_hex(unsigned int n, char type);
char	*ft_itoa_uint(unsigned int n);
char	*ft_itoa_ptr(unsigned long int n);
char	*ft_itoa(int n);

/*int*/
int		ft_hexlen(unsigned int nb);
int		ft_uintlen(unsigned int nb);
int		ft_intlen(int nb);

/*string*/
char	**ft_split(const char *str, char sep);
char	*ft_strchr(const char *str, int n);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *str, int n);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*chartostr(int c);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
size_t	ft_arrlen(char **arr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_tolower(int n);
int		ft_toupper(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*memory*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_arr(char **arr);
void	*ft_memchr(const void *p, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*io*/
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *c, int fd);
void	ft_error(char *str, int err);
char	*get_next_line(int fd);
char	*get_next_line_bonus(int fd);
int		ft_printf(const char *format, ...);

/*utils*/ /*helper funcs for other major funcs/projects*/
char	*get_type(t_print *tab);

#endif