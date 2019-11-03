#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
	short len = 0;
	unsigned long nbr_len = nbr;
	for (int i = 0; nbr_len; i++, len++)
		nbr_len /= 16;

	char *hex = mx_strnew(len);
	if (nbr == 0)
		*hex = '0';
	else {
		for (int i = 0; nbr; i++, nbr /= 16) {
			if (nbr % 16 <= 9)
				hex[i] = nbr % 16 + '0';
			else
				hex[i] = nbr % 16 + '0';
		}
		mx_str_reverse(hex);
	}
	return hex;
}