/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 13:45:53 by user42            #+#    #+#             */
/*   Updated: 2021/03/20 13:57:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_H
# define MATHS_H

/*
** VECTOR
*/
t_vector			new_vector(double x, double y, double z);
t_vector			vector_add(t_vector v1, t_vector v2);
t_vector			vector_sub(t_vector v1, t_vector v2);
t_vector			vector_mul(double x, t_vector v2);
double				vector_dot(t_vector v1, t_vector v2);
t_vector			vector_cross(t_vector v1, t_vector v2);
double				vector_len(t_vector v);
t_vector			vector_normalize(t_vector v);

/*
** MATRIX
*/
t_vector			vector_matrix_mul(t_vector v, t_vector *matrix);
t_vector			dir_matrix_mul(t_vector v, t_vector *matrix);
void				matrix_cpy(t_vector *dst, t_vector *src);
void				matrix_mul(t_vector *m1, t_vector *m2);
void				matrix_invert(t_vector *m);
void				matrix_transpose(t_vector *m);
void				init_rotation_matrix(t_vector *m);
void				set_xrotation_matrix(t_vector *m, double angle);
void				set_yrotation_matrix(t_vector *m, double angle);
void				set_zrotation_matrix(t_vector *m, double angle);

#endif
