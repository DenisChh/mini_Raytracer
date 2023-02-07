/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:43:50 by user42            #+#    #+#             */
/*   Updated: 2021/03/20 13:45:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*
** UTILS
*/
void				string_array_free(char **split);
int					check_nargs(char **split, int nargs);
int					set_color(char **split, t_color *color);
int					set_coord(char **split, t_vector *coord);
int					correct_direction(t_vector dir);

/*
** SCENE
*/
int					set_resolution(char **split, t_rt *rt);
int					set_ambiant_light(char **split, t_rt *rt);
int					set_camera(char **split, t_rt *rt);
int					set_light(char **split, t_rt *rt);
int					set_scene(char *line, t_rt *rt);

/*
** OBJECTS
*/
int					set_sphere(char **split, t_rt *rt);
int					set_plane(char **split, t_rt *rt);
int					set_triangle(char **split, t_rt *rt);
int					set_cylinder(char **split, t_rt *rt);
int					set_square(char **split, t_rt *rt);

t_rt				set_rt(char *pathfile);

#endif
