/*
 * $FU-Copyright$
 */

#ifndef OMNET_CONFIGURATION_H_
#define OMNET_CONFIGURATION_H_

#include "OMNeTARAMacros.h"
#include "Configuration.h"
#include "RoutingTable.h"
#include "IInterfaceTable.h"
#include "OMNeTLogger.h"
#include "OMNeTForwardingPolicy.h"

OMNETARA_NAMESPACE_BEGIN

class OMNeTConfiguration : public virtual Configuration {
    public:
        OMNeTConfiguration(cModule* module, RoutingTable* routingTable=nullptr, PacketFactory* packetFactory=nullptr);

        virtual RoutingTable* getRoutingTable();
        virtual PacketFactory* getPacketFactory();
        virtual EvaporationPolicy* getEvaporationPolicy();
        virtual PathReinforcementPolicy* getReinforcementPolicy();
        virtual ForwardingPolicy* getForwardingPolicy();
        virtual float getInitialPheromoneValue();
        virtual int getMaxNrOfRouteDiscoveryRetries();
        virtual int getMaxTTL();
        virtual unsigned int getRouteDiscoveryTimeoutInMilliSeconds();
        virtual unsigned int getPacketDeliveryDelayInMilliSeconds();
        virtual unsigned int getNeighborActivityCheckIntervalInMilliSeconds();
        virtual unsigned int getMaxNeighborInactivityTimeInMilliSeconds();
        virtual unsigned int getPANTIntervalInMilliSeconds();
        virtual bool isPreviousHopFeatureActivated();

        Logger* getLogger();

    protected:
        cModule* getHostModule();
        void setLogLevel(const char* logLevelParameter);

    protected:
        RoutingTable* routingTable;
        EvaporationPolicy* evaporationPolicy;
        PathReinforcementPolicy* reinforcementPolicy;
        PacketFactory* packetFactory;
        float initialPheromoneValue;
        int maxNrOfRouteDiscoveryRetries;
        int maxTTL;
        unsigned int routeDiscoveryTimeoutInMilliSeconds;
        unsigned int packetDeliveryDelayInMilliSeconds;
        unsigned int neighborActivityCheckIntervalInMilliSeconds;
        unsigned int maxNeighborInactivityTimeInMilliSeconds;
        unsigned int pantIntervalInMilliSeconds;
        bool previousHopFeatureIsActivated;

        cModule* simpleModule;
        OMNeTLogger* logger;
};

OMNETARA_NAMESPACE_END
#endif
