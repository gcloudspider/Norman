/**
 * OpenHms - version 1.0
 * --------------------------------------------------------
 * Copyright (C) 2016-2016, by Norman (none_lih@163.com)
 * Report bugs and download new versions at https://github.com/evely211/OpenHms/
 *
 * This library is distributed under the MIT License. See notice at the end
 * of this file.
 *
 * This work is based on the , which is:
 * Copyright (C) 2016, by Norman
 */

#ifndef _OPENHMS_H
#define _OPENHMS_H
#inlude "libnv_event/nv_application.h"

class HServer:public nv_event::nv_application{
public:
    HServer();
    virtual ~HServer();
};

DECLARE_APPLICATION_INSTANCE(HServer);
#endif
