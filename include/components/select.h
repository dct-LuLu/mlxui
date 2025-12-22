/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaubry-- <jaubry--@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 03:07:04 by jaubry--          #+#    #+#             */
/*   Updated: 2025/12/23 00:18:40 by jaubry--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SELECT_H
# define SELECT_H

# define SELECT_LABEL_LEN 20

# define MAX_OPTIONS 5

typedef struct s_select
{
	union
	{
		ANON_GEOM_PACKED;
		t_button	button;
	};
	t_textbox	*selected; //text always displayed
	bool		expanded;
	size_t		option_index;
	t_hbranch	*label_box;
	t_hbranch	*expand;
	t_hbranch	*margin;//invisible slightly smaller than expanded box
	t_vector	*options;// button childs of margin
	t_vector	*actions;
	bool		nullable;
}	t_select;

t_hbranch	*add_select(t_hbranch *parent_branch, char label[SELECT_LABEL_LEN]);
void	render_select(t_hbranch *hbranch, t_select *select);
int			add_select_option(t_hbranch *select, char option_name[SELECT_LABEL_LEN],
		void (*option_action)(t_hbranch *hbranch, void *arg));

#endif//SELECT_H
