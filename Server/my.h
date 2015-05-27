/*
** my.h for  in /home/cengiz_c/rendu/PSU_2014_myftp/src_client
** 
** Made by Cengiz Cihan
** Login   <cengiz_c@epitech.net>
** 
** Started on  Sun Mar 22 17:04:06 2015 Cengiz Cihan
** Last update Thu Mar 26 17:35:00 2015 Cengiz Cihan
*/

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

#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int	my_strlen(char *str);
int	nb_word(char *str);
char	**my_malloc_tab(char **tab, int size, int nb);
char	**my_str_to_word_tab(char **tab, char *str);
int	do_ls(char **env);
int	close_fd(int fd);
void	do_pwd();
void	do_get(char *buff);
int	create_file(char *str);
int	write_fd(char *str, int fd);
int	do_file(char *str);
int	do_cmd(int client_fd, char *client_ip, char **env);
void	def_struct(struct sockaddr_in *s_in, int port);
int	end_main(int fd);
int	ret_fd();
void	check_fd(int client_fd);
void	listen_fd(int fd);
int	exec(char **av, char **env);
void	send_msg(char *user, char *cpy, int client_fd);
void	check_pwd(char *user, char *pwd, int client_fd, char *tmp);
void	do_identification(char *buff, int client_fd);
int	main(int ac, char **av, char **env);

#endif
