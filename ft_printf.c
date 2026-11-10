#include <stdio.h>

int	ft_printf(const char *s, ...)
{
	int i;
	va_list	args;

	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			if (s[i] == 'c')
				total_len = total_len + ft_printf_char(va_arg(args, int));
			else if (s[i] == 's')
				total_len = total_len + ft_print_string(va_arg(args, char *));
			else if (s[i] == 'p')
				total_len = total_len + ft_print_adress(va_arg(args, void *));
			else if (s[i] == 'd' || s[i] == 'i')
				total_len = total_len + ft_print_decimal(va_arg(args, int));
			else if (s[i] == 'x')
				toral_len = total_len + ft_print_lower_hex(va_arg(args, unsigned int));

		}
	}
}
