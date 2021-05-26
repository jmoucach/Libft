# Libft

## What is the use of the libft?

The libft is a library of little usefull functions written in the programming language C. That I am required to use for my projects for the 42 school.

## List of the function in libft

### Libc function remakes:

* ft_memset: Fils the given memory with the given constant byte.
  ``` C
  void *ft_memset(void *s, int c, size_t n);
  ```
* ft_bzero: Fills the given memory with zero valued byte.
  ``` C
  void ft_bzero(void *s, size_t n);
  ```
* ft_memcpy: Copies N bytes of memory from an area to another.
  ```C
  void *ft_memcpy(void *dst, const void *src, size_t n);
  ```
* ft_memccpy: Copies N bytes of memory from an area to another stopping when given character is found.
  ``` C
  void *ft_memccpy(void *dest, const void *src, int c, size_t n);
  ```
* ft_memmove: Copies N bytes of memory form an area to another, the areas may overlapp since the copying is done in a non-destructive manner.
  ``` C
  void *ft_memmove(void *dst, const void *src, size_t len);
  ```
* ft_memchr: Scearches the initial N bytes of the memory for the first instance of a given character.
  ``` C
  void *ft_memchr(const void *s, int c, size_t n);
  ```
* ft_memcmp: Compares memory area.
  ``` C
  int ft_memcmp(const void *s1, const void *s2, size_t n);
  ```
* ft_strlen: Calucates the length of given string.
  ``` C
  size_t ft_strlen(const char *s)
  ```
* ft_strdup: Creates a malloced duplicate of the given string.
  ``` C
  char *ft_strdup(const char *s1);
  ```
* ft_strcpy: Copies the source string to the buffer including the terminating '\0'.
  ``` C
  char *ft_strcpy(char *dest, const char *src);
  ```
* ft_strncpy: Copies at most N bytes of the source string to the buffer; if there is no null bytes among the N first bytes of src, the buffer will not be null-terminated.
  ``` C
  char *ft_strncpy(char *dest, const char *src, size_t n);
  ```
* ft_strcat: Appends the source string to the destination string overwriting the terminating null at the end of the destination.
  ``` C
  char *ft_strcat(char *dest, const char *src);
  ```
* ft_strncat:  Appends at most N bytes from the source string to the destination string overwriting the terminating null at the end of the destination.
  ``` C
  char *ft_strncat(char *dest, const char *src, size_t n);
  ```
* ft_strlcat: Appends the null-terminated source string to the end of the destination.
  ``` C
  size_t strlcat(char *dst, const char *src, size_t size);
  ```
* ft_strchr: Returns a pointer to the first occurence of a given character in the source string.
  ``` C
  char *ft_strchr(const char *s, int c);
  ```
* ft_strrchr: Returns a pointer to the last occurence of a given character in the source string.
  ``` C
  char *ft_strrchr(const char *sd, int c);
  ```
* ft_strstr: Finds the first occurence of the needle substring in the haystack source string.
  ``` C
  char *ft_strstr(const char *haystack, const char *needle);
  ```
* ft_strcmp: Compares two strings s1 and s2; it returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
  ``` C
  int ft_strcmp(const char *s1, const char *s2);
  ```
* ft_strncmp: Compares  at most N byts of the 0two strings s1 and s2; it returns an integer less than, equal to, or greater than zero if s1 is found, respectively, to be less than, to match, or be greater than s2.
  ``` C
  int ft_strncmp(const char *s1, const char *s2, size_t n);
  ```
* ft_atoi: Converts the initial portion of a string to an int.
  ``` C
  int ft_atoi(const char *nptr);
  ```
* ft_isalpha: Checks for an alphabetic character.
  ``` C
  int ft_isalpha(int c);
  ```
* ft_isdigit: Checks for a digit.
  ``` C
  int ft_isdigit(int c);
  ```
* ft_isalnum: Checks for an alphanumeric character.
  ``` C
  int ft_isalnum(int c);
  ```
