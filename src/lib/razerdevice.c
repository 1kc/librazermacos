#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "razerdevice.h"
#include "razercommon.h"

bool is_razer_device(IOUSBDeviceInterface **dev)
{
	kern_return_t kr;
	UInt16 vendor;
	UInt16 product;
	UInt16 release;

	kr = (*dev)->GetDeviceVendor(dev, &vendor);
	kr = (*dev)->GetDeviceProduct(dev, &product);
	kr = (*dev)->GetDeviceReleaseNumber(dev, &release);

	return vendor == USB_VENDOR_ID_RAZER;
}

bool is_keyboard(IOUSBDeviceInterface **usb_dev)
{
	UInt16 product = -1;
	(*usb_dev)->GetDeviceProduct(usb_dev, &product);

	switch (product)
	{
	case USB_DEVICE_ID_RAZER_COBRA:
	case USB_DEVICE_ID_RAZER_NOSTROMO:
	case USB_DEVICE_ID_RAZER_ORBWEAVER:
	case USB_DEVICE_ID_RAZER_ORBWEAVER_CHROMA:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_STEALTH:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_STEALTH_EDITION:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2012:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2013:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_ULTIMATE_2016:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_X_ULTIMATE:
	case USB_DEVICE_ID_RAZER_TARTARUS:
	case USB_DEVICE_ID_RAZER_TARTARUS_CHROMA:
	case USB_DEVICE_ID_RAZER_TARTARUS_V2:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_OVERWATCH:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA:
	case USB_DEVICE_ID_RAZER_DEATHSTALKER_EXPERT:
	case USB_DEVICE_ID_RAZER_DEATHSTALKER_CHROMA:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA_TE:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_X_CHROMA:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_X_CHROMA_TE:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_LITE:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_2019:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_ESSENTIAL:
	case USB_DEVICE_ID_RAZER_ORNATA:
	case USB_DEVICE_ID_RAZER_ORNATA_CHROMA:
	case USB_DEVICE_ID_RAZER_ORNATA_CHROMA_V2:
	case USB_DEVICE_ID_RAZER_HUNTSMAN_ELITE:
	case USB_DEVICE_ID_RAZER_HUNTSMAN_TE:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_ELITE:
	case USB_DEVICE_ID_RAZER_HUNTSMAN:
	case USB_DEVICE_ID_RAZER_CYNOSA_CHROMA:
    case USB_DEVICE_ID_RAZER_CYNOSA_CHROMA_PRO:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_CHROMA_V2:
	case USB_DEVICE_ID_RAZER_ANANSI:
	case USB_DEVICE_ID_RAZER_CYNOSA_V2:
	case USB_DEVICE_ID_RAZER_CYNOSA_LITE:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_V3:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_V3_TK:
    case USB_DEVICE_ID_RAZER_BLACKWIDOW_V3_PRO_WIRED:
	case USB_DEVICE_ID_RAZER_HUNTSMAN_MINI:
    case USB_DEVICE_ID_RAZER_HUNTSMAN_V2_ANALOG:
    case USB_DEVICE_ID_RAZER_HUNTSMAN_V2:
    case USB_DEVICE_ID_RAZER_HUNTSMAN_V2_TKL:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_V3_MINI_WIRED:
	case USB_DEVICE_ID_RAZER_BLACKWIDOW_V3_MINI_WIRELESS:
		return true;
	}

	return false;
}

