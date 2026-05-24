#!/bin/bash

# CTP 公共基础库一键安装脚本
# 使用方法：chmod +x install.sh && ./install.sh

set -e

# 源码存放目录（在用户 home 下）
SOURCE_DIR="$HOME/futures/ctp-common"

# 默认安装路径
PREFIX="${1:-/usr/local/trade}"

echo "=========================================="
echo "CTP 公共基础库安装脚本"
echo "源码目录: $SOURCE_DIR"
echo "安装路径: $PREFIX"
echo "=========================================="

# 1. 创建目录并克隆代码
echo "[1/4] 创建目录并克隆代码..."
mkdir -p "$HOME/futures"
cd "$HOME/futures"

if [ -d "ctp-common" ]; then
   echo "源码目录已存在，跳过克隆"
else
   git clone https://github.com/mugugu/trade-base.git
fi

# 2. 进入目录
cd ctp-common

# 3. 配置
echo "[2/4] 配置安装路径..."
./configure --prefix="$PREFIX"

# 4. 编译
echo "[3/4] 编译..."
make

# 5. 安装
echo "[4/4] 安装..."
make install

echo "=========================================="
echo "安装完成！"
echo "源码位置: $SOURCE_DIR"
echo "头文件位置: $PREFIX/include/global/global.h"
echo "验证命令: ls -l $PREFIX/include/global/global.h"
echo "=========================================="
