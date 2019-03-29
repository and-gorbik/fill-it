#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

// static int		read_valid_string(int fd, char **dest)
// {
// 	char	buf[21];
// 	int		size;

// 	size = read(fd, buf, 20);
// 	if (size && buf[size - 1]) // если не уперлись в конец файла
// 		buf[size] = '\0';
// 	if (!(ft_strlen(buf) == 20 && ft_strcount(buf, '\n') == 4 &&
// 		ft_strcount(buf, '#') == 4 && ft_strcount(buf, '.') == 12))
// 		return (0);
// 	ft_strcpy(*dest, buf);
// 	return (1);
// }

int	ft_strcount(const char *s, char chr)
{
	int	counter;

	counter = 0;
	while (*s)
	{
		if (*s == chr)
			++counter;
		++s;
	}
	return (counter);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		++i;
	}
	return (b);
}

int main(int argc, char **argv)
{
    int     fd;
    int     size;
    char    buf[21];
    int     next;

	if (argc == 2)
	{
        fd = open(argv[1], O_RDONLY);
        next = 1;
        ft_memset(buf, '.', 21);
        while ((size = read(fd, buf, 20)))
        {
            if (size != 20)
            {
                printf("invalid file\n");
                return (0);
            }
            buf[20] = '\0';
            next = 0;
            if (!(strlen(buf) == 20 && ft_strcount(buf, '\n') == 4 && ft_strcount(buf, '#') == 4 && ft_strcount(buf, '.') == 12))
            {
                printf("invalid string\n");
                return (0);
            }
            printf("valid:\n%s\n", buf);
            if (read(fd, buf, 1))
            {
                if (buf[0] == '\n')
                    next = 1;
                else
                {
                    printf("invalid space between items\n");
                    return (0);
                }
            }
            else
            {
                next = 0;
            }
            ft_memset(buf, '.', 21);
        }
        if (next)
            printf("invalid end of file\n");
        close(fd);
	}
	return (0);
}
