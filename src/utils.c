/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:25:33 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/11 22:23:18 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*sub;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		sub = ft_substr(env[i], 0, j);
		if (ft_strcmp(sub, name) == 0)
		{
			free (sub);
			return (env[i] + j + 1);
		}
		free(sub);
		i++;
	}
	return (NULL);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**save_cmd;
	char	**all_path;
	char	*path_part;
	char	*exec;

	i = 0;
	all_path = ft_split(get_env("PATH", env), ':');
	save_cmd = ft_split(cmd, ' ');
	while (all_path[i++])
	{
		path_part = ft_strjoin(all_path[i], "/");
		exec = ft_strjoin(path_part, save_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_tab(save_cmd);
			return (exec);
		}
		free(exec);
	}
	free(all_path);
	free(save_cmd);
	return (cmd);
}

void	ft_exit(int n)
{
	if (n == 1)
	{
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfil\n", 2);
		exit(0);
	}
	if (n == 0)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(0);
	}
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 0)
		ret = open(file, O_RDONLY, 0777);
	if (ret == -1)
		exit(-1);
	return (ret);
}
