#ifndef DES_OPERATE_H
#define DES_OPERATE_H

#include <vector>
#include <string>
#include "des_constants.h"
#include "MakeData.h"

class CDesOperate {
public:
    int Encry(std::string plainText, std::string key, std::string& encryResult);  // 加密函数
    int Decry(std::string cipherText, std::string key, std::string& decryResult); // 解密函数

private:
    std::vector<bool> EncryPro(std::vector<bool> input, std::vector<std::vector<bool> > subKey); // 处理64bit的加密函数
    std::vector<bool> DecryPro(std::vector<bool> input, std::vector<std::vector<bool> > subKey); // 处理64bit的解密函数

    std::vector< std::vector<bool> > EncryDataProcess(std::string text); // 明文数据处理：string → bool
    std::vector< std::vector<bool> > DecryDataProcess(std::string text); // 密文数据处理：string → bool
    std::vector<bool> KeyProcess(std::string key); // key处理：string → bool

    std::vector<bool> InitReplacementIP(std::vector<bool> input, int type); // 初始/逆初始置换IP

    std::vector<bool> fFunc(std::vector<bool> input, std::vector<bool> key); // f函数
    std::vector<bool> EBox(std::vector<bool> input); // f1: 选择扩展运算E
    std::vector<bool> keyAddition(std::vector<bool> input, std::vector<bool> key); // f2: 密钥加运算
    std::vector<bool> selectCompressionOperation(std::vector<bool> input); // f3: 选择压缩运算S
    std::vector<bool> replacementOp(std::vector<bool> input); // f4: 置换运算P

    std::vector< std::vector<bool> > MakeKey(std::vector<bool> initKey); // 生成16个密钥中的每一个子密钥，得到subKey
};

#endif // DES_OPERATE_H
