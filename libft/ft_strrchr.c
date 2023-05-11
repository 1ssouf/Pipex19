/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 18:58:49 by ialousse          #+#    #+#             */
/*   Updated: 2022/08/02 18:39:10 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*ptr;

	a = 0;
	ptr = 0;
	while (s[a])
	{
		if (s[a] == (unsigned char)c)
			ptr = (char *)(s + a);
		a++;
	}
	if (s[a] == (unsigned char)c)
		ptr = (char *)(s + a);
	return (ptr);
}
