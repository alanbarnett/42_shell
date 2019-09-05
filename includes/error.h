/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:07:38 by abarnett          #+#    #+#             */
/*   Updated: 2019/09/04 14:28:30 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/*
** This enum is for the possible error codes. Leave ERROR_MESSAGE_COUNT as the
** last item, as it represents the size of the error strings array and is used
** for bounds checking when relating the codes to their actual string message.
** Make sure if you add a new code to add the proper string in error.c, in the
** get_error_string function.
*/

enum	e_err_code
{
	E_NOARGS = 1,
	E_NOTATTY,
	E_TSAVE_FAIL,
	E_TNONCANON_FAIL,
	E_TRESTORE_FAIL,
	ERROR_MESSAGE_COUNT,
};

int	print_error(enum e_err_code error_code);

#endif
