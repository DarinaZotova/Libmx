#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) 
{
    int fd_file = open(file, O_RDONLY);
    if (fd_file < 0) return NULL;

    int size = 0;
    char ch;
    while (read(fd_file, &ch, 1) > 0)
        size++;
    close(fd_file);

    if (size == 0) return NULL;

    char *data = mx_strnew(size);
    if (!data) return NULL;

    fd_file = open(file, O_RDONLY);
    if (fd_file < 0) return NULL;

    read(fd_file, data, size);
    close(fd_file);

    return data;
}
