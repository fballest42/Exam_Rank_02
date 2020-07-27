/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 09:34:30 by fballest          #+#    #+#             */
/*   Updated: 2020/07/01 11:22:26 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>

/*int		ft_strlen(char *str)
{
	int		y;

	y = 0;
	while (str[y] != '\0')
		y++;
	return (y);
}*/

char	*ft_strchr(char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
			return (0);
		str++;
	}
	return (str);
}

int		main(int argc, char **argv)
{
	int		used[255];
	int		y;

	if (argc == 3)
	{
		while (y < 255)
			used[y++] = 0;
		y = 0;
		while (argv[1][y])
		{
			if (!used[(unsigned char)argv[1][y]] && ft_strchr(argv[2], argv[1][y]))
			{
				used[(unsigned char)argv[1][y]] = 1;
				write(1, &argv[1][y], 1);
			}
			y++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
