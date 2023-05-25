/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:57:50 by ialousse          #+#    #+#             */
/*   Updated: 2023/05/25 12:06:45 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"


int	main(int ac, char **av, char **env)
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (ac < 5)
		ft_exit(1);
	if (ft_strcmp(av[1], "her_doc" == 0))
	{
		if (ac < 6)
			ft_exit(1);
		i = 3;
		fd_out = open_file(av[ac - 1], 2);
		her_doc(av);
	}
	else
	{
		i = 2;
		fd_in = open_file(av[1], 0);
		fd_out = open_file(av[ac - 1], 1);
		dup2(fd_in, 0);
	}
	while (i < ac - 2)
		do_pipe();
	dup2(fd_out, 2);
	exec(av[ac - 2], env);
}
