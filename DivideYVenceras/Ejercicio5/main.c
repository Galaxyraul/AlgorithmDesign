#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/if_link.h>
int main() {
    struct ifaddrs *ifaddr, *ifa;
    char host[NI_MAXHOST];
    char *addr;
    struct sockaddr_in *socket;
    unsigned char *mac_address;
    int family, s;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        family = ifa->ifa_addr->sa_family;

        //Vemos si es IPv4
        if (family == AF_INET) {
            printf("%s\n", ifa->ifa_name); //Nombre de la interfaz
            addr = inet_ntoa(((struct sockaddr_in*)ifa->ifa_addr)->sin_addr); //Direccion IP convertida a caracter legible
            printf("\tDireccion IPv4:   %s\n", addr);
            socket = (struct sockaddr_in *) ifa->ifa_netmask;//Mascara de red
            printf("\tMascara de red:   %s\n", inet_ntoa(socket->sin_addr));
            mac_address = (unsigned char *) ifa->ifa_addr->sa_data; //Direccion MAC
            printf("\tDirección MAC:   %02X:%02X:%02X:%02X:%02X:%02X\n", mac_address[0], mac_address[1], mac_address[2], mac_address[3], mac_address[4], mac_address[5]);
        }

        //Vemos si es IPv6
        if (family == AF_INET6) {
            char addr6[INET6_ADDRSTRLEN];
            inet_ntop(ifa->ifa_addr->sa_family, &(((struct sockaddr_in6*)ifa->ifa_addr)->sin6_addr), addr6, INET6_ADDRSTRLEN);
            printf("%s\n", ifa->ifa_name); //Nombre de la interfaz
            printf("\tDireccion IPv6: %-8s\n", addr6);
            char netmask6[INET6_ADDRSTRLEN];
            inet_ntop(ifa->ifa_addr->sa_family, &(((struct sockaddr_in6*)ifa->ifa_netmask)->sin6_addr), netmask6, INET6_ADDRSTRLEN);
            printf("\tMáscara de red: %-8s\n", netmask6);

        }
        if (family == AF_PACKET && ifa->ifa_data != NULL) {
            struct rtnl_link_stats *stats = static_cast<struct rtnl_link_stats *>(ifa->ifa_data);
            printf("%s\n", ifa->ifa_name);
            printf("\ttx_packets = %10u; rx_packets = %10u\n"
                   "\ttx_bytes   = %10u; rx_bytes   = %10u\n",
                   stats->tx_packets, stats->rx_packets,
                   stats->tx_bytes, stats->rx_bytes);
        }


    }

    freeifaddrs(ifaddr);
    return 0;

}