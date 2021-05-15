#include <iostream>
#include "vector.h"
#include <string>

int main() {
    vector<std::string> v;
    v.PushBack("123");
    v.PushBack("1");
    for (auto elem : v)
    {
        std::cout << elem << " ";
    }
}
