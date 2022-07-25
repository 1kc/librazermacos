#include <stdio.h>
#include "razerdevice.h"
#include "razerkbd_driver.h"

#define UNUSED(x) (void)(x)
int main(int argc, const char *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    RazerDevices allDevices = getAllRazerDevices();
    RazerDevice *razerDevices = allDevices.devices;

    printf("%d Razer device(s) found:\n", allDevices.size);

    for (int i = 0; i < allDevices.size; i++)
    {
        RazerDevice device = razerDevices[i];
        printf("Found Product ID %#06x\n", device.productId);
        switch (device.productId)
        {
        case 0x025A:
            // Testing out the blackwidow v3 pro changes by switching to wave
            printf("Found BlackWidow V3 PRO Keyboard (Wired)\n");
            razer_attr_write_mode_wave(device.usbDevice, "0", 0, 0x90);
            break;
        case 0x025C:

            // Testing out the blackwidow v3 pro changes by switching to wave
            printf("Found BlackWidow V3 PRO Keyboard (Wireless)\n");
            razer_attr_write_mode_wave(device.usbDevice, "1", 0, 0x90);
            break;
        default:
            break;
        }
    }

    closeAllRazerDevices(allDevices);
    return 0;
}
