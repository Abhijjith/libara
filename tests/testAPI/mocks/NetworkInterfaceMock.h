/*
 * $FU-Copyright$
 */

#ifndef NETWORKINTERFACEMOCK_H_
#define NETWORKINTERFACEMOCK_H_

#include "ReliableNetworkInterface.h"
#include "AbstractARAClient.h"
#include "Packet.h"
#include "Pair.h"
#include "AddressMock.h"

#include <memory>
#include <deque>

namespace ARA {

class NetworkInterfaceMock: public ARA::ReliableNetworkInterface {
public:
    NetworkInterfaceMock(AbstractARAClient* client = nullptr);
    NetworkInterfaceMock(const std::string interfaceName, AbstractARAClient* client = nullptr);
    NetworkInterfaceMock(const std::string interfaceName, const std::string localAddressName, AbstractARAClient* client = nullptr);
    ~NetworkInterfaceMock();

    void doSend(const Packet* packet, std::shared_ptr<Address> recipient);
    bool equals(NetworkInterface* otherInterface);

    std::string getName();
    std::deque<Pair<const Packet*, std::shared_ptr<Address>>*>* getSentPackets();
    unsigned int getNumberOfSentPackets();
    bool hasPacketBeenSent(Packet* packet);
    bool hasPacketBeenBroadCasted(Packet* packet);

    int getNrOfUnacknowledgedPackets() const;

private:
    std::string name;
    std::deque<Pair<const Packet*, std::shared_ptr<Address>>*> sentPackets;
};

} /* namespace ARA */
#endif /* NETWORKINTERFACEMOCK_H_ */
