/* -*-c++-*-
 * @file: TransportLayer.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/22
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Transport Layer 3 implementation
 */

#include <vector>
#include <cstdint>
#include <NetworkLayer.hpp>
#include "TransportLayer.hpp"

TransportLayer::TransportLayer(NetworkLayer *layer) : networkLayer(layer) {
  /* empty */
}

void TransportLayer::send(const std::vector<uint8_t> &data) {
  std::vector<uint8_t> frame = addHeaders(data);
  networkLayer->send(frame);
}

std::vector<uint8_t> TransportLayer::receive(void) {
  std::vector<uint8_t> data = networkLayer->receive();
  return removeHeaders(data);
}

std::vector<uint8_t> TransportLayer::addHeaders(const std::vector<uint8_t> &data) {
  /* implementaion goes here */
  return data;
}

std::vector<uint8_t> TransportLayer::removeHeaders(const std::vector<uint8_t> &frame) {
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

