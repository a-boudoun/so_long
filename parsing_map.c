#include"so_long.h"

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	map_check(char *filename, t_program *program, int fd)
{
	int len;
	char *line;

	if (fd < 0 || ft_strcmp(".ber", &filename[ft_strlen(filename) - 4]))
		exit_error(1);
	program->map.column = 0;
	line = get_next_line(fd);
	program->map.row = ft_strlen(line) - 1;
	while (line)
	{
		if (line[ft_strlen(line) + 1] == '\0')
			len = ft_strlen(line);
		else 
			len = ft_strlen(line) - 1;
		if (len != program->map.row)	
			exit_error(1);
		program->map.column += 1;
		line = get_next_line(fd);
	}
	close(fd);
}

void parsing_map(char *filename, t_program *program)
{
	int fd;
	int i;
	int j;
	char *line;

	i = -1;
	fd = open(filename, O_RDONLY);
	map_check(filename, program, fd);
	program->map.map = malloc(sizeof(char *) * program->map.column);
	if (!program -> map.map)
		exit_error(2);
	line = get_next_line(fd);
	while (++i < program->map.column)
	{
		j = -1;
		program->map.map[i] = malloc((sizeof(char) * program->map.row));
		if (!program -> map.map)
			exit_error(2);
		while (j < program->map.row)
			program->map.map[i][++j] = line[++j];
		line = get_next_line(fd);
	}

// 	i = 0;
// 	printf("%s", program->map.map[i]);
 	close(fd);
}