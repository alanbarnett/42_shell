/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 08:17:05 by abarnett          #+#    #+#             */
/*   Updated: 2019/07/28 03:11:12 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "error.h"
# include <termios.h>

struct	s_my_term
{
	struct termios	old_term;
	struct termios	new_term;
};

enum e_err_code	terminal_setup(void);
enum e_err_code	terminal_restore(void);

#endif
