/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuchins <jbuchins@student.42Wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 21:44:51 by jbuchins          #+#    #+#             */
/*   Updated: 2025/12/09 14:29:30 by jbuchins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define GREEN "\033[1;32m"
#define RED "\033[1;31m"
#define BLUE "\033[34m"
#define BBLUE "\033[1;34m"
#define RESET "\033[00m"

int	get_lines(int fd, char **ft, char **og, char **temprtrn, int *rtrn_ft, int *rtrn_og, char *type);
int	test_type(const char *path, char * flag);


static char	*Docs[] = { "./Text/PERCENT.txt", "./Text/POINTER.txt",
		"./Text/DECIMAL.txt", "./Text/HEXLOW.txt", "./Text/HEX.txt",
		"./Text/UINT.txt", "./Text/INT.txt", "./Text/STRING.txt",
		"./Text/CHAR.txt"};

void cut_newline(char * str)
{
	int i;
	
		i = 0;
		while(str[i] != '\0')
			i++;
		while(str[i] != '\n' && i >= 0)
			i--;
		if(i > 0)
			str[i] = '\0';
}
void print_header(char * header)
{
	int total_len=40;
	printf(BBLUE"========= %s",header);
	printf("%.*s\n\n", (int)(total_len - strlen(header))," ======================================="RESET);
}

int	main(int argc, char ** argv)
{
	setvbuf(stdout, NULL,_IONBF,0);
	if(argc > 3)
		return(0);
	printf (BBLUE"Content and Return compare\n\n"RESET);
	char *flag;
	if(argc == 1)
		flag = "eval";
	else
		flag = argv[1];
	int	i;
	int wrongs;
	int kos;

	wrongs = 0;

	i = 8;
	while(i >= 0)
	{
		kos = test_type(Docs[i], flag);
		i--;
		wrongs += kos;
	}
	if(wrongs)
		{
		if(strcmp(argv[1], "eval") != 0)
			printf(RED"%d Total Fails\n"RESET,wrongs);
		else
			printf(RED"%d Failed Category\n"RESET,wrongs);
		}
	else 
		printf(GREEN"ALL TEST PASSED\n"RESET);
		
	printf (BLUE"\nTESTER MADE BY @JBUCHINS\nEmail: jbuchins@student.42Wolfsburg.de\n\n"RESET);
		return (0);

}

int	test_type(const char *path, char * flag)
{
	int		fd;
	char	*ft;
	char	*og;
	char *temprtrn;
	int		rtrn_ft;
	int		rtrn_og;
	char	type[32];
	int compare;
	int rtrn_compare;
	int linecount;
	int ko_count;
	int testcount;

	ft = NULL;
	og = NULL;
	ko_count = 0;
	linecount= 0;
	testcount = 0;
	fd = open(path, O_RDONLY);
	if(fd <= 0)
		return 0;
	if(get_lines(fd, &ft, &og, &temprtrn, &rtrn_ft, &rtrn_og, type) == -1)
	{
		close(fd);
		return 0;
	}
	print_header(type);
	while(1)
	{
		cut_newline(ft);
		cut_newline(og);
		cut_newline(temprtrn);
		compare = strcmp(ft+2,og+2);
		rtrn_compare = (rtrn_ft == rtrn_og);
		if(compare != 0 || rtrn_compare != 1)
		{
			linecount++;
			testcount++;
			if(strcmp(flag,"eval") == 0)
			{
				printf(RED"[KO]"RESET"\n");
				printf("Case:\n'%s' | '%s' | Type:%s\n", og, ft, temprtrn);
				printf(RED"Testing Stopped for this Category\n"RESET);
				ko_count++;
				break;
			}
			else
			{
				printf(RED"\n[KO] "RESET);
				printf("%s | %s | Type:%s", og, ft, temprtrn);
				ko_count++;
				linecount = 0;
			}
		}
		else 
		{
			testcount++;
			linecount++;
			if((strcmp(flag, "show") == 0))
				printf(GREEN"[OK]"RESET"%s | %s | Type:%s\n", ft, og, temprtrn);
			else
				printf(GREEN"[OK] "RESET);
		}
		if(linecount % 25 == 0)
			printf("\n");
		free(ft);
		free(og);
		free(temprtrn);
		if(get_lines(fd, &ft, &og, &temprtrn, &rtrn_ft, &rtrn_og, type) == -1)
			break;
		
	}
	if(ko_count == 0)
	{	
		printf(GREEN"\n\nALL TEST PASSED\n"RESET);
		printf(GREEN"========================================\n\n"RESET);
	}
	else
	{
		printf(GREEN"\n%d [OK]"RESET" | ",(testcount-ko_count));
		printf(RED"%d [KO]"RESET" in %s\n", ko_count,type);
		printf(RED"========================================\n\n"RESET);
	}
	close(fd);
	return ko_count;
}

int	get_lines(int fd, char **ft, char **og, char **temprtrn, int *rtrn_ft, int *rtrn_og, char *type)
{
	*og = get_next_line(fd);
	*ft = get_next_line(fd);
	*temprtrn = get_next_line(fd);
	if(*ft == NULL || *og == NULL || *temprtrn == NULL)
	{
		if(*ft)
			free(*ft);
		if(*temprtrn)
			free(*temprtrn);
		if(*og)
			free(*og);
		return (-1);
	}
	if (sscanf(*temprtrn, "%30s ft=%d og=%d", type, rtrn_ft, rtrn_og) != 3)
	{
		free(*ft);
		free(*temprtrn);
		free(*og);
		printf("ERROR WHILE PARSING\n");
		return (-1);
	}
	return(1);
}

// GNL


static char	*check_in_cache(t_fd_list *fd_node)
{
	int		i;
	char	*cache_result;

	i = 0;
	if (fd_node->cache == NULL)
		return (NULL);
	while (fd_node->cache[i] != '\n' && fd_node->cache[i])
		i++;
	if (fd_node->cache[i] == '\n')
	{
		cache_result = ft_gnlcalloc(i + 2, sizeof(char));
		if (!cache_result)
			return (NULL);
	}
	else
		return (NULL);
	while (i >= 0)
	{
		cache_result[i] = fd_node->cache[i];
		i--;
	}
	if (shrink_cache(fd_node) < 0)
		return (free(cache_result), NULL);
	return (cache_result);
}

static char	*end_fd(t_fd_list *fd_node, char *buffer, t_fd_list **h)
{
	char	*result;
	int		i;

	i = 0;
	if (fd_node->cache && fd_node->cache[i])
		while (fd_node->cache[i])
			i++;
	else
	{
		rm_node(fd_node, &(*h));
		return (free(buffer), NULL);
	}
	result = ft_gnlcalloc(i + 1, sizeof(char));
	if (result == NULL)
		return (free(buffer), NULL);
	while (i >= 0)
	{
		result[i] = fd_node->cache[i];
		i--;
	}
	rm_node(fd_node, &(*h));
	free(buffer);
	return (result);
}

static char	*get_result(char *result, t_fd_list *fd_node, t_fd_list **h)
{
	ssize_t	bytes;
	char	*buffer;

	bytes = 1;
	while (result == NULL)
	{
		result = check_in_cache(fd_node);
		if (result)
			return (result);
		buffer = ft_gnlcalloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (NULL);
		bytes = read(fd_node->fd, buffer, BUFFER_SIZE);
		if (bytes > 0)
			if (!(grow_cache(fd_node, buffer)))
				return (rm_node(fd_node, &(*h)), free(buffer), NULL);
		if (bytes < 0)
			return (rm_node(fd_node, &(*h)), free(buffer), NULL);
		if (result == NULL && bytes == 0)
		{
			result = end_fd(fd_node, buffer, &(*h));
			return (result);
		}
	}
	return (result);
}

static t_fd_list	*check_create_fd_node(int fd, t_fd_list **h)
{
	t_fd_list	*temp;

	temp = (*h);
	while (temp)
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = addback(fd, &(*h));
	return (temp);
}

char	*get_next_line(int fd)
{
	t_fd_list			*fd_node;
	static t_fd_list	*head;
	char				*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	fd_node = check_create_fd_node(fd, &head);
	if (fd_node == NULL)
		return (NULL);
	result = NULL;
	result = get_result(result, fd_node, &head);
	return (result);
}

t_fd_list	*addback(int fd, t_fd_list **h)
{
	t_fd_list	*new_node;
	t_fd_list	*temp;

	temp = (*h);
	if (temp != NULL)
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
	}
	new_node = ft_gnlcalloc(1, sizeof(t_fd_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd = fd;
	new_node->cache = NULL;
	if (temp == NULL)
	{
		temp = new_node;
		(*h) = temp;
	}
	else
		temp->next = new_node;
	return (new_node);
}

int	shrink_cache(t_fd_list *fd_node)
{
	size_t	i;
	size_t	x;
	char	*new_cache;

	i = 0;
	x = 0;
	new_cache = NULL;
	while (fd_node->cache && fd_node->cache[i] != '\n' && fd_node->cache[i])
		i++;
	while (fd_node->cache && fd_node->cache[x])
		x++;
	if (x - i)
		new_cache = ft_gnlcalloc((x - i), sizeof(char));
	if (new_cache == NULL)
		return (-1);
	i++;
	x = 0;
	while (fd_node->cache[i + x])
	{
		new_cache[x] = fd_node->cache[x + i];
		x++;
	}
	free(fd_node->cache);
	fd_node->cache = new_cache;
	return (1);
}

int	grow_cache(t_fd_list *fd_node, char *buffer)
{
	char	*temp;
	size_t	cache_size;
	int		i;
	int		x;

	i = 0;
	x = -1;
	cache_size = 0;
	if (fd_node->cache != NULL)
		while (fd_node->cache[cache_size])
			cache_size++;
	temp = ft_gnlcalloc((cache_size + 1) + BUFFER_SIZE, sizeof(char));
	if (temp == NULL)
		return (-1);
	while (fd_node->cache != NULL && fd_node->cache[i])
	{
		temp[i] = fd_node->cache[i];
		i++;
	}
	while (buffer[++x])
		temp[i + x] = buffer[x];
	free(buffer);
	free(fd_node->cache);
	fd_node->cache = temp;
	return (1);
}

void	*ft_gnlcalloc(unsigned int nmemb, unsigned int size)
{
	unsigned int	i;
	unsigned char	*callo;

	i = 0;
	callo = malloc((nmemb * size));
	if (!callo)
		return (NULL);
	while (i < (nmemb * size))
	{
		callo[i] = 0;
		i++;
	}
	return (callo);
}

void	rm_node(t_fd_list *fd_node, t_fd_list **h)
{
	t_fd_list	*cur;
	t_fd_list	*delete;

	if (!(*h))
		return ;
	cur = (*h);
	if ((cur->fd) == (fd_node->fd))
	{
		(*h) = cur->next;
		free(cur->cache);
		free(cur);
		return ;
	}
	delete = cur->next;
	while (cur)
	{
		if (delete->fd == fd_node->fd)
		{
			cur->next = delete->next;
			free(delete->cache);
			return (free(delete));
		}
		cur = delete;
		delete = cur->next;
	}
}
