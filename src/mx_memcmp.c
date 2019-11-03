#include "libmx.h"

int mx_memcmp(const void *s1, const void *s2, size_t n) {
	const unsigned char *str1 = s1;
	const unsigned char *str2 = s2;

	n--;
	while ((*str1 && *str2) && n--) {
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
