/* -*-c++-*-
 * @file: ProtocolStack.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/21
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Protocol stack implementation
 */

#include <vector>
#include <cstdint>
#include "ProtocolStack.hpp"

ProtocolStack::ProtocolStack() {
  physicalLayer = new PhysicalLayer();
  dataLinkLayer = new DataLinkLayer(physicalLayer);
  networkLayer = new NetworkLayer(dataLinkLayer);
  transportLayer = new TransportLayer(networkLayer);
  sessionLayer = new SessionLayer(transportLayer);
  presentationLayer = new PresentationLayer(sessionLayer);
  applicationLayer = new ApplicationLayer(presentationLayer);
}

ProtocolStack::~ProtocolStack() {
  delete applicationLayer;
  delete presentationLayer;
  delete sessionLayer;
  delete transportLayer;
  delete networkLayer;
  delete dataLinkLayer;
  delete physicalLayer;
}

void ProtocolStack::send(const std::vector<uint8_t> &data) {
  applicationLayer->send(data);
}

std::vector<uint8_t> ProtocolStack::receive(void) {
  return applicationLayer->receive();
}

/*

Copyright © 2024 Dmitry Shpakov

This library is free software; you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published
by the Free Software Foundation; either version 3 of the License, or
(at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this library; if not, see <http://www.gnu.org/licenses/>.

*/

