#include <iostream>
#include "build/version.h"

int main(){
    std::cout << "Version: " << PATCH_VERSION << std::endl;
    std::cout << "Hello, world!" << std::endl;
    return 0;
}