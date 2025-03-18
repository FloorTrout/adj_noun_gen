#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {
    // Handle program arguments
    int mode = 0;
    bool use_full = false;
    bool show_zeros = false;
    if (argc > 1) {
        for (int i=1;i<argc;++i) {
            if (argv[i] == std::string("-0"))      { mode = 0; }
            else if (argv[i] == std::string("-1")) { mode = 1; }
            else if (argv[i] == std::string("-2")) { mode = 2; }
            else if (argv[i] == std::string("-3")) { mode = 3; }

            if (argv[i] == std::string("-s")) { show_zeros = true; }
        }
    }
    
    // Load in nouns
    std::vector<std::string> noun_vector;
    std::ifstream nouns("nouns.txt");
    std::string line;
    while (std::getline(nouns, line)) {
        noun_vector.push_back(line);
    }
    nouns.close();
    
    // Load in adjectives
    std::vector<std::string> adjs_vector;
    std::ifstream adjs("adjectives.txt");
    while (std::getline(adjs, line)) {
        adjs_vector.push_back(line);
    }
    adjs.close();

    // Combine words and numbers
    for (int i=0;i<adjs_vector.size();++i) {
        for (int j=0;j<noun_vector.size();++j) {
            int num_min = 0;
            int num_max = 1;
            if (mode == 1) { num_max = 10; }
            else if (mode == 2) { num_max = 100; }
            else if (mode == 3) { num_max = 1000; }
            for (int k=num_min; k<num_max; k++) {
                std::cout << adjs_vector[i] << noun_vector[j];
                if (mode != 0) {
                    if (show_zeros && k < 10) {
                        std::cout << "00";
                    } else if (show_zeros && k < 100) {
                        std::cout << "0";
                    }
                    std::cout << k;
                }
                std::cout << std::endl;
            }
        }
    }
    return 0;
}