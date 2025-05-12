
#include "../../include/miniRT.h"

int	allocation(t_miniRT *m)
{
	if (m->e_count[E_SPHERE])
	{
		m->spheres = ft_calloc(m->e_count[E_SPHERE], sizeof(t_sphere));
		if (!m->spheres)
			return (print_err(MLLC_MSG));
	}
	if (m->e_count[E_PLANE])
	{
		m->planes = ft_calloc(m->e_count[E_PLANE], sizeof(t_plane));
		if (!m->planes)
			return (print_err(MLLC_MSG));
	}
	if (m->e_count[E_CYLINDER])
	{
		m->cylinders = ft_calloc(m->e_count[E_CYLINDER], sizeof(t_cylinder));
		if (!m->cylinders)
			return (print_err(MLLC_MSG));
	}
	return (SUCCESS);
}
