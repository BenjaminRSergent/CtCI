#include <string>
#include <string.h>
#include <iostream>

void reverse(char* str, char* out, uint32_t len) {
    for (int index = 0; index < len; index++) {
        out[len - index - 1] = str[index];
    }

    out[len] = '\0';
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: unique_string a_string\n";
        return EXIT_FAILURE;
    }

    uint32_t len = strlen(argv[1]);

    char* reversed_str = new char[len + 1];
    reverse(argv[1], reversed_str, len);
    std::cout << argv[1] << " reversed is " << reversed_str << "\n";
    delete[] reversed_str;

    return EXIT_SUCCESS;
}
