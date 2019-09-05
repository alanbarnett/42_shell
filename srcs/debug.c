/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 09:42:49 by abarnett          #+#    #+#             */
/*   Updated: 2019/09/05 15:35:52 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef DEBUG

# include "ft_printf.h"
# include <unistd.h>

/*
** TODO: change all instances of "oort" to a shell name string
*/

extern inline void	print_debug(const char *func, const char *string)
{
	ft_printfd(STDERR_FILENO, "oort(debug:%s): %s\n", func, string);
}

#else

extern inline void	print_debug(const char *func, const char *string)
{
	(void)func;
	(void)string;
}

#endif
