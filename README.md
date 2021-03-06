# 42_Seoul_Libft
## 42_Seoul first assignment Libft

# ๐ memset

#include <string.h>

void *
memset(void *b, int c, size_t len);

โ๏ธ Description
The memset() function writes len bytes of value c (converted to an unsigned char) to the
string b.

memset()ํจ์๋ b ๊ฐ ๊ฐ๋ฆฌํค๋ ๋ฉ๋ชจ๋ฆฌ ์ฃผ์๋ถํฐ len ๋ฐ์ดํธ๋งํผ c๊ฐ์ ์ฑ์ด๋ค.
์ด๋, int๋ก ๋ฐ๋ c๋ ํจ์ ๋ด๋ถ์์ unsigned char๋ก ์๋ ๋ณ๊ฒฝ๋๋ค.

โ๏ธ Note
unsigned char๋ ๋ชจ๋  bit๋ฅผ ํฌ๋ชํ๊ฒ ๋ณผ ์ ์๋ค. (๋ถํธ๋นํธ๊ฐ ์๊ธฐ ๋๋ฌธ)
๋ฐ๋ผ์, ์์์ ๋ฉ๋ชจ๋ฆฌ์ ๋ฐ์ดํธ ๋จ์๋ก ์ ๊ทผํด ๊ฐ์ ๋ค๋ฃฐ ๋, ๋ฐ๋์ unsigned char๋ฅผ ์ฌ์ฉํ๋ค.
0, -1, 0x3F, 0x7F๋ฅผ ์ ์ธํ ๋๋จธ์ง ๊ฐ์ ์ํ๋ ๊ฐ์ผ๋ก ์ด๊ธฐํํ  ์ ์๋ค.

โ๏ธ Return
์ฑ๊ณต ์ ์ฒซ๋ฒ์งธ ์ธ์๋ก ๋ค์ด๊ฐ ptr์ ๋ฐํ, ์คํจ ์ NULL์ ๋ฐํํ๋ค.

โ๏ธ Notice
memset()๊ณผ bzero() ๋ชจ๋ unsigned char๋ก ์บ์คํํ๋ ๊ณผ์ ์ด ์๋ค.
1๋ฐ์ดํธ ๋ณ์๋ฅผ ์ ์ธํ ๋ณ์๋ฅผ ์ด๊ธฐํ ํ  ์, 0์ด์ธ์ ๊ฐ์ผ๋ก ์ด๊ธฐํ ์๋จ.

# ๐ bzero

#include <string.h>

 void
 bzero(void *s, size_t n);

โ๏ธ Description
The bzero() function writes n zeroed bytes to the string s. If n is zero, bzero() does
nothing.

bzero()ํจ์๋ s๊ฐ ๊ฐ๋ฆฌํค๋ ๋ฉ๋ชจ๋ฆฌ๋ก๋ถํฐ n๋ฐ์ดํธ๋งํผ 0๊ฐ์ ์ฑ์ด๋ค.

โ๏ธ Return
none

โ๏ธ Notice
memset()๊ณผ bzero() ๋ชจ๋ unsigned char๋ก ์บ์คํํ๋ ๊ณผ์ ์ด ์๋ค.

# ๐ memcpy

#include <string.h>

void *
memcpy(void *restrict dst, const void *restrict src, size_t n);
โ42์์ restrict ์ฌ์ฉ ๋ถ๊ฐ

โ๏ธ Restrict?
restrict ํฌ์ธํฐ๋ ๋ฉ๋ชจ๋ฆฌ ์ ๊ทผ์ ๊ด๋ จ๋ ์ต์ ํ ๊ธฐ๋ฅ (C99 ํ์ค).
ํฌ์ธํฐ๊ฐ ํ๋๋ง ๊ฐ๋ฆฌํค๊ณ  ์๋ค๋ ๊ฒ์ ์ปดํ์ผ๋ฌ๊ฐ ์๋ฉด, ๋ฉ๋ชจ๋ฆฌ ๋ณต์ฌ ์์ด ๋นํธ์ฐ์ฐ์๋ฅผ ์ด์ฉํด ์ฐ์ฐํ๋ค.
์๋ง์ ์กฐ๊ฑด์ด ์ ์ฉ๋๋ฉด, ์ฑ๋ฅ์ด ๋น์ฝ์ ์ผ๋ก ์ฆ๊ฐํ๋ค.

