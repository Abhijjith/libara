/*
 * $FU-Copyright$
 */

#include "EARAClientMock.h"
#include "EnergyAwareRoutingTable.h"
#include "BestPheromoneForwardingPolicy.h"
#include "LinearPathReinforcementPolicy.h"
#include "testAPI/mocks/LinearEvaporationPolicyMock.h"
#include "testAPI/mocks/time/ClockMock.h"

#include <sstream>

namespace ARA {

typedef std::shared_ptr<Address> AddressPtr;

EARAClientMock::EARAClientMock() {
    float initialPhi = 10.0;
    float deltaPhi = 5.0;
    EARAConfiguration configuration = EARAConfiguration(
            new LinearEvaporationPolicyMock(),
            new LinearPathReinforcementPolicy(deltaPhi),
            new BestPheromoneForwardingPolicy(),
            initialPhi
    );
    initialize(configuration, new EnergyAwareRoutingTable());
    currentEnergyLevel = 255;
}

void EARAClientMock::receivePacket(Packet* packet, NetworkInterface* interface) {
    storeReceivedPacket(packet, interface);
    AbstractEARAClient::receivePacket(packet, interface);
}

void EARAClientMock::handleRouteFailure(Packet* packet, AddressPtr nextHop, NetworkInterface* interface) {
    storeRouteFailurePacket(packet, nextHop, interface);
    AbstractEARAClient::handleRouteFailure(packet, nextHop, interface);
}

void EARAClientMock::deliverToSystem(const Packet* packet) {
    storeDeliveredPacket(packet);
}

void EARAClientMock::packetNotDeliverable(const Packet* packet) {
    storeUndeliverablePacket(packet);
}

char EARAClientMock::getCurrentEnergyLevel() {
    return currentEnergyLevel;
}

NetworkInterfaceMock* EARAClientMock::createNewNetworkInterfaceMock(const std::string localAddressName) {
    NetworkInterfaceMock* mock = AbstractClientMockBase::createNewNetworkInterfaceMock(localAddressName);
    addNetworkInterface(mock);
    return mock;
}

void EARAClientMock::setEnergy(char newEnergyLevel) {
    currentEnergyLevel = newEnergyLevel;
}

PacketTrap* EARAClientMock::getPacketTrap() {
    return packetTrap;
}

EnergyAwareRoutingTable* EARAClientMock::getRoutingTable() {
    return (EnergyAwareRoutingTable*) routingTable;
}

TimerMock* EARAClientMock::getEnergyDisseminationTimer() {
    return (TimerMock*) energyDisseminationTimer;
}

} /* namespace ARA */
