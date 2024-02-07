/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pinkdonkeyjuice <pinkdonkeyjuice@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 10:45:05 by pinkdonkeyj       #+#    #+#             */
/*   Updated: 2024/02/03 10:45:41 by pinkdonkeyj      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
