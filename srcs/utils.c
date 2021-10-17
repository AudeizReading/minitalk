/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alellouc <alellouc@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:10:47 by alellouc          #+#    #+#             */
/*   Updated: 2021/10/17 19:18:13 by alellouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	ft_atoi(const char *nptr)
{
	int			polarity;
	int			sign;
	long int	atoi;

	polarity = 1;
	sign = 0;
	atoi = 0;
//	while (ft_isspace(*nptr))
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == 45 || *nptr == 43)
	{
		if (*nptr == 45)
			polarity = -1;
		sign++;
		nptr++;
	}
	if (sign > 1)
		return (0);
//	while (ft_isdigit(*nptr))
	while (*nptr >= '0' && *nptr <= '9')
	{
		atoi = atoi * 10 + *nptr - '0';
		nptr++;
	}
	atoi *= polarity;
	return ((int)atoi);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}
