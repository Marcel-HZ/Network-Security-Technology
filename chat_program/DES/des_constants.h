#define SUCCESS 0

#define SERVER_SOCKET_ERR   1000
#define SERVER_BIND_ERR     1001
#define SERVER_LISTEN_ERR   1002
#define SERVER_ACCEPT_ERR   1003 
#define SERVER_RECV_ERR     1004
#define SERVER_SEND_ERR     1005

#define CLIENT_INETPTON_ERR 1010
#define CLIENT_SOCKET_ERR   1011
#define CLIENT_CONNECT_ERR  1012
#define CLIENT_SEND_ERR     1013
#define CLIENT_RECV_ERR     1014

#define DES_KEY             "BLACKHAT"
#define DES_ERR_BIT         1020
#define INIT_REPLACE_IP     1021 // 初始置换IP
#define INVERSE_REPLACE_IP  1022 // 逆初始置换IP
#define DES_ENCRY_ERR       1023 // 加密失败
#define DES_DECRY_ERR       1024 // 解密失败


#ifndef DES_CONSTANTS_H
#define DES_CONSTANTS_H

extern const int pc_first[64];
extern const int pc_last[64];
extern unsigned const int pc_by_bit[64];
extern const int des_P[32];
extern const int des_E[48];
extern const int des_S[8][64];
extern const int keyLeft[28];
extern const int keyRight[28];
extern const int leftTable[16];
extern const int keyChoose[48];

#endif // DES_CONSTANTS_H
