#define SUCCESS 0

#define DES_ERR_BIT         1020
#define INIT_REPLACE_IP     1021 // 初始置换IP
#define INVERSE_REPLACE_IP  1022 // 逆初始置换IP
#define DES_ENCRY_ERR       1023 // 加密失败
#define DES_DECRY_ERR       1024 // 解密失败

#define int64                   unsigned long long int

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
