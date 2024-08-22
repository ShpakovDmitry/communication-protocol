/* -*-c++-*-
 * @file: ApplicationLayer.cpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/22
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Application Layer 6 implementation
 */

#include <vector>
#include <cstdint>
#include <string>
#include <PresentationLayer.hpp>
#include "ApplicationLayer.hpp"

ApplicationLayer::ApplicationLayer(PresentationLayer *layer) : presentationLayer(layer) {
  /* empty */
}

void ApplicationLayer::send(const std::vector<uint8_t> &data) {
  std::vector<uint8_t> frame = addHeaders(data);
  presentationLayer->send(frame);
}

std::vector<uint8_t> ApplicationLayer::receive(void) {
  std::vector<uint8_t> data = presentationLayer->receive();
  return removeHeaders(data);
}

std::vector<uint8_t> ApplicationLayer::addHeaders(const std::vector<uint8_t> &data) {
  /* implementaion goes here */
  std::vector<uint8_t> packet = data;
  std::string header = ":L6:";
  packet.insert(packet.begin(), header.begin(), header.end());
  packet.insert(packet.end(), header.begin(), header.end());
  return packet;
}

std::vector<uint8_t> ApplicationLayer::removeHeaders(const std::vector<uint8_t> &frame) {
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

