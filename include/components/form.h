/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:18:05 by jaubry--          #+#    #+#             */
/*   Updated: 2025/11/13 18:17:55 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_H
# define FORM_H

typedef struct s_form
{
	union
	{
		ANON_GEOM_PACKED;
		t_box	box;
	};
	t_textbox	textbox;

}	t_form

t_hbranch	*add_form(t_hbranch *parent_branch, );
void		precompute_form(t_hbranch *hbranch);
void		render_form(t_hbranch *hbranch);

#endif//FORM_H

/*
	HOOK (TYPING) char textbuffer[FORM_SIZE];
	FORMATER (STRING CORRECTING, AFTER ENTER or CONTEXT OUT)
	VALIDATOR (TRANSFORM STRING INTO WANTED VALUE)
*/

/*
	const char	suffix_morpheme[5];
	added after formated string and not used for centering
*/
