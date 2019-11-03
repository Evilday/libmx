#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
	if (!sub || !str)
		return -1;
	
	int num_of_str = 0;
	int len = mx_strlen(sub);
	while (*str) {
		if (mx_strchr(str, *sub))
			if (mx_strncmp(str, sub, len) == 0)
				num_of_str++;
		str++;
	}
	return num_of_str;
}
