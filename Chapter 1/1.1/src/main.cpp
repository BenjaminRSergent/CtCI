#include <string.h>
#include <iostream>
#include <set>

bool is_unique(char* str) {
    uint32_t len = strlen(str);
    std::set<char> characters_found;
    for(int index = 0; index < len; index++) {
        if(characters_found.find(str[index]) != characters_found.end()) {
            return false;
        }
        characters_found.insert(str[index]);
    }    

    return true;
}

bool is_unique_no_structures(char* str) {
    uint32_t BYTE_TO_BIT = 8;
    const uint32_t NUM_POSSIBLE = 2 << (sizeof(char) * BYTE_TO_BIT);
    bool found[NUM_POSSIBLE];

    memset(found, false, NUM_POSSIBLE);

    uint32_t len = strlen(str);
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
    std::cout << (is_unique_no_structures(argv[1]) ? "Yes\n" : "No\n");

    return EXIT_SUCCESS;
}
