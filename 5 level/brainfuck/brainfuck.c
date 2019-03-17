#include <unistd.h>
#include <stdlib.h>

int		ft_find_brackets(char *argv, int i)
{
	int counter;
	int direction;

	counter = 0;
	if (argv[i] == '[')
		direction = 1;
	else if (argv[i] == ']')
		direction = -1;
	while (argv[i])
	{
		if (argv[i] == '[')
			counter++;
		else if (argv[i] == ']')
			counter--;
		if ((argv[i] == '[' || argv[i] == ']') && !counter)
			return (i);
		i += direction;
	}
	return (0);
}

void	ft_memset(void *src, size_t size)
{
	size_t i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)src)[i] = 0;
		i++;
	}
}

void	brainfuck(char *argv)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * 2048);
	ft_memset(str, sizeof(str));
	while (argv[i])
	{
		if (argv[i] == '>')
			j++;
		if (argv[i] == '<')
			j--;
		if (argv[i] == '+')
			str[j]++;
		if (argv[i] == '-')
			str[j]--;
		if (argv[i] == '.')
			write(1, &str[j], 1);
		if ((argv[i] == '[' && !str[j]) || (argv[i] == ']' && str[j]))
			i = ft_find_brackets(argv, i);
		i++;
	}
}

int		main(int argc, char *argv[])
{
	if (argc == 2)
		brainfuck(argv[1]);
	else
		write(1, "\n", 1);
	return (0);
}