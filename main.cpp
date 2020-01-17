#include <iostream>
#include "ClientHandler.h"
#include "StringReverser.h"
#include "Boot.h"


int main(int argc, char* argv[]) {
    // todo ofir: this is where i need to initiate fileCacheManager, read the problem->name map (+set count) from its file
    boot::Main main1;
    main1.main(atoi(argv[0]));
    return 0;
}
