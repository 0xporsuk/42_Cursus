#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>


typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

// is

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

//to

int		ft_atoi(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_itoa(int n);

//mem

void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
void	ft_bzero(void *ch, size_t n);
void	*ft_memset(void *dest, int ch, size_t count);


//str

size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

//put

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);









#endif
