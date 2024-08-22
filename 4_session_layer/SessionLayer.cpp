/* -*-c++-*-
 * @file: SessionLayer.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/22
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Session Layer 4 implementation
 */

#include <vector>
#include <cstdint>
#include <string>
#include <TransportLayer.hpp>
#include "SessionLayer.hpp"

SessionLayer::SessionLayer(TransportLayer *layer) : transportLayer(layer) {
  /* empty */
}

void SessionLayer::send(const std::vector<uint8_t> &data) {
  std::vector<uint8_t> frame = addHeaders(data);
  transportLayer->send(frame);
}

std::vector<uint8_t> SessionLayer::receive(void) {
  std::vector<uint8_t> data = transportLayer->receive();
  return removeHeaders(data);
}

std::vector<uint8_t> SessionLayer::addHeaders(const std::vector<uint8_t> &data) {
  /* implementaion goes here */
  std::vector<uint8_t> packet = data;
  std::string header = ":L4:";
  packet.insert(packet.begin(), header.begin(), header.end());
  packet.insert(packet.end(), header.begin(), header.end());
  return packet;
}

std::vector<uint8_t> SessionLayer::removeHeaders(const std::vector<uint8_t> &frame) {
  /* implementaion goes here */
  return frame;
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