โ๏ธ Description
The memcpy() function copies n bytes from memory area src to memory area dst. If dst and
src overlap, behavior is undefined. Applications in which dst and src might overlap should
use memmove(3) instead.

memcpy()ํจ์๋ src๊ฐ ๊ฐ๋ฆฌํค๋ ๋ฉ๋ชจ๋ฆฌ ์ฃผ์๋ก๋ถํฐ n๋ฐ์ดํธ ํฌ๊ธฐ(๊ธธ์ด)๋งํผ dst๋ฉ๋ชจ๋ฆฌ์ ๋ณต์ฌํ๋ค.

โ๏ธ Return
dst๋ฅผ ๋ฐํํ๋ค.

โ๏ธ Notice
์ฌ์ฉ ์, ๋ฉ๋ชจ๋ฆฌ ์์ญ์ ๊ฒน์น๋ฉด ์๋๋ค.
๊ณ์น๋ค๋ฉด, memmove()ํจ์๋ฅผ ์ฌ์ฉํด์ผ ํ๋ค.

# ๐ memmove
#include <string.h>

void *
memmove(void *dst, const void *src, size_t len);

โ๏ธ Description
The memmove() function copies len bytes from string src to string dst. The two strings may
overlap; the copy is always done in a non-destructive manner.

memmove()ํจ์๋ len๋ฐ์ดํธ๋งํผ src ๋ฉ๋ชจ๋ฆฌ์์ dest๋ก ๋ณต์ฌํ๋ค.
๋ณต์ฌ๋ ํญ์ ๋นํ๊ดด ๋ฐฉ์์ผ๋ก ์งํ๋๋ค.
์ฆ, src๋ฐฐ์ด์ src์ dest๋ฉ๋ชจ๋ฆฌ ์์ญ๊ณผ ๊ฒน์น์ง ์๋ ๋ฉ๋ชจ๋ฆฌ ์์ญ๋ถํฐ ๋จผ์  ๋ณต์ฌํ๋ค.
src ์ฃผ์๊ฐ dest๋ณด๋ค ํฌ๋ค๋ฉด, ์์ฐจ์ ์ผ๋ก ๋ฐ์ดํฐ๋ฅผ ๋ณต์ฌํ๋ฉด ๋๋ค.
src ์ฃผ์๊ฐ dest๋ณด๋ค ์๋ค๋ฉด, src ๋ง์ง๋ง ๋ฐ์ดํธ๋ถํฐ dest + len์ ๋ณต์ฌํ๋ค.

โ๏ธ Return
dest ๋ฐํ.

โ๏ธ Notice
ํ ๋ฐฐ์ด ์์์ ๋ณต์ฌ๋ฅผ ์ํํ๊ฑฐ๋, src ์์์ฃผ์๊ฐ dest ์์ ์ฃผ์๋ณด๋ค ์์ ์์ผ๋ฉด์ ๋ ์ฃผ์ ์ฐจ์ด๊ฐ len๋ณด๋ค ์์ผ๋ฉด ๋ฐ์ํ๋ค.

# ๐ memchr
#include <string.h>

void *
memchr(const void *s, int c, size_t n);

โ๏ธ Description
The memchr() function locates the first occurrence of c (converted to an unsigned char) in
string s.

memchr()ํจ์๋ s๊ฐ ๊ฐ๋ฆฌํค๋ ๋ฉ๋ชจ๋ฆฌ ์ฃผ์๋ก๋ถํฐ n๋ฐ์ดํธ ์ค ์ฒ์์ผ๋ก c์ ์ผ์นํ๋ ๊ฐ์ ์ฃผ์๋ฅผ ๋ฆฌํดํ๋ค.

