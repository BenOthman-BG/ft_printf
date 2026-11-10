static	int	print_hex(unsigned long a)
{
	int	count;

	count = 0;
	if (a /  16 > 0)
		count += print_hex(a / 16);
	count += write(1, &"0123456789abcdef"[a % 16], 1);
	return (count);
}

int	ft_print_adress(va_list *args)
{
	unsigned long	n;

	n = (unsigned long)va_arg(*args, void *);
	return (print_hex(n));
}
