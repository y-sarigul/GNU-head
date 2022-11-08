#ifndef FT_GETOPT_LONG_H
#define FT_GETOPT_LONG_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include "get_next_line.h"

//ft_checkflag.c
void	ft_checkflags(int , char**);

//ft_utils.c
int		ft_atoi(const char *);

//ft_control.c
void	ft_controlbytes(int, char **, int, int, int);
void	ft_controllines(int, char **, int, int, int);

//ft_print.c
void	ft_printbytes(int, char *);
void	ft_printlines(int, char *);

#endif
