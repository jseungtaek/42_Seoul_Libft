# 42_Seoul_Libft
## 42_Seoul first assignment Libft

# 🚀 memset
#include <string.h>

void *
memset(void *b, int c, size_t len);
✔️ Description
The memset() function writes len bytes of value c (converted to an unsigned char) to the
string b.

memset()함수는 b 가 가리키는 메모리 주소부터 len 바이트만큼 c값을 채운다.
이때, int로 받는 c는 함수 내부에서 unsigned char로 자동 변경된다.

✔️ Note
unsigned char는 모든 bit를 투명하게 볼 수 있다. (부호비트가 없기 때문)
따라서, 임의의 메모리에 바이트 단위로 접근해 값을 다룰 때, 반드시 unsigned char를 사용한다.
0, -1, 0x3F, 0x7F를 제외한 나머지 값은 원하는 값으로 초기화할 수 없다.

✔️ Return
성공 시 첫번째 인자로 들어간 ptr을 반환, 실패 시 NULL을 반환한다.

⁉️ Notice
memset()과 bzero() 모두 unsigned char로 캐스팅하는 과정이 있다.
1바이트 변수를 제외한 변수를 초기화 할 시, 0이외의 값으로 초기화 안됨.

# 🚀 bzero
#include <string.h>

 void
 bzero(void *s, size_t n);

✔️ Description
The bzero() function writes n zeroed bytes to the string s. If n is zero, bzero() does
nothing.

bzero()함수는 s가 가리키는 메모리로부터 n바이트만큼 0값을 채운다.

✔️ Return
none

⁉️ Notice
memset()과 bzero() 모두 unsigned char로 캐스팅하는 과정이 있다.

# 🚀 memcpy
#include <string.h>

     void *
     memcpy(void *restrict dst, const void *restrict src, size_t n);
❗42에서 restrict 사용 불가

✔️ Restrict?
restrict 포인터는 메모리 접근에 관련된 최적화 기능 (C99 표준).
포인터가 하나만 가리키고 있다는 것을 컴파일러가 알면, 메모리 복사 없이 비트연산자를 이용해 연산한다.
알맞은 조건이 적용되면, 성능이 비약적으로 증가한다.

✔️ Description
The memcpy() function copies n bytes from memory area src to memory area dst. If dst and
src overlap, behavior is undefined. Applications in which dst and src might overlap should
use memmove(3) instead.

memcpy()함수는 src가 가리키는 메모리 주소로부터 n바이트 크기(길이)만큼 dst메모리에 복사한다.

✔️ Return
dst를 반환한다.

⁉️ Notice
사용 시, 메모리 영역은 겹치면 안된다.
곂친다면, memmove()함수를 사용해야 한다.

#🚀 memccpy
#include <string.h>

void *
memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
❗42에서 restrict 사용 불가

✔️ Description
The memccpy() function copies bytes from string src to string dst. If the character c (as converted to an unsigned char) occurs in the string src, the copy stops and a pointer to the
byte after the copy of c in the string dst is returned. Otherwise, n bytes are copied, and
a NULL pointer is returned.

memccpy()함수는 src가 가리키는 메모리 주소로부터 n바이트 크기(길이)만큼 dst메모리에 복사한다. 단, 문자 c를 만나게 되면 c까지 복사하고 중단한다.

✔️ Return
dest에서 c의 다음 위치 (복사가 끝난 다음 메모리주소)를 리턴한다. c를 만나지 않는다면 n만큼 복사하고 NULL을 반환한다.

⁉️ Notice
c를 1바이트 크기가 아닌 자료형을 사용하여 찾을 경우, 문제가 생긴다.
memccpy함수는 1바이트 메모리만 비교하여 찾기 때문이다.
굳이 int형을 다뤄야 한다면, 1 ~ 255 범위 내 사용하는 것이 좋다.

# 🚀 memmove
#include <string.h>

void *
memmove(void *dst, const void *src, size_t len);

✔️ Description
The memmove() function copies len bytes from string src to string dst. The two strings may
overlap; the copy is always done in a non-destructive manner.

