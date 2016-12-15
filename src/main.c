/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abureau <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:44:03 by abureau           #+#    #+#             */
/*   Updated: 2016/12/15 14:51:15 by abureau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"

static int		is_specifier(const char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

static int		fisblank(const char c)
{
	if (c < 33)
	{
		return (1);
	}
	else
		return (0);
}

static int		gnw_limiter(const char c)
{
	if (c == ' ')
		return (1);
	return (0);
}

static int		get_next_word(const char *av, char **word)
{
	static int	index = 0;
	int			start;
	int			specifier;

	specifier = 0;
	if (*word)
	{
		free(*word);
		*word = NULL;
	}
	while (fisblank(av[index]) && av[index] != 0)
	{
		index++;
	}
	start = index;
	while ((ft_isprint(av[index]) && (!is_specifier(av[index])) && !specifier)
			|| ((is_specifier(av[index]) && start == index) && !specifier))
	{
		if (is_specifier(av[index]))
			while (is_specifier(av[index]))
			{
				specifier = 1;
				index++;
			}
		else
			index++;
	}
	if (index != start)
	{
		*word = ft_strsub(av, start, index - start);
		if (av[index])
			return (1);
		else
		{
			return (1);
		}
	}
	index = 0;
	return (0);
}

int				main(int ac, char **av)
{
	char	*word;

	word = NULL;
	while (get_next_word(av[1], &word))
	{
		ft_putendl(word);
	}
	return (0);
}
