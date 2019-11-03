#include "libmx.h"

static int mx_file_len(const char *file) {
	short fl = open(file, O_RDONLY);
	short sz = 0;
	int len = 0;
	char buf;

	sz = read(fl, &buf, 1);
	while (sz > 0) {
		sz = read(fl, &buf, 1);
		len++;
	}
	close(fl);
	return len;
}

char *mx_file_to_str(const char *file) {
		int fl = open(file, O_RDONLY);
		if (fl == -1) {
			close(fl);
			return NULL;
		}
		char buffer;
		int sz = 0;
		char *newstr = NULL;

		newstr = mx_strnew(mx_file_len(file));

		sz = read(fl, &buffer, 1);
		while (sz > 0) {
			mx_strcat(newstr, &buffer);
			sz = read(fl, &buffer, 1);
		}
		close(fl);
	return newstr;
}
