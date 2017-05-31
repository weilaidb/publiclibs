#ifndef WINS_H
#define WINS_H


#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <windows.h>
#include <winsock2.h>
#include <mswsock.h>
#include <process.h>
#include <ws2tcpip.h>

/* This structure does not exist on Windows platform. Let's fake it. */
struct sockaddr_un {
    short sun_family;
    char sun_path [sizeof (struct sockaddr_storage) -
        sizeof (short)];
};

#define ssize_t int

#endif // WINS_H
