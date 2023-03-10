/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 08:17:48 by user42            #+#    #+#             */
/*   Updated: 2021/02/21 20:11:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_scene	init_scene(void)
{
	t_scene s;

	s.ambiant_light.intensity = -1;
	s.light = NULL;
	s.camera = NULL;
	s.objects = NULL;
	return (s);
}
