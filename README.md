```
# CTP 公共基础库（global.h）

## 这是什么

一个 C 语言公共头文件库，为 CTP 期货交易程序提供统一的基础设施：
- 日志输出（带颜色，区分错误/警告/信息）
- 错误处理宏（减少重复代码）
- 常用常量和类型定义（时间、字符串长度等）
- 线程安全的回调校验宏

## 它能干什么

你不需要在每个 CTP 相关模块里重复写日志、判空、错误处理。  
直接 `#include <global/global.h>`，然后用：

LOG_ERROR("模块名", "连接失败：%s", reason);
LOG_INFO("模块名", "登录成功，用户：%s", user_id);
CHECK_RET(ptr == NULL, LOG_ERROR, -1, "指针为空");

## 在后续产品中的用途

这个库是所有 CTP 产品（登录包、交易包、行情包、策略框架）的共同底座：

CTP 登录基础包   -> 日志输出登录过程、校验回调参数
CTP 交易核心包   -> 错误处理宏、断线重连日志
CTP 策略框架     -> 统一的日志格式、时间转换工具

简单说：你买任何一个 CTP 产品，都会附带这个库。

## 安装方法

```bash
chmod +x install.sh
./install.sh
```

> 脚本执行说明：
> - 源码自动克隆到：`~/futures/ctp-common`
> - 默认安装路径：`/usr/local/trade`
> - 如需自定义安装路径：`./install.sh /你想要的路径`

## 验证安装

```bash
ls -l /usr/local/trade/include/global/global.h
```

## 使用方式

安装后，在代码中引用：

```c
#include <global/global.h>
```

编译时无需指定 -I，因为 /usr/local/trade/include 已经是默认搜索路径

## 开源协议

BSD 3-Clause

## 作者

[木古古] - [20488535@qq.com]

