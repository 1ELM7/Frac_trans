/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmendez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:14:52 by jmendez           #+#    #+#             */
/*   Updated: 2023/02/19 19:33:25 by jmendez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H
# ifdef __linux__
#  define K_ESC			65307
#  define K_NUM_MULT	65450
#  define K_NUM_DIV		65455
#  define K_NUM_PLUS	65451
#  define K_NUM_MINUS	65453
#  define K_NUM_ENTER	65421
#  define K_NUM_0		65438
#  define K_NUM_1       65436
#  define K_NUM_2       65433
#  define K_NUM_3       65435
#  define K_NUM_4       65430
#  define K_NUM_5       65437
#  define K_NUM_6       65432
#  define K_NUM_7       65429
#  define K_NUM_8       65431
#  define K_NUM_9       65434
#  define K_UP			65362
#  define K_DOWN		65364
#  define K_LEFT		65361
#  define K_RIGHT		65363
#  define K_DIGIT_1		49
#  define K_DIGIT_2		50
#  define K_DIGIT_3		51
#  define K_DIGIT_4		52
#  define K_DIGIT_5		53
#  define K_DIGIT_6		54
#  define K_DIGIT_7		55
#  define K_DIGIT_8		56
#  define K_J			106
#  define K_M			109
#  define K_B			98
# else
#  define K_ESC			53
#  define K_NUM_MULT	67
#  define K_NUM_DIV		75
#  define K_NUM_PLUS	69
#  define K_NUM_MINUS	78
#  define K_NUM_ENTER	76
#  define K_NUM_0		82
#  define K_UP			126
#  define K_DOWN		125
#  define K_LEFT		123
#  define K_RIGHT		124
#  define K_DIGIT_1		18
#  define K_L			37
# endif
#endif
