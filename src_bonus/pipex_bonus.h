/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:03:27 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/11 20:06:20 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "get_next_line.h"

/*lib_utils*/
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);

/*pipex_bonus_utils*/
void	ft_exit(int n);
int		open_file(char *file, int in_or_out);

#endif