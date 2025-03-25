#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_printf("Erreur : impossible d'envoyer SIGUSR2\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_printf("Erreur : impossible d'envoyer SIGUSR1\n");
				exit(EXIT_FAILURE);
			}
		}
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Erreur : PID invalide\n");
		return (1);
	}
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_char(pid, message[i]);
		i++;
	}
	return (0);
}
