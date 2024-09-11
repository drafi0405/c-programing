//Use of function pointer --- Event Table dispatch like event driven programing, call back functions, 
#include<stdio.h>
typedef enum{
    KEY_PRESS,
    MOUSE_PRESS,
    SYSTEM_ALERT,
    NON_OF_ABOVE
}EventType;
typedef void (*event_handler)(void);
event_handler eventHandler[NON_OF_ABOVE];
void key_function(void){
    printf("key function execution\n");
}
void mouse_function(void){
    printf("mouse function execution\n");
}
void alert_function(void){
    printf("alert function execution\n");
}
void trigger_event(EventType event){
    if(event >=0 && event < NON_OF_ABOVE){
        eventHandler[event]();
    }else{
        printf("unknown event\n");
    }
}
void init_event(void){
    eventHandler[KEY_PRESS]=key_function;
    eventHandler[MOUSE_PRESS]=mouse_function;
    eventHandler[SYSTEM_ALERT]=alert_function;
}
int main(){
    init_event();
    trigger_event(KEY_PRESS);
    trigger_event(MOUSE_PRESS);
    trigger_event(SYSTEM_ALERT);
    return 0;
}