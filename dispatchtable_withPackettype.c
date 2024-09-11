#include<stdio.h>
typedef enum{
    PKT_TCP,
    PKT_UDP,
    PKT_ICMP,
    PKT_UNKNOWN
}pkt_type;
typedef struct pack{
    int type;
    char data[100];
}pkt;
void packet_handler_tcp(pkt *p){
    printf("handling tcp packet data %s\n",p->data);
}
void packet_handler_udp(pkt *p){
    printf("handling udp packet  data %s\n",p->data);
}
void packet_handler_icmp(pkt *p){
    printf("handling icmp packet data %s\n",p->data);
}
void packet_handler_unknown(pkt *p){
    printf("handling unknown packet data %s\n",p->data);
}
void (*packet_handler[])(pkt *p)={
    packet_handler_tcp,
    packet_handler_udp,
    packet_handler_icmp,
    packet_handler_unknown
};
void packet_processor(pkt *p){
    if(p->type >= 0 && p->type < PKT_UNKNOWN){
        (packet_handler[p->type])(p);
    }else{
        (packet_handler[p->type])(p);
    }
}
int main(){
    pkt p[] = {
        {PKT_TCP,"tcp packet"},
        {PKT_UDP,"udp packet"},
        {PKT_ICMP,"icmp packet"},
        {PKT_UNKNOWN,"unknown packet"}
    };
    for(int i=0;i<=PKT_UNKNOWN;i++)
        packet_processor(&p[i]);
    return 0;
}