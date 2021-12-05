/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../../inc/MarlinConfig.h"

#if MOTHERBOARD == BOARD_WEEDO_73B
#include "../gcode.h"
#include "../../module/tool_change.h"

/**
 * M922: Enable/disable/query auto purge on tool-change
 *
 * Parameters
 *   S[bool] - Flag to enable / disable.
 *             If omitted, report current state.
 */
void GcodeSuite::M922() {

  if (parser.seen('S')) {
    toolchange_settings.x40_toolchange_config &= 254; // reset first bit to 0
    toolchange_settings.x40_toolchange_config |= parser.value_bool();
  } else {
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM("auto purge on tool-change ");
    serialprintln_onoff(toolchange_settings.x40_toolchange_config & 1);
  }
}

/**
 * M923: Enable/disable/query multiwipe on tool-change
 *
 * Parameters
 *   S[bool] - Flag to enable / disable.
 *             If omitted, report current state.
 */
void GcodeSuite::M923() {

  if (parser.seen('S')) {
    toolchange_settings.x40_toolchange_config &= 253; // reset second bit to 0
    toolchange_settings.x40_toolchange_config |= parser.value_bool() << 1;
  } else {
    SERIAL_ECHO_START();
    SERIAL_ECHOPGM("multiwipe on tool-change ");
    serialprintln_onoff(toolchange_settings.x40_toolchange_config & 2);
  }
}

#endif
