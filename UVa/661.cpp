//From https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=121&page=show_problem&problem=602
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define OFF 0
#define ON 1

int main() {
	int sequence_count = 0;
    int device_count, operation_count, fuse_capacity;
    while(scanf("%d %d %d\n", &device_count, &operation_count, &fuse_capacity) == 3) {
	    sequence_count++;
	    int max_power_consumption = 0;
	    // End condition
	    if(device_count == 0)
	    	break;
	    int devices_consumptions[device_count];
	    int devices_status[device_count];
	    int fuse_has_blown = false;
	    for(int i = 0; i < device_count; i++) {
	    	scanf("%d", &devices_consumptions[i]);
	    	devices_status[i] = OFF;
	    }
	    int actual_current = 0;
	    for(int i = 0; i < operation_count; i++) {
	    	int device_id;
	    	scanf("%d", &device_id);
	    	// Vector correction
	    	device_id--;
	    	if(devices_status[device_id] == OFF) {
	    		devices_status[device_id] = ON;
	    		actual_current += devices_consumptions[device_id];
	    	}
	    	else {
	    		devices_status[device_id] = OFF;
	    		actual_current -= devices_consumptions[device_id];
	    	}
	    	if(actual_current > fuse_capacity)
	    		fuse_has_blown = true;
	    	if(actual_current > max_power_consumption)
	    		max_power_consumption = actual_current;
	    }
	    printf("Sequence %d\n", sequence_count);
	    if(fuse_has_blown)
	    	printf("Fuse was blown.\n\n");
	    else{
	    	printf("Fuse was not blown.\n");
	    	printf("Maximal power consumption was %d amperes.\n\n", max_power_consumption);
	    }
	}
    return 0;
}