memmove()함수는 len바이트만큼 src 메모리에서 dest로 복사한다.
복사는 항상 비파괴 방식으로 진행된다.
즉, src배열은 src와 dest메모리 영역과 겹치지 않는 메모리 영역부터 먼저 복사한다.
src 주소가 dest보다 크다면, 순차적으로 데이터를 복사하면 된다.
src 주소가 dest보다 작다면, src 마지막 바이트부터 dest + len에 복사한다.

✔️ Return
dest 반환.

⁉️ Notice
한 배열 안에서 복사를 수행하거나, src 시작주소가 dest 시작 주소보다 앞에 있으면서 두 주소 차이가 len보다 작으면 발생한다.

# 🚀 memchr
#include <string.h>

void *
memchr(const void *s, int c, size_t n);

✔️ Description
The memchr() function locates the first occurrence of c (converted to an unsigned char) in
string s.

memchr()함수는 s가 가리키는 메모리 주소로부터 n바이트 중 처음으로 c와 일치하는 값의 주소를 리턴한다.

✔️ Return
c와 일치하는 값의 주소를 리턴한다. 찾지 못하면 NULL을 반환한다.

# 🚀 memcmp
#include <string.h>

int
memcmp(const void *s1, const void *s2, size_t n);

✔️ Description
The memcmp() function compares byte string s1 against byte string s2. Both strings are
assumed to be n bytes long.

s1이 가리키는 n바이트만큼의 데이터와 s2가 가리키는 n 바이트만큼의 데이터를 비교하여, 같으면 0을 리턴하고 다르면 0이 아닌 값을 리턴한다.

✔️ Return

⁉️ Notice
함수 사용 시 오버플로우에 주의. (n은 버퍼보다 작거나 같게)
strcmp와 차이점은, 두 문자열 중 하나가 끝나더라도 서로 다른 값이 나오거나 n개가 될 때까지 비교한다.
따라서, s1, s2 모두 NULL값이 나오면 남은 카운트 관계 없이 0을 반환한 strcmp와 차이가 있다.

# 🚀 strlen
---

# 🚀 strlcpy
#include <string.h>

size_t
strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);

✔️ Description
The strlcpy() and strlcat() functions copy and concatenate strings with the same input
parameters and output result as snprintf(3). They are designed to be safer, more consis-
tent, and less error prone replacements for the easily misused functions strncpy(3) and
strncat(3).
strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-ter-
mination if there is room. Note that room for the NUL should be included in dstsize.
strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating
the result if dstsize is not 0.
strlcpy() 함수는 실수하지 않도록 디자인되었다.
dstsize가 0이 아닌 경우 dstsize - 1만큼 문자를 src에서 dst로 복사 후 null을 포함하여 종료한다.
✔️ Return

# 🚀 strchr
#include <string.h>

char	*ft_strchr(const char *s, int c);

✔️ Description
The strchr() function locates the first occurrence of c (converted to a char) in the string
pointed to by s. The terminating null character is considered to be part of the string;
therefore if c is \0', the functions locate the terminating\0'.

strchr() 함수는 s에서 c문자가 가장 먼저 나타나는 곳을 찾는다.

✔️ Return
c의 주소를 리턴한다. 찾는 문자가 s안에 없다면 NULL포인터를 리턴한다.

⁉️ Notice
🚀 strrchr
🚀 strnstr
#include <string.h>

char *
strnstr(const char *haystack, const char *needle, size_t len);
구현 코드

