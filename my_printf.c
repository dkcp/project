#include <stdarg.h>
#include <stdio.h>

void my_printf_char(char c)
{
	//문자 출력
	printf("%c", c);
}

void my_printf_str(char *str)
{
	//문자열 출력
}

void my_printf_hexa(unsigned int nb, char *base)
{
	//16진수 출력
}

void my_printf_int(int nb)
{
	//10진수 출력
}

void my_printf_uint(unsigned int nb)
{
	//unsigned int 출력
}

void my_printf(char *str, ...)			//첫번째 인자는 문자열, 그 이후 인자는 가변인자
{
	va_list va;								//가변인자 리스트
	int i=0;									//반복

	va_start(va, str);						//가변인자 준비
	while (str[i])							//문자열 순회
	{
		if (str[i] == '%')					//문자열 내 서식문자
		{
			if (str[i + 1] == 's')									//%s
				my_printf_str(va_arg(va, char *));						//String문자열 출력
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')			//%d or %i
				my_printf_int(va_arg(va, int));							//10진수 int형 출력
			else if (str[i + 1] == 'c')								//%c
				my_printf_char((char)va_arg(va, int));					//char 문자형 출력
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')			//%x or %X	16진수 int형 출력
				my_printf_hexa(va_arg(va, unsigned int), (str[i + 1] == 'x' ? HEXA_MIN : HEXA_CAP));
			else if (str[i + 1] == 'u')								//%u
				my_printf_uint(va_arg(va, unsigned int));				//unsigned int형 출력
			else
				my_printf_char(str[i + 1]);			//
			i++;
	  }
	  else
		  my_printf_char(str[i]);
	  i++;
  }
  va_end(va);
}

int main(void)
{
	printf("printf : %d\n", 1);
	my_printf("my_printf : %d\n", 1);
	return (0);
}