#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
	if (s1 || s2) {
		if (!s1)
			return (char *)s2;
		else if (!s2)
			return (char *)s1;
		else {
			char *newstr = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
			mx_strcat(mx_strcpy(newstr, s1), s2);
			return newstr;
		}
	}
	return NULL;
}
