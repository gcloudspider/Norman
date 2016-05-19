#include "getspeed.h"
#include <ifaddrs.h> 
#include <arpa/inet.h> 
int get_if_dbytes(struct if_info* ndev){
	assert(ndev);
	struct ifaddrs *ifa_list = NULL;
	struct ifaddrs *ifa = NULL;
	struct if_data *ifd = NULL;
	int ret = 0;
	ret = getifaddrs(&ifa_list);
	if(ret < 0) {
		perror("Get Interface Address Fail:");
		goto end;
	} 

	for(ifa=ifa_list; ifa; ifa=ifa->ifa_next){
		if(!(ifa->ifa_flags & IFF_UP) && !(ifa->ifa_flags & IFF_RUNNING))
			continue;

		if(ifa->ifa_data == 0)
			continue;

		ret = strcmp(ifa->ifa_name,ndev->ifi_name);

		if(ret == 0){
			ifd = (struct if_data *)ifa->ifa_data;
			ndev->ifi_ibytes = ifd->ifi_ibytes;
			ndev->ifi_obytes = ifd->ifi_obytes;
			break;
		}
	}
	freeifaddrs(ifa_list);
end:
	return (ret ? -1 : 0);
}

int get_if_speed(struct if_speed* ndev){
	assert(ndev);
	struct if_info *p1=NULL,*p2=NULL;
	p1 = (struct if_info *)malloc(sizeof(struct if_info));
	p2 = (struct if_info *)malloc(sizeof(struct if_info));
	bzero(p1,sizeof(struct if_info));
	bzero(p2,sizeof(struct if_info));
	strncpy(p1->ifi_name,ndev->ifs_name,strlen(ndev->ifs_name));strncpy(p2->ifi_name,ndev->ifs_name,strlen(ndev->ifs_name));
	int ret = 0;
	ret = get_if_dbytes(p1);
	if(ret < 0)    goto end;
	usleep(ndev->ifs_us);
	ret = get_if_dbytes(p2);
	if(ret < 0)    goto end;
	ndev->ifs_ispeed = p2->ifi_ibytes - p1->ifi_ibytes;ndev->ifs_ospeed = p2->ifi_obytes - p1->ifi_obytes;
end:
	free(p1);
	free(p2);
}

int main(int argc, char **argv) {
	struct if_speed ndev;
	int ret = 0;
	bzero(&ndev,sizeof(ndev));
	sprintf(ndev.ifs_name,"eth0");
	ndev.ifs_us = 100000;
	printf("Get %s Speed",ndev.ifs_name);
	ret = get_if_speed(&ndev);
	if(ret < 0)
		printf("\t\t\t[Fail]\n");
	else
		printf("\t\t\t[OK]\n");
		float ispeed ,ospeed;
		while(1){
			printf("%f%f\n",ispeed,ospeed);
			ispeed = ndev.ifs_ispeed * 1.0/(ndev.ifs_us/1000 * 0.001);
			ospeed = ndev.ifs_ospeed * 1.0/(ndev.ifs_us/1000 * 0.001);
			printf("%s: Up Speed: %f MB/s || Down Speed: %f MB/s                  \r",ndev.ifs_name,ispeed/(1024.0*1024.0),ospeed/(1024.0*1024.0));
			get_if_speed(&ndev);
		}
	return 0;
}
