#include "ft_getopt_long.h"

static struct option options[] = {
		{"bytes", 1, NULL, '1'},
		{"lines", 1, NULL, '2'},
		{"verbose", 0, NULL, '3'},
		{"help", 0, NULL, '4'},
		{"version", 0, NULL, '5'},
		{0, 0, 0, 0}
};

void	ft_checkflags(int ac, char **av){
	
	int		result, err_flag;
	int		c_bytes_flag, n_lines_flag, v_verbose_flag, help_flag, version_flag;
	int		c_bytes_arg, n_lines_arg;

	err_flag = c_bytes_flag = n_lines_flag = v_verbose_flag = help_flag = version_flag= 0;
	c_bytes_arg = 0;
	n_lines_arg = 0;
	opterr = 0; 
	while ((result = getopt_long(ac, av, "c:n:v", options, NULL)) != -1)
	{
		if (n_lines_flag == 0 && (result == 'c' || result == '1')){
			c_bytes_flag = 1;
			c_bytes_arg = ft_atoi(optarg);
		}
		else if (c_bytes_flag == 0 && (result == 'n' || result == '2')){
			n_lines_flag = 1;
			n_lines_arg = ft_atoi(optarg);
		}
		else if (result == 'v' || result == '3')
			v_verbose_flag = 1;
		else if (result == '4')
			help_flag = 1;
		else if (result == '5')
			version_flag = 1;

		else if (result == '?'){
			if (optopt == 'c')
				fprintf(stderr, "-c without argument!\n");
			else if (optopt == '1')
				fprintf(stderr, "--bytes without argument!\n");
			else if (optopt == 'n')
				fprintf(stderr, "-n without argument!\n");
			else if (optopt == '2')
				fprintf(stderr, "--lines without argument!\n");
			else if (optopt != 0)
				fprintf(stderr, "invalid option : %c\n", optopt);
			else
				fprintf(stderr, "invalid long option\n");
			err_flag = 1;
		}
	}

	if (err_flag == 1)
		exit(EXIT_FAILURE);

  if (help_flag)
    ft_printhelp();

  else if (version_flag)
    ft_printversion();

  else if (v_verbose_flag)
    ft_printdefault(v_verbose_flag, ac, av);

	else if (c_bytes_flag)
		ft_controlbytes(ac, av, optind, c_bytes_arg, v_verbose_flag);

	else if (n_lines_flag)
		ft_controllines(ac, av, optind, n_lines_arg, v_verbose_flag);
  
  else if (optind == ac)
    ft_printin();

  else if (optind == 1 && ac > 1){
    printf("ac = %d\n",ac);
    printf("v == %d\n",version_flag);
    printf("default flag in \n");
    ft_printdefault(v_verbose_flag, ac, av);
  }
}
