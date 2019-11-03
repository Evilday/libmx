#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
	if (big_len >= little_len  && big_len > 0 && little_len > 0 
		&& (size_t)mx_strlen((const char*)big) == big_len 
		&& (size_t)mx_strlen((const char*)little) == little_len) {
		unsigned char *where = (unsigned char *)big;
		unsigned char *what = (unsigned char *)little;

		while (*where) {
			if (mx_memcmp(where, what, little_len) == 0) {
				return (void *)where;
			}
			where++;
		}
	}
	return NULL;
}
