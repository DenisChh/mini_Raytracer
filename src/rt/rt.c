/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 15:34:58 by user42            #+#    #+#             */
/*   Updated: 2021/03/20 14:24:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_rt	init_rt(void)
{
	t_rt rt;

	rt.width = -1;
	rt.height = -1;
	rt.depth = 0;
	rt.scene = init_scene();
	rt.transform = TRANSLATE;
	rt.transform_focus = CAMERA;
	rt.scene.camera = NULL;
	rt.scene.light = NULL;
	rt.scene.objects = NULL;
	rt.object = NULL;
	rt.camera = NULL;
	rt.light = NULL;
	rt.mlx = NULL;
	rt.window = NULL;
	rt.img.img = NULL;
	return (rt);
}

void	free_rt(t_rt *rt)
{
	if (rt)
	{
		ft_lstclear(&rt->scene.camera, &free);
		ft_lstclear(&rt->scene.light, &free);
		ft_lstclear(&rt->scene.objects, &free_object);
		if (rt->mlx)
		{
			if (rt->img.img)
				mlx_destroy_image(rt->mlx, rt->img.img);
			if (rt->window)
			{
				mlx_clear_window(rt->mlx, rt->window);
				mlx_destroy_window(rt->mlx, rt->window);
				mlx_destroy_display(rt->mlx);
			}
			free(rt->mlx);
		}
	}
}

void	set_mlx(t_rt *rt)
{
	int width;
	int height;

	rt->mlx = mlx_init();
	mlx_get_screen_size(rt->mlx, &width, &height);
	rt->width = MIN(rt->width, width);
	rt->height = MIN(rt->height, height);
	rt->img.img = mlx_new_image(rt->mlx, rt->width, rt->height);
	rt->img.addr = mlx_get_data_addr(rt->img.img,
										&rt->img.bits_per_pixel,
										&rt->img.line_length,
										&rt->img.endian);
}
