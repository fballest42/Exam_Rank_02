/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myunion.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 11:12:32 by fballest          #+#    #+#             */
/*   Updated: 2020/07/01 08:58:33 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

int	main(int argc, char **argv)
{
	int		used[255];
	int		x;
	int		y;

	if (argc == 3)
	{
		x = 0;
		while (x++ < 255)
			used[x] = 0;
		x = 1;
		while (x < 3)
		{
			y = 0;
			while (argv[x][y])
			{
				if (!used[((unsigned char)argv[x][y])])
				{
					used[((unsigned char)argv[x][y])] = 1;
					write(1, &argv[x][y], 1);
				}
				y++;
			}
			x++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
