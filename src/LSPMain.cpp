#include "LSP.h"
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    trypillia::LSPServer server;
    server.run();

    return 0;
}
