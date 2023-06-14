/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 16:50:16 by ialousse          #+#    #+#             */
/*   Updated: 2023/06/13 20:08:28 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

/****************UTILS****************/
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/****************GNL*****************/
char	*read_and_stash(int fd, char *stash);
char	*extract_line(char *line_in);
char	*clean_up(char *line_in);
char	*get_next_line(int fd);
int		search_newline(char *s);
void	*cleanup_while(char *line_in, char *cleaned_line, int len);

#endif