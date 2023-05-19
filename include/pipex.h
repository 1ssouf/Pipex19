/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:14:43 by ialousse          #+#    #+#             */
/*   Updated: 2023/05/19 12:47:43 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

int		open_file(char *file, int in_or_out);
void	ft_free_tab(char **tab);
void	ft_exit(int n);
char	*get_env(char *name, char **env);
char	*get_path(char *cmd, char **env);
void	parant(char **av, int pfd[2], char **env);
void	enfant(char **av, int pfd[2], char **env);
void	exec(char *cmd, char **env);

/**************LIB_UTILS************/
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strcmp(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_strlen(const char *s);
char	**ft_split(char const *s, char c);

#endif