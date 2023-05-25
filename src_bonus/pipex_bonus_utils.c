/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialousse <ialousse@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:54:32 by ialousse          #+#    #+#             */
/*   Updated: 2023/05/24 17:11:01 by ialousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_exit(int n)
{
	if (n == 0)
		ft_putstr_fd("./pipex infile cmd1 cmd2 outfil\n", 2);
	exit(0);
}

/*
O_WRONLY: C'est un indicateur qui spécifie que le fichier doit être ouvert 
          en mode écriture seulement (write-only).

O_CREAT: C'est un indicateur qui spécifie que le fichier doit être créé 
		 s'il n'existe pas déjà.

O_TRUNC: C'est un indicateur qui spécifie que si le fichier existe déjà, 
		 son contenu doit être tronqué (effacé) avant l'ouverture.

O_APPEND: C'est un indicateur qui spécifie que les données doivent être ajoutées 
		  à la fin du fichier plutôt que d'écraser son contenu existant.
*/

int	open_file(char *file, int in_or_out)
{
	int	ret;

	if (in_or_out == 0)
		ret = open(file, O_CREAT, 0777);
	if (in_or_out == 1)
		ret = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (in_or_out == 2)
		ret = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (in_or_out == -1)
		exit(1);
	return (ret);
}
