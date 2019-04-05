/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amendelo <amendelo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 14:48:43 by amendelo          #+#    #+#             */
/*   Updated: 2018/11/10 22:41:00 by amendelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_H
# define EVAL_EXPR_H
# include <unistd.h>
# include <stdlib.h>

int				atoi_move_cursor(char **str);
int				is_space(char c);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
int				parse_atom(char **str);
int				parse_factor(char **str);
int				parse_sum(char **str);
void			bye_spaces(char *in, char *out);
int				ft_strlen(char *str);

#endif
