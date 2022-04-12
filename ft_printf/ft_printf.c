#include <stdio.h>
#include <stdarg.h>

int test(char *s, ...)
{
	va_list ap;
	int	tmp;

	va_start(ap, s);
	while(*s)
	{
		if (*s == '%')
		{
			tmp = va_arg(ap, int);
			printf("%d", tmp);
			s += 2;
		}
		else
		{
			printf("%c", *s);
			s++;
		}
	}
	va_end(ap);

	return 0;
}

int main()
{
	test("asdasdasd %d %d", 1, 2);
	return 0;
}