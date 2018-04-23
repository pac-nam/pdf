/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:46:17 by tbleuse           #+#    #+#             */
/*   Updated: 2018/04/23 15:34:20 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		ft_write_map(t_point *p1, t_point *p2, t_stock *s)
{
	int	xy[2];

	xy[0] = 0;
	while (++xy[0] <= s->map[0][0])
	{
		xy[1] = 0;
		while (++xy[1] <= s->map[xy[0]][0])
		{
			p1->x = s->ref->x + (xy[1] - 1) * s->dif_right_x;
			p1->y = s->ref->y - (xy[1] - 1) * s->dif_right_y -
				s->map[xy[0]][xy[1]] * s->zoom;
			if (xy[1] < s->map[xy[0]][0])
			{
				p2->x = s->ref->x + (xy[1]) * s->dif_right_x;
				p2->y = s->ref->y - (xy[1]) * s->dif_right_y -
					s->map[xy[0]][xy[1] + 1] * s->zoom;
				ft_put_line(p1, p2, s);
			}
			if (xy[0] < s->map[0][0] && xy[1] <= s->map[xy[0] + 1][0])
			{
				p2->x = p1->x + s->dif_up_x;
				p2->y = s->ref->y - (xy[1] - 1) * s->dif_right_y + s->dif_up_y -
					s->map[xy[0] + 1][xy[1]] * s->zoom;
				ft_put_line(p1, p2, s);
			}
		}
		s->ref->x += s->dif_up_x;
		s->ref->y += s->dif_up_y;
	}
	return (1);
}

int		ft_fdf(t_stock *s)
{
	t_point		*p1;
	t_point		*p2;

	if (!(p1 = (t_point*)malloc(sizeof(t_point))) ||
			!(p2 = (t_point*)malloc(sizeof(t_point))))
		return (0);
	ft_write_map(p1, p2, s);
	return (1);
}
