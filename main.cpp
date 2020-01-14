#include <iostream>
#include "ClientHandler.h"

using namespace std;

namespace server_side {
    class Server {
        virtual void open(int port, ClientHandler c) = 0;
        virtual void close() = 0;
    };

    class MySerivalServer : public Server {
    };
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
