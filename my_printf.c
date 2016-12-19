#include <stdarg.h>
#include <stdio.h>

void my_printf_char(char c)
{
	//���� ���
	printf("%c", c);
}

void my_printf_str(char *str)
{
	//���ڿ� ���
}

void my_printf_hexa(unsigned int nb, char *base)
{
	//16���� ���
}

void my_printf_int(int nb)
{
	//10���� ���
}

void my_printf_uint(unsigned int nb)
{
	//unsigned int ���
}

void my_printf(char *str, ...)			//ù��° ���ڴ� ���ڿ�, �� ���� ���ڴ� ��������
{
	va_list va;								//�������� ����Ʈ
	int i=0;									//�ݺ�

	va_start(va, str);						//�������� �غ�
	while (str[i])							//���ڿ� ��ȸ
	{
		if (str[i] == '%')					//���ڿ� �� ���Ĺ���
		{
			if (str[i + 1] == 's')									//%s
				my_printf_str(va_arg(va, char *));						//String���ڿ� ���
			else if (str[i + 1] == 'd' || str[i + 1] == 'i')			//%d or %i
				my_printf_int(va_arg(va, int));							//10���� int�� ���
			else if (str[i + 1] == 'c')								//%c
				my_printf_char((char)va_arg(va, int));					//char ������ ���
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')			//%x or %X	16���� int�� ���
				my_printf_hexa(va_arg(va, unsigned int), (str[i + 1] == 'x' ? HEXA_MIN : HEXA_CAP));
			else if (str[i + 1] == 'u')								//%u
				my_printf_uint(va_arg(va, unsigned int));				//unsigned int�� ���
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