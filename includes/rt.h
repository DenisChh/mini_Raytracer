/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 07:15:21 by user42            #+#    #+#             */
/*   Updated: 2021/03/20 14:02:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <unistd.h>
# include <math.h>
# include "libft.h"
# include "types.h"
# include "maths.h"
# include "parser.h"
# include "mlx.h"

# define MAX(x,y)	((x) > (y) ? (x) : (y))
# define MIN(x,y)	((x) < (y) ? (x) : (y))

/*
** KEY CODE
*/
# define ESCAPE		65307
# define CONTROL	65507
# define TAB		65289
# define SPACE		32

/*
** TRANSFORMATION
*/
# define CAMERA		0
# define OBJECT		1
# define LIGHT		2
# define TRANSLATE	0
# define ROTATE		1
# define RAD		0.174533

/*
** COLOR
*/
t_color				new_color(double r, double g, double b);
int					color_to_trgb(t_color color);
t_color				color_add(t_color c1, t_color c2);
t_color				color_mix(t_color c1, t_color c2);
t_color				color_scale(double x, t_color color);
t_color				color_mul(t_color c1, t_color c2);
t_color				color_clamp(t_color color);

/*
** RT
*/
t_ray				new_ray(t_vector pos, t_vector dir);
t_rt				init_rt();
void				free_rt(t_rt *rt);
void				render(t_rt *rt);
t_color				trace_ray(t_rt *rt, int depth);
double				get_closest_intersection(t_rt *rt,
											t_object **closest_object,
											double t_min,
											double t_max);
t_color				compute_light(t_rt *rt,
								t_object *object,
								t_vector intersection,
								t_vector normal);
int					resolve_quadratic(t_vector v, double *t1, double *t2);
void				img_to_bmp(t_rt *rt, char *path);

/*
** MLX
*/
void				set_mlx(t_rt *rt);
void				img_pixel_put(t_rt *rt, int x, int y, int color);

/*
** HOOK
*/
int					exit_prog(t_rt *rt);
int					expose_hook(t_rt *rt);
void				transform_hook(int key, t_rt *rt);
void				grab_focus(int key,
								t_rt *rt,
								t_list **objects,
								t_list **lights);
int					key_hook(int key, t_rt *rt);

/*
** SCENE
*/
t_scene				init_scene();
void				set_camera_matrix(t_camera *camera);
void				add_camera(t_rt *rt, t_camera *camera);
void				compute_camera(t_rt *rt, double x, double y);

/*
** OBJECT
*/
void				free_object(void *object);
int					check_object_param(t_object *object, double p);
t_object			*new_object(char **split,
								int color_index,
								int n_vertices,
								int rotate);
void				set_object(t_object *object,
								void *ptr,
								int rotate,
								double specular);

/*
** INTERSECT
*/
double				ray_sphere_intersect(t_ray ray,
										t_object *object,
										double t_min,
										double t_max);
t_vector			get_sphere_normal(t_ray ray,
									t_vector intersection,
									t_object *object);
double				ray_plane_intersect(t_ray ray,
										t_object *object,
										double t_min,
										double t_max);
t_vector			get_plane_normal(t_ray ray,
									t_vector intersection,
									t_object *object);
double				ray_square_intersect(t_ray ray,
										t_object *object,
										double t_min,
										double t_max);
double				ray_cylinder_planes_intersect(t_ray ray,
												t_object *object,
												double t_min,
												double t_max);
int					get_caps_normal(t_vector intersection,
									t_object *object,
									t_vector *normal);
double				ray_cylinder_intersect(t_ray ray,
											t_object *object,
											double t_min,
											double t_max);
t_vector			get_cylinder_normal(t_ray ray,
										t_vector intersection,
										t_object *object);
double				ray_triangle_intersect(t_ray ray,
											t_object *object,
											double t_min,
											double t_max);
t_vector			get_triangle_normal(t_ray ray,
										t_vector intersection,
										t_object *object);

/*
** TRANSFORM
*/
void				move_camera(int key, t_vector *matrix);
void				rotate_camera(int key, t_camera *cam);
t_vector			get_translation(int key, t_vector *cam_matrix);
void				move_object(t_object *object);
void				rotate_object(int key, t_object *object, t_camera *cam);

/*
** ERROR
*/
void				ft_perror();
void				print_error_msg(char *msg);
void				parsing_error(t_rt *rt, char *msg);

#endif
