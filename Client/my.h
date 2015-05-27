

#ifndef	_MY_H_
#define	_MY_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av);
int	close_fd(int fd);
void	def_struct(struct sockaddr_in *s_in, char *ip, int port);
int	end_of_client();

#endif
