#pragma once

#include "IRelaySocket.h"
#include "CoreMinimal.h"

//#include "Networking.h"
#include "Sockets.h"

namespace BrainCloud
{
    class RelayTCPSocket : public IRelaySocket
	{
    public:
        RelayTCPSocket(const FString& host, int port);
        virtual ~RelayTCPSocket();

        bool isConnected() override;
        bool isValid() override;

        void update() override;
        void updateConnection() override; // Call each frame when !isConnected and isValid

        void send(const uint8* pData, int size) override;
        //void recv(const FArrayReaderPtr& ArrayReaderPtr, const FIPv4Endpoint& EndPt);
        const uint8* peek(int& size) override; // Returns null if nothing to read

        void close() override;

    private:

        bool m_isConnected = false;
        bool m_isSocketConnected = false;
        bool m_isValid = true;

        FCriticalSection m_mutex;
        TSharedPtr<FInternetAddr> m_remoteAddr;
        TSharedPtr<FInternetAddr> m_localAddr;
        FSocket* m_connectedSocket = nullptr;
        TArray<TArray<uint8>> m_packetQueue;
        TArray<TArray<uint8>> m_sendPacketQueue;
        TArray<uint8> m_currentPacket;
        TArray<uint8> m_sendPacket;
        TArray<uint8> m_receiveBuffer;
	};
}
