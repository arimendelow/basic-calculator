/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:47:20 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/13 15:06:16 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.h"

/*
**  Recursive Descent Parser
**  see https://www.strchr.com/expression_evaluator
**	_______ parse_sum
**	___ ___ parse_factor
**	_ _ _ _ parse_atom
**
**	- We have a heirarchy, where atoms constitute the lowest level.
**	- Atoms are combined into factors
**	- Factors are combined into summands
**	- Summands are summed together and then returned.
**
**	To Do:
**	- build in error handling - current iteration assumes all input to be valid
*/

//	- if currently pointed at a number, will output that number. if pointed at
//		a negative sign followed by an opening bracket, will set (out) to -1
//		before entering the if statement for handling brackets.
//	- see comments in atoi_move_cursor.c for more information.
int		parse_atom(char **str)
{
	int out;
	int sum;

	out = atoi_move_cursor(str);

	// if we aproach an opening bracket...
	if (**str == '(')
	{
		(*str)++; // go past the opening bracket.
		sum = parse_sum(str); // call a new parse_sum to handle the contents.
		(*str)++; // go past the closing bracket.

		// return sum, unless "out" is set to something other than a 0
		//	(this happens in the event that the '(' was preceeded
		//	by a '-' - see above).
		return (out != 0 ? sum * out : sum);
	}
	else
		return (out);
}

// deals with items that need to be multiplied/divided/modulo-ed before
//	sending them back to parse_sum to be treated as a summand/subtrahand.
int		parse_factor(char **str)
{
	int		fac1;
	int		fac2;
	char	op;

	fac1 = parse_atom(str);
	while (**str == '*' || **str == '/' || **str == '%')
	{
		// set op to current operation symbol before iterating past it.
		op = **str;
		(*str)++;
		fac2 = parse_atom(str);
		if (op == '*')
			fac1 *= fac2;
		if (op == '/')
			fac1 /= fac2;
		if (op == '%')
			fac1 %= fac2;
	}
	return (fac1);
}

// deals with summands/subtrahands. this is the last calculation
//	done before returning a final value.
int		parse_sum(char **str)
{
	int		pro1;
	int		pro2;
	char	op;

	// call function for parsing factors
	pro1 = parse_factor(str);
	while (**str == '+' || **str == '-')
	{
		// set op to current operation symbol before iterating past it.
		op = **str;
		(*str)++;
		// get the next factor after the '+' or '-'
		pro2 = parse_factor(str);
		if (op == '+')
			pro1 += pro2;
		if (op == '-')
			pro1 -= pro2;
	}
	return (pro1);
}

int		eval_expr(char *str)
{
	char	*out;
	char	*hold;
	int		o;

	// malloc for output, malloc the length of input + 1 for null terminator
	if (!(out = (char *)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (0);
	hold = out;
	bye_spaces(str, out);
	o = parse_sum(&out);
	free(hold);
	return (o);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}
