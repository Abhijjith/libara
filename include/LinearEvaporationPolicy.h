/******************************************************************************
 Copyright 2012, The DES-SERT Team, Freie Universität Berlin (FUB).
 All rights reserved.

 These sources were originally developed by Friedrich Große, Michael Frey
 at Freie Universität Berlin (http://www.fu-berlin.de/),
 Computer Systems and Telematics / Distributed, Embedded Systems (DES) group
 (http://cst.mi.fu-berlin.de/, http://www.des-testbed.net/)
 ------------------------------------------------------------------------------
 This program is free software: you can redistribute it and/or modify it under
 the terms of the GNU General Public License as published by the Free Software
 Foundation, either version 3 of the License, or (at your option) any later
 version.

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

 You should have received a copy of the GNU General Public License along with
 this program. If not, see http://www.gnu.org/licenses/ .
 ------------------------------------------------------------------------------
 For further information and questions please use the web site
 http://www.des-testbed.net/
 *******************************************************************************/

#ifndef LINEAR_EVAPORATION_POLICY_H_
#define LINEAR_EVAPORATION_POLICY_H_

#include <cmath>
#include <cstring>
#include <stdint.h>
#include <sys/time.h>

#include "EvaporationPolicy.h"

namespace ARA { 
   /**
    * This class provides the linear evaporation function of the ant routing algorithm (ARA).
    */
    class LinearEvaporationPolicy : public EvaporationPolicy {
        public:
            LinearEvaporationPolicy();
            ~LinearEvaporationPolicy();

            /// the method checks if it's time to start the evaporation process
            bool checkForEvaporation();
            /// the method reduces the pheromone value of a routing table entry
            float evaporate(float phi);

        private:
            /// the linear factor
            float q;
            /// the threshold which denotes at what point the pheromone level is set to 0
            float threshold;
            /// the last access time of the routing table
			struct timeval *lastAccessTime;
            /// the factor which indicates how often the evaporation should take place 
            uint8_t factor;
    };
} /* namespace ARA */

#endif 
