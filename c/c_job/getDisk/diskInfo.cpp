/*
 *  CDiskInfo.cpp
 *
 *  Created on: 2014-3-12
 *  Author: qinyinghao
 */

#include "diskInfo.h"
extern "C" {
#include <sys/vfs.h>
}
#include <string>
namespace qyh {

    CDiskInfo::CDiskInfo(const std::string& _path) :
        disk_total_capacity(0), disk_used_capacity(0), disk_free_capacity(0), disk_format(
                DISK_FORMAT_UNKNOW), path(_path) {
            struct statfs buf;
            int i = statfs(path.c_str(), &buf);
            if (i < 0) {
                //printf("get disk infomation faild\n");
            } else {
                switch (buf.f_type) {
                    case 0x4d44:
                        disk_format = DISK_FORMAT_FAT;
                        break;
                    case 0x5346544e:
                    case 0X65735546:
                        disk_format = DISK_FORMAT_NTFS;
                        break;
                    case 0xEF53:
                    case 0xEF51:
                        disk_format = DISK_FORMAT_EXT2;
                        break;
                    default:
                        disk_format = DISK_FORMAT_UNKNOW;
                        break;
                }
                disk_total_capacity = (((long long) buf.f_bsize
                            * (long long) buf.f_blocks) / (long long) 1024);
                disk_free_capacity =
                    (((long long) buf.f_bsize * (long long) buf.f_bfree)
                     / (long long) 1024);
                disk_used_capacity = disk_total_capacity - disk_free_capacity;
            }
        }

    CDiskInfo::~CDiskInfo() {
    }

    void CDiskInfo::refreshInfo() {
        struct statfs buf;
        int i = statfs(path.c_str(), &buf);
        if (i < 0) {
            //printf("refresh get disk infomation faild\n");
            return;
        }
        switch (buf.f_type) {
            case 0x4d44:
                disk_format = DISK_FORMAT_FAT;
                break;
            case 0x5346544e:
            case 0X65735546:
                disk_format = DISK_FORMAT_NTFS;
                break;
            case 0xEF53:
            case 0xEF51:
                disk_format = DISK_FORMAT_EXT2;
                break;
            default:
                disk_format = DISK_FORMAT_UNKNOW;
                break;
        }
        disk_total_capacity = (((long long) buf.f_bsize * (long long) buf.f_blocks)
                / (long long) 1024);
        disk_free_capacity = (((long long) buf.f_bsize * (long long) buf.f_bfree)
                / (long long) 1024);
        disk_used_capacity = disk_total_capacity - disk_free_capacity;
    }
    long int CDiskInfo::getTotalSize() {
        return disk_total_capacity;
    }
    long int CDiskInfo::getUsedSize() {
        return disk_used_capacity;
    }
    long int CDiskInfo::getLeftSize() {
        return disk_free_capacity;
    }
    DISK_FORMAT CDiskInfo::getDiskFormat() {
        return disk_format;
    }
} /* namespace qyh */
