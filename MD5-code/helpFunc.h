#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <streambuf>

using namespace std;

// 打印帮助信息
void PrintHelp(int argc, char *argv[]);

// 打印程序的测试信息
void PrintTest(int argc, char *argv[]);

// 计算被测文件的 MD5 摘要并打印
void ComputeMD5(int argc, char *argv[]);

// 让用户输入被测文件 MD5，然后重新计算被测文件的 MD5，将两个摘要逐位比较
void ValidateMD5(int argc, char *argv[]);

// 程序读取 .md5 摘要，重新计算被测文件的 MD5，最后将两者逐位比较
void ValidateMD5FromFile(int argc, char *argv[]);