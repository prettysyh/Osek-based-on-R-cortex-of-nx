#!/bin/bash

# 定义当前目录和目标include目录
current_dir="."
include_dir="./include"

# 创建目标include目录如果它不存在
mkdir -p "$include_dir"

# 移动所有.h文件到include目录
for file in "$current_dir"/*.h; do
    if [ -f "$file" ]; then
        mv "$file" "$include_dir"
        echo "Moved: $file to $include_dir"
    fi
done

