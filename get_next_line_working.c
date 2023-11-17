#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char	*get_next_line(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*line;
	int		bytes_read;
	int		counter;
	int		index;
	int		index_temp;
	int		i;

	line = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		counter = 0;
		while (counter < bytes_read)
		{
			if (buffer[counter] == '\n')
            if
			{
				line = (char *)realloc(line, index + 1);
				if (line == NULL)
					return (NULL);
				index_temp = 0;
				while (index_temp < index)
				{
					line[index_temp] = buffer[index_temp];
					index_temp++;
				}
				line[index] = '\0';
				return (line);
			}
			index++;
			counter++;
		}
		line = (char *)realloc(line, index + bytes_read + 1);
		if (line == NULL)
			return (NULL);
		i = 0;
		while (counter < bytes_read)
		{
			line[index++] = buffer[counter++];
			i++;
		}
	}
	free(line); // Free allocated memory before returning NULL
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
