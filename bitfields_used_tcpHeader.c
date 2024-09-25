#include<stdio.h>
typedef struct tcp{
    unsigned int sport:16;
    unsigned int dport:16;
    unsigned int seqno:32;
    unsigned int ackno:32;
    unsigned int reserve:4;
    unsigned int dataoffset:4;
    unsigned int flags:8;
}tcp_header_t;
int main(){
    tcp_header_t tcp_header = {0};
    tcp_header.sport=8080;
    tcp_header.dport=80;
    tcp_header.flags=0x12;
    printf("sport %u",tcp_header.sport);
    printf("sport %u",tcp_header.dport);
    printf("sport %u",tcp_header.flags);
    printf("tcp_header size in bytes %zu",sizeof(tcp_header));
    return 0;
}