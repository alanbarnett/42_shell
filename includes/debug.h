/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 09:11:45 by abarnett          #+#    #+#             */
/*   Updated: 2019/09/03 20:06:25 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# define PRINT_DEBUG(string) print_debug(__func__, (string))

void	print_debug(const char *func, const char *string);

#endif
