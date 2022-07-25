/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 22:58:29 by idongmin          #+#    #+#             */
/*   Updated: 2022/07/25 17:42:09 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	init_map(t_cub *cub, t_list *map_lines)
{
	int	i;

	cub->map_width = ft_find_maxwidth(map_lines);
	cub->map_height = ft_lstsize(map_lines);
	cub->map = malloc(sizeof(char *) * (cub->map_height + 1));
	if (!(cub->map))
		ft_exit("Fail to malloc map(height)\n");
	cub->map[cub->map_height] = NULL;
	i = 0;
	while (map_lines)
	{
		cub->map[i] = malloc(sizeof(char) * (cub->map_width + 1));
		if (!(cub->map[i]))
			ft_exit("Fail to malloc map(width)\n");
		ft_memset(cub->map[i], ' ', cub->map_width);
		cub->map[i][cub->map_width] = '\0';
		i++;
		map_lines = (map_lines)->next;
	}
}

static void	init_user(t_cub *cub, int i, int j)
{
	if (cub->user.spawn_pos)
		ft_exit("Invalid map content(multiple player)\n");
	cub->user.spawn_pos = cub->map[i][j];
	cub->user.pos_x = 0.5f + j;
	cub->user.pos_y = 0.5f + i;
	if (cub->user.spawn_pos == 'N')
		cub->ray.th = 270;
	else if (cub->user.spawn_pos == 'S')
		cub->ray.th = 90;
	else if (cub->user.spawn_pos == 'E')
		cub->ray.th = 0;
	else if (cub->user.spawn_pos == 'W')
		cub->ray.th = 180;
}

static void	store_map(t_cub *cub, t_list *map_lines)
{
	int		i;
	int		j;
	char	*content;
	int		len_content;

	i = -1;
	while (++i < cub->map_height)
	{
		content = (char *)((map_lines)->content);
		len_content = (int)ft_strlen(content);
		j = -1;
		while (++j < len_content)
		{
			if (!ft_strchr("01NSEW \n", content[j]))
				ft_exit("Invalid map content(01NSEW)\n");
			cub->map[i][j] = content[j];
			if (ft_strchr("NSEW", content[j]))
				init_user(cub, i, j);
		}
		map_lines = (map_lines)->next;
	}
}

void	check_map(t_cub *cub)
{
	char	*line;
	int		wordcnt;
	char	**word;
	int		type;

	wordcnt = 0;
	cub->map_lines = ft_lstnew(NULL);
	line = get_next_line(cub->fd);
	while (line)
	{
		wordcnt = ft_wordcnt(line, ' ');
		word = ft_split(line, ' ');
		if (!word)
			ft_exit("Fail to split lines\n");
		type = check_type(cub, word, wordcnt);
		ft_two_point_free(word);
		if (type == MAP)
			ft_lstadd_back(&cub->map_lines, ft_lstnew(ft_strdup_nl(line)));
		free(line);
		line = get_next_line(cub->fd);
	}
	init_map(cub, cub->map_lines->next);
	store_map(cub, cub->map_lines->next);
	ft_lstclear(&cub->map_lines, free);
	error_check(cub);
}
