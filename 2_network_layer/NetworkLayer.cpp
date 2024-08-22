/* -*-c++-*-
 * @file: NetworkLayer.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/22
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Network Layer 2 implementation
 */

#include <vector>
#include <cstdint>
#include <DataLinkLayer.hpp>
#include "NetworkLayer.hpp"

NetworkLayer::NetworkLayer(DataLinkLayer *layer) : dataLinkLayer(layer) {
  /* empty */
}

void NetworkLayer::send(const std::vector<uint8_t> &data) {
  std::vector<uint8_t> frame = addHeaders(data);
  dataLinkLayer->send(frame);
}

std::vector<uint8_t> NetworkLayer::receive(void) {
  std::vector<uint8_t> data = dataLinkLayer->receive();
  return removeHeaders(data);
}

std::vector<uint8_t> NetworkLayer::addHeaders(const std::vector<uint8_t> &data) {
  /* implementaion goes here */
  return data;
}

std::vector<uint8_t> NetworkLayer::removeHeaders(const std::vector<uint8_t> &frame) {
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

