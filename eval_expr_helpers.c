/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 22:35:31 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:05:32 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

//	this guy takes in a string that may or may not have spaces and copies it
//	to a new string, without the spaces.
//	- we use this because while separating numbers/operations with spaces
//		may be easier for a human bean to read, it's more difficult to parse.
void	bye_spaces(char *in, char *out)
{
	char *cursor;

	cursor = out;
	while (*in)
	{
		if (!is_space(*in))
		{
			*cursor = *in;
			cursor++;
		}
		in++;
	}
	*(cursor) = '\0';
}

// just good 'ol strlen :)
int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