โ๏ธ Return
c์ ์ผ์นํ๋ ๊ฐ์ ์ฃผ์๋ฅผ ๋ฆฌํดํ๋ค. ์ฐพ์ง ๋ชปํ๋ฉด NULL์ ๋ฐํํ๋ค.

# ๐ memcmp
#include <string.h>

int
memcmp(const void *s1, const void *s2, size_t n);

โ๏ธ Description
The memcmp() function compares byte string s1 against byte string s2. Both strings are
assumed to be n bytes long.

s1์ด ๊ฐ๋ฆฌํค๋ n๋ฐ์ดํธ๋งํผ์ ๋ฐ์ดํฐ์ s2๊ฐ ๊ฐ๋ฆฌํค๋ n ๋ฐ์ดํธ๋งํผ์ ๋ฐ์ดํฐ๋ฅผ ๋น๊ตํ์ฌ, ๊ฐ์ผ๋ฉด 0์ ๋ฆฌํดํ๊ณ  ๋ค๋ฅด๋ฉด 0์ด ์๋ ๊ฐ์ ๋ฆฌํดํ๋ค.

โ๏ธ Return

โ๏ธ Notice
ํจ์ ์ฌ์ฉ ์ ์ค๋ฒํ๋ก์ฐ์ ์ฃผ์. (n์ ๋ฒํผ๋ณด๋ค ์๊ฑฐ๋ ๊ฐ๊ฒ)
strcmp์ ์ฐจ์ด์ ์, ๋ ๋ฌธ์์ด ์ค ํ๋๊ฐ ๋๋๋๋ผ๋ ์๋ก ๋ค๋ฅธ ๊ฐ์ด ๋์ค๊ฑฐ๋ n๊ฐ๊ฐ ๋  ๋๊น์ง ๋น๊ตํ๋ค.
๋ฐ๋ผ์, s1, s2 ๋ชจ๋ NULL๊ฐ์ด ๋์ค๋ฉด ๋จ์ ์นด์ดํธ ๊ด๊ณ ์์ด 0์ ๋ฐํํ strcmp์ ์ฐจ์ด๊ฐ ์๋ค.

# ๐ strlen

# ๐ strlcpy
#include <string.h>

size_t
strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

โ๏ธ Description
The strlcpy() and strlcat() functions copy and concatenate strings with the same input
parameters and output result as snprintf(3). They are designed to be safer, more consis-
tent, and less error prone replacements for the easily misused functions strncpy(3) and
strncat(3).
strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-ter-
mination if there is room. Note that room for the NUL should be included in dstsize.
strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating
the result if dstsize is not 0.

strlcpy() ํจ์๋ ์ค์ํ์ง ์๋๋ก ๋์์ธ๋์๋ค.
dstsize๊ฐ 0์ด ์๋ ๊ฒฝ์ฐ dstsize - 1๋งํผ ๋ฌธ์๋ฅผ src์์ dst๋ก ๋ณต์ฌ ํ null์ ํฌํจํ์ฌ ์ข๋ฃํ๋ค.

โ๏ธ Return

# ๐ strchr
#include <string.h>

char	*ft_strchr(const char *s, int c);

โ๏ธ Description
The strchr() function locates the first occurrence of c (converted to a char) in the string
pointed to by s. The terminating null character is considered to be part of the string;
therefore if c is \0', the functions locate the terminating\0'.

strchr() ํจ์๋ s์์ c๋ฌธ์๊ฐ ๊ฐ์ฅ ๋จผ์  ๋ํ๋๋ ๊ณณ์ ์ฐพ๋๋ค.

โ๏ธ Return
c์ ์ฃผ์๋ฅผ ๋ฆฌํดํ๋ค. ์ฐพ๋ ๋ฌธ์๊ฐ s์์ ์๋ค๋ฉด NULLํฌ์ธํฐ๋ฅผ ๋ฆฌํดํ๋ค.

โ๏ธ Notice

# ๐ strrchr

