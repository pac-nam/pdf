/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbleuse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 14:08:51 by tbleuse           #+#    #+#             */
/*   Updated: 2018/03/30 18:07:14 by tbleuse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

#include <stdio.h>
//		ROUGE
static int		ft_put_line_nne_ssw(int x1, int y1, int x2, int y2, t_stock *s)
{
	float   e;
	float   to_add;

	e = 0;
	to_add = 1 / -((float)(y2 - y1) / (float)(x2 - x1));
	printf("to_add %f\n", to_add);
	ft_putstr("rouge\n");
	while (x1 <= x2)
	{
		while (e <= 0.5 && y1 >= y2)
		{
			mlx_pixel_put(s->mlx, s->win, x1, y1--, 0xFF0000);
			e += to_add;
		}
		e -= 1;
		++x1;
	}
	return (1);
}

//		BLEU
static int		ft_put_line_nnw_sse(int x1, int y1, int x2, int y2, t_stock *s)
{
	float	e;
	float	to_add;

	e = 0;
	to_add = 1 / ((float)(y2 - y1) / (float)(x2 - x1));
	printf("to_add %f\n", to_add);
	ft_putstr("bleu\n");
	while (x1 <= x2)
	{
		while (e <= 0.5 && y1 <= y2)
		{
			mlx_pixel_put(s->mlx, s->win, x1, y1++, 0x0000FF);
			e += to_add;
		}
		e -= 1;
		++x1;
	}
	return (1);
}

//              VERT
static int              ft_put_line_ene_wsw(int x1, int y1, int x2, int y2, t_stock *s)
{
	float   e;
	float   to_add;

	e = 0;
	to_add = -((float)(y2 - y1) / (float)(x2 - x1));
	printf("to_add %f\n", to_add);
	ft_putstr("vert\n");
	while (y1 >= y2)
	{
		while (e <= 0.5 && x1 <= x2)
		{
			mlx_pixel_put(s->mlx, s->win, x1++, y1, 0x00FF00);
			e += to_add;
		}
		e -= 1;
		--y1;
	}
	return (1);
}

//              BLANC
static int              ft_put_line_ese_wnw(int x1, int y1, int x2, int y2, t_stock *s)
{
	float   e;
	float   to_add;

	e = 0;
	to_add = ((float)(y2 - y1) / (float)(x2 - x1));
	printf("to_add %f\n", to_add);
	ft_putstr("blanc\n");
	while (y1 <= y2)
	{
		while (e <= 0.5 && x1 <= x2)
		{
			mlx_pixel_put(s->mlx, s->win, x1++, y1, 0xFFFF00);
			e += to_add;
		}
		e -= 1;
		++y1;
	}
	return (1);
}

int				ft_put_line(int x1, int y1, int x2, int y2, t_stock *s)
{
	if (x2 < x1)
	{
		ft_swap(&x1, &x2);
		ft_swap(&y1, &y2);
	}
	ft_printf("x1:%d, y1:%d, x2:%d, y2:%d\n", x1, y1, x2, y2);
	if (((float)(y2 - y1) / (float)(x2 - x1)) > 1 ||
			((float)(y2 - y1) / (float)(x2 - x1)) < -1)
	{
		if (y1 < y2)
			return (ft_put_line_nnw_sse(x1, y1, x2, y2, s));
		return (ft_put_line_nne_ssw(x1, y1, x2, y2, s));
	}
	if (y1 < y2)
		return (ft_put_line_ese_wnw(x1, y1, x2, y2, s));
	return (ft_put_line_ene_wsw(x1, y1, x2, y2, s));
}
