// d2x: https://github.com/d2learn/d2x
// license: Apache-2.0
// file: dslings/hellocpp.cpp
//
// Exercise/练习: 自动化代码练习使用教学
//
// Tips/提示:
//    该项目是使用d2x工具搭建的自动化代码练习项目, 通过在项目根目录下
//    执行 d2x checker 进入"编译器驱动开发模式"的练习代码自动检测.
//    你需要根据控制台的报错和提示信息, 修改代码中的错误. 当修复所有编译错误和
//    运行时检查点后, 你可以删除或注释掉代码中的 d2x::wait() 宏, 会自动进入下一个练习.
//
//      - d2x::wait: 该宏用于隔离不同练习, 你可以删除或注释掉该宏, 进入下一个练习.
//      - d2x::assert_eq: 该宏用于运行时检查点, 你需要修复代码中的错误, 使得所有
//      - D2X_YOUR_ANSWER: 该宏用于提示你需要修改的代码, 一般用于代码填空(即用正确的代码替换这个宏)
//
// Auto-Checker/自动检测命令:
//
//   d2x checker hellocpp
//

#include <d2x/cpp/d2x.hpp>

// 新的 d2x 函数已支持颜色输出和源文件位置信息
// 修改代码时可以观察到控制台"实时"的变化

int main() {

    std::cout << "hello, mcpp!" << std:endl; // 0.修复这个编译错误

    int a = 1.1; // 1.修复这个运行时错误, 修改int为double, 通过检查

    d2x::assert_eq(a, 1.1); // 2.运行时检查点, 需要修复代码通过所有检查点(不能直接删除检查点代码)

    /* D2X_YOUR_ANSWER */ b = a; // 3.修复这个编译错误, 给b一个合适的类型

    d2x::assert_eq(b, 1); // 4.运行时检查点2

    d2x::wait(); // 5.删除或注释掉这个函数调用, 进入下一个练习(项目正式代码练习)

    return 0;
}

//// --- 更多详细介绍 | | |
//                  V V V
/*

# [[ 控制台输出解读 ]]

 🌏 ▒░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░ 0/2  -->> 显示当前的练习进度
                                                                                                                               
 ✗ hellocpp                 -->> 当前显示检测状态和练习名
 + → dslings/hellocpp.cpp   -->> 当前练习的文件路径
                                                                                                                               
 [ 23%]: cache compiling.release dslings/hellocpp.cpp -->> 显示编译状态
 error: dslings/hellocpp.cpp:29:39: error: found ':' in nested-name-specifier, expected '::'
    29 |     std::cout << "hello, mcpp!" << std:endl; // 0.修复这个编译错误
       |                                       ^
       |                                       ::
   ▼ 5 more lines below...

🤖:   AI Disabled / 未启用 - https://github.com/d2learn/d2x  -->> 显示AI状态/信息

*/