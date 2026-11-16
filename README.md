*This project has been created as part of the 42 curriculum by obenyahy.*

# ft_printf

## Description

**ft_printf** is a re-implementation of the C library function `printf()`.
The goal is to learn how **variadic functions** work in C (`va_list`, `va_start`, `va_arg`, `va_end`) and to write clean, extensible code.

The prototype is:

```c
int ft_printf(const char *s, ...);
```

It returns the number of characters printed, like the original `printf()`, or `-1` if a `write()` fails or if the format string is `NULL` or ends with a lone `%`.
The project is built as a static library, `libftprintf.a`.

### Supported conversions

| Conversion | Description |
|------------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (`(null)` if the pointer is `NULL`) |
| `%p` | Prints a `void *` pointer in hexadecimal, prefixed with `0x` (`(nil)` for `NULL`, as the reference `printf` does on Linux) |
| `%d` | Prints a signed decimal (base 10) number |
| `%i` | Prints a signed integer (base 10) |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in lowercase hexadecimal |
| `%X` | Prints a number in uppercase hexadecimal |
| `%%` | Prints a percent sign |

As required by the subject, the buffer management of the original `printf()` is **not** implemented.

### Project structure

| File | Role |
|------|------|
| `ft_printf.c` | Main file: contains `ft_printf()` and the loop that parses the format string |
| `ft_dispatch.c` | Builds the dispatch table (array of function pointers) |
| `ft_print_text.c` | Text conversions: `%c`, `%s`, `%%` |
| `ft_print_nums.c` | Decimal conversions: `%d`, `%i`, `%u` |
| `ft_print_hex.c` | Hexadecimal conversions: `%x`, `%X`, `%p` |
| `ft_printf.h` | Header: prototypes and the `t_printer` function pointer type |
| `Makefile` | Builds `libftprintf.a` with `cc -Wall -Wextra -Werror` and `ar` |

## Instructions

### Compilation

```bash
make        # builds libftprintf.a at the root of the repository
make clean  # removes object files
make fclean # removes object files and libftprintf.a
make re     # fclean + make
```

### Usage

Include the header and link against the library:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s, you are number %d!\n", "world", 42);
	return (0);
}
```

```bash
cc main.c libftprintf.a -o test
./test
```

## Algorithm and data structure

**Data structure: an array of function pointers.** A table `t_printer table[256]` is indexed by the conversion character: `table['d']` points to `print_d`, `table['s']` to `print_s`, and so on (`NULL` for unsupported characters). After a `%`, the right function is found with one lookup, `table[(unsigned char)c]`, instead of a long `if / else` chain. Adding a conversion only needs one new function and one new line in the table.

**Algorithm.** `ft_printf` walks through the format string character by character. A normal character is written with `write()`. After a `%`, the matching function is called with the `va_list`, and each function returns the number of characters it printed. These counts are added up and returned, and any `write()` error is propagated as `-1`.

**Recursion.** Numbers (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) are printed recursively: the function first prints `n / base` (the higher digits), then the last digit. This needs no buffer and no `malloc`, so there are no leaks. `ft_putnbr` handles base 10 and `print_hex` handles base 16 (lowercase or uppercase).

## Resources

## Resources
 
**References**
 
- Manual pages (`man 3 printf`, `man 3 stdarg`) for `printf` and variadic functions (`va_start`, `va_arg`, `va_end`)
- Stack Overflow, to clarify some concepts
- Google, to search for answers to specific questions

AI was used for the following tasks:

- **Understanding new concepts:** to help me understand new concepts, and to practice implementing them before moving on to solve the actual functions of the project.
- **Peer discussions:** to help me discuss and compare different perspectives on a new concept with my peers.
- **README:** to help build this README file.