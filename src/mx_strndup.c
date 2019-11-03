#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
	char *newstr = mx_strnew(n);

	if (newstr == NULL)
		return NULL;
	return newstr ? mx_strncpy(newstr, s1, n) : NULL;
}