bool is_mouse(IOUSBDeviceInterface **usb_dev)
{
	UInt16 product = -1;
	(*usb_dev)->GetDeviceProduct(usb_dev, &product);

	switch (product)
	{
	case USB_DEVICE_ID_RAZER_OROCHI_2011:
	case USB_DEVICE_ID_RAZER_DEATHADDER_3_5G:
	case USB_DEVICE_ID_RAZER_ABYSSUS_1800:
	case USB_DEVICE_ID_RAZER_MAMBA_2012_WIRED:
	case USB_DEVICE_ID_RAZER_MAMBA_2012_WIRELESS:
	case USB_DEVICE_ID_RAZER_NAGA_2012:
	case USB_DEVICE_ID_RAZER_IMPERATOR:
	case USB_DEVICE_ID_RAZER_OUROBOROS:
	case USB_DEVICE_ID_RAZER_TAIPAN:
	case USB_DEVICE_ID_RAZER_NAGA_HEX_RED:
	case USB_DEVICE_ID_RAZER_DEATHADDER_2013:
	case USB_DEVICE_ID_RAZER_DEATHADDER_1800:
	case USB_DEVICE_ID_RAZER_OROCHI_2013:
	case USB_DEVICE_ID_RAZER_NAGA_2014:
	case USB_DEVICE_ID_RAZER_NAGA_X:
	case USB_DEVICE_ID_RAZER_NAGA_HEX:
	case USB_DEVICE_ID_RAZER_ABYSSUS:
	case USB_DEVICE_ID_RAZER_DEATHADDER_CHROMA:
	case USB_DEVICE_ID_RAZER_MAMBA_WIRED:
	case USB_DEVICE_ID_RAZER_MAMBA_WIRELESS:
	case USB_DEVICE_ID_RAZER_MAMBA_TE_WIRED:
	case USB_DEVICE_ID_RAZER_OROCHI_CHROMA:
	case USB_DEVICE_ID_RAZER_DIAMONDBACK_CHROMA:
	case USB_DEVICE_ID_RAZER_NAGA_HEX_V2:
	case USB_DEVICE_ID_RAZER_NAGA_CHROMA:
	case USB_DEVICE_ID_RAZER_DEATHADDER_3500:
	case USB_DEVICE_ID_RAZER_LANCEHEAD_WIRED:
	case USB_DEVICE_ID_RAZER_LANCEHEAD_WIRELESS:
	case USB_DEVICE_ID_RAZER_ABYSSUS_V2:
	case USB_DEVICE_ID_RAZER_DEATHADDER_ELITE:
	case USB_DEVICE_ID_RAZER_ABYSSUS_2000:
	case USB_DEVICE_ID_RAZER_LANCEHEAD_TE_WIRED:
	case USB_DEVICE_ID_RAZER_BASILISK:
	case USB_DEVICE_ID_RAZER_BASILISK_ULTIMATE:
	case USB_DEVICE_ID_RAZER_BASILISK_ULTIMATE_RECEIVER:
	case USB_DEVICE_ID_RAZER_NAGA_TRINITY:
	case USB_DEVICE_ID_RAZER_NAGA_PRO_WIRELESS:
	case USB_DEVICE_ID_RAZER_NAGA_PRO_WIRED:
	case USB_DEVICE_ID_RAZER_ABYSSUS_ELITE_DVA_EDITION:
	case USB_DEVICE_ID_RAZER_ABYSSUS_ESSENTIAL:
	case USB_DEVICE_ID_RAZER_MAMBA_ELITE:
	case USB_DEVICE_ID_RAZER_DEATHADDER_ESSENTIAL:
	case USB_DEVICE_ID_RAZER_LANCEHEAD_WIRELESS_RECEIVER:
	case USB_DEVICE_ID_RAZER_LANCEHEAD_WIRELESS_WIRED:
	case USB_DEVICE_ID_RAZER_DEATHADDER_ESSENTIAL_WHITE_EDITION:
	case USB_DEVICE_ID_RAZER_MAMBA_WIRELESS_RECEIVER:
	case USB_DEVICE_ID_RAZER_MAMBA_WIRELESS_WIRED:
	case USB_DEVICE_ID_RAZER_VIPER:
	case USB_DEVICE_ID_RAZER_VIPER_8KHZ:
	case USB_DEVICE_ID_RAZER_VIPER_MINI:
	case USB_DEVICE_ID_RAZER_BASILISK_V2:
	case USB_DEVICE_ID_RAZER_VIPER_ULTIMATE_WIRED:
	case USB_DEVICE_ID_RAZER_VIPER_ULTIMATE_WIRELESS:
	case USB_DEVICE_ID_RAZER_DEATHADDER_V2:
	case USB_DEVICE_ID_RAZER_DEATHADDER_V2_PRO_WIRED:
  case USB_DEVICE_ID_RAZER_DEATHADDER_V2_PRO_WIRELESS:
	case USB_DEVICE_ID_RAZER_DEATHADDER_V2_MINI:
	case USB_DEVICE_ID_RAZER_NAGA_LEFT_HANDED_2020:
	case USB_DEVICE_ID_RAZER_ATHERIS_RECEIVER:
  case USB_DEVICE_ID_RAZER_DEATHADDER_ESSENTIAL_2021:
	case USB_DEVICE_ID_RAZER_BASILISK_V3:
	case USB_DEVICE_ID_RAZER_BASILISK_V3_X_HYPERSPEED:
	case USB_DEVICE_ID_RAZER_BASILISK_V3_35K:
	case USB_DEVICE_ID_RAZER_BASILISK_V3_PRO_WIRED:
  case USB_DEVICE_ID_RAZER_BASILISK_V3_PRO_WIRELESS:
	case USB_DEVICE_ID_RAZER_BASILISK_V3_PRO_35K_WIRED:
  case USB_DEVICE_ID_RAZER_BASILISK_V3_PRO_35K_WIRELESS:
	case USB_DEVICE_ID_RAZER_BASILISK_ESSENTIAL:
  case USB_DEVICE_ID_RAZER_OROCHI_V2_RECEIVER:
  case USB_DEVICE_ID_RAZER_OROCHI_V2_BLUETOOTH:
		return true;
	}

	return false;
}

