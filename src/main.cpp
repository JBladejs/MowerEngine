#include <iostream>
#include "Mower.h"
#include "graphics/util/Color.h"
#include "util/Bag.h"

int main(int argc, char *args[]) {
//    Mower engine = Mower();
//    engine.start();
//    return engine.getExitCode();
    Bag<int> bag = Bag<int>();
    for (int i = 0; i < 128; ++i) {
        bag.add(i);
        std::cout << i + 1 << " " << bag.size() << " " << bag.capacity() << std::endl;
    }
    bag.remove(12);
    bag.remove(64);
    bag.remove(127);
    for (int i = 0; i < bag.size(); ++i) {
        std::cout << bag.get(i) << std::endl;
    }
}