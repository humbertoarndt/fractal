/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaroth </var/spool/mail/astaroth>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 19:39:12 by astaroth          #+#    #+#             */
/*   Updated: 2022/10/24 21:05:57 by astaroth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char *argv[])
{
	if (argc == 2)
		parserr(argv[1], NULL, NULL);
	else if (argc == 4)
		parserr(argv[1], argv[2], argv[3]);
	else
		ft_printf("Wrong usage.\nExamples:\n%s\n%s\n", EX_JULIA, EX_MANDEL);
}
