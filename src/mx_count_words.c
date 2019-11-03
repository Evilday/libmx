#include "libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int count_words = 0;

    if (str) {
        while (*str) {
            for (; *str && *str == delimiter; ++str);

            if (*str && *str != delimiter) {
                for (; *str && *str != delimiter; ++str);
                ++count_words;
            }
        }
    }
    return count_words;
}
