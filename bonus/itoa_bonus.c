/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyvergni <gyvergni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:45:05 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/09 14:17:52 by gyvergni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	len(int n)
{
	int	count;

	count = 1;
	if (n < 0)
		count++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int				i_num;
	int				offset;
	char			*num;
	unsigned int	nb;

	offset = 0;
	num = malloc(sizeof(char) * (len(n) + 1));
	if (num == NULL)
		return (NULL);
	nb = n;
	if (n < 0)
	{
		num[0] = '-';
		nb = -n;
		offset = 1;
	}
	i_num = len(n) - 1;
	num[len(n)] = '\0';
	while (i_num >= offset)
	{
		num[i_num] = (nb % 10 + 48);
		nb = nb / 10;
		i_num--;
	}
	return (num);
}
