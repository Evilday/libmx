#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	const unsigned char *str = (unsigned char *)s + (mx_strlen(s));

	while ((str != s) && n) {
		if (*str == c)
			return (void *)str;
		else
			str--;
		n--;
	}
	return NULL;
}