✔️ Description
The strnstr() function locates the first occurrence of the null-terminated string needle in
the string haystack, where not more than len characters are searched. Characters that
appear after a `\0' character are not searched. Since the strnstr() function is a FreeBSD
specific API, it should only be used when portability is not a concern.
문자열 내에서 부분문자열을 탐색하는 함수이다.
✔️ Return
needle이 처음 나타나는 주소를 리턴한다. 만약 없다면 NULL을 리턴한다.

⁉️ Notice
🚀 strncmp
🚀 atoi
⁉️ Notice
atoi함수는 long long max 보다 큰 오버플로우 시 -1, long long min 보다 작은 언더플로우 시 0이 반환된다.
---
🚀 isalpha
🚀 isdigit
🚀 isalnum
🚀 isascii
🚀 isprint
🚀 toupper
🚀 tolower
---
🚀 calloc
#include <stdlib.h>

void *
calloc(size_t count, size_t size);
구현 코드

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count + size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
✔️ Description
The calloc() function contiguously allocates enough space for count
objects that are size bytes of memory each and returns a pointer to
the allocated memory. The allocated memory is filled with bytes of
value zero.
calloc()함수는 malloc()함수와 마찬가지로 size크기(바이트)의 count개수만큼 바이트를 할당한다.
malloc과 달리 전부 0으로 초기화한다.
✔️ Return
할당된 메모리 주소를 반환한다.

⁉️ Notice
🚀 strdup
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
구현 코드

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count + size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
✔️ Description
The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it. The pointer may subsequently be used as an argument to the function free(3). If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
strdup()함수는 s1이 복사되어 충분히 들어갈만한 공간을 확보하고, 문자열을 복사한다.
공간은 str길이 + 1 만큼 확보되어야 한다.
✔️ Return
복사된 문자열의 주소를 반환한다. 에러 발생시 NULL을 반환한다.

⁉️ Notice
함수 사용 시, free 함수 등으로 메모리 해제를 하여야 한다.
🚀 ft_substr
char *ft_substr(char const *s, unsigned int start, size_t len)
구현 코드

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	l;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (len > ft_strlen(s))
		l = ft_strlen(s);
	else
		l = len;
	ptr = (char *)malloc(sizeof(char) * (l + 1));
	if (!ptr)
		return (0);
	if (l == 0)
		ptr[0] = 0;
	else
		ft_strlcpy(ptr, (char *)(s + start), l + 1);
	return (ptr);
}
✔️ Description
Allocates (with malloc(3)) and returns a substring from the string s.
The substring begins at index start and is of maximum size len
문자열[start] 에서부터 len만큼의 길이만큼 하위문자열을 복제하여 반환한다.
✔️ Return
하위문자열을 반환한다.

문자열의 길이보다 start 값이 클 경우 빈 문자열을 반환한다.

복사할 문자열의 길이가 len보다 짧으면 그만큼만 복사 후 반환한다. (문자열 할당 길이는 변동 x)

⁉️ Notice
🚀 ft_strjoin
char	*ft_strjoin(char const *s1, char const *s2)
구현 코드

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(ptr = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_memcpy(ptr, s1, s1_len);
	ft_strlcpy(ptr + s1_len, (char *)s2, s2_len + 1);
	return (ptr);
}
✔️ Description
Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
새로운 공간을 할당하여 s1, s2를 연결한 문자열을 저장한 뒤 반환한다.
✔️ Return
s1과 s2를 연결한 새로운 문자열을 반환한다.

⁉️ Notice
s1, s2 전부 널이면 0을 반환한다.
하나만 널일경우 나머지 문자열만 복제하여 반환한다.
🚀 ft_strtrim
char	*ft_strtrim(char const *s1, char const *set)
구현 코드

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start_ptr;
	char	*end_ptr;
	char	*answer;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start_ptr = (char *)s1;
	while (*start_ptr && ft_strchr(set, *start_ptr))
		start_ptr++;
	if (!(*start_ptr))
		return (ft_strdup(""));
	end_ptr = (char *)s1;
	while (*end_ptr)
		end_ptr++;
	end_ptr--;
	while (start_ptr < end_ptr && ft_strchr(set, *end_ptr))
		end_ptr--;
	if (start_ptr >= end_ptr)
		return (ft_strdup(""));
	if (!(answer = (char *)malloc((end_ptr - start_ptr + 1) + 1)))
		return (0);
	ft_strlcpy(answer, start_ptr, (end_ptr - start_ptr + 1) + 1);
	return (answer);
}
✔️ Description
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
s1에서 문자열의 시작과 끝에서 set에 지정된 문자들을 제거한 문자열을 새로 복제하여 반환한다.
✔️ Return
위 참고

⁉️ Notice
s1이 널이면 0을 반환한다.
set이 널이면 s1을 복제하여 반환한다.
문자열 전체가 아님을 유의한다.
🚀 ft_split
char			**ft_split(char const *s, char c)
구현 코드

static size_t	get_strs_size(char const *s, char c)
{
	size_t		size;
	int			flag;

	size = 1;
	flag = 0;
	while (*s)
	{
		if (*s != c)
			break ;
		s++;
	}
	while (*s)
	{
		if (*s == c)
		{
			if (*(s + 1) != c && *(s + 1) != 0)
				size++;
		}
		s++;
	}
	return (size);
}

static void		set_all_memory_null(char **strs, size_t index)
{
	size_t	i;

	i = 0;
	while (i < index)
		free(strs[i++]);
	free(strs);
	return ;
}

char			**ft_split(char const *s, char c)
{
	char	**strs;
	char	*patrol;
	size_t	index;

	index = 0;
	if (!(strs = (char **)malloc(sizeof(char *) * (get_strs_size(s, c) + 1))))
		return (0);
	while (*s)
		if (*s != c)
		{
			patrol = (char *)s;
			while (*patrol && *patrol != c)
				patrol++;
			if (!(strs[index] = (char *)malloc(patrol - s + 1)))
			{
				set_all_memory_null(strs, index - 1);
				return (0);
			}
			ft_strlcpy(strs[index++], (char *)s, patrol - s + 1);
			s = patrol;
		}
		else
			s++;
	strs[index] = 0;
	return (strs);
}
✔️ Description
Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.
구분문자 c를 활용하여, s문자열을 분할하고 이차원 배열에 저장하여 반환한다. 이때 배열은 null로 끝나야 한다.
✔️ Return
맨 끝에 null이 들어간 이차원 배열.

⁉️ Notice
이차원배열의 개념이 어렵다면, 문자열이 나열된 배열이라 생각하자.
libft에서 가장 오래 걸리는 문제들 중 하나임을 유의하자.
🚀 ft_itoa
char		*ft_itoa(int n)
구현 코드

static int	get_number_digits(int n)
{
	int		answer;

	answer = 0;
	if (n <= 0)
		answer++;
	while (n)
	{
		answer++;
		n = n / 10;
	}
	return (answer);
}

static int	get_abs_num(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

char		*ft_itoa(int n)
{
	int		len;
	int		minus_flag;
	char	*result;

	minus_flag = 1;
	if (n < 0)
		minus_flag *= -1;
	len = get_number_digits(n);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len--] = 0;
	while (len >= 0)
	{
		result[len] = get_abs_num(n % 10) + '0';
		n = n / 10;
		len--;
	}
	if (minus_flag == -1)
		result[0] = '-';
	return (result);
}
✔️ Description
Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
인수로 받은 정수를 문자열로 치환하여 반환한다. 음수가 고려되어야 한다.
✔️ Return
문자열

⁉️ Notice
🚀 ft_strmapi
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
구현 코드

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	i = 0;
	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = 0;
	return (result);
}
✔️ Description
Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
문자열 s를 복제하는데, 내부 데이터를 문자열 s의 각 데이터를 f에 넣어 받은 값으로 채운다.
s[0] ⇒ t[f(s[0])]
✔️ Return
복제된 문자열

⁉️ Notice
함수포인터에 대해 알아보자.
🚀 ft_putchar_fd
void	ft_putchar_fd(char c, int fd)
구현 코드

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
✔️ Description
Outputs the character ’c’ to the given file descriptor.
지정된 파일 설명자에 문자 'c'를 출력한다.
✔️ Return
⁉️ Notice
파일 디스크립터에 대해 알아보자.
🚀 ft_putstr_fd
void	ft_putstr_fd(char *s, int fd)
구현 코드

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}
✔️ Description
Outputs the string ’s’ to the given file descriptor.
지정된 파일 설명자에 문자열 's'를 출력한다.
✔️ Return
⁉️ Notice
파일 디스크립터에 대해 알아보자.
🚀 ft_putendl_fd
void	ft_putendl_fd(char *s, int fd)
구현 코드

void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
✔️ Description
Outputs the string ’s’ to the given file descriptor. followed by a newline.
지정된 파일 설명자에 문자열 's'를 출력하고 마지막에 개행을 추가한다.
✔️ Return
⁉️ Notice
파일 디스크립터에 대해 알아보자.
🚀 ft_putnbr_fd
void		ft_putnbr_fd(int n, int fd)
구현 코드

static void	print_number(unsigned int num, int fd)
{
	char c;

	if (num <= 0)
		return ;
	print_number(num / 10, fd);
	c = num % 10 + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (fd < 0)
		return ;
	if (n < 0)
		write(fd, "-", 1);
	else if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n == -2147483648)
		num = 2147483648;
	else
	{
		if (n < 0)
			n *= -1;
		num = (unsigned int)n;
	}
	print_number(num, fd);
}
✔️ Description
Outputs the integer ’n’ to the given file descriptor.
주어진 파일 설명자에 정수 'n'을 출력한다.
✔️ Return
⁉️ Notice
파일 디스크립터에 대해 알아보자.
아래 코드부터는 구조체를 사용한 함수들이다.

typedef struct	   	s_list
{
	void			        *content;
		struct  s_list	*next;
}				           	t_list;
🚀 ft_lstnew
t_list	*ft_lstnew(void *content)
구현 코드

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (0);
	new->content = content;
	new->next = 0;
	return (new);
}
✔️ Description
Allocates (with malloc(3)) and returns a new lement. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
새 요소(이하 노드)에 content는 매개변수로 받은 content, next는 널로 초기화하여 반환한다.
✔️ Return
새 노드

⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
🚀 ft_lstadd_front
void	ft_lstadd_front(t_list **lst, t_list *new)
구현 코드

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
✔️ Description
Adds the element ’new’ at the beginning of the list.
(연결리스트) 시작 부분에 new노드를 추가한다.
✔️ Return
⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
🚀 ft_lstsize
int		ft_lstsize(t_list *lst)
구현 코드

int		ft_lstsize(t_list *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
✔️ Description
Counts the number of elements in a list.
리스트의 노드 수를 반환한다.
✔️ Return
노드의 개수

⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
🚀 ft_lstlast
t_list	*ft_lstlast(t_list *lst)
구현 코드

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
✔️ Description
Returns the last element of the list.
리스트의 마지막 노드를 반환한다.
✔️ Return
마지막 노드

⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
🚀 ft_lstadd_back
void	ft_lstadd_back(t_list **lst, t_list *new)
구현 코드

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
}
✔️ Description
Adds the element ’new’ at the end of the list.
리스트 끝에 new노드를 추가합니다.
✔️ Return
⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
🚀 ft_lstdelone
void	ft_lstdelone(t_list *lst, void (*del)(void *))
구현 코드

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
✔️ Description
Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed.
노드를 매개변수로 취하는 del함수를 사용하여 노드의 콘텐츠 메모리를 해제하고, 노드를 free한다. next의 메모리를 free해서는 안된다.
✔️ Return
⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
함수포인터에 대해 알아보자.
del함수가 콘텐츠를 free하므로 콘텐츠에 관한 free는 고려하지 않는다.
🚀 ft_lstclear
void	ft_lstclear(t_list **lst, void (*del)(void *))
구현 코드

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*now;
	t_list	*next;

	now = *lst;
	while (now)
	{
		next = now->next;
		ft_lstdelone(now, del);
		now = next;
	}
	*lst = 0;
}
✔️ Description
Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
리스트의 노드들을 전부 삭제(free)해야한다.
노드 삭제 시 노드 내 컨텐츠 또한 삭제(free)되어야 한다.
✔️ Return
⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
함수포인터에 대해 알아보자.
이전 문제를 잘 활용한다.
🚀 ft_lstiter
void	ft_lstiter(t_list *lst, void (*f)(void *))
구현 코드

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
✔️ Description
Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
연결리스트 lst의 각 노드의 콘텐츠를 f함수의 매개변수로 활용하여 f함수를 호출한다.
✔️ Return
⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
함수포인터에 대해 알아보자.
🚀 ft_lstmap
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
구현 코드

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp_result;

	if (!(result = ft_lstnew(f(lst->content))))
		return (0);
	temp_result = result;
	lst = lst->next;
	while (lst)
	{
		if (!(temp_result->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		temp_result = temp_result->next;
		lst = lst->next;
	}
	return (result);
}
✔️ Description
Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.
리스트를 복제하여 새로운 리스트를 만든다.
이때, 새로운 리스트의 content는 f함수의 반환값으로, 매개변수는 복제할 리스트의 content를 사용한다.
✔️ Return
⁉️ Notice
구조체와 연결리스트에 대해 알아보자.
함수포인터에 대해 알아보자.

출처 : https://velog.io/@tmdgks2222/libft#-calloc
