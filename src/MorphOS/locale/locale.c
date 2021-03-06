#ifndef LOCALE_H
#define LOCALE_H


/****************************************************************************/


/* This file was created automatically by CatComp.
 * Do NOT edit by hand!
 */


#ifndef EXEC_TYPES_H
#include <exec/types.h>
#endif

#ifdef CATCOMP_ARRAY
#undef CATCOMP_NUMBERS
#undef CATCOMP_STRINGS
#define CATCOMP_NUMBERS
#define CATCOMP_STRINGS
#endif

#ifdef CATCOMP_BLOCK
#undef CATCOMP_STRINGS
#define CATCOMP_STRINGS
#endif


/****************************************************************************/


#ifdef CATCOMP_NUMBERS

#define MSG_OK_GAD 0
#define MSG_CANCEL_GAD 1
#define MSG_PREFS_TYPE_GAD 2
#define MSG_PREFS_READ_ONLY_GAD 3
#define MSG_PREFS_FILE_GAD 4
#define MSG_PREFS_DEVICE_GAD 5
#define MSG_PREFS_CREATE_GAD 6
#define MSG_PREFS_UNIT_GAD 7
#define MSG_PREFS_FLAGS_GAD 8
#define MSG_PREFS_START_BLOCK_GAD 9
#define MSG_PREFS_BLOCKS_GAD 10
#define MSG_PREFS_BLOCK_SIZE_GAD 11
#define MSG_PREFS_RAMSIZE_GAD 12
#define MSG_PREFS_ADD_GAD 13
#define MSG_PREFS_EDIT_GAD 14
#define MSG_PREFS_REMOVE_GAD 15
#define MSG_PREFS_CD_DEVICE_GAD 16
#define MSG_PREFS_CD_UNIT_GAD 17
#define MSG_PREFS_CD_BOOT_GAD 18
#define MSG_PREFS_CD_DISABLE_DRIVER_GAD 19
#define MSG_PREFS_MORPHOS_ROOT_GAD 20
#define MSG_PREFS_VOLUMETYPE_FILE_GAD 21
#define MSG_PREFS_VOLUMETYPE_DEVICE_GAD 22
#define MSG_PREFS_ID_0_DEVICE_GAD 23
#define MSG_PREFS_ID_1_DEVICE_GAD 24
#define MSG_PREFS_ID_2_DEVICE_GAD 25
#define MSG_PREFS_ID_3_DEVICE_GAD 26
#define MSG_PREFS_ID_4_DEVICE_GAD 27
#define MSG_PREFS_ID_5_DEVICE_GAD 28
#define MSG_PREFS_ID_6_DEVICE_GAD 29
#define MSG_PREFS_SCSI_UNIT_GAD 30
#define MSG_PREFS_MODEM_DEVICE_GAD 31
#define MSG_PREFS_MODEM_UNIT_GAD 32
#define MSG_PREFS_MODEM_PARALLEL_GAD 33
#define MSG_PREFS_ETHERNET_DEVICE_GAD 34
#define MSG_PREFS_ETHERNET_UNIT_GAD 35
#define MSG_PREFS_PRINTER_DEVICE_GAD 36
#define MSG_PREFS_PRINTER_UNIT_GAD 37
#define MSG_PREFS_PRINTER_PARALLEL_GAD 38
#define MSG_PREFS_GFX_WIDTH_GAD 39
#define MSG_PREFS_GFX_HEIGHT_GAD 40
#define MSG_PREFS_GFX_FULLSCREEN_GAD 41
#define MSG_PREFS_GFX_8BIT_GAD 42
#define MSG_PREFS_GFX_FRAMESKIP_GAD 43
#define MSG_PREFS_DISABLE_SOUND 44
#define MSG_PREFS_SYSTEM_RAM_GAD 45
#define MSG_PREFS_SYSTEM_MODEL_GAD 46
#define MSG_PREFS_SYSTEM_ROM_GAD 47
#define MSG_PREFS_START_GAD 48
#define MSG_PREFS_QUIT_GAD 49
#define MSG_MAC_VOLUMES 50
#define MSG_CDROM 51
#define MSG_VIRTUAL_SCSI_DEVICES 52
#define MSG_MODEM 53
#define MSG_ETHERNET 54
#define MSG_PRINTER 55
#define MSG_GRAPHICS 56
#define MSG_SOUND 57
#define MSG_SYSTEM 58
#define MSG_SIZE 59
#define MSG_MB 60
#define MSG_TITLE_BASILISK_SETTINGS 61
#define MSG_TITLE_ADD_VOLUME 62
#define MSG_TITLE_EDIT_VOLUME 63
#define MSG_PAGE_VOLUMES 64
#define MSG_PAGE_SCSI 65
#define MSG_PAGE_COMMUNICATION 66
#define MSG_PAGE_EMULATION 67
#define MSG_MENU_TITLE_BASILISK 68
#define MSG_MENU_BASILISK_ABOUT 69
#define MSG_MENU_BASILISK_START 70
#define MSG_MENU_BASILISK_QUIT 71
#define MSG_AUTHOR_INFORMATION 72
#define MSG_PORT_INFORMATION 73
#define MSG_GFX_INFORMATION 74
#define MSG_DESCRIPTION 75

