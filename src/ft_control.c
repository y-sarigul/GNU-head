#include "ft_getopt_long.h"

void	ft_controlbytes(int ac, char **av, int opt, int bytes_av, int v)
{
	if ((ac - opt) >= 2 || v)
	{
		while (opt < ac)
		{
			printf("==> %s <==\n",av[opt]);
			ft_printbytes(bytes_av, av[opt++]);
		}
	}

	else if ((ac - opt) == 1){
		ft_printbytes(bytes_av, av[opt]);
	}
}

void	ft_controllines(int ac, char **av, int opt, int lines_av, int v)
{	
	if ((ac - opt) >= 2 || v)
	{
		while (opt < ac)
		{
			printf("==> %s <==\n",av[opt]);
			ft_printlines(lines_av, av[opt++]);
		}
	}

	else if ((ac - opt) == 1)
	{
		ft_printlines(lines_av, av[opt]);
	}
}
