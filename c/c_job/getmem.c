#include<stdio.h>
#include <sys/sysinfo.h>

SysCPUInfo* _GetHostCPUInfo(){
    SysCPUInfo *cpuinfo = (SysCPUInfo *)malloc(sizeof(SysCPUInfo));
    if (cpuinfo == NULL)
        err_dump("_GetCPUInfo: malloc struct SysCPUInfo error");

    FILE    *fd;
    char    buff[256];
    memset(buff, '\0', 256);

    fd = fopen("/proc/stat", "r");
    fgets(buff, sizeof(buff), fd);

    sscanf(buff, "%s %lu %lu %lu %lu", cpuinfo->name, &cpuinfo->user, &cpuinfo->nic, 
            &cpuinfo->system, &cpuinfo->idle);
    fclose(fd);
    return cpuinfo;
}

float _CalculateHostCPURate(SysCPUInfo *first, SysCPUInfo *second){
    unsigned long   old_CPU_Time, new_CPU_Time;
    unsigned long   usr_Time_Diff, sys_Time_Diff, nic_Time_Diff;
    float           cpu_use = 0.0;

    old_CPU_Time = (unsigned long)(first->user + first->nic + first->system + first->idle);
    new_CPU_Time = (unsigned long)(second->user + second->nic + second->system + second->idle);

    usr_Time_Diff = (unsigned long)(second->user - first->user);
    sys_Time_Diff = (unsigned long)(second->system - first->system);
    nic_Time_Diff = (unsigned long)(second->nic -first->nic);

    if ((new_CPU_Time - old_CPU_Time) != 0)
        cpu_use = (float)100*(usr_Time_Diff + sys_Time_Diff + nic_Time_Diff)/(new_CPU_Time - old_CPU_Time);
    else
        cpu_use = 0.0;
    return cpu_use;
}

float GetHostCPURate(){
    float cpu_rate;
    SysCPUInfo *first, *second;
    first = _GetHostCPUInfo();
    sleep(10);
    second = _GetHostCPUInfo();

    cpu_rate = _CalculateHostCPURate(first, second);

    /* clean auxiliary memory */
    free(first);
    free(second);
    first = second = NULL;

    return cpu_rate;
}


SysMemInfo * GetHostMemInfo() {
    SysMemInfo *memInfo = (SysMemInfo *)malloc(sizeof(SysMemInfo));
    if (NULL == memInfo)
        err_dump("GetMemInfo: malloc SysMemInfo Struct error");

    struct sysinfo tmp;
    int ret = 0;
    ret = sysinfo(&tmp);
    if (ret == 0) {
        memInfo->MemFree = (unsigned long)tmp.freeram/(1024*1024);
        memInfo->MemTotal = (unsigned long)tmp.totalram/(1024*1024);
    } else {
        err_dump("GetMemInfo: sysinfo() error");
    }
    return memInfo;
}


SysDiskInfo * GetHostDiskInfo(){
    SysDiskInfo *sys_disk_info = (SysDiskInfo *)malloc(sizeof(SysDiskInfo));
    DiskInfo        *disk_info;
    struct statfs   fs_info;
    struct mntent   *mnt_info;
    FILE            *fh;
    float           percent;
    unsigned long   sum_Total = 0, total_free = 0;

    if ((fh = setmntent("/etc/mtab", "r")) == NULL) {
        printf("Cannot open /etc/mtab file!:%s\n",strerror(errno));
        return NULL;
    }

    while ((mnt_info = getmntent(fh)) != NULL) {
        if (statfs(mnt_info->mnt_dir, &fs_info) < 0) {
            continue;
        }

        if ((disk_info = (DiskInfo *)malloc(sizeof(DiskInfo))) == NULL) {
            continue;
        }

        if (strcmp(mnt_info->mnt_type, "proc") &&
                strcmp(mnt_info->mnt_type, "devfs") &&
                strcmp(mnt_info->mnt_type, "usbfs") &&
                strcmp(mnt_info->mnt_type, "sysfs") &&
                strcmp(mnt_info->mnt_type, "tmpfs") &&
                strcmp(mnt_info->mnt_type, "devpts") &&
                strcmp(mnt_info->mnt_type, "fusectl") &&
                strcmp(mnt_info->mnt_type, "debugfs") &&
                strcmp(mnt_info->mnt_type, "binfmt_misc") &&
                strcmp(mnt_info->mnt_type, "fuse.gvfs_fuse_daemon")&&
                strcmp(mnt_info->mnt_type, "securityfs")) {
            if (fs_info.f_blocks != 0) {
                percent = ((float)fs_info.f_blocks - (float)fs_info.f_bfree * 100.0/
                        (float)fs_info.f_blocks);
            } else {
                percent = 0;
            }
        } else {
            continue;
        }

        strcpy(disk_info->type, mnt_info->mnt_type);
        strcpy(disk_info->device, mnt_info->mnt_fsname);
        strcpy(disk_info->mntpnt, mnt_info->mnt_dir);

        unsigned long block_size = fs_info.f_bsize/1024;
        disk_info->blocks = fs_info.f_blocks * block_size / 1024;
        disk_info->bfree = fs_info.f_bfree * block_size / 1024;
        disk_info->availiable_disk = fs_info.f_bavail * block_size / 1024;
        disk_info->bused = (fs_info.f_blocks - fs_info.f_bfree) * block_size / 1024;
        disk_info->bused_percent = percent;

        sum_Total += disk_info->blocks;
        total_free += disk_info->availiable_disk;

        /* clean auxiliary memory */
        free(disk_info);
        disk_info = NULL;
    }
    sys_disk_info->Disk_Total = sum_Total/1024;
    sys_disk_info->Disk_Free = total_free/1024;
    return sys_disk_info;
}

int main(){
	struct sysinfo si;
	sysinfo(&si);
	printf("Load1:		%ld\n",si.loads[0]);
	printf("Load5:		%ld\n",si.loads[1]);
	printf("Load10:		%ld\n",si.loads[2]);
	printf("Totalram:	%ld\n",si.totalram);
	printf("Available:	%ld\n",si.freeram);
	printf("Bufferram:	%ld\n",si.bufferram);
	printf("Totalswap:	%ld\n",si.freeswap);
	printf("Totalhigh:	%ld\n",si.totalhigh);
	printf("Freehigh:	%ld\n",si.freehigh);
	
}
