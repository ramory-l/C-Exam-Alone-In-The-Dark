#include <unistd.h>

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

void	rostring(char *argv)
{
	int	i;
	int	j;
	int k;

	i = 0;
	while (ft_isspace(argv[i]) && argv[i])
		i++;
	j = i;
	while (!ft_isspace(argv[j]) && argv[j])
		j++;
	while (ft_isspace(argv[j]) && argv[j])
		j++;
	k = j;
	while (argv[j])
	{
		if (ft_isspace(argv[j]) && !ft_isspace(argv[j + 1]) && argv[j + 1])
			write(1, " ", 1);
		else if (!ft_isspace(argv[j]) && argv[j])
			write(1, &argv[j], 1);
		j++;
	}
	if (argv[k])
		write(1, " ", 1);
	while (!ft_isspace(argv[i]) && argv[i])
	{
		write(1, &argv[i], 1);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc > 1)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
