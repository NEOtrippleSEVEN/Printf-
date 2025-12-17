/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuchins <jbuchins@student.42Wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 15:57:03 by jbuchins          #+#    #+#             */
/*   Updated: 2025/11/29 16:07:56 by jbuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif // BUFFER_SIZE

# include <stdlib.h>
# include <unistd.h>

typedef struct s_fd_list
{
	int					fd;
	char				*cache;
	struct s_fd_list	*next;
}						t_fd_list;

char					*get_next_line(int fd);

int						grow_cache(t_fd_list *fd_node, char *buffer);
void					rm_node(t_fd_list *fd_node, t_fd_list **h);
int						shrink_cache(t_fd_list *fd_node);
void					*ft_gnlcalloc(unsigned int nmemb, unsigned int size);
t_fd_list				*addback(int fd, t_fd_list **h);

#endif // GET_NEXT_LINE_BONUS_H