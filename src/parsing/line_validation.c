
#include "../../include/miniRT.h"

validate_exact_element(char *line, t_miniRT *m, int i)
{
	
}

int define_element_type(char *line, t_miniRT *m)
{
	int	i;
	int	len;

	i = 0;
	while (i < E_TYPES_AMOUNT)
	{
		len = ft_strlen(m->e_names[i]);
		if (!ft_strncmp(line, m->e_names[i], len) \
			|| line[len] && line[len] == ' ')
		{
			m->e_count[i]++;
			if (ft_iscapital(m->e_names[i][0]) && m->e_count[i] > 1)
				return (print_err(DB_ELEM_MSG));
			/*validate_exact_element(char *line, t_miniRT *m, i)*/
		}
		i++;
	}
	if (i == E_TYPES_AMOUNT)
		return (print_err(VALID_MSG));
	return (SUCCESS);
}