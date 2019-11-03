#include "libmx.h"

void *mx_realloc(void *ptr, size_t size) {
	if (size <= 0 && ptr) {
		free(ptr);
		return NULL;
	}
	else if (!ptr && size > 0)
		return (void *)mx_strnew(size);
	else {
		void *new_ptr = (void *)mx_strnew(size);
		mx_memcpy(new_ptr, ptr, size);
		free(ptr);
		return (void *)new_ptr;
	}
	return NULL;
}
