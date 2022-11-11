#include "ft_getopt_long.h"

void	ft_controlbytes(int ac, char **av, int opt, int bytes_av, int v)
{
  int rd;
  int i;
  char *buff;

  buff =(char *)malloc(sizeof(char) * (bytes_av + 1));
  i = 0;
	if ((ac - opt) >= 2 || v)
	{
		while (opt < ac)
		{
			printf("==> %s <==\n",av[opt]);
      ft_printbytes(bytes_av, av[opt++]);
		}
	}

	else if ((ac - opt) == 1)
		ft_printbytes(bytes_av, av[opt]);

  else if (opt == ac){
    while (i <= bytes_av){
      rd = read(0, buff, bytes_av);
        if (rd >= bytes_av){
          buff[bytes_av] = '\0';
          printf("%s",buff);
          break;
        }
      i = i + ft_strlen(buff);
      buff[bytes_av] = '\0';
      printf("%s",buff);
    }
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
		ft_printlines(lines_av, av[opt]);

  else if (ac == opt)
    ft_printline_without_argv(lines_av);
}
