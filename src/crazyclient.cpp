#include "NatNetTypes.h"
#include "NatNetClient.h"

#include <iostream>

sNatNetClientConnectParams params;
// params.connectionType = ConnectionType_Multicast;
params.serverCommandPort = 1510;
// params.serverDataPort = 1511;
// params.serverAddress = "192.168.2.16";
// params.localAddress = "192.168.2.10";
// params.multicastAddress = "239.255.42.99";

int main()
{
    std::cout << "Hello, Crazy Client!" << std::endl;
    auto g_pClient = new NatNetClient();
    g_pClient->Connect(params);
    g_pClient -> Disconnect();
    delete g_pClient;

    // Set the frame callback handler
    g_pClient->SetFrameReceivedCallback( DataHandler, g_pClient );	// this function will receive data from the server
    return 0;
}