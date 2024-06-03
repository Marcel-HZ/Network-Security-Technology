#include "MD5.h"
#include "helpFunc.h" // 包含帮助函数的头文件

int main(int argc, char *argv[]) {
	// 定义一个映射，将命令行参数和对应的函数关联起来
    unordered_map<string, void (*)(int, char *[])> mapOp = {
        {"-t", PrintTest},
        {"-c", ComputeMD5},
        {"-v", ValidateMD5},
        {"-f", ValidateMD5FromFile},
    };

    if (argc < 2) {
        // 如果没有提供命令行参数，则打印帮助信息
        PrintHelp(argc, argv);
        return 0;
    }

    string op = argv[1]; // 获取命令行参数
    if (mapOp.find(op) != mapOp.end()) {
        mapOp[op](argc, argv); // 根据参数调用相应的函数
    } else {
        cout << "未知的参数: " << op << endl;
    }

    return 0;
}