/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_move_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 21:58:29 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:05:18 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
		c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

// this version of atoi functions the same as the normal one, with two tweaks:
//	- it takes in a pointer to the string pointer, so that the string 
//		pointer can be iterated forward. this allows us to integrate atoi
//		into a function that wants to use whatever comes after the valid num.
//	- if the input string begins with '-' and is followed with an opening
//		bracket, this function will return '-1' rather than 0. this is
//		because in a math expression parser, -(num) needs to be interpreted
//		as -1 * num rather than just as num.
int		atoi_move_cursor(char **str)
{
	int result;
	int sign;

	result = 0;
	sign = 1;
	while (is_space(**str))
	{
		(*str)++;
	}
	if (**str == '-')
	{
		sign = -1;
		(*str)++;
		if (**str == '(')
			return (-1);
	}
	else if (**str == '+')
		(*str)++;
	while (**str >= '0' && **str <= '9')
	{
		result = (10 * result) + **str - '0';
		(*str)++;
	}
	return (result * sign);
}
