/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obenyahy <obenyahy@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 09:20:07 by obenyahy          #+#    #+#             */
/*   Updated: 2026/11/11 09:47:12 by obenyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>

// النموذج الأولي (Prototype) لدالتك
int ft_printf(const char *format, ...);

int main(void)
{
    int ret1;
    int ret2;
    char *null_str = NULL;
    int num = 42;

    printf("\n==========================================\n");
    printf("         FT_PRINTF MANDATORY TEST         \n");
    printf("==========================================\n");

    /* ------------------------------------------------ */
    printf("\n[1] Testing Characters (%%c):\n");
    ret1 = printf("Original : %c | %c | %c\n", 'A', '0', 0);
    ret2 = ft_printf("ft_printf: %c | %c | %c\n", 'A', '0', 0);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[2] Testing Strings (%%s):\n");
    ret1 = printf("Original : %s | %s | %s\n", "Hello", "", null_str);
    ret2 = ft_printf("ft_printf: %s | %s | %s\n", "Hello", "", null_str);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[3] Testing Pointers (%%p):\n");
    ret1 = printf("Original : %p | %p\n", &num, null_str);
    ret2 = ft_printf("ft_printf: %p | %p\n", &num, null_str);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[4] Testing Decimals/Integers (%%d / %%i):\n");
    ret1 = printf("Original : %d | %i | %d | %d\n", 0, -42, INT_MAX, INT_MIN);
    ret2 = ft_printf("ft_printf: %d | %i | %d | %d\n", 0, -42, INT_MAX, INT_MIN);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[5] Testing Unsigned (%%u):\n");
    ret1 = printf("Original : %u | %u | %u\n", 0, 42, UINT_MAX);
    ret2 = ft_printf("ft_printf: %u | %u | %u\n", 0, 42, UINT_MAX);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[6] Testing Hexadecimal (%%x / %%X):\n");
    ret1 = printf("Original : %x | %X | %x | %X | %x\n", 0, 0, 255, 255, UINT_MAX);
    ret2 = ft_printf("ft_printf: %x | %X | %x | %X | %x\n", 0, 0, 255, 255, UINT_MAX);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[7] Testing Percent Sign (%%%%):\n");
    ret1 = printf("Original : %% | %%%% | %%%%%%%%%%\n");
    ret2 = ft_printf("ft_printf: %% | %%%% | %%%%%%%%%%\n");
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[8] Testing Mix and Edge Cases:\n");
    ret1 = printf("Original : %s is %d years old, pointer %p, rate %d%%\n", "Othman", 20, &num, 100);
    ret2 = ft_printf("ft_printf: %s is %d years old, pointer %p, rate %d%%\n", "Othman", 20, &num, 100);
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    /* ------------------------------------------------ */
    printf("\n[9] The \"Lonely Percent\" Test:\n");
    ret1 = printf("Original : Hello %");
    printf("\n"); // سطر جديد للتوضيح
    ret2 = ft_printf("ft_printf: Hello %");
    printf("\n"); // سطر جديد للتوضيح
    printf("-> Return : Orig = %d, ft = %d\n", ret1, ret2);
    if (ret1 == ret2) printf("✅ OK\n"); else printf("❌ KO\n");

    printf("\n==========================================\n");

    return (0);
}