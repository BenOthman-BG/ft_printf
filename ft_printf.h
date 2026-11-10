#ifndef FT_PRINTF
# define FT_PRINTF

#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *s, ...);
void	ft_print_char(char c);
void	ft_print_string(char *s);
void	ft_print_adress(void *s);
void	ft_print_decimal(int a);
void	ft_print_unsigned_decimal(unsigned int a);
void	ft_print_lower_hex(unsigned int a);
void	ft_print_upper_hex(unsigned int a);

#endif
