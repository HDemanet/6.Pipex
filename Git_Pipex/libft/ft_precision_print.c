/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:39:50 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/31 10:36:01 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_precision_nbr(t_flags *flags, int n)
{
	char	*nbr;
	int		i;

	i = 0;
	flags->dot = 0;
	if (n == 0)
		return (ft_print_chr('0', flags));
	if (n < 0)
	{
		i += ft_print_chr('-', flags);
		n = -n;
	}
	while (flags->precision-- > ft_nbrlen(n, 10))
		i += ft_print_chr('0', flags);
	if (n == INT_MIN)
		i += ft_print_str("2147483648", flags);
	else
	{
		nbr = ft_itoa(n);
		i += ft_print_str(nbr, flags);
		free(nbr);
	}
	return (i);
}

int	ft_precision_others(int n, t_flags *flags, int hex)
{
	int	len;
	int	i;

	i = 0;
	if (hex)
		len = ft_nbrlen(n, 16);
	else
		len = ft_nbrlen(n, 10);
	if (n == 0)
		return (0);
	while (flags->precision-- > len)
		i += ft_print_chr('0', flags);
	flags->dot = 0;
	return (i);
}

int	ft_precision_str(t_flags *flags, char *s)
{
	int	i;

	i = 0;
	flags->dot = 0;
	while (*s && flags->precision > 0)
	{
		i += ft_print_chr(*s, flags);
		flags->precision--;
		s++;
	}
	return (i);
}
