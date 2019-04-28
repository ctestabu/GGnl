/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctestabu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 13:18:10 by ctestabu          #+#    #+#             */
/*   Updated: 2019/04/21 13:18:10 by ctestabu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_GET_NEXT_LINE_H
# define GNL_GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_FD 1000

# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int					get_next_line(int const fd, char **line);

#endif
