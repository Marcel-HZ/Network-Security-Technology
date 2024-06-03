#include "helpFunc.h"

#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))              //F函数
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))              //G函数
#define H(x, y, z) ((x) ^ (y) ^ (z))                         //H函数
#define I(x, y, z) ((y) ^ ((x) | (~z)))                      //I函数
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n)))) //32位数字x的循环左移n位操作

#define FF(a, b, c, d, x, s, ac) { (a) += F ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }
#define GG(a, b, c, d, x, s, ac) { (a) += G ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }
#define HH(a, b, c, d, x, s, ac) { (a) += H ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }
#define II(a, b, c, d, x, s, ac) { (a) += I ((b), (c), (d)) + (x) + ac; (a) = ROTATE_LEFT ((a), (s)); (a) += (b); }

#define T(i) 4294967296 * abs(sin(i))

class ModifiedMD5 {
public:
    void Update(const string &str);
    void Update(ifstream &in);
    string ToString();

private:
    void Reset();
    void Update(vector<uint8_t> input);
    void Transform(const vector<uint8_t> block);
    vector<uint32_t> DivideBlock(const vector<uint8_t>input);
    string DecimalToHex(uint32_t decimal);
    vector<uint8_t> Int64ToInt8Vec(uint64_t num);

private:
    uint32_t state[4];
};