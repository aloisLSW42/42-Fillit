/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleclet <aleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 09:52:11 by aleclet           #+#    #+#             */
/*   Updated: 2017/04/11 16:50:05 by aleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	***ft_alloc_table(char ***table, int n)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (!(table = (char***)ft_alloc(sizeof(char**) * (n + 1))))
		return (NULL);
	while ((n--))
	{
			table[n] = (char **)ft_alloc(sizeof(char**) * 5);
		while (y < 4)
		{
			table[n][y] = (char *)ft_alloc(sizeof(char*) * 5);
			x = 0;
			y++;
		}
		y = 0;
	}
	return (table);
}

void	ft_free_table(char ***table, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ft_free(table[i]);
		i++;
	}
	free(table);
}

void	ft_manage_xyi(int *i, int *y, int *x, char c)
{
	if (c != '\n')
	{
		*x += 1;
	}
	if (c == '\n')
	{
		*x = 0;
		*y += 1;
		if (*y == 5)
		{
			*y = 0;
			*i += 1;
		}
		//why when you replace by a ternaire expression it segfault ?
	}
}

int		ft_fill_table(char ***table, char *filename)
{
	int		fd;
	int		x;
	int		y;
	int		i;
	char	buf[1];

	x = 0;
	y = 0;
	i = 0;
	fd = ft_open_file(filename);
	while (read(fd, buf, 1))
	{
		if (buf[0] != '\n')
		{
			table[i][y][x] = buf[0];
		}
		ft_manage_xyi(&i, &y, &x, buf[0]);
	}
	return (table == NULL);
}