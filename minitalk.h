/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 03:15:00 by lsomrat           #+#    #+#             */
/*   Updated: 2022/09/14 17:59:40 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

typedef struct s_sigcharacter
{
	char	c;
	int		bit;
}	t_sigcharacter;

void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *s);

#endif
