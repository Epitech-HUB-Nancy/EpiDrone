
#include "my.h"

void	def_struct(struct sockaddr_in *s_in, int port)
{
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
}

int	end_main(int fd)
{
  if (close(fd) == -1)
    return (1);
  return (0);
}

int	ret_fd()
{
  struct protoent	*pe;
  int			fd;

  if ((pe = getprotobyname("TCP")) == NULL)
    exit(-1);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    exit(-1);
  return (fd);
}

int	close_fd(int fd)
{
  if (close(fd) == -1)
    return (1);
  return (1);
}

int	write_fd(char *str, int fd)
{
  char	buff[40960];
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i] && str[i] != ']')
    i++;
  if (str[i] == ']')
    {
      i++;
      while (str[i])
        buff[j++] = str[i++];
      buff[j] = 0;
      write(fd, buff, strlen(buff));
      return (0);
    }
  return (-1);
}


void	check_fd(int client_fd)
{
  int	i;

  if (client_fd == -1)
    {
      i = close_fd(client_fd);
      exit(-1);
    }
}

void	listen_fd(int fd)
{
  int	i;

  if (listen(fd, 42) == -1)
    {
      i = close_fd(fd);
      exit(-1);
    }
}

int	exec(char **av, char **env)
{
  struct sockaddr_in	s_in;
  struct sockaddr_in	s_in_client;
  socklen_t		s_in_size;
  int			fd;
  int			pid;
  int			client_fd;
  char			*client_ip;

  s_in_size = sizeof(s_in_client);
  fd = ret_fd();
  def_struct(&s_in, atoi(av[1]));
  if (bind(fd, (const struct sockaddr *)&s_in, sizeof(s_in)) == -1)
    return (close_fd(fd));
  listen_fd(fd);
  while (1)
    {
      client_fd = accept(fd, (struct sockaddr *)&s_in_client, &s_in_size);
      if (!(pid = fork()))
	{
	  check_fd(client_fd);
	  client_ip = inet_ntoa(s_in_client.sin_addr);
	  do_cmd(client_fd, client_ip, env);
	}
    }
  end_main(fd);
}

int	main(int ac, char **av, char **env)
{
  if (ac != 2)
    return (1);
  exec(av, env);
}

