/* -*-c++-*-
 * @file: PhysicalLayer.hpp
 * @author: Dmitry Shpakov
 * @date: 2024/08/21
 * @licence: LGPL3 (see text at the end of a file)
 * @description: Physical Layer 0 definition
 */

#pragma once

#include <vector>
#include <cstdint>
#include <AbstractLayer.hpp>

class PhysicalLayer : public AbstractLayer {
public:
  void send(const std::vector<uint8_t> &data) override;
  std::vector<uint8_t> receive(void) override;
};

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

