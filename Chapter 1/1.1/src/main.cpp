#include <string.h>
#include <climits>
#include <iostream>

bool is_unique(char* str) {
    const uint32_t NUM_POSSIBLE = 2 << CHAR_BIT;
    uint32_t len = strlen(str);

    if(len > NUM_POSSIBLE) {
        return false;
    }

    bool found[NUM_POSSIBLE];
    memset(found, false, NUM_POSSIBLE);

    for(int index = 0; index < len; index++) {
        if(found[str[index]]) {
            return false;
        }
        found[str[index]] = true;
    }    

    return true;
}

int main(int argc, char** argv) {
    if(argc < 2) {
        std::cout << "Usage: unique_string a_string\n";
        return EXIT_FAILURE;
    }

    std::cout << argv[1] << " has unique characters: ";
    std::cout << (is_unique(argv[1]) ? "Yes\n" : "No\n");

    return EXIT_SUCCESS;
}