#endif /* CATCOMP_NUMBERS */


/****************************************************************************/


#ifdef CATCOMP_STRINGS

#define MSG_OK_GAD_STR "_Ok"
#define MSG_CANCEL_GAD_STR "_Cancel"
#define MSG_PREFS_TYPE_GAD_STR "_Type"
#define MSG_PREFS_READ_ONLY_GAD_STR "_Read Only"
#define MSG_PREFS_FILE_GAD_STR "_File"
#define MSG_PREFS_DEVICE_GAD_STR "_Device"
#define MSG_PREFS_CREATE_GAD_STR "Create"
#define MSG_PREFS_UNIT_GAD_STR "_Unit"
#define MSG_PREFS_FLAGS_GAD_STR "_Flags"
#define MSG_PREFS_START_BLOCK_GAD_STR "_Start Block"
#define MSG_PREFS_BLOCKS_GAD_STR "_Blocks"
#define MSG_PREFS_BLOCK_SIZE_GAD_STR "Block Size"
#define MSG_PREFS_RAMSIZE_GAD_STR "%ldMB"
#define MSG_PREFS_ADD_GAD_STR "_Add..."
#define MSG_PREFS_EDIT_GAD_STR "_Edit..."
#define MSG_PREFS_REMOVE_GAD_STR "_Remove"
#define MSG_PREFS_CD_DEVICE_GAD_STR "_Device"
#define MSG_PREFS_CD_UNIT_GAD_STR "_Unit"
#define MSG_PREFS_CD_BOOT_GAD_STR "_Boot from CD"
#define MSG_PREFS_CD_DISABLE_DRIVER_GAD_STR "Disable CD-ROM driver"
#define MSG_PREFS_MORPHOS_ROOT_GAD_STR "MorphOS root"
#define MSG_PREFS_VOLUMETYPE_FILE_GAD_STR "File"
#define MSG_PREFS_VOLUMETYPE_DEVICE_GAD_STR "Device"
#define MSG_PREFS_ID_0_DEVICE_GAD_STR "ID _0 Device"
#define MSG_PREFS_ID_1_DEVICE_GAD_STR "ID _1 Device"
#define MSG_PREFS_ID_2_DEVICE_GAD_STR "ID _2 Device"
#define MSG_PREFS_ID_3_DEVICE_GAD_STR "ID _3 Device"
#define MSG_PREFS_ID_4_DEVICE_GAD_STR "ID _4 Device"
#define MSG_PREFS_ID_5_DEVICE_GAD_STR "ID _5 Device"
#define MSG_PREFS_ID_6_DEVICE_GAD_STR "ID _6 Device"
#define MSG_PREFS_SCSI_UNIT_GAD_STR "Unit"
#define MSG_PREFS_MODEM_DEVICE_GAD_STR "Device"
#define MSG_PREFS_MODEM_UNIT_GAD_STR "Unit"
#define MSG_PREFS_MODEM_PARALLEL_GAD_STR "Parallel device"
#define MSG_PREFS_ETHERNET_DEVICE_GAD_STR "Device"
#define MSG_PREFS_ETHERNET_UNIT_GAD_STR "Unit"
#define MSG_PREFS_PRINTER_DEVICE_GAD_STR "Device"
#define MSG_PREFS_PRINTER_UNIT_GAD_STR "Unit"
#define MSG_PREFS_PRINTER_PARALLEL_GAD_STR "Parallel device"
#define MSG_PREFS_GFX_WIDTH_GAD_STR "_Width"
#define MSG_PREFS_GFX_HEIGHT_GAD_STR "_Height"
#define MSG_PREFS_GFX_FULLSCREEN_GAD_STR "_Full screen"
#define MSG_PREFS_GFX_8BIT_GAD_STR "_8bit mode"
#define MSG_PREFS_GFX_FRAMESKIP_GAD_STR "_Frame skip"
#define MSG_PREFS_DISABLE_SOUND_STR "_Disable sound"
#define MSG_PREFS_SYSTEM_RAM_GAD_STR "MacOS RAM"
#define MSG_PREFS_SYSTEM_MODEL_GAD_STR "Mac Model"
#define MSG_PREFS_SYSTEM_ROM_GAD_STR "_ROM File"
#define MSG_PREFS_START_GAD_STR "Start"
#define MSG_PREFS_QUIT_GAD_STR "Quit"
#define MSG_MAC_VOLUMES_STR "Mac Volumes"
#define MSG_CDROM_STR "CD-ROM"
#define MSG_VIRTUAL_SCSI_DEVICES_STR "Virtual SCSI devices"
#define MSG_MODEM_STR "Modem"
#define MSG_ETHERNET_STR "Ethernet"
#define MSG_PRINTER_STR "Printer"
#define MSG_GRAPHICS_STR "Graphics"
#define MSG_SOUND_STR "Sound"
#define MSG_SYSTEM_STR "System"
#define MSG_SIZE_STR "Size"
#define MSG_MB_STR "MB"
#define MSG_TITLE_BASILISK_SETTINGS_STR "Basilisk II Settings"
#define MSG_TITLE_ADD_VOLUME_STR "Add Volume"
#define MSG_TITLE_EDIT_VOLUME_STR "Edit Volume"
#define MSG_PAGE_VOLUMES_STR "Volumes"
#define MSG_PAGE_SCSI_STR "SCSI"
#define MSG_PAGE_COMMUNICATION_STR "Communication"
#define MSG_PAGE_EMULATION_STR "Emulation"
#define MSG_MENU_TITLE_BASILISK_STR "Basilisk"
#define MSG_MENU_BASILISK_ABOUT_STR "?\0About..."
#define MSG_MENU_BASILISK_START_STR "S\0Start"
#define MSG_MENU_BASILISK_QUIT_STR "Q\0Quit"
#define MSG_AUTHOR_INFORMATION_STR "\33cBasilisk II 1.0 by Christian Bauer\n� Copyright 1997-2001\nDistribtion under General Public License (GPL)"
#define MSG_PORT_INFORMATION_STR "MorphOS port by Ilkka Lehtoranta, 2005-2007"
#define MSG_GFX_INFORMATION_STR "Basilisk icons by Christian Rosentereter"
#define MSG_DESCRIPTION_STR "68k MacIntosh emulator"

