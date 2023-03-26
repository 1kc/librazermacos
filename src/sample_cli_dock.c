#include <stdio.h>
#include <unistd.h>
#include "razerdevice.h"
#include "razermouse_driver.h"

int main(int argc, const char *argv[])
{
    RazerDevices allDevices = getAllRazerDevices();
    RazerDevice *razerDevices = allDevices.devices;

    printf("%d Razer device(s) found:\n", allDevices.size);

    for (int i = 0; i < allDevices.size; i++)
    {
        RazerDevice device = razerDevices[i];
        printf("%#06x\n", device.productId);

        if (device.productId == 0x00a4)
        {
            char buf2[256];
            ssize_t result2 = razer_attr_read_get_battery(device.usbDevice, buf2);
            printf("battery: %s\n", buf2);
            printf("Done!\n");
        }
    }

    closeAllRazerDevices(allDevices);
    return 0;
}
