#include<stdio.h>
#include "razerdevice.h"
#include "razerkbd_driver.h"

int main(int argc, const char * argv[]) {

    IOUSBDeviceInterface **dev = getRazerUSBDeviceInterface(0);
    printf("Getting Razer usb device\n");

    if (dev == NULL) {
        printf("No device found\n");
		return -1;  // Assume appropriate error message displayed during the lookup
	}

    return 0;

}
