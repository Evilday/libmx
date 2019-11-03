#include "libmx.h"

void *mx_memmove(void *dst, const void *src, size_t len) {
	size_t i = 0;

	while (i < len) {
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return dst;
}