bool is_mouse_dock(IOUSBDeviceInterface **usb_dev)
{
	UInt16 product = -1;
	(*usb_dev)->GetDeviceProduct(usb_dev, &product);

	switch (product)
	{
	case USB_DEVICE_ID_RAZER_MOUSE_CHARGING_DOCK:
		return true;
	}

	return false;
}

bool is_mouse_mat(IOUSBDeviceInterface **usb_dev)
{
	UInt16 product = -1;
	(*usb_dev)->GetDeviceProduct(usb_dev, &product);

	switch (product)
	{
	case USB_DEVICE_ID_RAZER_FIREFLY_HYPERFLUX:
	case USB_DEVICE_ID_RAZER_FIREFLY:
	case USB_DEVICE_ID_RAZER_FIREFLY_V2:
	case USB_DEVICE_ID_RAZER_GOLIATHUS_CHROMA:
	case USB_DEVICE_ID_RAZER_GOLIATHUS_CHROMA_EXTENDED:
		return true;
	}

	return false;
}

bool is_egpu(IOUSBDeviceInterface **usb_dev)
{
	UInt16 product = -1;
	(*usb_dev)->GetDeviceProduct(usb_dev, &product);

	switch (product)
	{
	case USB_DEVICE_ID_RAZER_CORE_X_CHROMA:
		return true;
	}

	return false;
}


bool is_headphone(IOUSBDeviceInterface **usb_dev) 
{
    UInt16 product = -1;
    (*usb_dev)->GetDeviceProduct(usb_dev, &product);

    switch (product) 
    {
        case USB_DEVICE_ID_RAZER_KRAKEN_KITTY_EDITION:
        case USB_DEVICE_ID_RAZER_KRAKEN_V2:
        case USB_DEVICE_ID_RAZER_KRAKEN_ULTIMATE:
            return true;
    }

    return false;
}

bool is_accessory(IOUSBDeviceInterface **usb_dev)
{
    UInt16 product = -1;
    (*usb_dev)->GetDeviceProduct(usb_dev, &product);

    switch (product)
    {
        case USB_DEVICE_ID_RAZER_MOUSE_DOCK_PRO:
        case USB_DEVICE_ID_RAZER_NOMMO_CHROMA:
        case USB_DEVICE_ID_RAZER_NOMMO_PRO:
        case USB_DEVICE_ID_RAZER_CHROMA_MUG:
        case USB_DEVICE_ID_RAZER_CHROMA_BASE:
        case USB_DEVICE_ID_RAZER_CHROMA_HDK:
        case USB_DEVICE_ID_RAZER_MOUSE_BUNGEE_V3_CHROMA:
        case USB_DEVICE_ID_RAZER_BASE_STATION_V2_CHROMA:
        case USB_DEVICE_ID_RAZER_THUNDERBOLT_4_DOCK_CHROMA:
        case USB_DEVICE_ID_RAZER_LAPTOP_STAND_CHROMA:
            return true;
    }

    return false;
}

