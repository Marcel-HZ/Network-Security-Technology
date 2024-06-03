#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include "des_constants.h"
#include "des.h"

#define PORT 9977
#define MSG_SIZE 4096
#define MAX_LINE 20

int server();

#endif // SERVER_H