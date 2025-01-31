/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdemanet <hdemanet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:33:38 by hdemanet          #+#    #+#             */
/*   Updated: 2024/07/31 10:35:21 by hdemanet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_zero_nbr(int n, t_flags *flags)
{
	char	*nbr;
	int		size;
	int		i;

	i = 0;
	if (n == 0)
		return (ft_print_chr('0', flags));
	if (n < 0)
	{
		i += ft_print_chr('-', flags);
		n = -n;
	}
	size = flags->width - ft_nbrlen(n, 10);
	while (i < size)
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

int	ft_print_justify_before(t_flags *flags, int n)
{
	int	i;

	i = 0;
	if (flags->only_number)
		flags->only_number = 0;
	while (i < flags->width - n)
		i += ft_print_chr(' ', flags);
	return (i);
}

int	ft_print_justify_after(t_flags *flags, int n)
{
	int	i;

	i = 0;
	if (flags->minus)
		flags->minus = 0;
	while (i < flags->width - n)
		i += ft_print_chr(' ', flags);
	return (i);
}

int	ft_print_zero(int n, t_flags *flags, int hex)
{
	int	size;
	int	i;

	i = 0;
	if (hex)
		size = flags->width - ft_nbrlen(n, 16);
	else
		size = flags->width - ft_nbrlen(n, 10);
	if (n == 0)
		return (0);
	while (i < size)
		i += ft_print_chr('0', flags);
	return (i);
}
