/*
 * $FU-Copyright$
 */

#ifndef STOCHASTIC_FORWARDING_POLICY_H_
#define STOCHASTIC_FORWARDING_POLICY_H_

#include "ARAMacros.h"
#include "ForwardingPolicy.h"
#include "NextHop.h"
#include "Packet.h"
#include "RoutingTable.h"

#include <deque>
#include <numeric>

ARA_NAMESPACE_BEGIN

class StochasticForwardingPolicy : public ForwardingPolicy {
    public:
        StochasticForwardingPolicy(RoutingTable* routingTable) : ForwardingPolicy(routingTable) {};

        /**
         * Stochastically selects the next hop according to their pheromone value
         * but never the sender of the given packet.
         */
        virtual NextHop* getNextHop(const Packet* packet);

    protected:
        void initializeRandomNumberGenerator(unsigned int seed=((unsigned)time(0)));
        float getRandomNumber();
};

ARA_NAMESPACE_END

#endif
