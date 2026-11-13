//
//  razerdevice.h
//  Razer device query functions
//
//

#ifndef DRIVER_RAZERDEVICE_H_
#define DRIVER_RAZERDEVICE_H_

#include <IOKit/usb/IOUSBLib.h>
#include <IOKit/IOCFPlugIn.h>
#include <stdio.h>

#include "razerkbd_driver.h"
#include "razermouse_driver.h"
#include "razermousedock_driver.h"
#include "razermousemat_driver.h"
#include "razerheadphone_driver.h"
#include "razeregpu_driver.h"
#include "razerkraken_driver.h"
#include "razeraccessory_driver.h"

#define TYPE_KEYBOARD 0
#define TYPE_BLADE 1
#define TYPE_MOUSE 2
#define TYPE_MOUSE_DOCK 3
#define TYPE_MOUSE_MAT 4
#define TYPE_EGPU 5
#define TYPE_HEADPHONE 6
#define TYPE_ACCESSORY 7

#ifndef USB_VENDOR_ID_RAZER
#define USB_VENDOR_ID_RAZER 0x1532
#endif

/*
 * A mouse paired to a Razer Mouse Dock Pro has no USB device of its own: the dock
 * forwards commands with a transaction id in 0x00-0x1F to the mouse, while 0xE0-0xFF
 * address the dock itself. Such a mouse is exposed as an extra RazerDevice whose
 * usbDevice is a proxy around the dock's interface. The driver code sees the mouse's
 * own (wireless) product id; RazerDevice.productId carries RAZER_DOCKED_MOUSE_ID()
 * so the paired mouse is distinguishable from the same mouse on its own dongle.
 */
#define RAZER_DOCKED_MOUSE_FLAG 0x8000
#define RAZER_DOCKED_MOUSE_ID(mouse_product_id) (RAZER_DOCKED_MOUSE_FLAG | (mouse_product_id))

// The dock does not report which mouse is paired; the Basilisk V3 Pro 35K is the
// only one this has been tested with.
#define RAZER_MOUSE_DOCK_PRO_PAIRED_MOUSE USB_DEVICE_ID_RAZER_BASILISK_V3_PRO_35K_WIRELESS

typedef struct {
    IOUSBDeviceInterface **usbDevice;
    UInt16 productId;
    int internalDeviceId;
} RazerDevice;

typedef struct {
    RazerDevice *devices;
    int size;
} RazerDevices;

IOUSBDeviceInterface **getRazerUSBDeviceInterface(int type);
void closeRazerUSBDeviceInterface(IOUSBDeviceInterface **dev);

RazerDevices getAllRazerDevices();
void closeAllRazerDevices(RazerDevices devices);

#endif