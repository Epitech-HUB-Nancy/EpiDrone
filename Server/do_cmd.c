
#include "my.h"

int	do_cmd(int client_fd, char *client_ip, char **env)
{
  char		buff[40960];
  
  dup2(client_fd, 1);
  write(1, "Successfull !!!", 10);
  return (0);
}
