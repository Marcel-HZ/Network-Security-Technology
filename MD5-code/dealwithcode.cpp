#include "MD5.h" // Include the header file for the ModifiedMD5 class

// 将64字节（64*8 bit）的数据块划分为16个32位大小的子分组，input.size()=64
vector<uint32_t> ModifiedMD5::DivideBlock(const vector<uint8_t> input) {
    // 将 input 的4个8bit数字合并成一个 output 的32bit数字，但是要反过来，ABCD->DCBA
    vector<uint32_t> output;
    for (int i = 0; i < input.size() / 4; ++i) {
        uint32_t temp = 0;
        for (int j = 3; j >= 0; --j) {
            temp += input[i * 4 + j];
            if (j != 0) {
                temp = temp << 8;
            }
        }
        output.push_back(temp);
    }
    return output;
}

// 将32位十进制数转换成16进制字符串，使用8个字母表示
string ModifiedMD5::DecimalToHex(uint32_t decimal) {
    string hex;
    uint32_t help = 4026531840;
    unordered_map<int, string> map10To16 = { {0, "0"},  {1, "1"},  {2, "2"},  {3, "3"},
                                             {4, "4"},  {5, "5"},  {6, "6"},  {7, "7"},
                                             {8, "8"},  {9, "9"},  {10, "a"}, {11, "b"},
                                             {12, "c"}, {13, "d"}, {14, "e"}, {15, "f"} };
    for (int i = 0; i < 8; ++i) {
        int tempResult = (decimal & help) >> 28;
        hex += map10To16[tempResult];
        decimal = decimal << 4;
    }
    return hex;
}

// 将一个64位整数转换成 vector<uint8_t>
vector<uint8_t> ModifiedMD5::Int64ToInt8Vec(uint64_t num) {
    vector<uint8_t> result(8);
    uint8_t help = 255;
    for (int i = 0; i < 8; ++i) {
        result[i] = num & help;
        num = num >> 8;
    }
    return result;
}