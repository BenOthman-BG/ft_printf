#include <stdarg.h>

/*int	ft_print_string(va_list *args)
{
	int	i;
	char *s;

	s = va_arg(*args, char *);
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}*/

#include <stdio.h>
#include <unistd.h>

int main ()
{
	char *null = NULL;
	int 	a;

	a = printf("%x", -10);
	printf("%d", a);
	return (0);
}
