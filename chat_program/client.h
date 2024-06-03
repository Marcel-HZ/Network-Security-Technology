#ifndef CLIENT_H
#define CLIENT_H

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
#include "DES/des_constants.h"
#include "MakeData.h"
#include "RSA/rsa_constants.h"
#include "DES/des.h"
#include "RSA/rsa.h"

#define PORT 9977
#define MAX_LINE 20
#define MSG_SIZE 4096
#define DEFAULT_SERVER "127.0.0.1"

int client();

#endif // CLIENT_H
