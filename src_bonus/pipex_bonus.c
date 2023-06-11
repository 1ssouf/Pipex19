/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:57:50 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/11 22:31:46 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "../src/pipex.h"

void	her_doc(char **av)
{
	pid_t	pid;
	int		p_fd[2];

	if (pipe(p_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	if (!pid)
		put_in_her_docs(av, p_fd);
	else
	{
		close(pid);
		dup2(p_fd, 0);
		wait(0);
	}
}

void	put_in_her_docs(char **av, int *p_fd)
{
	char	*ret;

	close(p_fd[0]);
	while (1)
	{
		ret = get_next_line(0);
		if (ft_strncmp(ret, av[2], ft_strlen(av[2])) == 0)
		{
			free(ret);
			exit(0);
		}
		ft_putstr_fd(ret, p_fd[1]);
		free(ret);
	}
}


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
