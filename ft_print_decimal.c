#include <unistd.h>
#include <stdio.h>

static	int	ft_putnbr(long a)
{
	int	count;

	count = 0;
	if (a / 10 > 0)
		count += ft_putnbr(a / 10);
	count += write(1, &"0123456789"[a % 10], 1);
	return (count);
}

int	ft_print_decimal(int n)
{
	long	a;
	int		len;

	//a = va_arg(*args, int);
	a = n;
	len = 0;
	if (a < 0)
	{
		write(1, "-", 1);
		a = a * (-1);
		len++;
	}
	return (len + ft_putnbr(a));
}

int main ()
{
	int a;
	int b;

	a = ft_print_decimal(-1029019);
	printf("\n");
	b = printf("%d", -1029019);

	printf("\n%d - %d", a, b);
	return (0);
}
