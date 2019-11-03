#include "libmx.h"

int mx_read_line(char **lineptr, int buf_size, char delim, const int fd) {
	int status = 0;
	int c = 0;
	int num_of_letters = 0;

	if (!lineptr || fd == -1)
		return -1;
	while ((status = read(fd, &c, 1)) > 0) {
		if (c == delim || status == 0)
			break;
		*lineptr = mx_realloc(*lineptr, num_of_letters + 1);
		*(*lineptr + num_of_letters) = c;
		num_of_letters++;
	}
	*(*lineptr + num_of_letters) = 0;
	if (num_of_letters < buf_size) {
		*lineptr = mx_realloc(*lineptr, 1);
		**lineptr = 0;
	}
	return status == 0 ? 0 : num_of_letters;
}
