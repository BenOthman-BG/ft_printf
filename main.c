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
#include <stdio.h>
#include <unistd.h>

int main()
{
    int ret_orig;
    int ret_mine;

	//setbuf(stdout, NULL);

    /close(1); 
    int i;
    i = 0;
    while (i < 10000)
    {
        printf("i");
        i++;
    }
    ft_printf("Hello Worod");
    write(1,"\n",1);
    //printf("fkjenfkejnf\n");


    //dprintf(2, "Original return: %d\n", ret_orig); // سيطبع -1
    //dprintf(2, "My return: %d\n", ret_mine);       // يجب أن يطبع -1 أيضاً
    
    return (0);
}