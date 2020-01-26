#include <iostream>
#include "ClientHandler.h"
#include "StringReverser.h"
#include "Boot.h"


int main(int argc, char* argv[]) {
    boot::Main main1;
    if (argc >= 2) {
        main1.main(stoi(argv[1]));
    } else {
        main1.main(5600);
    }
    return 0;
}
