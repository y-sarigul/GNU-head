#include "ft_getopt_long.h"

void	ft_printbytes(int byte_av, char *sign)
{
	char *buff;
	int rd_bytes;
	int fd;

	buff = (char *)malloc(sizeof(char) * byte_av + 1);
	fd = open(sign, O_RDONLY);
	if (!buff){
		fprintf(stderr,"Buffer not created\n");
		exit(EXIT_FAILURE);
	}
	rd_bytes = read(fd, buff, byte_av);
	if (rd_bytes == -1)
		fprintf(stderr, "Read error\n");
	buff[rd_bytes] = '\0';
	close (fd);
	printf("%s",buff);
}

void	ft_printlines(int lines, char *sign){
	int fd;

	fd = open(sign, O_RDONLY);
	while (lines--){
		printf("%s",get_next_line(fd));
	}
}


































