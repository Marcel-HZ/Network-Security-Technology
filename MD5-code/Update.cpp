#include "MD5.h"

// 对给定长度的字符串进行 MD5 计算
void ModifiedMD5::Update(const string &str) {
    Reset();
    // 将输入字符串转换为标准字节流，然后调用私有函数进行 MD5 计算
    vector<uint8_t> input;
    for (int i = 0; i < str.size(); ++i) {
        input.push_back(str[i]);
    }
    Update(input);
}

// 对文件内容进行 MD5 计算
void ModifiedMD5::Update(ifstream &in) {
    Reset();
    string str((istreambuf_iterator<char>(in)), istreambuf_iterator<char>()); 
    vector<uint8_t> input;
    for (int i = 0; i < str.size(); ++i) {
        input.push_back(str[i]);
    }
    Update(input);
}

// 私有函数：对字节流进行 MD5 计算
// 对长度为 length 的字节流进行预处理，然后调用 Transform 函数对每一个 64 字节（512 位）数据块进行计算
void ModifiedMD5::Update(vector<uint8_t> input) {
    // 消息填充：N * 512 + 448 （N 为正整数）
    vector<uint8_t> trueLen = Int64ToInt8Vec(input.size() * 8); // 真实长度，trueLen.size()=8
    vector<uint8_t> fillHelp(64, (uint8_t)0); // 最多填充 512 位 = 64*8
    fillHelp[0] = (uint8_t)128;
    
    if (input.size() * 8 % 512 == 448) {
        input.insert(input.end(), fillHelp.begin(), fillHelp.end());
    }
    else {
        int index = 0;
        while(input.size() * 8 % 512 != 448) {
            input.push_back(fillHelp[index++]);
        }
    }
    input.insert(input.end(), trueLen.begin(), trueLen.end());

    // 开始 MD5 运算，每次 512 位 = 8*64
    int transformTime = input.size() / 64;
    for (int i = 0; i < transformTime; ++i) {
        vector<uint8_t> md5input;
        md5input.insert(md5input.end(), input.begin() + i * 64, input.begin() + (i + 1) * 64); 
        // 包含参数2，不包含参数3
        Transform(md5input);
    }
}