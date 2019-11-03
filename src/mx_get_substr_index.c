#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
	int i = 0;

	if (str && sub) {
		int len = mx_strlen(sub);
		for (; str[i] != '\0'; i++) {
			if (*str == *sub)
				if (mx_strncmp(str, sub, len) == 0)
					return i;
			str++;
		}
		if (!str[i])
			return -1;
	}
	return -2;
}
