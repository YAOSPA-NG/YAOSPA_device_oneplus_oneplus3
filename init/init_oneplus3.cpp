/*
   Copyright (c) 2016 Paranoid Android

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"

#include "init_msm.h"

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type) {

    std::string project_name = property_get("ro.boot.project_name");
    std::string rf_version = property_get("ro.boot.rf_version");

    if (project_name == "15811") {
        property_set("ro.product.device", "OnePlus3T");
        property_set("ro.battery.capacity", "3400");
        if (rf_version == "12") {
            /* China model */
            property_set("ro.telephony.default_network", "22,22");
            property_set("telephony.lteOnCdmaDevice", "1");
            property_set("persist.radio.force_on_dc", "true");
            property_set("ro.product.model", "ONEPLUS A3010");
        } else if (rf_version == "22") {
            /* Europe / Asia model */
            property_set("ro.telephony.default_network", "9,9");
            property_set("ro.product.model", "ONEPLUS A3003");
        } else if (rf_version == "32") {
            /* North America model */
            property_set("ro.telephony.default_network", "22,22");
            property_set("telephony.lteOnCdmaDevice", "1");
            property_set("persist.radio.force_on_dc", "true");
            property_set("ro.product.model", "ONEPLUS A3000");
        }
   } else {
        property_set("ro.product.device", "OnePlus3");
        property_set("ro.battery.capacity", "3000");
        if (rf_version == "11" || rf_version == "31") {
            /* China / North America model */
            property_set("ro.telephony.default_network", "22,22");
            property_set("telephony.lteOnCdmaDevice", "1");
            property_set("persist.radio.force_on_dc", "true");
            property_set("ro.product.model", "ONEPLUS A3000");
        } else if (rf_version == "21") {
            /* Europe / Asia model */
            property_set("ro.telephony.default_network", "9,9");
            property_set("ro.product.model", "ONEPLUS A3003");
        }
   }
}
