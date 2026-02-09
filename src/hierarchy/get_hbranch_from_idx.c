#include "mlxui.h"

t_hbranch   *get_hbranch_ref_idx(t_htree *htree, size_t idx)
{
    return (*(t_hbranch **)get_vector_value(&htree->refs, idx));
}

t_hbranch   *get_hbranch_child_idx(t_hbranch *parent, size_t idx)
{
    return (get_hbranch_ref_idx(parent->head,
        *(size_t *)get_vector_value(parent->childs, idx)
    ));
}

ssize_t	get_hbranch_index(t_vector *v, t_hbranch *hbranch)
{
	size_t	i;
	size_t	*refs_idx;

	if (!v || !hbranch)
		return (-1);
	i = 0;
	refs_idx = v->data;
	while (i < v->num_elements)
	{
		if (hbranch == get_hbranch_ref_idx(hbranch->head, refs_idx[i]))
			return (i);
		i++;
	}
	return (-1);
}
