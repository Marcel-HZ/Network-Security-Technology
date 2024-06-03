#include "helpFunc.h"
#include "MD5.h"

// 打印帮助信息
void PrintHelp(int argc, char *argv[]) {
    if (2 != argc) {
        
    }
    cout << "usage：" << "\t" << "[-t] --打印程序的测试信息" << endl
         << "\t" << "[-c] [file path of the file computed]" << endl
         << "\t" << "\t" <<"--计算出的被测文件的MD5摘要并打印" << endl
         << "\t" << "[-v] [file path of the file validated]" << endl
         << "\t" << "\t" <<"--用户输入被测文件的MD5摘要，然后重新计算被测文件nankai.txt的MD5摘要，进行比较" << endl
         << "\t" << "[-f] [file path of the file validated] [file path of the .md5 file]" << endl
         << "\t" << "\t" <<"--程序读取nankai.md5摘要，重新计算被测文件nankai.txt的MD5，最后进行比较" << endl;
}

// 打印程序的测试信息
void PrintTest(int argc, char *argv[]) {
    if (2 != argc) {
        cout << "参数错误" << endl;
    }
    vector<string> str = {"", "a", "abc", "message digest", "abcdefghijklmnopqrstuvwxyz", "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789", "12345678901234567890123456789012345678901234567890123456789012345678901234567890"};
    ModifiedMD5 md5;
    for (int i = 0; i < str.size(); ++i) { 
        md5.Update(str[i]);
        cout << "MD5(\"" + str[i] + "\") = " << md5.ToString() << endl;
    }
}

// 计算被测文件的MD5摘要并打印
void ComputeMD5(int argc, char *argv[]) {
    if (3 != argc) {
        cout << "参数错误" << endl;
        return;
    }

    string filePath = argv[2];
    string md5FilePath = filePath + ".md5";
    ifstream fileStream(filePath);

    // 如果文件存在，就删除以覆盖旧文件
    remove(md5FilePath.c_str());

    // 计算 MD5 值
    ModifiedMD5 md5;
    md5.Update(fileStream);
    string md5Value = md5.ToString();
    cout << "文件(\"" << filePath << "\")的 MD5 值为：" << md5Value << endl;

    // 将 MD5 值写入 .md5 文件中
    ofstream md5FileStream(md5FilePath);
    if (!md5FileStream) {
        cout << "无法创建或打开 .md5 文件" << endl;
        return;
    }

    md5FileStream << md5Value;
    cout << "MD5 值已写入文件：" << md5FilePath << endl;
}

// 让用户输入被测文件的MD5摘要，然后重新计算被测文件的MD5摘要，将两个摘要逐位比较
void ValidateMD5(int argc, char *argv[]) {
    if (3 != argc) {
        cout << "参数错误" << endl;
    }
    string filePath = argv[2];
    cout << "Please input the MD5 value of file(\"" << filePath << "\")..." << endl;
    string inputMD5;
    cin >> inputMD5;
    cout << "The old MD5 value of file(\"" << filePath << "\") you have input is" << endl << inputMD5 << endl;
    ifstream fileStream(filePath);
    ModifiedMD5 md5;
    md5.Update(fileStream);
    string genMD5 = md5.ToString();
    cout << "The new MD5 value of file(\"" << filePath << "\") that has computed is" << endl << genMD5 << endl;
    if (!genMD5.compare(inputMD5)) {
        cout << "OK! The file is integrated" << endl;
    }
    else {
        cout << "Match Error! The file has been modified!" << endl;
    }
}

// 程序读取.md5摘要，重新计算被测文件的MD5，最后将两者逐位比较
void ValidateMD5FromFile(int argc, char *argv[]) {
    if (4 != argc) {
        cout << "参数错误" << endl;
    }
    string filePath = argv[2];
    string md5Path = argv[3];

    ifstream md5Stream(md5Path);
    string oldMD5Str((istreambuf_iterator<char>(md5Stream)), istreambuf_iterator<char>());
    cout << "The old MD5 value of file(\"" << filePath << "\") in " << md5Path << " is " << endl << oldMD5Str << endl;

    ifstream fileStream(filePath);
    ModifiedMD5 md5;
    md5.Update(fileStream);
    string genMD5 = md5.ToString();
    cout << "The new MD5 value of file(\"" << filePath << "\") that has computed is" << endl << genMD5 << endl;
    if (!genMD5.compare(oldMD5Str)) {
        cout << "OK! The file is integrated" << endl;
    }
    else {
        cout << "Match Error! The file has been modified!" << endl;
    }
}