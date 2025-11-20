#include "NatNetTypes.h"
#include "NatNetClient.h"

#include <iostream>

// NatNet Callbacks
void NATNET_CALLCONV ServerDiscoveredCallback(const sNatNetDiscoveredServer* pDiscoveredServer, void* pUserContext);
void NATNET_CALLCONV DataHandler(sFrameOfMocapData* data, void* pUserData);    // receives data from the server
void NATNET_CALLCONV MessageHandler(Verbosity msgType, const char* msg);      // receives NatNet error messages

sNatNetClientConnectParams g_connectParams;

// Connection variables
NatNetClient* g_pClient = NULL;
sNatNetClientConnectParams g_connectParams;
sServerDescription g_serverDescription;

void initializeParams()
{
    g_connectParams.connectionType = ConnectionType_Multicast;
    g_connectParams.serverCommandPort = 1510;
    g_connectParams.serverDataPort = 1511;
    g_connectParams.serverAddress = "192.168.2.16";
    g_connectParams.localAddress = "192.168.2.10";
    g_connectParams.multicastAddress = "239.255.42.99";
}   

int main()
{
    initializeParams();

    std::cout << "Hello, Crazy Client!" << std::endl;
    auto g_pClient = new NatNetClient();
    g_pClient->Connect(g_connectParams);
    g_pClient -> Disconnect();
    delete g_pClient;

    // Set the frame callback handler
    // g_pClient->SetFrameReceivedCallback( DataHandler, g_pClient );	// this function will receive data from the server
    return 0;
}