โ๏ธ Return
strchr๊ณผ ๋ง์ฐฌ๊ฐ์ง์ด๋, ๋ค๋ฅธ์ ์ ๋ค์์๋ถํฐ ์ฐพ๋ ํจ์ str์ด ๋น ๋ฌธ์์ด์ผ๋๋ s์ ์ฒซ ๋ฌธ์๋ง c์ผ ๋, NULL์ด ์๋๋ผ s์ ์ฒซ๊ธ์๋ฅผ ๋ฐํํ๋๋ก ์์ธ์ฒ๋ฆฌํจ.

# ๐ strnstr
#include <string.h>

char *
strnstr(const char *haystack, const char *needle, size_t len);

โ๏ธ Description
The strnstr() function locates the first occurrence of the null-terminated string needle in
the string haystack, where not more than len characters are searched. Characters that
appear after a `\0' character are not searched. Since the strnstr() function is a FreeBSD
specific API, it should only be used when portability is not a concern.

๋ฌธ์์ด ๋ด์์ ๋ถ๋ถ๋ฌธ์์ด์ ํ์ํ๋ ํจ์์ด๋ค.

โ๏ธ Return
needle์ด ์ฒ์ ๋ํ๋๋ ์ฃผ์๋ฅผ ๋ฆฌํดํ๋ค. ๋ง์ฝ ์๋ค๋ฉด NULL์ ๋ฆฌํดํ๋ค.

โ๏ธ Notice

# ๐ strncmp

# ๐ atoi

โ๏ธ Notice
atoiํจ์๋ long long max ๋ณด๋ค ํฐ ์ค๋ฒํ๋ก์ฐ ์ -1, long long min ๋ณด๋ค ์์ ์ธ๋ํ๋ก์ฐ ์ 0์ด ๋ฐํ๋๋ค.

# ๐ isalpha
# ๐ isdigit
# ๐ isalnum
# ๐ isascii
# ๐ isprint
# ๐ toupper
# ๐ tolower

# ๐ calloc
#include <stdlib.h>

void *
calloc(size_t count, size_t size);

โ๏ธ Description
The calloc() function contiguously allocates enough space for count
objects that are size bytes of memory each and returns a pointer to
the allocated memory. The allocated memory is filled with bytes of
value zero.

calloc()ํจ์๋ malloc()ํจ์์ ๋ง์ฐฌ๊ฐ์ง๋ก sizeํฌ๊ธฐ(๋ฐ์ดํธ)์ count๊ฐ์๋งํผ ๋ฐ์ดํธ๋ฅผ ํ ๋นํ๋ค.
malloc๊ณผ ๋ฌ๋ฆฌ ์ ๋ถ 0์ผ๋ก ์ด๊ธฐํํ๋ค.

โ๏ธ Return
ํ ๋น๋ ๋ฉ๋ชจ๋ฆฌ ์ฃผ์๋ฅผ ๋ฐํํ๋ค.

โ๏ธ Notice

# ๐ strdup
#include <string.h>



โ๏ธ Description
The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it. The pointer may subsequently be used as an argument to the function free(3). If insufficient memory is available, NULL is returned and errno is set to ENOMEM.

strdup()ํจ์๋ s1์ด ๋ณต์ฌ๋์ด ์ถฉ๋ถํ ๋ค์ด๊ฐ๋งํ ๊ณต๊ฐ์ ํ๋ณดํ๊ณ , ๋ฌธ์์ด์ ๋ณต์ฌํ๋ค. ๊ณต๊ฐ์ str๊ธธ์ด + 1 ๋งํผ ํ๋ณด๋์ด์ผ ํ๋ค.

โ๏ธ Return
๋ณต์ฌ๋ ๋ฌธ์์ด์ ์ฃผ์๋ฅผ ๋ฐํํ๋ค. ์๋ฌ ๋ฐ์์ NULL์ ๋ฐํํ๋ค.

โ๏ธ Notice
ํจ์ ์ฌ์ฉ ์, free ํจ์ ๋ฑ์ผ๋ก ๋ฉ๋ชจ๋ฆฌ ํด์ ๋ฅผ ํ์ฌ์ผ ํ๋ค.

# ๐ ft_substr

char *ft_substr(char const *s, unsigned int start, size_t len)

โ๏ธ Description
Allocates (with malloc(3)) and returns a substring from the string s.
The substring begins at index start and is of maximum size len

๋ฌธ์์ด[start] ์์๋ถํฐ len๋งํผ์ ๊ธธ์ด๋งํผ ํ์๋ฌธ์์ด์ ๋ณต์ ํ์ฌ ๋ฐํํ๋ค.

โ๏ธ Return
ํ์๋ฌธ์์ด์ ๋ฐํํ๋ค.
๋ฌธ์์ด์ ๊ธธ์ด๋ณด๋ค start ๊ฐ์ด ํด ๊ฒฝ์ฐ ๋น ๋ฌธ์์ด์ ๋ฐํํ๋ค.
๋ณต์ฌํ  ๋ฌธ์์ด์ ๊ธธ์ด๊ฐ len๋ณด๋ค ์งง์ผ๋ฉด ๊ทธ๋งํผ๋ง ๋ณต์ฌ ํ ๋ฐํํ๋ค. (๋ฌธ์์ด ํ ๋น ๊ธธ์ด๋ ๋ณ๋ x)

โ๏ธ Notice

# ๐ ft_strjoin

char	*ft_strjoin(char const *s1, char const *s2)

โ๏ธ Description
Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of โs1โ and โs2โ.

์๋ก์ด ๊ณต๊ฐ์ ํ ๋นํ์ฌ s1, s2๋ฅผ ์ฐ๊ฒฐํ ๋ฌธ์์ด์ ์ ์ฅํ ๋ค ๋ฐํํ๋ค.

โ๏ธ Return
s1๊ณผ s2๋ฅผ ์ฐ๊ฒฐํ ์๋ก์ด ๋ฌธ์์ด์ ๋ฐํํ๋ค.

โ๏ธ Notice
s1, s2 ์ ๋ถ ๋์ด๋ฉด 0์ ๋ฐํํ๋ค. ํ๋๋ง ๋์ผ๊ฒฝ์ฐ ๋๋จธ์ง ๋ฌธ์์ด๋ง ๋ณต์ ํ์ฌ ๋ฐํํ๋ค.

# ๐ ft_strtrim

char	*ft_strtrim(char const *s1, char const *set)

โ๏ธ Description
Allocates (with malloc(3)) and returns a copy of โs1โ with the characters specified in โsetโ removed from the beginning and the end of the string.

s1์์ ๋ฌธ์์ด์ ์์๊ณผ ๋์์ set์ ์ง์ ๋ ๋ฌธ์๋ค์ ์ ๊ฑฐํ ๋ฌธ์์ด์ ์๋ก ๋ณต์ ํ์ฌ ๋ฐํํ๋ค.

โ๏ธ Return

โ๏ธ Notice
s1์ด ๋์ด๋ฉด 0์ ๋ฐํํ๋ค.
set์ด ๋์ด๋ฉด s1์ ๋ณต์ ํ์ฌ ๋ฐํํ๋ค.
๋ฌธ์์ด ์ ์ฒด๊ฐ ์๋์ ์ ์ํ๋ค.

# ๐ ft_split

char			**ft_split(char const *s, char c)

โ๏ธ Description
Allocates (with malloc(3)) and returns an array of strings obtained by splitting โsโ using the character โcโ as a delimiter. The array must be ended by a NULL pointer.

๊ตฌ๋ถ๋ฌธ์ c๋ฅผ ํ์ฉํ์ฌ, s๋ฌธ์์ด์ ๋ถํ ํ๊ณ  ์ด์ฐจ์ ๋ฐฐ์ด์ ์ ์ฅํ์ฌ ๋ฐํํ๋ค. ์ด๋ ๋ฐฐ์ด์ null๋ก ๋๋์ผ ํ๋ค.

โ๏ธ Return
๋งจ ๋์ null์ด ๋ค์ด๊ฐ ์ด์ฐจ์ ๋ฐฐ์ด.

โ๏ธ Notice
์ด์ฐจ์๋ฐฐ์ด์ ๊ฐ๋์ด ์ด๋ ต๋ค๋ฉด, ๋ฌธ์์ด์ด ๋์ด๋ ๋ฐฐ์ด์ด๋ผ ์๊ฐํ์.
libft์์ ๊ฐ์ฅ ์ค๋ ๊ฑธ๋ฆฌ๋ ๋ฌธ์ ๋ค ์ค ํ๋์์ ์ ์ํ์.

# ๐ ft_itoa

char		*ft_itoa(int n)

โ๏ธ Description
Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.

์ธ์๋ก ๋ฐ์ ์ ์๋ฅผ ๋ฌธ์์ด๋ก ์นํํ์ฌ ๋ฐํํ๋ค. ์์๊ฐ ๊ณ ๋ ค๋์ด์ผ ํ๋ค.

โ๏ธ Return
๋ฌธ์์ด

โ๏ธ Notice

# ๐ ft_striteri

void		ft_striteri(char *s, void (*f)(unsigned int, char *))

โ๏ธ Description
Applies the function f to each character of the string passed as argument, and passing its index as first argument. Each character is passed by address to f to be modified if necessary

๋ฌธ์์ด 's' ์ ๊ฐ ๋ฌธ์๋ฅผ ์ํํ๋ฉฐ ํจ์ 'f'๋ฅผ ์ ์ฉํ๊ณ , ํด๋น ๋ฌธ์์ ์ธ๋ฑ์ค๋ฅผ ํจ์ 'f'์ ์ฒซ ๋ฒ์งธ ์ธ์๋ก ์ฌ์ฉํฉ๋๋ค. ๋ํ ๊ฐ ๋ฌธ์์ ์ฃผ์๊ฐ์ด 'f' ํจ์์ ๋ ๋ฒ์งธ ์ธ์๋ก ์ฌ์ฉ๋๋ฉฐ, ๊ฒฝ์ฐ์ ๋ฐ๋ผ ์์ ๋  ์ ์์ต๋๋ค.

โ๏ธ Return
์์

# ๐ ft_strmapi

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))

โ๏ธ Description
Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.

๋ฌธ์์ด s๋ฅผ ๋ณต์ ํ๋๋ฐ, ๋ด๋ถ ๋ฐ์ดํฐ๋ฅผ ๋ฌธ์์ด s์ ๊ฐ ๋ฐ์ดํฐ๋ฅผ f์ ๋ฃ์ด ๋ฐ์ ๊ฐ์ผ๋ก ์ฑ์ด๋ค.
s[0] โ t[f(s[0])]

โ๏ธ Return
๋ณต์ ๋ ๋ฌธ์์ด

โ๏ธ Notice
ํจ์ํฌ์ธํฐ์ ๋ํด ์์๋ณด์.

# ๐ ft_putchar_fd

void	ft_putchar_fd(char c, int fd)

โ๏ธ Description
Outputs the character โcโ to the given file descriptor.

์ง์ ๋ ํ์ผ ์ค๋ช์์ ๋ฌธ์ 'c'๋ฅผ ์ถ๋ ฅํ๋ค.

โ๏ธ Return

โ๏ธ Notice
ํ์ผ ๋์คํฌ๋ฆฝํฐ์ ๋ํด ์์๋ณด์.

# ๐ ft_putstr_fd

void	ft_putstr_fd(char *s, int fd)

โ๏ธ Description
Outputs the string โsโ to the given file descriptor.

์ง์ ๋ ํ์ผ ์ค๋ช์์ ๋ฌธ์์ด 's'๋ฅผ ์ถ๋ ฅํ๋ค.

โ๏ธ Return

โ๏ธ Notice
ํ์ผ ๋์คํฌ๋ฆฝํฐ์ ๋ํด ์์๋ณด์.

# ๐ ft_putendl_fd

void	ft_putendl_fd(char *s, int fd)

โ๏ธ Description
Outputs the string โsโ to the given file descriptor. followed by a newline.

์ง์ ๋ ํ์ผ ์ค๋ช์์ ๋ฌธ์์ด 's'๋ฅผ ์ถ๋ ฅํ๊ณ  ๋ง์ง๋ง์ ๊ฐํ์ ์ถ๊ฐํ๋ค.

โ๏ธ Return

โ๏ธ Notice
ํ์ผ ๋์คํฌ๋ฆฝํฐ์ ๋ํด ์์๋ณด์.
# ๐ ft_putnbr_fd

void		ft_putnbr_fd(int n, int fd)

โ๏ธ Description
Outputs the integer โnโ to the given file descriptor.

์ฃผ์ด์ง ํ์ผ ์ค๋ช์์ ์ ์ 'n'์ ์ถ๋ ฅํ๋ค.

โ๏ธ Return

โ๏ธ Notice
ํ์ผ ๋์คํฌ๋ฆฝํฐ์ ๋ํด ์์๋ณด์.
---
### ์๋ ์ฝ๋๋ถํฐ๋ ๊ตฌ์กฐ์ฒด๋ฅผ ์ฌ์ฉํ ํจ์๋ค์ด๋ค.

typedef struct	   	s_list
{
	void			        *content;
		struct  s_list	*next;

}				           	t_list;

# ๐ ft_lstnew

t_list	*ft_lstnew(void *content)

โ๏ธ Description
Allocates (with malloc(3)) and returns a new lement. The variable โcontentโ is initialized with the value of the parameter โcontentโ. The variable โnextโ is initialized to NULL.

์ ์์(์ดํ ๋ธ๋)์ content๋ ๋งค๊ฐ๋ณ์๋ก ๋ฐ์ content, next๋ ๋๋ก ์ด๊ธฐํํ์ฌ ๋ฐํํ๋ค.

โ๏ธ Return
์ ๋ธ๋

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.

# ๐ ft_lstadd_front

void	ft_lstadd_front(t_list **lst, t_list *new)

โ๏ธ Description
Adds the element โnewโ at the beginning of the list.

(์ฐ๊ฒฐ๋ฆฌ์คํธ) ์์ ๋ถ๋ถ์ new๋ธ๋๋ฅผ ์ถ๊ฐํ๋ค.

โ๏ธ Return

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.

# ๐ ft_lstsize

int		ft_lstsize(t_list *lst)

โ๏ธ Description
Counts the number of elements in a list.

๋ฆฌ์คํธ์ ๋ธ๋ ์๋ฅผ ๋ฐํํ๋ค.

โ๏ธ Return
๋ธ๋์ ๊ฐ์

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.

# ๐ ft_lstlast

t_list	*ft_lstlast(t_list *lst)

โ๏ธ Description
Returns the last element of the list.

๋ฆฌ์คํธ์ ๋ง์ง๋ง ๋ธ๋๋ฅผ ๋ฐํํ๋ค.

โ๏ธ Return
๋ง์ง๋ง ๋ธ๋

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.
lst์ next๊ฐ ์กด์ฌํ๋ค๋ ๋ป์, lst๊ฐ ๋ง์ง๋ง ๋ธ๋๊ฐ ์๋๋ผ๋ ๋ป์ด๋ค. ๋ฐ๋ผ์ lst์ next๊ฐ NULL์ด ์๋ ๋๊น์ง ๋ฆฌ์คํธ๋ฅผ ํ์ํ๋ค.

# ๐ ft_lstadd_back

void	ft_lstadd_back(t_list **lst, t_list *new)

โ๏ธ Description
Adds the element โnewโ at the end of the list.

๋ฆฌ์คํธ ๋์ new๋ธ๋๋ฅผ ์ถ๊ฐํฉ๋๋ค.

โ๏ธ Return

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.
# ๐ ft_lstdelone

void	ft_lstdelone(t_list *lst, void (*del)(void *))

โ๏ธ Description
Takes as a parameter an element and frees the memory of the elementโs content using the function โdelโ given as a parameter and free the element. The memory of โnextโ must not be freed.

๋ธ๋๋ฅผ ๋งค๊ฐ๋ณ์๋ก ์ทจํ๋ delํจ์๋ฅผ ์ฌ์ฉํ์ฌ ๋ธ๋์ ์ฝํ์ธ  ๋ฉ๋ชจ๋ฆฌ๋ฅผ ํด์ ํ๊ณ , ๋ธ๋๋ฅผ freeํ๋ค. next์ ๋ฉ๋ชจ๋ฆฌ๋ฅผ freeํด์๋ ์๋๋ค.

โ๏ธ Return

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.
ํจ์ํฌ์ธํฐ์ ๋ํด ์์๋ณด์.
delํจ์๊ฐ ์ฝํ์ธ ๋ฅผ freeํ๋ฏ๋ก ์ฝํ์ธ ์ ๊ดํ free๋ ๊ณ ๋ คํ์ง ์๋๋ค.

# ๐ ft_lstclear

void	ft_lstclear(t_list **lst, void (*del)(void *))

โ๏ธ Description
Deletes and frees the given element and every successor of that element, using the function โdelโ and free(3).
Finally, the pointer to the list must be set to NULL.

๋ฆฌ์คํธ์ ๋ธ๋๋ค์ ์ ๋ถ ์ญ์ (free)ํด์ผํ๋ค.
๋ธ๋ ์ญ์  ์ ๋ธ๋ ๋ด ์ปจํ์ธ  ๋ํ ์ญ์ (free)๋์ด์ผ ํ๋ค.

โ๏ธ Return

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.
ํจ์ํฌ์ธํฐ์ ๋ํด ์์๋ณด์.
์ด์  ๋ฌธ์ ๋ฅผ ์ ํ์ฉํ๋ค.
# ๐ ft_lstiter

void	ft_lstiter(t_list *lst, void (*f)(void *))

โ๏ธ Description
Iterates the list โlstโ and applies the function โfโ to the content of each element.

์ฐ๊ฒฐ๋ฆฌ์คํธ lst์ ๊ฐ ๋ธ๋์ ์ฝํ์ธ ๋ฅผ fํจ์์ ๋งค๊ฐ๋ณ์๋ก ํ์ฉํ์ฌ fํจ์๋ฅผ ํธ์ถํ๋ค.
lst์ ์ฐ๊ฒฐ๋ ๋ชจ๋  ๋ฆฌ์คํธ์ content์ f๋ฅผ ์ ์ฉํ๋ ํจ์

โ๏ธ Return

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.
ํจ์ํฌ์ธํฐ์ ๋ํด ์์๋ณด์.
# ๐ ft_lstmap

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))

โ๏ธ Description
Iterates the list โlstโ and applies the function โfโ to the content of each element. Creates a new list resulting of the successive applications of the function โfโ. The โdelโ function is used to delete the content of an element if needed.

๋ฆฌ์คํธ๋ฅผ ๋ณต์ ํ์ฌ ์๋ก์ด ๋ฆฌ์คํธ๋ฅผ ๋ง๋ ๋ค.
์ด๋, ์๋ก์ด ๋ฆฌ์คํธ์ content๋ fํจ์์ ๋ฐํ๊ฐ์ผ๋ก, ๋งค๊ฐ๋ณ์๋ ๋ณต์ ํ  ๋ฆฌ์คํธ์ content๋ฅผ ์ฌ์ฉํ๋ค.
ํ๋ผ๋ฏธํฐ๋ก ๋ฐ์ ์ฐ๊ฒฐ ๋ฆฌ์คํธ์ ๊ฐ content์ f ํจ์๋ฅผ ์ ์ฉํ ์ ์ฐ๊ฒฐ ๋ฆฌ์คํธ๋ฅผ ๋ง๋๋ ํจ์
์ ๋ธ๋๋ฅผ mallocํ๋ ๋ฐ ์คํจํ  ๊ฒฝ์ฐ ์๋กญ๊ฒ ๋ง๋  ๋ชจ๋  lst์ content์ lst๋ฅผ freeํด ์ค

โ๏ธ Return

โ๏ธ Notice
๊ตฌ์กฐ์ฒด์ ์ฐ๊ฒฐ๋ฆฌ์คํธ์ ๋ํด ์์๋ณด์.
ํจ์ํฌ์ธํฐ์ ๋ํด ์์๋ณด์.

์ถ์ฒ : https://velog.io/@tmdgks2222/libft#-calloc
