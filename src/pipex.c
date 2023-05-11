/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:17:39 by ialousse          #+#    #+#             */
/*   Updated: 2023/05/11 22:32:39 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

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

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
		error();
	if (pipe(fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		enfant(av, fd, env);
	parant(av, fd, env);
}

// // #include <unistd.h>
// // #include <stdio.h>
// // #include <fcntl.h>

// // int main()
// // {
// // 	open("example.txt", O_WRONLY | O_CREAT, 0644);
// // 	if (access("example.txt", R_OK) != -1)
// // 		printf("I have permission\n");
// // 	else
// // 		printf("I don't have permission\n");

// // 	return (0);
// // }

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
 
// // int main()
// // {
// // 	int fd[2];
// // 	pid_t pid;
// // 	char buffer[13];
 
// // 	if (pipe(fd) == -1)
// // 	{
// // 		perror("pipe");
// // 		exit(EXIT_FAILURE);
// // 	}
 
// // 	pid = fork();
// // 	if (pid == -1)
// // 	{
// // 		perror("fork");
// // 		exit(EXIT_FAILURE);
// // 	}
 
// // 	if (pid == 0)
// // 	{
// // 		close(fd[0]); // close the read end of the pipe
// // 		write(fd[1], "Hello parent!", 13);
// // 		close(fd[1]); // close the write end of the pipe
// // 		printf("--- %d\n", pid);
// // 		exit(EXIT_SUCCESS);
// // 	}
// // 	else
// // 	{
// // 		close(fd[1]); // close the write end of the pipe
// // 		read(fd[0], buffer, 13);
// // 		close(fd[0]); // close the read end of the pipe
// // 		printf("Message from child: '%s' --- %d\n", buffer, pid);
// // 		exit(EXIT_SUCCESS);
// // 	}
// // }

// // int main()
// // {
// // 	if (unlink("example.txt") == 0)
// // 		printf("File successfully deleted");
// // 	else
// // 		printf("Error deleting file");
 
// // 	return (0);
// // }


// // #include <stdio.h>
// // #include <stdlib.h>
// // #include <unistd.h>
// // #include <sys/wait.h>
 
// // int main(int argc, char *argv[])
// // {
// // 	pid_t pid;
 
// // 	pid = fork();
// // 	if (pid == -1)
// // 	{
// // 		perror("fork");
// // 		exit(EXIT_FAILURE);
// // 	}
// // 	else if (pid == 0)
// // 	{
// // 		printf("I am the child process.\n");
// // 		sleep(2);
// // 		exit(EXIT_SUCCESS);
// // 	}
// // 	else
// // 	{
// // 		printf("I am the parent process.\n");
// // 		wait(NULL);
// // 		printf("Child process terminated after a 2s delay.\n");
// // 	}
 
// // 	return (EXIT_SUCCESS);
// // }


// int	main()
// {
// 	ft_init_pipex()
// 	ft_check_args()
// 	ft_parse_cmds()
// 	ft_parse_args()
// 	while (cmds)
// 		ft_exec()
// 	ft_cleanup()
// }