/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:17:39 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/14 20:27:22 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char **env)
{
	char	**save_cmd;
	char	*path;

	save_cmd = ft_split(cmd, ' ');
	path = get_path(save_cmd[0], env);
	if (execve(path, save_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(save_cmd[0], 2);
		ft_free_tab(save_cmd);
		exit(0);
	}
}

void	enfant(char **av, int pfd[2], char **env)
{
	int	fd;

	fd = open_file(av[1], 0);
	dup2(fd, 0);
	dup2(pfd[1], 1);
	close(pfd[0]);
	exec(av[2], env);
}

// pfd[0] correspondant à la lecture de la sortie du pipe 
// et pfd[1] à l'écriture dans le pipe
// 0	Entrée standard		stdin
// 1	Sortie standard		stdout

void	parant(char **av, int pfd[2], char **env)
{
	int	fd;

	fd = open_file(av[4], 1);
	dup2(fd, 1);
	dup2(pfd[0], 0);
	close(pfd[1]);
	exec(av[3], env);
}

/*
vérifie si il y a le bon nbr d'arg
vérifie si la création du tube a échoué
vérifie si la création du processus fils a échoué.
vérifie si le processus est le processus enfant
*/

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		i;

	if (ac != 5 || (av[2][0] == '\0' || av[3][0] == '\0'))
		ft_exit(1);
	i = 0;
	while ((av[2][i] && av[2][i] == ' ') || (av[3][i] && av[3][i] == ' '))
		i++;
	if ((av[2][i] && av[2][i] != ' ') && (av[3][i] && av[3][i] != ' '))
	{
		if (pipe(fd) == -1)
			exit(-1);
		pid = fork();
		if (pid == -1)
			exit(-1);
		if (!pid)
			enfant(av, fd, env);
		parant(av, fd, env);
		i++;
	}
	else
		ft_exit(0);
}
