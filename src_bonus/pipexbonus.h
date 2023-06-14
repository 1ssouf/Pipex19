/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexbonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:48:32 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/12 18:21:30 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXBONUS_H
# define PIPEXBONUS_H

# include "../utils/utils.h"

/****************PIPEX_BONUS*****************/
void	ft_exit(int n);
int		open_file(char *file, int in_or_out);
void	do_pipe(char *cmd, char **env);
void	put_in_her_docs(char **av, int *p_fd);
void	her_doc(char **av);
void	exec(char *cmd, char **env);
char	*get_path(char *cmd, char **env);
char	*my_getenv(char *name, char **env);
void	ft_free_tab(char **tab);

#endif