#endif /* CATCOMP_STRINGS */


/****************************************************************************/


#ifdef CATCOMP_ARRAY

struct CatCompArrayType
{
    LONG   cca_ID;
    STRPTR cca_Str;
};

static const struct CatCompArrayType CatCompArray[] =
{
    {MSG_OK_GAD,(STRPTR)MSG_OK_GAD_STR},
    {MSG_CANCEL_GAD,(STRPTR)MSG_CANCEL_GAD_STR},
    {MSG_PREFS_TYPE_GAD,(STRPTR)MSG_PREFS_TYPE_GAD_STR},
    {MSG_PREFS_READ_ONLY_GAD,(STRPTR)MSG_PREFS_READ_ONLY_GAD_STR},
    {MSG_PREFS_FILE_GAD,(STRPTR)MSG_PREFS_FILE_GAD_STR},
    {MSG_PREFS_DEVICE_GAD,(STRPTR)MSG_PREFS_DEVICE_GAD_STR},
    {MSG_PREFS_CREATE_GAD,(STRPTR)MSG_PREFS_CREATE_GAD_STR},
    {MSG_PREFS_UNIT_GAD,(STRPTR)MSG_PREFS_UNIT_GAD_STR},
    {MSG_PREFS_FLAGS_GAD,(STRPTR)MSG_PREFS_FLAGS_GAD_STR},
    {MSG_PREFS_START_BLOCK_GAD,(STRPTR)MSG_PREFS_START_BLOCK_GAD_STR},
    {MSG_PREFS_BLOCKS_GAD,(STRPTR)MSG_PREFS_BLOCKS_GAD_STR},
    {MSG_PREFS_BLOCK_SIZE_GAD,(STRPTR)MSG_PREFS_BLOCK_SIZE_GAD_STR},
    {MSG_PREFS_RAMSIZE_GAD,(STRPTR)MSG_PREFS_RAMSIZE_GAD_STR},
    {MSG_PREFS_ADD_GAD,(STRPTR)MSG_PREFS_ADD_GAD_STR},
    {MSG_PREFS_EDIT_GAD,(STRPTR)MSG_PREFS_EDIT_GAD_STR},
    {MSG_PREFS_REMOVE_GAD,(STRPTR)MSG_PREFS_REMOVE_GAD_STR},
    {MSG_PREFS_CD_DEVICE_GAD,(STRPTR)MSG_PREFS_CD_DEVICE_GAD_STR},
    {MSG_PREFS_CD_UNIT_GAD,(STRPTR)MSG_PREFS_CD_UNIT_GAD_STR},
    {MSG_PREFS_CD_BOOT_GAD,(STRPTR)MSG_PREFS_CD_BOOT_GAD_STR},
    {MSG_PREFS_CD_DISABLE_DRIVER_GAD,(STRPTR)MSG_PREFS_CD_DISABLE_DRIVER_GAD_STR},
    {MSG_PREFS_MORPHOS_ROOT_GAD,(STRPTR)MSG_PREFS_MORPHOS_ROOT_GAD_STR},
    {MSG_PREFS_VOLUMETYPE_FILE_GAD,(STRPTR)MSG_PREFS_VOLUMETYPE_FILE_GAD_STR},
    {MSG_PREFS_VOLUMETYPE_DEVICE_GAD,(STRPTR)MSG_PREFS_VOLUMETYPE_DEVICE_GAD_STR},
    {MSG_PREFS_ID_0_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_0_DEVICE_GAD_STR},
    {MSG_PREFS_ID_1_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_1_DEVICE_GAD_STR},
    {MSG_PREFS_ID_2_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_2_DEVICE_GAD_STR},
    {MSG_PREFS_ID_3_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_3_DEVICE_GAD_STR},
    {MSG_PREFS_ID_4_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_4_DEVICE_GAD_STR},
    {MSG_PREFS_ID_5_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_5_DEVICE_GAD_STR},
    {MSG_PREFS_ID_6_DEVICE_GAD,(STRPTR)MSG_PREFS_ID_6_DEVICE_GAD_STR},
    {MSG_PREFS_SCSI_UNIT_GAD,(STRPTR)MSG_PREFS_SCSI_UNIT_GAD_STR},
    {MSG_PREFS_MODEM_DEVICE_GAD,(STRPTR)MSG_PREFS_MODEM_DEVICE_GAD_STR},
    {MSG_PREFS_MODEM_UNIT_GAD,(STRPTR)MSG_PREFS_MODEM_UNIT_GAD_STR},
    {MSG_PREFS_MODEM_PARALLEL_GAD,(STRPTR)MSG_PREFS_MODEM_PARALLEL_GAD_STR},
    {MSG_PREFS_ETHERNET_DEVICE_GAD,(STRPTR)MSG_PREFS_ETHERNET_DEVICE_GAD_STR},
    {MSG_PREFS_ETHERNET_UNIT_GAD,(STRPTR)MSG_PREFS_ETHERNET_UNIT_GAD_STR},
    {MSG_PREFS_PRINTER_DEVICE_GAD,(STRPTR)MSG_PREFS_PRINTER_DEVICE_GAD_STR},
    {MSG_PREFS_PRINTER_UNIT_GAD,(STRPTR)MSG_PREFS_PRINTER_UNIT_GAD_STR},
    {MSG_PREFS_PRINTER_PARALLEL_GAD,(STRPTR)MSG_PREFS_PRINTER_PARALLEL_GAD_STR},
    {MSG_PREFS_GFX_WIDTH_GAD,(STRPTR)MSG_PREFS_GFX_WIDTH_GAD_STR},
    {MSG_PREFS_GFX_HEIGHT_GAD,(STRPTR)MSG_PREFS_GFX_HEIGHT_GAD_STR},
    {MSG_PREFS_GFX_FULLSCREEN_GAD,(STRPTR)MSG_PREFS_GFX_FULLSCREEN_GAD_STR},
    {MSG_PREFS_GFX_8BIT_GAD,(STRPTR)MSG_PREFS_GFX_8BIT_GAD_STR},
    {MSG_PREFS_GFX_FRAMESKIP_GAD,(STRPTR)MSG_PREFS_GFX_FRAMESKIP_GAD_STR},
    {MSG_PREFS_DISABLE_SOUND,(STRPTR)MSG_PREFS_DISABLE_SOUND_STR},
    {MSG_PREFS_SYSTEM_RAM_GAD,(STRPTR)MSG_PREFS_SYSTEM_RAM_GAD_STR},
    {MSG_PREFS_SYSTEM_MODEL_GAD,(STRPTR)MSG_PREFS_SYSTEM_MODEL_GAD_STR},
    {MSG_PREFS_SYSTEM_ROM_GAD,(STRPTR)MSG_PREFS_SYSTEM_ROM_GAD_STR},
    {MSG_PREFS_START_GAD,(STRPTR)MSG_PREFS_START_GAD_STR},
    {MSG_PREFS_QUIT_GAD,(STRPTR)MSG_PREFS_QUIT_GAD_STR},
    {MSG_MAC_VOLUMES,(STRPTR)MSG_MAC_VOLUMES_STR},
    {MSG_CDROM,(STRPTR)MSG_CDROM_STR},
    {MSG_VIRTUAL_SCSI_DEVICES,(STRPTR)MSG_VIRTUAL_SCSI_DEVICES_STR},
    {MSG_MODEM,(STRPTR)MSG_MODEM_STR},
    {MSG_ETHERNET,(STRPTR)MSG_ETHERNET_STR},
    {MSG_PRINTER,(STRPTR)MSG_PRINTER_STR},
    {MSG_GRAPHICS,(STRPTR)MSG_GRAPHICS_STR},
    {MSG_SOUND,(STRPTR)MSG_SOUND_STR},
    {MSG_SYSTEM,(STRPTR)MSG_SYSTEM_STR},
    {MSG_SIZE,(STRPTR)MSG_SIZE_STR},
    {MSG_MB,(STRPTR)MSG_MB_STR},
    {MSG_TITLE_BASILISK_SETTINGS,(STRPTR)MSG_TITLE_BASILISK_SETTINGS_STR},
    {MSG_TITLE_ADD_VOLUME,(STRPTR)MSG_TITLE_ADD_VOLUME_STR},
    {MSG_TITLE_EDIT_VOLUME,(STRPTR)MSG_TITLE_EDIT_VOLUME_STR},
    {MSG_PAGE_VOLUMES,(STRPTR)MSG_PAGE_VOLUMES_STR},
    {MSG_PAGE_SCSI,(STRPTR)MSG_PAGE_SCSI_STR},
    {MSG_PAGE_COMMUNICATION,(STRPTR)MSG_PAGE_COMMUNICATION_STR},
    {MSG_PAGE_EMULATION,(STRPTR)MSG_PAGE_EMULATION_STR},
    {MSG_MENU_TITLE_BASILISK,(STRPTR)MSG_MENU_TITLE_BASILISK_STR},
    {MSG_MENU_BASILISK_ABOUT,(STRPTR)MSG_MENU_BASILISK_ABOUT_STR},
    {MSG_MENU_BASILISK_START,(STRPTR)MSG_MENU_BASILISK_START_STR},
    {MSG_MENU_BASILISK_QUIT,(STRPTR)MSG_MENU_BASILISK_QUIT_STR},
    {MSG_AUTHOR_INFORMATION,(STRPTR)MSG_AUTHOR_INFORMATION_STR},
    {MSG_PORT_INFORMATION,(STRPTR)MSG_PORT_INFORMATION_STR},
    {MSG_GFX_INFORMATION,(STRPTR)MSG_GFX_INFORMATION_STR},
    {MSG_DESCRIPTION,(STRPTR)MSG_DESCRIPTION_STR},
};

#endif /* CATCOMP_ARRAY */


/****************************************************************************/


struct LocaleInfo
{
    APTR li_LocaleBase;
    APTR li_Catalog;
};



#endif /* LOCALE_H */