IOUSBDeviceInterface **getRazerUSBDeviceInterface(int type)
{
	CFMutableDictionaryRef matchingDict;
	matchingDict = IOServiceMatching(kIOUSBDeviceClassName);
	if (matchingDict == NULL)
	{
		return NULL;
	}

	io_iterator_t iter;
	kern_return_t kReturn =
		IOServiceGetMatchingServices(MACH_PORT_NULL, matchingDict, &iter);
	if (kReturn != kIOReturnSuccess)
	{
		return NULL;
	}

	io_service_t usbDevice;
	while ((usbDevice = IOIteratorNext(iter)))
	{
		IOCFPlugInInterface **plugInInterface = NULL;
		SInt32 score;

		kReturn = IOCreatePlugInInterfaceForService(
			usbDevice, kIOUSBDeviceUserClientTypeID, kIOCFPlugInInterfaceID, &plugInInterface, &score);

		IOObjectRelease(usbDevice); // Not needed after plugin created
		if ((kReturn != kIOReturnSuccess) || plugInInterface == NULL)
		{
			// printf("Unable to create plugin (0x%08x)\n", kReturn);
			continue;
		}

		IOUSBDeviceInterface **dev = NULL;
		HRESULT hResult = (*plugInInterface)->QueryInterface(plugInInterface, CFUUIDGetUUIDBytes(kIOUSBDeviceInterfaceID), (LPVOID *)&dev);

		(*plugInInterface)->Release(plugInInterface); // Not needed after device interface created
		if (hResult || !dev)
		{
			// printf("Couldn’t create a device interface (0x%08x)\n", (int) hResult);
			continue;
		}

		// Filter out non-Razer devices
		if (!is_razer_device(dev))
		{
			(*dev)->Release(dev);
			continue;
		}

		switch (type) 
        {
			case TYPE_KEYBOARD:
			case TYPE_BLADE:
				// Filter out non-keyboards and non-blade laptops
				if (!(is_keyboard(dev) || is_blade_laptop(dev))) 
                {
					(*dev)->Release(dev);
					continue;
				}
				break;
        
			case TYPE_MOUSE:
				// Filter out non-mice
				if (!is_mouse(dev)) 
                {
					(*dev)->Release(dev);
					continue;
				}
				break;
        
			case TYPE_MOUSE_DOCK:
				// Filter out non-mice-mats
				if (!is_mouse_dock(dev)) 
                {
					(*dev)->Release(dev);
					continue;
				}
				break;
        
			case TYPE_MOUSE_MAT:
				// Filter out non-mice-mats
				if (!is_mouse_mat(dev)) 
                {
					(*dev)->Release(dev);
					continue;
				}
				break;

 	        case TYPE_HEADPHONE:
                if (!is_headphone(dev))
                {
                  (*dev)->Release(dev);
                  continue;
                }
                break;

            case TYPE_EGPU:
			    // Filter out non-mice-mats
			    if (!is_egpu(dev))
			    {
				  (*dev)->Release(dev);
				  continue;
			    }
			  break;
            case TYPE_ACCESSORY:
                if (!is_accessory(dev))
                {
                    (*dev)->Release(dev);
                    continue;
                }
                break;
        
		    default:
			    // Unsupported Razer peripheral type
			    (*dev)->Release(dev);
			    continue;
		}

		kReturn = (*dev)->USBDeviceOpen(dev);
		if (kReturn != kIOReturnSuccess)
		{
			printf("Unable to open USB device: %08x\n", kReturn);
			(*dev)->Release(dev);
			continue;
		}

		// Success. We found the Razer USB device.
		// Caller is responsible for closing USB and release device.
		IOObjectRelease(iter);
		return dev;
	}

	IOObjectRelease(iter);
	return NULL;
}

void closeRazerUSBDeviceInterface(IOUSBDeviceInterface **dev)
{
	kern_return_t kr;
	kr = (*dev)->USBDeviceClose(dev);
	kr = (*dev)->Release(dev);
}

/*
 * Proxy device for a mouse paired to a Mouse Dock Pro (see razerdevice.h).
 *
 * The proxy looks like an IOUSBDeviceInterface** to the driver code: `vtable` must stay
 * the first member so that &proxy->vtable can be passed around as the interface. Only the
 * methods librazermacos calls are implemented; they forward to the dock, except that
 * GetDeviceProduct reports the mouse and outgoing reports are re-addressed to the mouse.
 */
typedef struct {
    IOUSBDeviceInterface *vtable;
    IOUSBDeviceInterface functions;
    IOUSBDeviceInterface **dock;
    UInt16 productId;
} RazerDockedMouse;

#define RAZER_DOCK_TARGET_MASK 0x1F // transaction ids 0x00-0x1F reach the paired mouse

static IOReturn docked_mouse_get_product(void *self, UInt16 *product)
{
    *product = ((RazerDockedMouse *)self)->productId;
    return kIOReturnSuccess;
}

