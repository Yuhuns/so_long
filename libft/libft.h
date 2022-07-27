/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awallet <awallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:33:17 by awallet           #+#    #+#             */
/*   Updated: 2022/07/26 21:35:27 by awallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

// FT_PRINTF
# define BIG "0123456789ABCDEF"
# define LIT "0123456789abcdef"
# define NUM "0123456789"
# if defined (__APPLE__)
#  define PTR_NULL "0x0"
#  define IS_APPLE 1
# elif __linux__
#  define PTR_NULL "(nil)"
#  define IS_APPLE 0
# endif

// LIBFT
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_atoi(const char *str);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
void	*ft_memset(void *dest, int val, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t len);
void	ft_usleep(unsigned int msecond);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
size_t	ft_strcspn(const char *s, const char *reject);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *src, int c);
char	*ft_strdup(const char *s1);
char	*ft_strnstr(const char	*big, const char *little, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(const char *s1, const char *set);
char	*ft_itoa(int nb);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dest, const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strstr(char *str, char *to_find);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_rev_print(char *str);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// GET_NET_LINE
char	*get_next_line(int fd);
// FT_PRINTF
int		ft_print_putchar_fd(int c, int fd);
int		ft_printf(const char *str, ...);
int		ft_print_putstr_fd(char *s, int fd);
int		ft_print_nbr(int nb, int fd);
int		ft_print_base(unsigned int n, const char *pattern, int base, int fd);
int		ft_print_ptr(unsigned long int n, const char *p, int fd);

#endif
