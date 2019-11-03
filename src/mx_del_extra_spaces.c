#include "libmx.h"

static int mx_size_without_extra_spaces(const char *str) {
	int size = 0;
	
	while (*str) {
		while (mx_isspace(*str) && mx_isspace(*(str + 1)))
			str++;
		size++;
		str++;
	}
	return size;
}

char *mx_del_extra_spaces(const char *str) {
	char *trim_str = mx_strtrim(str);
	char *newstr = mx_strnew(mx_size_without_extra_spaces(trim_str));
	char *finalstr = newstr;

	while (*trim_str) {
		if (mx_isspace(*trim_str)) {
			while (mx_isspace(*trim_str))
				trim_str++;
			*newstr = ' ';
			newstr++;
		}
		else {
			*newstr = *trim_str;
			newstr++;
			trim_str++;
		}
	}
	return finalstr;
}
