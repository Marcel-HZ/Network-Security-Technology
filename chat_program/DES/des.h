#ifndef DES_OPERATE_H
#define DES_OPERATE_H

#include <vector>
#include <string>
#include "des_constants.h"
#include "../MakeData.h"

class CDesOperate {
public:
    int Encry(string plainText, string key, string& encryResult);  // 加密函数
    int Decry(string cipherText, string key, string& decryResult); // 解密函数
    static string GenerateDesKey(); // 生成随机DES密钥

private:
    vector<bool> EncryPro(vector<bool> input, vector<vector<bool> > subKey); // 处理64bit的加密函数
    vector<bool> DecryPro(vector<bool> input, vector<vector<bool> > subKey); // 处理64bit的解密函数

    vector< vector<bool> > EncryDataProcess(string text); // 明文数据处理：string → bool
    vector< vector<bool> > DecryDataProcess(string text); // 密文数据处理：string → bool
    vector<bool> KeyProcess(string key); // key处理：string → bool

    vector<bool> InitReplacementIP(vector<bool> input, int type); // 初始/逆初始置换IP

    vector<bool> fFunc(vector<bool> input, vector<bool> key); // f函数
    vector<bool> EBox(vector<bool> input); // f1: 选择扩展运算E
    vector<bool> keyAddition(vector<bool> input, vector<bool> key); // f2: 密钥加运算
    vector<bool> selectCompressionOperation(vector<bool> input); // f3: 选择压缩运算S
    vector<bool> replacementOp(vector<bool> input); // f4: 置换运算P

    vector< vector<bool> > MakeKey(vector<bool> initKey); // 生成16个密钥中的每一个子密钥，得到subKey
};

#endif // DES_OPERATE_H
