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

void  ft_printhelp(void){
  printf("-c ya da--bytes: Dosyanın başından itibaren kaş byte'ın yazdırılacağını belirtir.Bu seçeneklerin argümanları vadır.\n");
  printf("-n ya da --lines: Dosyanınbaşından itibaren kaçsatırın yazdırılacağını belirtir. Bu da argümanlı bir seçenektir.\n");
  printf("-v ya da --verbose: Dosyaların isimlerini de yazdırır.\n");
  printf("--help: Komut hakkında açıklamayı ekrana yazdırır. (Şu anda okuduğunuz yazıyı aynı biçimde kullanabilirsiniz)\n");
  printf("--version: Copyright bilgisini ve versiyon numarasını yazdırır\n");
}

void  ft_printversion(void){
  printf("Version -0.01\n");
}

void ft_printline_without_argv(int line){
  while (line){
    printf("%s",get_next_line(0));
    line--;
  }
}

void ft_printline_without_argv(int line){
  while (line){
    printf("%s",get_next_line(0));
    line--;
  }
}
void  ft_printin(void){
  char *buff;

  buff = (char *)malloc(sizeof(char) * 1000);
  while (1){
    scanf("%s",buff);
    printf("%s\n",buff);
  }
  free(buff);
}

void  ft_printdefault(int v, int ac, char ** av){
  int fd;
  int i;
  int count;

  count = 10;
  i = 1;
  if (ac == 2){
    If (v)
			printf("==> %s <==\n",av[i]);
    fd = open(av[i], O_RDONLY);
    while (count--){
      printf("%s", get_next_line(fd));
    }
    close (fd);
  }

  else if (ac > 2){
    while (ac >= 2){
			printf("==> %s <==\n",av[i]);
      fd = open(av[i], O_RDONLY);
      while (count--)
        printf("%s", get_next_line(fd));
      close(fd);
      ac--;
      count = 10;
      i++;
    }
  }
}
