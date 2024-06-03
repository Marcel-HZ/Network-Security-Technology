#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "des.h"
#include "des_constants.h"
#include "MakeData.h"
using namespace std;
int CDesOperate::Encry(string plainText, string key, string& encryResult) {



vector<bool> CDesOperate:: EncryPro(vector<bool> input, vector<vector<bool> > subKey) {
    // 步骤1: 初始置换IP
    vector<bool> tempStep1 = InitReplacementIP(input, INIT_REPLACE_IP);
    map<string, vector<bool> > step1;
    vector<bool> tempLeft, tempRight;
    for (int i = 0; i < 32; i++) {
        tempLeft.push_back(tempStep1[i]);
        tempRight.push_back(tempStep1[i + 32]);
    }

    step1["left"] = tempLeft;
    step1["right"] = tempRight;

    // 步骤2: 16轮迭代
    // 每一轮：左 = 右， 右 = f(右, subkey)^左 
    for (int i = 0; i < 16; i++) {
        vector<bool> fFuncResult = fFunc(step1["right"], subKey[i]);
        vector<bool> xorResult = XOR(fFuncResult, step1["left"]);

        step1["left"] = step1["right"];
        step1["right"] = xorResult;
    }

    // 步骤3: 逆初始置换IP
    vector<bool> step3 = step1["left"];
    step3.insert(step3.end(), step1["right"].begin(), step1["right"].end());
    step3 = InitReplacementIP(step3, INVERSE_REPLACE_IP);
    return step3;
}