/*
** main.c for  in /home/cengiz_c/rendu/PSU_2014_myftp
** 
** Made by Cengiz Cihan
** Login   <cengiz_c@epitech.net>
** 
** Started on  Tue Mar 17 15:08:35 2015 Cengiz Cihan
** Last update Wed May 27 14:54:35 2015 Cengiz Cihan
*/

#include "my.h"

int	close_fd(int fd)
{
  if (close(fd) == -1)
    return (1);
  return (1);
}

void	def_struct(struct sockaddr_in *s_in, char *ip, int port)
{
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = inet_addr(ip);
}

int	end_of_client()
{
  write(1, "End of the connection !\n", 24);
  return (1);
}

int	send_cmd(int fd)
{
  char		buff[40960];
  static int	first = 0;
  int		i;

  i = read(fd, buff, 40959);
  buff[i] = 0;
  write(1, "Drone : ", 8);
  write(1, buff, strlen(buff));
  return (0);
}

int	main(int ac, char **av)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			exit;

  exit = 0;
  if (ac != 3)
    return (1);
  pe = getprotobyname("TCP");
  if (!pe)
    return (1);
  while (exit == 0)
    {
      fd = socket(AF_INET, SOCK_STREAM, pe->p_proto);
      if (fd == -1)
	return (1);
      def_struct(&s_in, av[1], atoi(av[2]));
      if (connect(fd, (struct sockaddr *)&s_in, sizeof(s_in)) == -1)
	return (close_fd(fd));
      exit = send_cmd(fd);
      if (close(fd) == -1)
	return (1);
    }
  return (0);
}
