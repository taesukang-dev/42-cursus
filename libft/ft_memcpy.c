#include "libft.h"

/*
void	*memcpy(void *dest, const void *src, size_t num)
{
	

}

int main()
{

	return 0;
}
*/

void test(int *restrict a, int *restrict b, int *restrict x)
{
	*a += *x;
	*b += *x;
}

int main()
{
	int a = 1;
	test(&a, &a, &a);
	printf("%d", a);
}
