libARA [![Build Status](https://travis-ci.org/des-testbed/libara.png?branch=develop)](https://travis-ci.org/des-testbed/libara) 
=======
An enhanceable framework for developing and testing the Ant Routing Algorithm (ARA) as proposed by M. Güneş, U. Sorges and I. Bouazizi in 2002.


Installation from git
---------------------
1. Clone the repository:

		git clone git://github.com/des-testbed/libara.git
		
2. Please install the required dependencies

		clang >= 3.2
		OMNeT++ >= 4.5
	
3. After the checkout you can build the sources and simulation via 

		make all
		
   We also support a headless build via

		 make HEADLESS=TRUE

5. libARA is developed with a test driven approach using the [CppUTest][1] framework. 
You should can run the whole libARA regression test suit via the following command.
This will automatically initialize and update the git submodule [tests/cpputest][2].

		make test

6. A doxygen based documentation can be build using the 'doc' target

		make doc


Hacking
-------

If you are new to the framework you should take a look at the [AbstractARAClientTest][3] which can give you a good feeling on how everything works.
If you are only interested in the OMNeT++ part you should look at [omnetpp][4] and of course the [simulations][5] folder.

Bug tracker
-----------
Have a bug or feature request? Please create an issue here on GitHub!

https://github.com/des-testbed/libara/issues



Publications
------------
You are using libARA in a scientific context? Please cite libARA with publication **2**.

1. Friedrich Grosse, **Optimization and Evaluation of Energy Aware Ant Routing Algorithm Strategies Based on Network Simulations**, Master Thesis, August 2013
2. Michael Frey, Friedrich Grosse, Mesut Günes, **libARA: A framework for simulation and testbed based studies on ant routing algorithms in wireless multi-hop networks**, [7th International Conference on Performance Evaluation Methodologies and Tools](http://valuetools.org/2013/show/home), December 2013
3. Michael Frey, Friedrich Grosse, Mesut Günes, **Energy Aware Ant Routing in Wireless Multi-Hop Networks**, [IEEE International Conference on Communications (ICC)](http://www.ieee-icc.org), June 2014
4. Michael Frey, Mesut Günes, **Attack of the Ants: Studying Ant Routing Algorithms in Simulation and Wireless Testbeds**, [OMNeT++ Community Summit 2014](http://summit.omnetpp.org/2014/), September 2014

License
-------
libARA is licensed under the GNU GENERAL PUBLIC LICENSE (GPL) Version 3. For further information on the license please refer to the LICENSE file in the repository or the [website](https://www.gnu.org/licenses/gpl-3.0.txt).

[1]: http://www.cpputest.org/
[2]: https://github.com/FGrosse/cpputest
[3]: https://github.com/des-testbed/Ara-Sim/blob/develop/tests/libara/core/AbstractARAClientTest.cpp
[4]: https://github.com/des-testbed/Ara-Sim/tree/develop/omnetpp
[5]: https://github.com/des-testbed/Ara-Sim/tree/develop/simulations

