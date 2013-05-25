/*
 * $FU-Copyright$
 */

#include "omnetpp/TrafficControllInfo.h"
#include "omnetpp/OMNeTAddress.h"

#include "IPv4Address.h"

OMNETARA_NAMESPACE_BEGIN

TrafficControlInfo::TrafficControlInfo(const char* destinationIPv4Address) {
    IPv4Address destinationAddress = IPv4Address(destinationIPv4Address);
    destination = AddressPtr(new OMNeTAddress(destinationAddress));
    creationTime = simTime();
}

AddressPtr TrafficControlInfo::getDestination() const {
    return destination;
}

SimTime TrafficControlInfo::getCreationTime() const {
    return creationTime;
}

OMNETARA_NAMESPACE_END
