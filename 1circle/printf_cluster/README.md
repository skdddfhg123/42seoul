## 선행 지식

[가변 인자 (Value Argument)](https://www.notion.so/Value-Argument-0c18214528844cd081c71ccce0ada836)

## 과제의 개요

- `stdio.h`기본 라이브러리에 포함되어 있는 **`printf`** 함수의 일부 기능들을 직접 구현해보기.

<aside>
💡 printf의 f는 **formatted**의 약자이며, **서식화된 출력을 지원**한다는 의미이다.

</aside>

**printf**는 `<stdio.h>` 헤더파일 안에 있으며

`int printf(const char *restrict format, ...)`로 정의된다.

첫 번째 매개 변수로 문자열(format)이 입력되고, 그 이후는 가변 인자로 n개의 매개 변수를 받는다.

반환값이 int형으로 정의된 이유는 출력된 문자열의 수가 반환됨

**format**은 `%[parameter][flags][width][.precision][length] type` 형식을 가지며 해석하면

`%[n][flag][출력 너비][출력되는 값(숫자)의 정확도][데이터 타입 범위] type(서식문자)`이다.

### flag

- [#] 진법 형식에 맞게 0, 0x 0X를 추가
- [0] width에 맞게 주어진 너비의 빈자리를 0으로 채움
- [ ] 양수일 땐 +대신 공백, 음수일 땐 -출력
- ['] 정수와 지수에 천 단위를 표시함 (2,000)
- [+] 양수일 때 +, 음수일 때 - 표시
- [-] 좌측 정렬

### width

- [n] n은 양수이며, 출력될 길이
- [*] 너비 값을 인자로 받음

### precision

.만 사용된 경우

- [cp] 정확도를 무시
- [diouxX] flag필드로 0이 주어지면, 0옵션을 무시함
- [feEgGaA] 소수점 아래를 출력하지 않고, 마지막 숫자는 반올림
- [s] 문자열 출력하지 않음
- [*s] 출력할 최대 길이를 인자로 받음

.n이 입력된 경우 앞의 width를 무시하고 n만큼 출력됨

- [c] 정확도를 무시
- [diouxX] 출력할 최대 자릿수를 지정, 출력값이 적은경우 남은 자릿수는 0으로 채움
- [feEgGaA] 출력할 소수점 자릿수를 지정, 출력할 자리 직후의 숫자를 반올림
- [s] 출력할 최대 문자열 길이를 지정
- [p] 0x를 제외하고 총 길이로 주어진 n에 맞춰 출력

### length

- [signed char] - hhd, hhi
- [unsigned char] - hhu, hhx, hhX
- [short] - hd, hi
- [unsigned short] - hu, hx, hX
- [long] - ld, li
- [long long] - lld, lli
- [unsigned long] - lu, lx, lX
- [unsigned long long] - llu, llx, llX
- [wint_t] - lc
- [wchar_t *] - ls

## 작성 코드 및 설명

## 필수 파트

```jsx
#include "ft_printf.h"

int	format_print(const char **str, va_list ap)
{
	while (**str)
	{
		if ((char) **str == 'c')
			return (print_c(str, ap));
		else if ((char) **str == 's')
			return (print_s(str, ap));
		else if ((char) **str == 'p')
			return (print_p(str, ap));
		else if ((char) **str == 'd' || **str == 'i')
			return (print_di(str, ap));
		else if ((char) **str == 'u')
			return (print_u(str, ap));
		else if ((char) **str == 'x')
			return (print_x(str, ap));
		else if ((char) **str == 'X')
			return (print_X(str, ap));
		else if ((char) **str == '%')
		{
			(*str)++;
			return (ft_putchar_len('%'));
		}
		else
			return (0);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap; // 가변인자들을 저장하기 위한 저장공간

	va_start(ap, str); // va_list를 str의 저장공간을 기점으로 초기화
	len = 0;
	while (*str)
	{
		while (*str && str[0] != '%') // 형식지정자가 아닐 경우 문자열 끝까지 탐색 
		{
			len += ft_putchar_len(str[0]);
			str++;
		}
		if (*str == '%') // 형식지정자를 만날 경우
		{
			str++;
			len += format_print(&str, ap);
		}
	}
	va_end(ap);
	return (len);
}
```

사용한 테스터

https://github.com/paulo-santana/ft_printf_tester

https://github.com/Tripouille/printfTester
