/* -*-c++-*-
 * @file: DataLinkLayer.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/21
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Data Link Layer 1 implementation
 */

#include <vector>
#include <cstdint>
#include <PhysicalLayer.hpp>
#include "DataLinkLayer.hpp"

DataLinkLayer::DataLinkLayer(PhysicalLayer *layer) : physicalLayer(layer) {
  /* empty */
}

void DataLinkLayer::send(const std::vector<uint8_t> &data) {
  // Add headers, error checking, etc.
  std::vector<uint8_t> frame = addHeaders(data);
  physicalLayer->send(frame);
}

std::vector<uint8_t> DataLinkLayer::receive(void) {
  std::vector<uint8_t> data = physicalLayer->receive();
  return removeHeaders(data);
}

std::vector<uint8_t> DataLinkLayer::addHeaders(const std::vector<uint8_t> &data) {
  /* implementaion goes here */
  return data;
}

std::vector<uint8_t> DataLinkLayer::removeHeaders(const std::vector<uint8_t> &frame) {
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

