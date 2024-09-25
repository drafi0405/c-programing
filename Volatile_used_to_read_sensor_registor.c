#include<stdio.h>
#define SENSOR_REGISTER (*(volatile unsigned int *)0x4000300)
unsigned int sensor_read_value(){
    return SENSOR_REGISTER;
}
void process_sensor_value(unsigned int value){
    printf(" sensor value %u\n", value);
}
int main(){
    unsigned int value = sensor_read_value();
    process_sensor_value(value);
    return 0;
}