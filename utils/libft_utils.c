/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:03:19 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/20 14:50:14 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	i = 0;
// 	if (!s)
// 		return ;
// 	if (s != 0)
// 	{
// 		while (s[i])
// 		{
// 			write(fd, &s[i], 1);
// 			i++;
// 		}
// 	}
// }

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
