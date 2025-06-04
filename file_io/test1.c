#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>




void print_usage(const char *program);


void print_usage(const char *program)
{
	printf("usage : %s <file>\n",program);
	return;
}


int main(int argc,char **argv)
{
	if(argc < 2)
	{
		print_usage(argv[0]);
		return -1;
	}


	int fd = open(argv[1],O_RDONLY);
	if(fd == -1)
	{
		perror("open : ");
		return -2;
	}

	char buf[1024] = {0};

	ssize_t numread = read(fd,buf,sizeof(buf));
	if(numread == -1)
	{
		perror("read : ");
		return -3;
	}

	puts(buf);

	int status = close(fd);
	if(status == -1)
	{
		perror("close : ");
		return -4;
	}


	return 0;
}



