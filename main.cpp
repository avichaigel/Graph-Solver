#include <iostream>
#include "ClientHandler.h"
#include "StringReverser.h"
#include "Boot.h"


int main(int argc, char* argv[]) {
    auto myCache = new FileCacheManager();
    auto start = myCache->get("start");
    boot::Main main1;
    main1.main(atoi(argv[0]));
    return 0;
}