* ft_isascii: Checks whether the given int corresponds to a 7-bit unsigned char value that fits into the ASCII character set.
  ``` C
  int ft_isascii(int c);
* ft_isprint: Checks for any printable character including space.
  ``` C
  int ft_isprint(int c);
  ```
* ft_toupper: Converts the letter c to upper case if possible.
  ``` C
  int ft_toupper(int c)
  ```
* ft_tolower: Converts the letter c to lower case if possible.
  ``` C
  int ft_toupper(int c)
  ```
## Additionnal useful functions:

* ft_memalloc: Allocates and returns "fresh" memory area, the memory is initialized to 0.
  ``` C
  void *ft_memalloc(size_t size);
  ```
 * ft_memdel: Takes as a parameter the address of a memory area that neeeds to be freed then put the pointer to NULL.
  ``` C
  void ft_memdel(**ap);
  ```
* ft_strnew: Allocates and returns a “fresh” string ending with ’\0’. Each character of the string is initialized at ’\0’. If the allocation fails the function returns NULL.
   ``` C
   char *ft_strnew(size_t size);
   ```
 * ft_strdel: Takes as a parameter the address of a string that needs to be freed then set its pointer to NULL.
  ``` C
  void ft_strdel(char **as);
  ```
 * ft_strclr: Sets every character of the string to value '\0'.
  ``` C
  void ft_strclr(char *s);
  ```
* ft_striter: Applies the function f to each character of the string; Each character is passed by address to f to be modified if necessary.
  ``` C
  void ft_striter(char *s, void (*f)(char *));
  ```
* ft_striteri: Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary.
  ``` C
  void ft_striteri(char *s, void (*f)(unsigned int, char *));
  ```
* ft_strmap: Applies the function f to each character of the string given as argument to create a “fresh” new string resulting from the successive applications of f.
  ``` C
  char * ft_strmap(char const *s, char (*f)(char));
  ```
* ft_strmapi: Applies the function f to each character of the string passed as argument by giving its index as first argument to create a “fresh” new string resulting from the successive applications of f.
  ``` C
  char *ft_strmapi(cont char *s, char (*f)(char));
  ```
* ft_strequ: Lexicographical comparison between s1 and s2. If the 2 strings are identical the function returns 1, or 0 otherwise.
  ``` C
  int ft_strequ(cont char *s1, const char *s2);
  ```
* ft_strnequ:  Lexicographical comparison between s1 and s2 up to n characters or until a ’\0’ is reached. If the 2 strings are identical, the function returns 1, or 0 otherwise.
  ``` C
  int ft_strnequ(const char *s1, const char *s2, size_t n);
  ```
* ft_strsub: Allocates and returns a “fresh” substring from the string given as argument. The substring begins at indexstart and is of size len. If start and len aren’t refering to a valid substring, the behavior is undefined.
  ``` C
  char * ft_strsub(const char *s, unsigned int start, size_t len);
  ```
* ft_strjoin: Allocates and returns a “fresh” string ending with ’\0’, result of the concatenation of s1 and s2. 
  ``` C
  char *ft_strjoin(const char *s1, const char *s2);
  ```
* ft_strtrim: Allocates and returns a copy of the string given as argument without whitespaces at the beginning or at the end of the string. Will be considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s has no whitespaces at the beginning or at the end, the function returns a copy of s.
  ``` C
  char * ft_strtrim(char const *s);
  ```
* ft_strsplit: Allocates and returns an array of “fresh” strings (all ending with ’\0’, including the array itself) obtained by spliting s using the character c as a delimiter.
  ``` C
  char **ft_strsplit(const char *s, char c);
  ```
* ft_itoa: Allocate and returns a “fresh” string ending with ’\0’ representing the integer n given as argument.
  ``` C
  char * ft_itoa(int n);
  ```
* ft_putchar: Outputs the character to the standard output.
  ``` C
  void ft_putchar(char c);
  ```
* ft_putstr: Outputs the string s to the standard output.
  ``` C
  void ft_putstr(char *s);
  ```
* ft_putendl: Outputs the string s to the standard output followed by a ’\n’.
  ``` C
  void ft_putendl(char *s);
  ```
* ft_putnbr: Outputs the integer n to the standard output.
  ``` C
  void ft_putnbr(int n);
  ```
* ft_putchar_fd: Outputs the char c to the file descriptor fd.
  ``` C
  void ft_putchar_fd(char c, int fd);
  ```
* ft_putstr_fd: Outputs the string s to the file descriptor fd.
  ``` C
  void ft_putstr_fd(char const *s, int fd);
  ```
* ft_putendl_fd: Outputs the string s to the file descriptor fd followed by a ’\n’.
  ``` C
  void ft_putendl_fd(char const *s, int fd);
  ```
* ft_putnbr_fd: Outputs the integer n to the file descriptor fd.
  ``` C
  void ft_putnbr_fd(int n, int fd);
  ```
## List template functions
### A bit of information

 The t_list structure is a typedef for a linked list structure name s_list containning a (void*) being the content, a (size_t) being the content size and a pointer to the next link of the list.
 Although it is not useful as is it serves as a placeholder for any linked list structure.
 
### The functions

* ft_lstnew: Allocates and returns a “fresh” link. The variables content and content_size of the new link are initialized by copy of the parameters of the function. If the parameter content is nul, the variable content is initialized to NULL and the variable content_size is initialized to 0 even if the parameter content_size isn’t. The variable next is initialized to NULL.
  ``` C
  t_list * ft_lstnew(void const *content, size_t content_size);
  ```
* ft_lstdelone: Takes as a parameter a link’s pointer address and frees the memory of the link’s content using the function del given as a parameter, then frees the link’s memory. Finally, the pointer to the link that was just freed is be
set to NULL (quite similar to the function ft_memdel).
  ``` C
  void ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
  ```
* ft_lstdel: Takes as a parameter the adress of a pointer to a link and frees the memory of this link and every successors of that link using the functions del and free. Finally the pointer to the link that was just freed is set to NULL (quite similar to the function ft_memdel).
  ``` C
  void ft_lstdel(t_list **alst, void (*del)(void *, size_t));
  ```
* ft_lstadd: Adds the element new at the beginning of the list.
  ``` C
  void ft_lstadd(t_list **alst, t_list *new);
  ```
* ft_lstiter: Iterates the list lst and applies the function f to each link.
  ``` C
  void ft_lstiter(t_list *lst, void (*f)(t_list *elem));
  ````
* ft_lstmap: Iterates a list lst and applies the function f to each link to create a “fresh” list resulting from the successive applications of f.
  ``` C
  t_list * ft_lstmap(t_list *lst, t_list * (*f)(t_list *elem));
  ```
## Additional functions that may be of use

* ft_strrev: Reverses the given string's order
  ``` C
  char *ft_strrev(char *str);
  ```
* ft_sqrt: Calculates the integral square root of a given integer.
  ``` C
  int ft_sqrt(int nb);
  ```
* ft_abs: Calculates the absolute value of a given integer.
  ``` C
  int ft_abs(int nb);
  ```
* ft_replace: Replaces every occurence of a character in a string by a given character.
  ``` C
  char *ft_replace(char *str, char find, char replace);
  ```
* ft_htoi: Converts the initial portion of a hexadecimal string to an int.
  ``` C
  int ft_htoi(char *hex);
  ```

