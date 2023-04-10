#include <iostream>

struct paquete_ping {
    struct iphdr cabeceraIP;
    struct icmphdr cabeceraICMP;
    char payload[32];
};

struct paquete_ping monta_paquete(
        char * origen, char * destino, unsigned short n) {
    struct paquete_ping ping = {
            .cabeceraIP {
                    .ihl = 5,
                    .version = 4,
                    .tot_len = htons(sizeof(struct iphdr) +
                                     sizeof(struct icmphdr) + 32),
                    .id = (unsigned short) rand(),
                    .frag_off = 0,
                    .ttl = 24,
                    .protocol = IPPROTO_ICMP,
                    .saddr = inet_addr(origen),
                    .daddr = inet_addr(destino)
            },
            .cabeceraICMP {
                    .type = ICMP_ECHO,
                    .code = 0,
                    .checksum = 0,
                    .un {
                            .echo {
                                    .id = htons((unsigned short) getpid()),
                                    .sequence = htons(n)
                            }
                    }
            },
    };
    strcpy(ping.payload, "123-ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    ping.cabeceraICMP.checksum = suma_comprobacion(
            (unsigned short *)&ping.cabeceraICMP,
            sizeof ping.cabeceraICMP + 32);
    return ping;
}
uint16_t suma_comprobacion(uint16_t * palabras, uint16_t bytes) {
    uint32_t suma = 0;
    while(bytes > 1) {
        suma += *palabras++;
        bytes -= 2;
    }
    if(bytes == 1) suma += *(uint8_t *) palabras;
    suma = (suma >> 16) + (suma & 0xFFFF);
    return ~(suma + (suma >> 16));
}

struct paquete_ping monta_paquete(char *, char *, unsigned short);

void muestraICMP(char* datos){
    iphdr* cabeceraIP = (iphdr*)(datos);
    icmphdr* cabeceraICMP = (icmphdr*)(datos);
    cout << inet_ntoa(cabeceraIP->source) << inet_ntoa(cabeceraIP->dest) << ntohs(cabecera->sequence) <<
}
int main(int argc, char *argv[]) {
    int misocketenv;
    int misocket2;
    unsigned numseq = 1;
    if(argc < 3) throw runtime_error("Facilitar IP de origen y de destino");
    struct sockaddr_in destino = {};
    destino.sin_family = AF_INET;
    destino.sin_addr.s_addr = inet_addr(argv[2]);
    if(misocketenv=socket(AF_INET, SOCK_RAW, IPPROTO_RAW); misocketenv==-1) {
        throw runtime_error(strerror(errno));
    }
    if(misocket2=socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); misocket2 == -1) {
        throw runtime_error(strerror(errno));
    }
    while(auto i = 0 < 5 ){
        struct paquete_ping ping = monta_paquete(argv[1], argv[2], numseq++);
        if(sendto(misocketenv, &ping, sizeof(struct paquete_ping), 0,
                  (struct sockaddr *)&destino, sizeof(destino)) < 1) {
            throw runtime_error(strerror(errno));
        }
        if(sendto(misocket2, &ping, sizeof(struct paquete_ping),13,
                  (struct sockaddr *)&destino, sizeof(destino)) < 1) {
            throw runtime_error(strerror(errno));
        }
        auto bytes = recvfrom(misocket2, paquete, IP_MAXPACKET, 13,
                              (sockaddr *) &origen, &long_origen);

    }
    close(misocketenv);
    return 0;
}

