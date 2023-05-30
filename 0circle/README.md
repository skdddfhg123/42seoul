## 선행 지식

[파일 디스크립터(FD)](https://www.notion.so/FD-0768f9536b994b6181a408835aa528b0)

[함수포인터](https://www.notion.so/8ef10041b0f046579c9225efbb7c265d)

## 과제의 목표

- libc 함수들을 직접 만들어보자.
- 함수를 man에 정의 되어 있는 대로 만들되, ‘restrict’을 프로토타입에 사용하는 것은 금지된다.

## 작성 코드 및 설명

## 필수 파트

## Part 1

### memset

---

### ✔️ 함수의 원형

```c
void *memset(void *b, int c, size_t len);
```

---

- **구현 코드**
    
    ```c
    void    *ft_memset(void *b, int c, size_t len)
    {
        size_t          i;
        char            *s_ptr;
        unsigned char   data;
    
        i = 0;
        data = (unsigned char)c; 
    // 위에서 언급했듯 기존 함수의 내부에서 unsigned char로 변환되어 저장되기에 
    // 캐스팅해서 데이터를 넣는 방식으로 짬.
        s_ptr = (char*)b; 
    // gcc에서는 void포인터를 자동적으로 char, unsigned char 크기만큼 연산하지만
    // c언어 표준을 맞추기 위해 캐스팅함.
        while (i < len)
        {
            s_ptr[i] = data;
            i++;
        }
        return b;
    }
    ```
    

---

**`man`**에서 **"memset() 함수는 값 c의 len 바이트(부호되지 않은 문자로 변환)를 문자열 b에 기록합니다"** 이렇게 정의한다.
쉽게 말하자면, memset함수는 **어떤 메모리의 시작점에서 값을 원하는 크기만큼 특정 값으로 세팅 할 수 있는 함수**이다.

---

### **✔️ Description**

- `unsigned char`는 모든 `bit`를 투명하게 볼 수 있다. (부호비트가 없기 때문)
- 따라서, 임의의 메모리에 바이트 단위로 접근해 값을 다룰 때, 반드시 `unsigned char`를 사용한다.
- `0`, `-1`, `0x3F`, `0x7F`를 제외한 나머지 값은 원하는 값으로 초기화할 수 없다.

헤더 파일은 `man`에서는 **string.h**만 적혀있지만,  **memory.h**에도 memset함수가 정의 되어 있어 둘 중 하나를 사용하면 된다.

### ✔️ Return

성공 시 첫번째 인자로 들어간 `ptr`을 반환, 실패 시 `NULL`을 반환한다.

### ⁉️ Notice

- `memset()`과 `bzero()` 모두 `unsigned char`로 캐스팅하는 과정이 있다.
- 1바이트 변수를 제외한 변수를 초기화 할 시, `0`이외의 값으로 초기화 안됨.

```c
int n;
memset(&n, 1, sizeof(int));
//n = [00000001000000010000000100000001] = 16843009
```

- new, malloc 등 동적 배열 생성하는 변수가 있는 struct, class는 memset으로 초기화 안됨.
사용 시, 각각 분리하여 초기화.
- 헤더파일은 `man`에서는 **string.h**만 적혀있지만, **memory.h**에도 `memset()`함수가 정의 되어 있어 둘 중 하나를 사용하면 된다.

### bzero

---

### ✔️ 함수의 원형

```c
void    bzero(void *s, size_t n)
```

---

- **구현 코드**
    
    ```c
    void	ft_bzero(void *s, size_t n)
    {
    	size_t			i;
    	unsigned char	*s_ptr;
    
    	s_ptr = (unsigned char*)s;
    	i = 0;
    	while (i < n)
    	{
    		s_ptr[i] = 0;
    		i++;
    	}
    }
    ```
    

---

### ✔️ Description

- The bzero() function writes n zeroed bytes to the string s.  If n is zero, bzero() does
nothing.
- bzero()함수는 `s`가 가리키는 메모리로부터 `n`바이트만큼 `0`값을 채운다.

### ✔️ Return

`none`

### ⁉️ Notice

- `memset()`과 `bzero()` 모두 `unsigned char`로 캐스팅하는 과정이 있다.
- 헤더파일은 `memset()`과 마찬가지로 `man`에서는 **string.h**만 적혀있지만, **memory.h**에도 `memset()`함수가 정의 되어 있어 둘 중 하나를 사용하면 된다

### memcpy

---

### ✔️ 함수의 원형

```c
void *memcpy(void *restrict dst, const void *restrict src, size_t n);
```

---

- **구현 코드**
    
    ```c
    void	*ft_memcpy(void *dst, const void *src, size_t n) 
    // 여기서 restrict을 뺀 이유는 c99 표준을 따르게 위해 뺐습니다.
    {	
            size_t			i;
            unsigned char  	        *dst_ptr;
    	unsigned char	        *src_ptr;
    
            dst_ptr = (unsigned char *)dst; 
    // size_t n이 바이트 단위를 기준으로 들어오기 때문에 
    // dst의 void*를 char*으로 캐스팅 해주었습니다.
    	src_ptr = (unsigned char *)src;
    	i = 0;
    	if (dst_ptr == 0 && src_ptr == 0)
    		return (0);
    	while (i < n)
    	{
    		dst_ptr[i] = src_ptr[i];
    		i++;
    	}
    	return (dst);
    }
    ```
    

---

<aside>
💡 ❗42에서 restrict 사용 불가

</aside>

### ✔️ Restrict?

- restrict 포인터는 메모리 접근에 관련된 최적화 기능 (C99 표준).
- 포인터가 하나만 가리키고 있다는 것을 컴파일러가 알면, 메모리 복사 없이 비트연산자를 이용해 연산한다.
- 알맞은 조건이 적용되면, 성능이 비약적으로 증가한다.

### ✔️ Description

- The memcpy() function copies n bytes from memory area src to memory area dst.  If dst and
src overlap, behavior is undefined.  Applications in which dst and src might overlap should
use memmove(3) instead.
- `memcpy()`함수는 `src`가 가리키는 메모리 주소로부터 `n`바이트 크기(길이)만큼 `dst`메모리에 복사한다.

### ✔️ Return

`dst`를 반환한다.

### ⁉️ Notice

- `memcpy()`함수는 **n**바이트를 **source**의 메모리 영역에서 **destination**의 메모리 영역으로 복사하는 함수이다.
- 보통 `memcpy()`는 `mememove()`와 많이 비교가 되는데 `memcpy()`함수의 경우에는 **dstination**과 **source**의 메모리 영역이 겹치면 동작하지 않는다. 따라서 메모리 영역이 겹치는 경우에는 `memcpy()`대신 `memmove()`를 사용해야 한다.

### memccpy

---

### ✔️ 함수의 원형

```c
void *  memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
```

---

- **구현 코드**
    
    ```c
    void	*ft_memccpy(void *d, const void *s, int c, size_t n)
    {
    	size_t			i;
    	unsigned char	data;
    	unsigned char	*dst_ptr;
    	unsigned char	*src_ptr;
    
    	dst_ptr = (unsigned char*)d;
    	src_ptr = (unsigned char*)s;
    	data = (unsigned char)c;
    	i = 0;
    	if (!d && !s)
    		return (0);
    	while (i < n)
    	{
    		if (src_ptr[i] == data)
    		{
    			dst_ptr[i] = src_ptr[i];
    			return (&dst_ptr[i + 1]);
    		}
    		dst_ptr[i] = src_ptr[i];
    		i++;
    	}
    	return (0);
    }
    ```
    

---

### ✔️ Description

- The memccpy() function copies bytes from string src to string dst.  If the character c (as converted to an unsigned char) occurs in the string src, the copy stops and a pointer to the
byte after the copy of c in the string dst is returned.  Otherwise, n bytes are copied, and
a NULL pointer is returned.
- `memccpy()`함수는 `src`가 가리키는 메모리 주소로부터 `n`바이트 크기(길이)만큼 `dst`메모리에 복사한다. 단, 문자 c를 만나게 되면 `c까지 복사`하고 중단한다.

### ✔️ Return

`dest`에서 `c`의 다음 위치 (복사가 끝난 다음 메모리주소)를 리턴한다. `c`를 만나지 않는다면 `n`만큼 복사하고 **NULL**을 반환한다.

### ⁉️ Notice

- `c`를 1바이트 크기가 아닌 자료형을 사용하여 찾을 경우, 문제가 생긴다.
memccpy함수는 1바이트 메모리만 비교하여 찾기 때문이다.
굳이 int형을 다뤄야 한다면, 1 ~ 255 범위 내 사용하는 것이 좋다.
- `memccpy()`함수는 문자열 **source**에서 문자열 **destination**으로 **n**바이트를 복사합니다. `memcpy()`함수와 다른 점은 `memccpy()`함수는 문자열 **source**에서 **unsigned char**로 변환한 c가 발생하면 복사를 멈추고 문자열의 c 복사 후 바이트에 대한 포인터 **destination**이 변환됩니다. 그렇지 않으면 **n**바이트가 복사되고 **NULL**포인터가 반환됩니다.

<aside>
💡 **동작이 정의되지 않았으므로 소스 문자열과 대상 문자열이 겹치지 않아야 합니다.**

</aside>

### memmove

---

### ✔️ 함수의 원형

```c
void *     memmove(void *dst, const void *src, size_t len);
```

---

- **구현 코드**
    
    ```c
    void	*ft_memmove(void *dst, const void *src, size_t len)
    {
    	unsigned char	*dst_p;
    	unsigned char	*src_p;
    
    	if (dst == src || !len)
    		return (dst);
    	dst_p = (unsigned char *)dst;
    	src_p = (unsigned char *)src;
    	if (dst < src)
    		ft_memcpy(dst_p, src_p, len);
    	else
    	{
    		dst_p += len;
    		src_p += len;
    		while (len--)
    			*--dst_p = *--src_p;
    	}
    	return (dst);
    }
    ```
    

---

### ✔️ Description

- The memmove() function copies len bytes from string src to string dst.  The two strings may
overlap; the copy is always done in a non-destructive manner.
- memmove()함수는 `len`바이트만큼 `src` 메모리에서 `dest`로 복사한다.
- 복사는 항상 비파괴 방식으로 진행된다.
- 즉, src배열은 src와 dest메모리 영역과 겹치지 않는 메모리 영역부터 먼저 복사한다.
- src 주소가 dest보다 `크다면`, 순차적으로 데이터를 복사하면 된다.
src 주소가 dest보다 `작다면`, src 마지막 바이트부터 `dest + len`에 복사한다.

### ✔️ Return

`dest` 반환.

### ⁉️ Notice

- 한 배열 안에서 복사를 수행하거나, `src` 시작주소가 `dest` 시작 주소보다 앞에 있으면서 `두 주소 차이가 len보다 작으면` 발생한다.

### memchr

---

### ✔️ 함수의 원형

```c
void * memchr ( const void * ptr, int value, size_t num );
```

---

- **구현 코드**
    
    ```c
    void	*ft_memchr(const void *s, int c, size_t n)
    {
    	size_t			i;
    	unsigned char	data;
    	unsigned char	*s_ptr;
    
    	i = 0;
    	data = (unsigned char)c;
    	s_ptr = (unsigned char*)s;
    	while (i < n)
    	{
    		if (s_ptr[i] == data)
    		{
    			return (&s_ptr[i]);
    		}
    		i++;
    	}
    	return (0);
    }
    ```
    

---

### ✔️ Description

- The memchr() function locates the first occurrence of c (converted to an unsigned char) in
string s.
- memchr()함수는 `s`가 가리키는 메모리 주소로부터 `n바이트` 중 처음으로 `c`와 일치하는 값의 주소를 리턴한다.

### ✔️ Return

`c와 일치하는 값의 주소`를 리턴한다. 찾지 못하면 `NULL`을 반환한다.

### ⁉️ Notice

- `memchr()`은 **ptr**이 가리키는 메모리의 처음 **num**바이트 중에서 처음으로 **value**와 일치하는 값(문자)의 주소를 반환하는 함수이다.

### memcmp

---

### ✔️ 함수의 원형

```c
int memcmp ( const void * ptr1, const void * ptr2, size_t num );
```

---

- **구현 코드**
    
    ```c
    int		ft_memcmp(const void *s1, const void *s2, size_t n)
    {
    	size_t			i;
    	unsigned char	*s1_ptr;
    	unsigned char	*s2_ptr;
    	int				res;
    
    	i = 0;
    	s1_ptr = (unsigned char*)s1;
    	s2_ptr = (unsigned char*)s2;
    	while (i < n)
    	{
    		if (s1_ptr[i] - s2_ptr[i] != 0)
    		{
    			res = (int)s1_ptr[i] - (int)s2_ptr[i];
    			return (res);
    		}
    		i++;
    	}
    	return (0);
    }
    ```
    

---

### ✔️ Description

- The memcmp() function compares byte string s1 against byte string s2.  Both strings are
assumed to be n bytes long.
- `s1`이 가리키는 `n바이트`만큼의 데이터와 `s2`가 가리키는 `n 바이트`만큼의 데이터를 비교하여, 같으면 0을 리턴하고 다르면 0이 아닌 값을 리턴한다.

### ✔️ Return

위 기재

### ⁉️ Notice

- 함수 사용 시 오버플로우에 주의. (n은 버퍼보다 작거나 같게)
- `strcmp()`와 차이점은, 두 문자열 중 하나가 끝나더라도 서로 다른 값이 나오거나 n개가 될 때까지 비교한다.
따라서 s1, s2 모두 **NULL**값이 나오면 남은 카운트 관계 없이 0을 반환한 `strcmp()`와 차이가 있다.

### strlen

---

### ✔️ 함수의 원형

```c
size_t strlen ( const char * str );
```

---

- **구현 코드**
    
    ```c
    size_t	ft_strlen(const char *s)
    {
    	size_t	i;
    
    	i = 0;
    	while (s[i])
    		i++;
    	return (i);
    }
    ```
    

---

### ✔️ Description

- `strlen()`함수는 문자열을 인자로 받아, 그 문자열의 길이를 구해 반환하는 함수이다.

### ✔️ Return

문자열의 길이

### strlcpy

---

### ✔️ 함수의 원형

```c
size_t strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
```

---

- **구현 코드**
    
    ```c
    size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
    {
    	size_t		i;
    	size_t		src_len;
    
    	i = 0;
    	src_len = 0;
    	if (src == 0)
    		return (0);
    	while (src[src_len])
    		src_len++;
    	if (dstsize)
    	{
    		while (src[i] && i + 1 < dstsize) 
    // 여기서 dstsize는 null값이 포함되어 있기 때문에 i에 1을 더해 연산
    		{
    			dst[i] = src[i];
    			i++;
    		}
    		dst[i] = 0;
    	}
    	return (src_len); 
    // 반환 값이 dstsize보다 작을 경우 출력 문자열이 잘린 것이고, 
    // 이것은 발신자의 책임으로 보고 있음.
    }
    ```
    

---

### ✔️ Description

- The strlcpy() and strlcat() functions copy and concatenate strings with the same input
parameters and output result as snprintf(3).  They are designed to be safer, more consis-
tent, and less error prone replacements for the easily misused functions strncpy(3) and
strncat(3).
- strlcpy() and strlcat() take the full size of the destination buffer and guarantee NUL-ter-
 mination if there is room.  Note that room for the NUL should be included in dstsize.
- strlcpy() copies up to dstsize - 1 characters from the string src to dst, NUL-terminating
 the result if dstsize is not 0.
- strlcpy() 함수는 실수하지 않도록 디자인되었다.
- `dstsize`가 0이 아닌 경우 `dstsize - 1`만큼 문자를 `src`에서 `dst`로 복사 후 `null을 포함`하여 종료한다.

### ✔️ Return

- 문자열의 길이를 반환(여기서 길이는 NULL을 포함한 길이)

### ⁉️ Notice

- `strlcpy()`의 반환값은 만드려는 문자열의 총 길이이다. 따라서 **src**의 길이를 반환한다. 반환 값이 **dstsize**보다 작을 경우 출력 문자열이 잘린 것이다. 
원형 함수에서는 이것을 **발신자의 책임**으로 보고 있습니다.

### strchr

---

### ✔️ 함수의 원형

```c
char *strchr(const char *s, int c);
```

---

- **구현 코드**
    
    ```c
    char    *ft_strchr(const char *s, int c)
    {
        unsigned char   data;
        int             i;
        i = 0;
        data = (unsigned char)c;
        while (s[i])
        {
            if (s[i] == data)
                return ((char *)&s[i]);
            i++;
        }
        if (data == '\0') // NULL을 찾는 경우 예외 처리
            return ((char *)&s[i]);
        return (0);
    }
    ```
    

---

### ✔️ Description

- The strchr() function locates the first occurrence of c (converted to a char) in the string
pointed to by s.  The terminating null character is considered to be part of the string;
therefore if c is \\0', the functions locate the terminating\0'.
- `strchr()` 함수는 **s**에서 **c**문자가 가장 먼저 나타나는 곳을 찾는다.

### ✔️ Return

- `c`의 주소를 리턴한다. 찾는 문자가 `s`안에 없다면 `NULL포인터`를 리턴한다.

### strrchr

---

### ✔️ 함수의 원형

```c
char *strrchr(const char *s, int c);
```

---

- **구현 코드**
    
    ```c
    char    *ft_strrchr(const char *s, int c)
    {
        unsigned char   data;
        int             i;
        i = ft_strlen(s);
        data = (unsigned char)c;
        if (data == '\0') // 찾고자 하는 문자가 null일 경우 예외처리
            return ((char *)&s[i]);
        while (--i >= 0) // 문자열로 진행하기에 i를 1 줄여 시작
        {
            if (s[i] == data)
                return ((char *)&s[i]);
        }
        return (0);
    }
    ```
    

---

### ✔️ Description

- The strchr() function locates the first occurrence of c (converted to a char) in the string
pointed to by s.  The terminating null character is considered to be part of the string;
therefore if c is \\0', the functions locate the terminating\0'.
- `strrchr()`함수는 문자열에서 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾고, 이를 가리키는 포인터를 반환하는 함수입니다.

### ✔️ Return

- 일치하는 문자가 있을 경우 문자열에서 가장 마지막으로 나타나는 위치의 포인터를 반환하고 없을 경우에는 `NULL포인터`를 반환합니다.

### strnstr

---

### ✔️ 함수의 원형

```c
char *    strnstr(const char *haystack, const char *needle, size_t len);
```

---

- **구현 코드**
    
    ```c
    char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
    {
        size_t      i;
        if (!(*needle))
            return ((char *)haystack);
        while (*haystack && len)
        {
            i = 0;
            while (haystack[i] == needle[i] && i < len)
            {
                i++;
                if (!(needle[i]))
                    return ((char *)&haystack[0]);
            }
            haystack++;
            len--;
        }
        return (0);
    }
    ```
    

---

### ✔️ Description

- The strnstr() function locates the first occurrence of the null-terminated string needle in
the string haystack, where not more than len characters are searched.  Characters that
appear after a `\0' character are not searched.  Since the strnstr() function is a FreeBSD
specific API, it should only be used when portability is not a concern.
- 문자열 내에서 부분 문자열을 탐색하는 함수이다.

### ✔️ Return

`needle`이 처음 나타나는 주소를 리턴한다. 만약 없다면 `NULL`을 리턴한다.

### strncmp

---

### ✔️ 함수의 원형

```c
int    strncmp(const char *s1, const char *s2, size_t n);
```

---

- **구현 코드**
    
    ```c
    int     ft_strncmp(const char *s1, const char *s2, size_t n)
    {
        size_t          i;
        if (n < 1)
            return (0);
        i = 0;
        while (i + 1 < n && s1[i] == s2[i] && s1[i] && s2[i])
            i++;
        return ((int)((unsigned char)s1[i] - (unsigned char)s2[i]));
    }
    ```
    

---

### ✔️ Description

- The strnstr() function locates the first occurrence of the null-terminated string needle in
the string haystack, where not more than len characters are searched.  Characters that
appear after a `\0' character are not searched.  Since the strnstr() function is a FreeBSD
specific API, it should only be used when portability is not a concern.
- 인자로 들어온 두 개의 문자열을 n의 크기만큼 비교하여 문자열이 완전히 같다하면 0 반환, 다르면 음수 혹은 양수를 반환하는 함수이다.

### ✔️ Return

- 문자열을 비교하여 같으면 0, 다르면 음수 또는 양수를 반환한다.

### ⁉️ Notice

- `strncmp()` 의 인자로 들어오는 s1, s2의 비교하는 n보다 길이가 작을 시에 정확한 비교를 할 수 없다는 점을 주의해야 한다.

### atoi

---

### ✔️ 함수의 원형

```c
int    atoi(const char *str);
```

---

- **구현 코드**
    
    ```c
    static int  check_range(unsigned long long result, int n_check)
    {
        if (result > LLONG_MAX - 1 && n_check == -1)
            return (0);
        if (result > LLONG_MAX && n_check == 1)
            return (-1);
        return (result * n_check);
    }
    
    int         ft_atoi(const char *str)
    {
        int                 i;
        int                 n_check;
        unsigned long long  result;
        i = 0;
        result = 0;
        while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
            i++;
        n_check = 1;
        if (str[i] == '-' || str[i] == '+')
        {
            if (str[i] == '-')
                n_check *= -1;
            i++;
        }
        while (str[i] && str[i] >= '0' && str[i] <= '9')
        {
            result = (result * 10) + (str[i] - '0');
            i++;
        }
        return (check_range(result, n_check));
    }
    ```
    

---

### ✔️ Description

- atoi함수는 문자열을 정수 타입으로 변환하는 함수입니다.

### ✔️ Return

- 성공적으로 변환을 했다면 **int**값을 리턴하고, 만일 변환을 실패했다면 **0**을 반환합니다. 만일 변환을 하였지만 그 값이 **long long max**보다 크다면 **-1**을 반환 **long long min**보다 작다면 **0**을 반환합니다.

### isalpha

---

### ✔️ 함수의 원형

```c
int    isalpha(int c);
```

---

- **구현 코드**
    
    ```c
    int     ft_isalpha(int c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return (1);
        return (0);
    }
    ```
    

---

### ✔️ Description

- isalpha함수는 들어온 인자가 알파벳인지 아닌지 확인하여 알파벳이면 0이아닌 양의 정수를 반환하는 함수이다.

### ✔️ Return

- 알파벳이면 1, 아닐 시 0을 반환한다.

### isdigit

---

### ✔️ 함수의 원형

```c
int    isdigit(int c);
```

---

- **구현 코드**
    
    ```c
    int     ft_isdigit(int c)
    {
        if (c >= '0' && c <= '9')
            return (1);
        return (0);
    }
    ```
    

---

### ✔️ Description

- isdigit함수는 들어온 인자가 숫자인지 아닌지 확인하여 숫자면 0이아닌 양의 정수를 반환하는 함수이다.

### ✔️ Return

- 숫자면 1, 아닐 시 0을 반환한다.

### isalnum

---

### ✔️ 함수의 원형

```c
int    isalnum(int c);
```

---

- **구현 코드**
    
    ```c
    int     ft_isalnum(int c)
    {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9'))
            return (1);
        return (0);
    }
    ```
    

---

### ✔️ Description

- isalnum함수는 들어온 인자가 숫자나 알파벳인지 아닌지 확인하여 숫자나 알파벳이면 0이아닌 양의 정수를 반환하는 함수입니다.

### ✔️ Return

- 숫자나 알파벳이면 1, 아닐 시 0을 반환한다.

### isascii

---

### ✔️ 함수의 원형

```c
int    isascii(int c);
```

---

- **구현 코드**
    
    ```c
    int     ft_isascii(int c)
    {
        if (c >= 00 && c <= 0177) // 8진법
            return (1);
        return (0);
    }
    ```
    

---

### ✔️ Description

- isascii함수는 들어온 인자가 아스키 값인지 아닌지 확인하여 아스키 값이면 0이아닌 양의 정수를 반환하는 함수입니다.

### ✔️ Return

- 아스키 값이면 1, 아닐 시 0을 반환한다.

### isprint

---

### ✔️ 함수의 원형

```c
int    isprint(int c);
```

---

- **구현 코드**
    
    ```c
    int     ft_isprint(int c)
    {
        if (c >= 040 && c <= 0176) // 8진수
            return (1);
        return (0);
    }
    ```
    

---

### ✔️ Description

- isprint함수는 들어온 인자가 출력 가능한 값인지 아닌지 확인하여 출력 가능한 값이면 0이아닌 양의 정수를 반환하는 함수입니다.

### ✔️ Return

- 프린터블하면 1, 아닐 시 0을 반환한다.

### toupper

---

### ✔️ 함수의 원형

```c
int    toupper(int c);
```

---

- **구현 코드**
    
    ```c
    int		ft_toupper(int c)
    {
    	if (c >= 'a' && c <= 'z')
    		return (c - 32);
    	return (c);
    }
    ```
    

---

### ✔️ Description

- toupper함수는 들어온 인자가 소문자인지 아닌지 확인하여 소문자면 대문자로 변환하는 함수입니다.

### ✔️ Return

- c값이 소문자일 경우 대문자로 반환해주고, 아닐 시에는 c값을 그대로 반환

### tolower

### ✔️ 함수의 원형

```c
int    tolower(int c);
```

---

- **구현 코드**
    
    ```c
    int     ft_tolower(int c)
    {
        if (c >= 'A' && c <= 'Z')
            return (c + 32);
        return (c);
    }
    ```
    

---

### ✔️ Description

- tolower함수는 들어온 인자가 소문자인지 아닌지 확인하여 소문자면 대문자로 변환하는 함수입니다.

### ✔️ Return

- c값이 대문자일 경우 소문자로 반환해주고, 아닐 시에는 c값을 그대로 반환

### calloc

---

### ✔️ 함수의 원형

```c
void *    calloc(size_t count, size_t size);
```

---

- **구현 코드**
    
    ```c
    void    *ft_calloc(size_t count, size_t size)
    {
        void        *arr;
        if (!(arr = (void *)malloc(size * count)))
            return (0);
        ft_memset(arr, 0, count * size);
        return (arr);
    }
    ```
    

---

### ✔️ Description

- The calloc() function contiguously allocates enough space for count
objects that are size bytes of memory each and returns a pointer to
the allocated memory.  The allocated memory is filled with bytes of
value zero.
- calloc()함수는 malloc()함수와 마찬가지로 `size크기(바이트)`의 `count개수`만큼 바이트를 할당한다.
- malloc과 달리 전부 `0으로 초기화`한다.

### ✔️ Return

- 할당한 성공했을 시에 메모리의 첫번째 포인터를 반환합니다. 실패시에는 널포인트를 반환합니다.

### strdup

---

### ✔️ 함수의 원형

```c
char *    strdup(const char *s1);
```

---

- **구현 코드**
    
    ```c
    char    *ft_strdup(const char *str)
    {
        char        *res;
        size_t      len;
        size_t      i;
        len = ft_strlen(str);
        i = 0;
        if (!(res = (char *)malloc(sizeof(char) * (len + 1))))
            return (0);
        while (i < len)
        {
            res[i] = str[i];
            i++;
        }
        res[i] = 0;
        return (res);
    }
    ```
    

---

### ✔️ Description

- The strdup() function allocates sufficient memory for a copy of the string s1, does the copy, and returns a pointer to it.  The pointer may subsequently be used as an argument to the function free(3). If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
- strdup()함수는 `s1`이 복사되어 충분히 들어갈만한 `공간을 확보`하고, 문자열을 `복사`한다.
- 공간은 `str길이 + 1` 만큼 확보되어야 한다.

### ✔️ Return

- 정상적으로 복제했을 경우 복제할 문자열의 `포인터`를 반환하고, 실패시에는 `NULL포인터`를 반환합니다.

### ⁉️ Notice

- 함수 사용 시, free 함수 등으로 메모리 해제를 하여야 한다.

## Part 2

### substr

---

### ✔️ 함수의 원형

```c
char *ft_substr(char const *s, unsigned int start, size_t len);
```

---

- **구현 코드**
    
    ```c
    char    *ft_substr(char const *s, unsigned int start, size_t len)
    {
        char    *res;
        size_t  s_size;
        size_t  i;
        size_t  real_len;
        if (!s) // NULL 가드
            return (0);
        real_len = len;
        s_size = ft_strlen(s);
        if (start >= s_size) 
    // 시작위치가 s의 길이보다 클 경우 빈 스트링을 할당하여 반환합니다.
            return (ft_strdup(""));
        if (len > s_size - (size_t)start) 
    // s의 길이에서 시작 지점을 뺀 값보다 len이 클 경우 그 크기를 줄여줍니다.
            real_len = s_size - (size_t)start;
        if (!(res = ((char*)malloc(sizeof(char) * (real_len + 1)))))
            return (0);
        i = 0;
        while (real_len--)
            res[i++] = s[start++];
        res[i] = 0;
        return (res);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns a substring from the string `s`.
The substring begins at index `start` and is of maximum size `len`
- 문자열[start] 에서부터 len만큼의 길이만큼 하위문자열을 복제하여 반환한다.

### ✔️ Return

- 반환값은 `하위 문자열`을 반환하고, 실패시에는 `NULL포인트`를 반환합니다.
- 시작위치가 **s**의 길이보다 클 경우 **빈 스트링을 할당**하여 반환합니다.

### strjoin

---

### ✔️ 함수의 원형

```c
char       *ft_strjoin(char const *s1, char const *s2);
```

---

- **구현 코드**
    
    ```c
    char    *ft_strjoin(char const *s1, char const *s2)
    {
        char    *str;
        size_t  s1_len;
        size_t  s2_len;
        size_t  i;
        size_t  j;
    
        if (!s1 || !s2)
            return (0);
        s1_len = ft_strlen(s1);
        s2_len = ft_strlen(s2);
        if (!(str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
            return (0);
        i = 0;
        while (i < s1_len)
        {
            str[i] = s1[i];
            i++;
        }
        j = 0;
        while (j < s2_len)
            str[i++] = s2[j++];
        str[i] = 0;
        return (str);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.
- 새로운 공간을 할당하여 s1, s2를 연결한 문자열을 저장한 뒤 반환한다.

### ✔️ Return

s1과 s2를 연결한 `새로운 문자열`을 반환한다.

### ⁉️ Notice

- s1, s2 `전부 널이면 0`을 반환한다.
- `하나만 널`일경우 `나머지 문자열만 복제`하여 반환한다.

### strtrim

---

### ✔️ 함수의 원형

```c
char *ft_strtrim(char const *s1, char const *set);
```

---

- **구현 코드**
    
    ```c
    static size_t	ft_isset(char c, char const *set)
    {
    	size_t		i;
    
    	i = 0;
    	while (set[i])
    	{
    		if (set[i] == c)
    			return (1);
    		i++;
    	}
    	return (0);
    }
    
    char			*ft_strtrim(char const *s1, char const *set)
    {
    	char		*res;
    	size_t		s_point;
    	size_t		e_point;
    	size_t		i;
    
    	if (!s1)
    		return (0);
    	e_point = ft_strlen(s1);
    	s_point = 0;
    	while (s_point < e_point && ft_isset(s1[s_point], set))
    		s_point++;
    	while (s_point < e_point && ft_isset(s1[e_point - 1], set))
    		e_point--;
    	if (!(res = (char*)malloc(sizeof(char) * (e_point - s_point + 1))))
    		return (0);
    	i = 0;
    	while (s_point < e_point)
    		res[i++] = s1[s_point++];
    	res[i] = 0;
    	return (res);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.
- s1에서 문자열의 시작과 끝에서 `set에 지정된 문자들을 제거`한 문자열을 새로 복제하여 반환한다.

### ✔️ Return

위 참고

### ⁉️ Notice

- s1이 널이면 `0`을 반환한다.
- set이 널이면 `s1을 복제`하여 반환한다.
- 문자열 전체가 아님을 유의한다.

### split

---

### ✔️ 함수의 원형

```c
char **ft_split(char const *s, char c);
```

---

- **구현 코드**
    
    ```c
    static size_t		ft_issep(char ch, char c)
    {
    	if (ch == c)
    		return (1);
    	return (0);
    }
    
    static size_t		ft_count_words(char *s, char c)
    {
    	size_t			cnt;
    
    	cnt = 0;
    	while (*s)
    	{
    		while (*s && ft_issep(*s, c))
    			s++;
    		if (*s && !ft_issep(*s, c))
    		{
    			cnt++;
    			while (*s && !ft_issep(*s, c))
    				s++;
    		}
    	}
    	return (cnt);
    }
    
    static void			*ft_mem_free(char **arr, size_t cnt)
    {
    	size_t			i;
    
    	i = 0;
    	while (i < cnt)
    	{
    		free(arr[i]);
    		i++;
    	}
    	free(arr);
    	return (0);
    }
    
    static char			*ft_malloc_word(char *s, char c, char **arr, size_t cnt)
    {
    	char			*word;
    	size_t			i;
    
    	i = 0;
    	while (s[i] && !ft_issep(s[i], c))
    		i++;
    	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
    	{
    		ft_mem_free(arr, cnt);
    		return (0);
    	}
    	i = 0;
    	while (s[i] && !ft_issep(s[i], c))
    	{
    		word[i] = s[i];
    		i++;
    	}
    	word[i] = 0;
    	return (word);
    }
    
    char				**ft_split(char const *s, char c)
    {
    	char			**arr;
    	size_t			word_num;
    	size_t			i;
    
    	if (!s)
    		return (0);
    	word_num = ft_count_words((char *)s, c);
    	if (!(arr = (char**)malloc(sizeof(char *) * (word_num + 1))))
    		return (0);
    	i = 0;
    	while (*s && i < word_num)
    	{
    		while (*s && ft_issep(*s, c))
    			s++;
    		if (*s && !ft_issep(*s, c))
    		{
    			if (!(arr[i] = ft_malloc_word((char *)s, c, arr, i)))
    				return (0);
    			i++;
    			while (*s && !ft_issep(*s, c))
    				s++;
    		}
    	}
    	arr[i] = 0;
    	return (arr);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.
- 구분문자 c를 활용하여, s문자열을 분할하고 `이차원 배열`에 저장하여 반환한다. 이때 배열은 `null`로 끝나야 한다.

### ✔️ Return

맨 끝에 null이 들어간 이차원 배열.

### ⁉️ Notice

- 이차원배열의 개념이 어렵다면, `문자열이 나열된 배열`이라 생각하자.
- libft에서 가장 오래 걸리는 문제들 중 하나임을 유의하자.

### itoa

---

### ✔️ 함수의 원형

```c
char *itoa(int value, char *string, int radix);
```

---

- **구현 코드**
    
    ```c
    static size_t		ft_digits(long long n)
    {
    	size_t			len;
    
    	len = 0;
    	if (n < 0)
    	{
    		n *= -1;
    		len++;
    	}
    	else if (n == 0)
    		return (1);
    	while (n > 0)
    	{
    		n = n / 10;
    		len++;
    	}
    	return (len);
    }
    
    static long long	ft_neg_check(long long n)
    {
    	long long		tmp;
    
    	tmp = 0;
    	if (n < 0)
    	{
    		tmp = n * -1;
    	}
    	else
    		tmp = n;
    	return (tmp);
    }
    
    char				*ft_itoa(int n)
    {
    	char			*str;
    	long long		tmp;
    	size_t			len;
    
    	if (!(tmp = ft_neg_check((long long)n)))
    		return (ft_strdup("0"));
    	len = ft_digits((long long)n);
    	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
    		return (0);
    	if (n < 0)
    		str[0] = '-';
    	str[len] = 0;
    	while (tmp > 0)
    	{
    		str[--len] = (tmp % 10) + '0';
    		tmp /= 10;
    	}
    	return (str);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
- 인수로 받은 정수를 문자열로 치환하여 반환한다. 음수가 고려되어야 한다.

### ✔️ Return

문자열

### ft_strmapi

---

### ✔️ 함수의 원형

```c
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
```

---

- **구현 코드**
    
    ```c
    char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
    {
    	char		*str;
    	size_t		i;
    	size_t		len;
    
    	if (!s || !f)
    		return (0);
    	len = ft_strlen(s);
    	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
    		return (0);
    	i = 0;
    	while (i < len)
    	{
    		str[i] = f((unsigned int)i, s[i]);
    		i++;
    	}
    	str[i] = 0;
    	return (str);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled.
- 문자열 s를 복제하는데, 내부 데이터를 문자열 s의 각 데이터를 f에 넣어 받은 값으로 채운다.
`s[0] ⇒ t[f(s[0])]`

### ✔️ Return

복제된 문자열

### ⁉️ Notice

- `함수포인터`에 대해 알아보자.

### ft_putchar_fd

---

### ✔️ 함수의 원형

```c
void	ft_putchar_fd(char c, int fd)
```

---

- **구현 코드**
    
    ```c
    void	ft_putchar_fd(char c, int fd)
    {
    	write(fd, &c, 1);
    }
    ```
    

---

### ✔️ Description

- Outputs the character ’c’ to the given file descriptor.
- 지정된 파일 설명자에 문자 'c'를 출력한다.

### ✔️ Return

### ⁉️ Notice

- 파일 디스크립터에 대해 알아보자.

### ft_putstr_fd

---

### ✔️ 함수의 원형

```c
void	ft_putstr_fd(char *s, int fd)
```

---

- **구현 코드**
    
    ```c
    void	ft_putstr_fd(char *s, int fd)
    {
    	if (!s || fd < 0)
    		return ;
    	write(fd, s, ft_strlen(s));
    }
    ```
    

---

### ✔️ Description

- Outputs the string ’s’ to the given file descriptor.
- 지정된 파일 설명자에 문자열 's'를 출력한다.

### ✔️ Return

### ⁉️ Notice

- 파일 디스크립터에 대해 알아보자.

### ft_putendl_fd

---

### ✔️ 함수의 원형

```c
void	ft_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}
```

---

- **구현 코드**
    
    ```c
    void	ft_putchar_fd(char c, int fd)
    {
    	write(fd, &c, 1);
    }
    ```
    

---

### ✔️ Description

- Outputs the string ’s’ to the given file descriptor. followed by a newline.
- 지정된 파일 설명자에 문자열 's'를 출력하고 마지막에 개행을 추가한다.

### ✔️ Return

### ⁉️ Notice

- 파일 디스크립터에 대해 알아보자.

### ft_putnbr_fd

---

### ✔️ 함수의 원형

```c
void		ft_putnbr_fd(int n, int fd)
```

---

- **구현 코드**
    
    ```c
    void	ft_putnbr_fd(int n, int fd)
    {
    	long	nb;
    
    	nb = (long)n;
    	if (nb < 0)
    	{
    		ft_putchar_fd('-', fd);
    		nb *= -1;
    	}
    	if (nb > 9)
    	{
    		ft_putnbr_fd(nb / 10, fd);
    		ft_putnbr_fd(nb % 10, fd);
    	}
    	else
    		ft_putchar_fd(nb % 10 + '0', fd);
    }
    ```
    

---

### ✔️ Description

- Outputs the integer ’n’ to the given file descriptor.
- 주어진 파일 설명자에 정수 'n'을 출력한다.

### ✔️ Return

### ⁉️ Notice

- 파일 디스크립터에 대해 알아보자.

## 보너스 파트

## Bonus Part

<aside>
💡 보너스 파트는 구조체를 사용한 함수들이다.

</aside>

```c
typedef struct	   	s_list
{
	void			        *content;
		struct  s_list	*next;
}				           	t_list;
```

### ft_lstnew

---

### ✔️ 함수의 원형

```c
t_list	*ft_lstnew(void *content)
```

---

- **구현 코드**
    
    ```c
    t_list	*ft_lstnew(void *content)
    {
    	t_list	*n_list;
    
    	if (!(n_list = (t_list *)malloc(sizeof(t_list))))
    		return (0);
    	n_list->content = content;
    	n_list->next = 0;
    	return (n_list);
    }
    ```
    

---

### ✔️ Description

- Allocates (with malloc(3)) and returns a new lement. The variable ’content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.
- 새 요소(이하 노드)에 `content`는 매개변수로 받은 `content`, `next`는 `널`로 초기화하여 반환한다.

### ✔️ Return

새 노드

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.

### lastadd_front

---

### ✔️ 함수의 원형

```c
void	ft_lstadd_front(t_list **lst, t_list *new)
```

---

- **구현 코드**
    
    ```c
    void	ft_lstadd_front(t_list **lst, t_list *new)
    {
    	if (!lst || !new)
    		return ;
    	new->next = *lst;
    	*lst = new;
    }
    ```
    

---

### ✔️ Description

- Adds the element ’new’ at the beginning of the list.
- (연결리스트) 시작 부분에 `new`노드를 추가한다.

### ✔️ Return

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.

### ft_lstsize

---

### ✔️ 함수의 원형

```c
int		ft_lstsize(t_list *lst)
```

---

- **구현 코드**
    
    ```c
    int		ft_lstsize(t_list *lst)
    {
    	int		cnt;
    	t_list	*last_lst;
    
    	cnt = 0;
    	last_lst = lst;
    	if (!lst)
    		return (0);
    	while (last_lst->next)
    	{
    		last_lst = last_lst->next;
    		cnt++;
    	}
    	if (!last_lst->next)
    		cnt++;
    	return (cnt);
    }
    ```
    

---

### ✔️ Description

- Counts the number of elements in a list.
- 리스트의 `노드 수`를 반환한다.

### ✔️ Return

노드의 개수

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.

### ft_lstlast

---

### ✔️ 함수의 원형

```c
t_list	*ft_lstlast(t_list *lst)
```

---

- **구현 코드**
    
    ```c
    t_list		*ft_lstlast(t_list *lst)
    {
    	t_list	*last_lst;
    
    	last_lst = lst;
    	if (!lst)
    		return (0);
    	while (last_lst->next)
    	{
    		last_lst = last_lst->next;
    	}
    	return (last_lst);
    }
    ```
    

---

### ✔️ Description

- Returns the last element of the list.
- 리스트의 `마지막 노드`를 반환한다.

### ✔️ Return

마지막 노드

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.

### ft_lstadd_back

---

### ✔️ 함수의 원형

```c
void	ft_lstadd_back(t_list **lst, t_list *new)
```

---

- **구현 코드**
    
    ```c
    void	ft_lstadd_back(t_list **lst, t_list *new)
    {
    	t_list		*last;
    
    	if (!(*lst))
    	{
    		*lst = new;
    		return ;
    	}
    	last = *lst;
    	while (last->next)
    		last = last->next;
    	last->next = new;
    }
    ```
    

---

### ✔️ Description

- Adds the element ’new’ at the end of the list.
- 리스트 끝에 `new`노드를 추가합니다.

### ✔️ Return

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.

### ft_lstdelone

---

### ✔️ 함수의 원형

```c
void	ft_lstdelone(t_list *lst, void (*del)(void *))
```

---

- **구현 코드**
    
    ```c
    void	ft_lstdelone(t_list *lst, void (*del)(void *))
    {
    	if (!lst || !del)
    		return ;
    	del(lst->content);
    	free(lst);
    }
    ```
    

---

### ✔️ Description

- Takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed.
- 노드를 매개변수로 취하는 `del함수를 사용하여 노드의 콘텐츠 메모리를 해제`하고, 노드를 free한다. next의 메모리를 free해서는 안된다.

### ✔️ Return

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.
- 함수포인터에 대해 알아보자.
- del함수가 콘텐츠를 free하므로 `콘텐츠에 관한 free는 고려하지 않는다.`

### ft_lstclear

---

### ✔️ 함수의 원형

```c
void	ft_lstclear(t_list **lst, void (*del)(void *))
```

---

- **구현 코드**
    
    ```c
    void	ft_lstclear(t_list **lst, void (*del)(void *))
    {
    	t_list	*tmp_lst;
    
    	tmp_lst = *lst;
    	if (!lst || !del)
    		return ;
    	while (*lst)
    	{
    		*lst = tmp_lst->next;
    		del(tmp_lst->content);
    		free(tmp_lst);
    		tmp_lst = *lst;
    	}
    }
    ```
    

---

### ✔️ Description

- Deletes and frees the given element and every successor of that element, using the function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.
- 리스트의 노드들을 `전부 삭제(free)`해야한다.
- 노드 삭제 시 노드 내 `컨텐츠` 또한 삭제(free)되어야 한다.

### ✔️ Return

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.
- 함수포인터에 대해 알아보자.
- 이전 문제를 잘 활용한다.

### ft_lstiter

---

### ✔️ 함수의 원형

```c
void	ft_lstiter(t_list *lst, void (*f)(void *))
```

---

- **구현 코드**
    
    ```c
    void	ft_lstiter(t_list *lst, void (*f)(void *))
    {
    	t_list	*last_lst;
    
    	last_lst = lst;
    	if (!lst || !(*f))
    		return ;
    	while (last_lst)
    	{
    		(*f)(last_lst->content);
    		last_lst = last_lst->next;
    	}
    }
    ```
    

---

### ✔️ Description

- Iterates the list ’lst’ and applies the function ’f’ to the content of each element.
- 연결리스트 lst의 각 노드의 콘텐츠를 f함수의 매개변수로 활용하여 `f함수를 호출`한다.

### ✔️ Return

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.
- 함수포인터에 대해 알아보자.

### ft_lstmap

---

### ✔️ 함수의 원형

```c
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
```

---

- **구현 코드**
    
    ```c
    t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
    {
    	t_list	*head;
    	t_list	*tmp;
    
    	if (!lst || !f)
    		return (0);
    	head = 0;
    	while (lst)
    	{
    		if (!(tmp = ft_lstnew(f(lst->content))))
    		{
    			ft_lstclear(&head, del);
    			return (0);
    		}
    		ft_lstadd_back(&head, tmp);
    		lst = lst->next;
    	}
    	return (head);
    }
    ```
    

---

### ✔️ Description

- Iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.
- 리스트를 복제하여 새로운 리스트를 만든다.
- 이때, 새로운 리스트의 `content는 f함수의 반환값`으로, 매개변수는 `복제할 리스트의 content`를 사용한다.

### ✔️ Return

### ⁉️ Notice

- 구조체와 연결리스트에 대해 알아보자.
- 함수포인터에 대해 알아보자.
