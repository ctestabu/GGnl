/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 20:13:03 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/27 20:13:03 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_magic(int fd, char *s[], char **line)
{
	int		len;
	char	*helper;

	len = 0;
	if (*s[fd] == '\0')
		return (0);
	while (s[fd][len] != '\n' && s[fd][len] != '\0')// длина до обозначения конца
		len++;
	*line = ft_strsub(s[fd], 0, len);// обрезание стека
	helper = ft_strdup(&*(s[fd] + len + 1)); // что полсе \n
	ft_memdel((void**)&s[fd]);
	s[fd] = ft_strdup(helper);//положили остаток строки
	ft_memdel((void**)&helper);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char	*s[MAX_FD];
	char		line_buf[BUFF_SIZE + 1];
	char		*helper;
	int			ret;

	if (fd == -1 || (read(fd, line_buf, 0) == -1) || fd > MAX_FD)
		return (-1);
	(s[fd] == NULL) && (s[fd] = ft_strnew(0));
	while ((ft_strchr(s[fd], '\n') == NULL) || (ft_strchr(s[fd], '\0') == NULL))
	{
		ret = read(fd, line_buf, BUFF_SIZE);//считывает файл по фд
		if (ret == 0 && *s[fd] != '\0')// нету символов в строке
		{
			helper = s[fd];
			s[fd] = ft_strjoin(helper, "\n");
			ft_memdel((void**)&helper);
		}
		if (ret == 0)
			break ;
		line_buf[ret] = '\0';// кидаем \0 в конец считанной строки
		helper = s[fd];
		s[fd] = ft_strjoin(helper, line_buf);//собираем строку по лайнбафам
		ft_memdel((void**)&helper);
	}
	return (line_magic(fd, s, line));
}
