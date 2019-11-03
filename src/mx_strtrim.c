#include "libmx.h"

char *mx_strtrim(const char *str) {
	int len = mx_strlen(str);
	int start = 0;
	int last = 0;
	char *res;
	if (!str)
		return NULL;
	for (; mx_isspace(str[start]); start++);
	for (int j = len - 1; mx_isspace(str[j]); j--)
		last++;
	res = mx_strnew(len - start - last);
	mx_strncpy(res, str + start, len - start - last);
	return res;
}
