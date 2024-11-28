/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:20:43 by sbartoul          #+#    #+#             */
/*   Updated: 2024/11/28 22:35:20 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_settings(t_settings *settings)
{
	settings->render_scale = 2;
	settings->edit_scale = 0.85;
	settings->render_w = 1920 * settings->render_scale;
	settings->render_h = 1080 * settings->render_scale;
	settings->edit_w = 1920 * settings->edit_scale;
	settings->edit_h = 1080 * settings->edit_scale;
	settings->disp_w = 1920;
	settings->disp_h = 1080;
	settings->collisions = true;
	settings->reflection_depth = REFLECTION_DEPTH;
}
