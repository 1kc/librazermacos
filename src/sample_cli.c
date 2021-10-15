#include<stdio.h>
#include "razerdevice.h"
#include "razerkbd_driver.h"

int main(int argc, const char * argv[]) {
    RazerDevices allDevices = getAllRazerDevices();
    RazerDevice *razerDevices = allDevices.devices;

    printf("%d Razer device(s) found:\n", allDevices.size);

    for (int i = 0; i < allDevices.size; i++) {
        RazerDevice device = razerDevices[i];
        printf("%#06x\n", device.productId);
        if (device.productId == 0x0099){
            printf("Found Basilisk V3\n");
            // printf("dpi: %u\n", razer_attr_read_dpi(device.usbDevice));

            razer_attr_write_scroll_mode_static(device.usbDevice, "F", 3);
            razer_attr_write_left_mode_static(device.usbDevice, "F", 3);
            razer_attr_write_logo_mode_static(device.usbDevice, "F", 3);

        }
        // Testing out the blackwidow v3 pro changes by switching to wave
        if (device.productId == 0x025A)
        {
            printf("Found blackwidow v3 pro keyboard (wired)\n");
            razer_attr_write_mode_wave(device.usbDevice, "1", 0, 0x90);
        }
    }

    closeAllRazerDevices(allDevices);
    return 0;

}

