#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

char *get_next_line(int fd) {
    char buffer[BUFFER_SIZE];
    char *line;
    int bytes_read;
    int counter = 0;
    int index = 0;

    while((bytes_read = read(fd, buffer, BUFFER_SIZE) > 0))
    {
        while(counter < bytes_read)
        {
            if(buffer[counter] == '\n')
            {
                line = (char *)malloc(counter + 1);
                if (line == NULL)
                    return (NULL);
            }
            while (index++ < counter)
                line[index] = buffer[index];
            line[counter] = '\0';
            return line;
            counter++;
        }
        counter++;
    }

}

int main() {
    int fd;
    char *line;

    // Open the file for reading
    fd = open("text.txt", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Read lines using get_next_line until the end of the file
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    // Close the file
    close(fd);

    return 0;
}