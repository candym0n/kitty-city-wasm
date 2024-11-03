#include <javascript/output.h>

EM_JS(void, printString, (const char* ), {})

void print(const char *format, ...) {
    va_list args;
    va_start(args, format);

    // Initial buffer size
    size_t buffer_size = 1024;
    char *buffer = (char *)malloc(buffer_size);

    // Continuously format and reallocate until all arguments are processed
    while (1) {
        va_list args_copy;
        va_copy(args_copy, args);

        int chars_written = vsnprintf(buffer, buffer_size, format, args_copy);

        va_end(args_copy);

        // If the buffer was too small, reallocate
        if (chars_written >= buffer_size) {
            buffer_size *= 2;
            buffer = (char *)realloc(buffer, buffer_size);
            continue;
        }

        // If the buffer was large enough, break the loop
        break;
    }

    printString(buffer);
    va_end(args);
    free(buffer);
}
