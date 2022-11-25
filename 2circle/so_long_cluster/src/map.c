/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 07:28:28 by idongmin          #+#    #+#             */
/*   Updated: 2022/04/01 16:27:56 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_filename(char *file_name)
{
	int		len;
	char	*start;

	len = ft_strlen(file_name);
	start = (char *)&file_name[(len - 4)];
	if (ft_strncmp(start, ".ber", 4) == 0)
		return (1);
	error("Please put in the correct path.\n");
	return (0);
}

void	get_map_height_and_malloc_map(char *file_name, t_game **game)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error("fd is wrong\n");
	line = get_next_line(fd);
	if (!line || line[0] == 0)
		error("fail recieve map\n");
	((*game)->map_h) = 0;
	while (line)
	{
		free(line);
		((*game)->map_h) += 1;
		line = get_next_line(fd);
	}
	(*game)->map = (char **)malloc(sizeof(char *) * ((*game)->map_h) + 1);
	if (!(*game)->map)
		error("malloc error\n");
	close(fd);
}

int	read_map_file(char *file_name, t_game **game)
{
	char	*line;
	int		fd;
	int		i;

	get_map_height_and_malloc_map(file_name, game);
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			(*game)->map_w = ft_strlen(line) - 1;
		else
			(*game)->map_w = ft_strlen(line);
		(*game)->map[i] = malloc(sizeof(char) * ((*game)->map_w + 1));
		if (!(*game)->map[i])
			error("malloc error\n");
		ft_strlcpy((*game)->map[i], line, (*game)->map_w + 1);
		(*game)->map[i++][(*game)->map_w] = '\0';
		free(line);
		line = get_next_line(fd);
	}
	(*game)->map[i] = 0;
	close(fd);
	return (1);
}

int	make_map(int argc, char **argv, t_game **game)
{
	if (argc != 2)
		error("argument count is not two\n");
	(*game) = malloc(sizeof(t_game));
	if (!(*game))
		error("malloc error\n");
	if (check_filename(argv[1]))
	{
		if (!read_map_file(argv[1], game))
			return (0);
		if (check_map_data(game))
			return (1);
	}
	return (0);
}
