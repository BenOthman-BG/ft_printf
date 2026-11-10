#include <unistd.h>
#include <stdio.h>

static	int	ft_putnbr(unsigned int a)
{
	int	count;

	count = 0;
	if (a / 10 > 0)
		count += ft_putnbr(a / 10);
	count += write(1, &"0123456789"[a % 10], 1);
	return (count);
}

int	ft_print_unsigned_decimal(unsigned int n)
{
	unsigned int	a;

	//a = va_arg(*args, unsigned int);
	return (ft_putnbr(n));
}

int main ()
{
	int a;
	int b;

	a = ft_print_decimal(-1);
	printf("\n");
	b = printf("%u", -1);

	printf("\n%d - %d", a, b);
	return (0);
}
