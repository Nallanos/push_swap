*This project has been created as part of the 42 curriculum by moabdess.*

## Description
Libft is the first project in the 42 curriculum. Its goal is to create a personal library of useful functions that can be reused in future C projects.

## Instructions

In order to compile this project, use the provided `Makefile` :

```bash
make
```
or
```bash
make all
```
creates the `libft.a` static library at the root of the repository.

```bash
make clean
```
deletes all created object files.

```bash
make fclean
```
deletes all created object files as well as the libft.a library.

```bash
make re
```
deletes all created object files and the libft.a library then recompiles the project.

## Description of the library
This library contains a variety of functions that replicate the behaviour of certain libc functions, it also contains additional functions that are not part of the standard library.\
Here are all the functions in this Libft grouped by their purpose.

### Character Check Functions

`int	ft_isalpha(int c);`\
`int	ft_isdigit(int c);`\
`int	ft_isalnum(int c);`\
`int	ft_isascii(int c);`\
`int	ft_isprint(int c);`

### Conversion Functions

`int	ft_toupper(int c);`\
`int	ft_tolower(int c);`

`int	ft_atoi(const char *nptr);`\
`char	*ft_itoa(int n);`

### String Functions

`size_t	ft_strlen(const char *s);`\
`size_t	ft_strlcpy(char *dst, const char *src, size_t size);`\
`size_t	ft_strlcat(char *dst, const char *src, size_t size);`\
`int	ft_strncmp(const char *s1, const char *s2, size_t n);`

`char	*ft_strchr(const char *s, int c);`\
`char	*ft_strrchr(const char *s, int c);`\
`char	*ft_strnstr(const char *big, const char *little, size_t len);`

`char	*ft_substr(char const *s, unsigned int start, size_t len);`\
`char	*ft_strjoin(char const *s1, char const *s2);`\
`char	*ft_strtrim(char const *s1, char const *set);`\
`char	**ft_split(char const *s, char c);`

`char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));`\
`void	ft_striteri(char *s, void (*f)(unsigned int, char *));`

### Memory Functions

`void	ft_bzero(void *s, size_t n);`\
`void	*ft_memset(void *s, int c, size_t n);`\
`void	*ft_memcpy(void *dest, const void *src, size_t n);`\
`void	*ft_memmove(void *dest, const void *src, size_t n);`\
`void	*ft_memchr(const void *s, int c, size_t n);`\
`int	ft_memcmp(const void *s1, const void *s2, size_t n);`

`void	*ft_calloc(size_t nmemb, size_t size);`\
`char	*ft_strdup(const char *s);`

### File Descriptor Output Functions

`void	ft_putchar_fd(char c, int fd);`\
`void	ft_putstr_fd(char *s, int fd);`\
`void	ft_putendl_fd(char *s, int fd);`\
`void	ft_putnbr_fd(int n, int fd);`

### Linked List Functions
```c
typedef struct s_list
{
	void	*content;
	struct s_list	*next;
}	t_list;
```

`t_list	*ft_lstnew(void	*content);`\
`t_list	*ft_lstlast(t_list *lst);`\
`unsigned int	ft_lstsize(t_list *lst);`\
`void	ft_lstadd_front(t_list **lst, t_list *new);`\
`void	ft_lstadd_back(t_list **lst, t_list *new);`\
`void	ft_lstdelone(t_list *lst, void (*del)(void *));`\
`void	ft_lstclear(t_list **lst, void (*del)(void *));`\
`void	ft_lstiter(t_list *lst, void (*f)(void *));`\
`t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));`

## Resources

- Manual pages of the Libc functions
- The 42 Libft subject pdf
- **AI was not used in any part of this project**