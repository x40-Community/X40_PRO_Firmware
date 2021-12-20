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
#include "../../MarlinCore.h"
#include "../../module/temperature.h"
#include "../../sd/cardreader.h"
#include "../../module/planner.h"
#include "../../libs/duration_t.h"
#include "../../module/printcounter.h"
#include "../../wtdgus/print/WTDGUSScreen_Printing.h"
#include "../../wtdgus/WTDGUSSerial.h"
#include "../../wtdgus/WTDGUSConfig.h"
#include "../../wtdgus/WTDGUSManager.h"
#include "../../wtlib/WTCounter.h"
#include "../../wtdgus/WTHelpDoc.h"
#include "../../wtlib/WTCMD.h"
#include "../../wtlib/WTGcodeinfo.h"

#if MOTHERBOARD == BOARD_WEEDO_73B
#include "../gcode.h"

/**
 * M0: Weedo X40 printing pause
 *   
 *            
 */
void GcodeSuite::M0() {
if (wt_onlineprinting == SPARK_IDLE || wt_onlineprinting == SPARK_LOST)
				{
					if (card.flag.sdprinting)
						wt_sdcard_pause();
					else
						wt_sdcard_resume();
				}
				else if (wt_onlineprinting == SPARK_PRINTING)
				{
					wt_online_pause();
				}
				else
				{
					wt_online_resume();
				}
  
}


#endif
