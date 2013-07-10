/*
 * $FU-Copyright$
 */

#include "testbed/NetworkInterface.h"
#include "TestbedAddress.h"
#include "PacketDispatcher.h"

TESTBED_NAMESPACE_BEGIN

AddressPtr NetworkInterface::localAddress = AddressPtr(new TestbedAddress(DESSERT_LOCAL_ADDRESS));
AddressPtr NetworkInterface::broadcastAddress = AddressPtr(new TestbedAddress(DESSERT_BROADCAST_ADDRESS));
extern NetworkInterfaceMap networkInterfaces;

NetworkInterface::NetworkInterface(dessert_meshif_t* dessertPointer, AbstractARAClient* client, PacketFactory* packetFactory, int ackTimeoutInMicroSeconds)
                        : ReliableNetworkInterface(client, packetFactory, ackTimeoutInMicroSeconds, localAddress, broadcastAddress) {
    this->dessertPointer = dessertPointer;
    registerInterface();
}

NetworkInterface::~NetworkInterface() {
    networkInterfaces.erase(dessertPointer);
}

bool NetworkInterface::isRegistered() {
    if (extractNetworkInterface(dessertPointer) == this) {
        return true;
    }
    else {
        return false;
    }
}

void NetworkInterface::receive(Packet* packet) {
    deliverToARAClient(packet);
}

void NetworkInterface::deliverToARAClient(Packet* packet) {
    client->receivePacket(packet, this);
}

bool NetworkInterface::equals(ARA::NetworkInterface* otherInterface) {
    ARA::testbed::NetworkInterface* other = (ARA::testbed::NetworkInterface*)otherInterface;
    return this->dessertPointer->hwaddr == other->dessertPointer->hwaddr;
}

dessert_meshif_t* NetworkInterface::getDessertPointer()  const{
    return this->dessertPointer;
}

void NetworkInterface::doSend(const Packet* packet, std::shared_ptr<Address> recipient){
    packetToNetworkDispatcher(packet, this, recipient);
}

void NetworkInterface::registerInterface() {
    networkInterfaces[dessertPointer] = this;
}

TESTBED_NAMESPACE_END