static IOReturn docked_mouse_get_vendor(void *self, UInt16 *vendor)
{
    IOUSBDeviceInterface **dock = ((RazerDockedMouse *)self)->dock;
    return (*dock)->GetDeviceVendor(dock, vendor);
}

static IOReturn docked_mouse_get_release_number(void *self, UInt16 *release)
{
    IOUSBDeviceInterface **dock = ((RazerDockedMouse *)self)->dock;
    return (*dock)->GetDeviceReleaseNumber(dock, release);
}

static IOReturn docked_mouse_device_request(void *self, IOUSBDevRequest *request)
{
    IOUSBDeviceInterface **dock = ((RazerDockedMouse *)self)->dock;

    if (request->bRequest != HID_REQ_SET_REPORT || request->pData == NULL
        || request->wLength < sizeof(struct razer_report)) {
        return (*dock)->DeviceRequest(dock, request);
    }

    // Some commands default to transaction id 0xFF, which the dock would answer itself.
    // The crc does not cover the transaction id, so it can be changed in place on a copy.
    struct razer_report report;
    memcpy(&report, request->pData, sizeof(report));
    report.transaction_id.id &= RAZER_DOCK_TARGET_MASK;

    IOUSBDevRequest forwarded = *request;
    forwarded.pData = &report;
    return (*dock)->DeviceRequest(dock, &forwarded);
}

static IOReturn docked_mouse_open_close(void *self)
{
    // The dock entry owns the USB session.
    (void)self;
    return kIOReturnSuccess;
}

static ULONG docked_mouse_release(void *self)
{
    free(self);
    return 0;
}

static IOUSBDeviceInterface **create_docked_mouse(IOUSBDeviceInterface **dock, UInt16 productId)
{
    RazerDockedMouse *mouse = calloc(1, sizeof(RazerDockedMouse));
    if (mouse == NULL) {
        return NULL;
    }
    mouse->functions.Release = docked_mouse_release;
    mouse->functions.USBDeviceOpen = docked_mouse_open_close;
    mouse->functions.USBDeviceClose = docked_mouse_open_close;
    mouse->functions.GetDeviceVendor = docked_mouse_get_vendor;
    mouse->functions.GetDeviceProduct = docked_mouse_get_product;
    mouse->functions.GetDeviceReleaseNumber = docked_mouse_get_release_number;
    mouse->functions.DeviceRequest = docked_mouse_device_request;
    mouse->vtable = &mouse->functions;
    mouse->dock = dock;
    mouse->productId = productId;
    return &mouse->vtable;
}

/*
 * Ask for the serial number with the given transaction id, retrying while the dock reports busy.
 * Returns true and fills serial (23 bytes) when a matching, successful answer arrives.
 */
static bool read_serial_through_dock(IOUSBDeviceInterface **dock, unsigned char transaction_id, char *serial)
{
    struct razer_report request = get_razer_report(0x00, 0x82, 0x16);
    struct razer_report response = {0};
    request.transaction_id.id = transaction_id;
    request.crc = razer_calculate_crc(&request);

    for (int attempt = 0; attempt < 5; attempt++) {
        if (razer_get_usb_response(dock, 0x00, &request, 0x00, &response, RAZER_NEW_MOUSE_RECEIVER_WAIT_MIN_US) != kIOReturnSuccess) {
            return false;
        }
        if (response.status != RAZER_CMD_BUSY) {
            break;
        }
        usleep(RAZER_NEW_MOUSE_RECEIVER_WAIT_MIN_US);
    }

    if (response.status != RAZER_CMD_SUCCESSFUL
        || response.transaction_id.id != transaction_id
        || response.command_class != 0x00 || response.command_id.id != 0x82) {
        return false;
    }
    memcpy(serial, response.arguments, 22);
    serial[22] = '\0';
    return serial[0] != '\0';
}

/*
 * A paired mouse answers on the mouse transaction ids with a serial number of its own.
 */
static bool mouse_dock_pro_has_paired_mouse(IOUSBDeviceInterface **dock)
{
    char dock_serial[23] = {0};
    char mouse_serial[23] = {0};

    if (!read_serial_through_dock(dock, 0xFF, dock_serial)) {
        return false;
    }
    if (!read_serial_through_dock(dock, RAZER_DOCK_TARGET_MASK, mouse_serial)) {
        return false;
    }
    return strcmp(dock_serial, mouse_serial) != 0;
}

RazerDevices getAllRazerDevices()
{
    RazerDevices allDevices = { .devices = NULL, .size = 0 };

    CFMutableDictionaryRef matchingDict;
    matchingDict = IOServiceMatching(kIOUSBDeviceClassName);
    if (matchingDict == NULL)
    {
        return allDevices;
    }

    io_iterator_t iter;
    kern_return_t kReturn =
            IOServiceGetMatchingServices(MACH_PORT_NULL, matchingDict, &iter);
    if (kReturn != kIOReturnSuccess)
    {
        return allDevices;
    }

    int array_size = 0;
    int array_index = -1;
    RazerDevice *razerDevices = malloc(array_size * sizeof(RazerDevice));

    io_service_t usbDevice;
    while ((usbDevice = IOIteratorNext(iter)))
    {
        IOCFPlugInInterface **plugInInterface = NULL;
        SInt32 score;

        kReturn = IOCreatePlugInInterfaceForService(
                usbDevice, kIOUSBDeviceUserClientTypeID, kIOCFPlugInInterfaceID, &plugInInterface, &score);

        IOObjectRelease(usbDevice); // Not needed after plugin created
        if ((kReturn != kIOReturnSuccess) || plugInInterface == NULL)
        {
            // printf("Unable to create plugin (0x%08x)\n", kReturn);
            continue;
        }

        IOUSBDeviceInterface **dev = NULL;
        HRESULT hResult = (*plugInInterface)->QueryInterface(plugInInterface, CFUUIDGetUUIDBytes(kIOUSBDeviceInterfaceID), (LPVOID *)&dev);

        (*plugInInterface)->Release(plugInInterface); // Not needed after device interface created
        if (hResult || !dev)
        {
            // printf("Couldn’t create a device interface (0x%08x)\n", (int) hResult);
            continue;
        }

        // Filter out non-Razer devices
        if (!is_razer_device(dev))
        {
            (*dev)->Release(dev);
            continue;
        }

        if(!is_keyboard(dev)
        && !is_blade_laptop(dev)
        && !is_mouse(dev)
        && !is_mouse_dock(dev)
        && !is_mouse_dock(dev)
        && !is_mouse_mat(dev)
        && !is_headphone(dev)
        && !is_egpu(dev)
        && !is_accessory(dev)
        ) {
            (*dev)->Release(dev);
            continue;
        }

        kReturn = (*dev)->USBDeviceOpen(dev);
        if (kReturn != kIOReturnSuccess)
        {
            printf("Unable to open USB device: %08x\n", kReturn);
            (*dev)->Release(dev);
            continue;
        }

        // Success. We found the Razer USB device.
        // Caller is responsible for closing USB and release device.
        array_size++;
        razerDevices = realloc(razerDevices, array_size * sizeof(RazerDevice));
        array_index++;

        UInt16 productId;
        (*dev)->GetDeviceProduct(dev, &productId);

        RazerDevice newDevice = { .usbDevice = dev, .internalDeviceId = array_index, .productId = productId };
        razerDevices[array_index] = newDevice;

        if (productId == USB_DEVICE_ID_RAZER_MOUSE_DOCK_PRO && mouse_dock_pro_has_paired_mouse(dev))
        {
            IOUSBDeviceInterface **mouse = create_docked_mouse(dev, RAZER_MOUSE_DOCK_PRO_PAIRED_MOUSE);
            if (mouse != NULL)
            {
                array_size++;
                razerDevices = realloc(razerDevices, array_size * sizeof(RazerDevice));
                array_index++;

                RazerDevice pairedMouse = {
                    .usbDevice = mouse,
                    .internalDeviceId = array_index,
                    .productId = RAZER_DOCKED_MOUSE_ID(RAZER_MOUSE_DOCK_PRO_PAIRED_MOUSE)
                };
                razerDevices[array_index] = pairedMouse;
            }
        }
    }

    IOObjectRelease(iter);
    allDevices.devices = razerDevices;
    allDevices.size = array_size;
    return allDevices;
}

void closeAllRazerDevices(RazerDevices devices)
{
    for(int counter=0; counter < devices.size; ++counter) {
        IOUSBDeviceInterface **dev = devices.devices[counter].usbDevice;
        (*dev)->USBDeviceClose(dev);
        (*dev)->Release(dev);
    }
    free(devices.devices);
    devices.devices = NULL;
}
