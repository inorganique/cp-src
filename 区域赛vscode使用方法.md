# 区域赛vscode使用方法

## 用vscode打开文件夹

一般区域赛都用 ubuntu 系统, 可按组合键 `Ctrl+Alt+T` 打开系统终端, 输入 `mkdir xxx` 即可在用户目录新建文件夹 `xxx`, 输入 `code xxx` 即可用 vscode 打开文件夹, 右键左侧边栏即可创建文件/文件夹, 按 `Ctrl+B` 可将其显示/隐藏。

按 `Ctrl+J` 可显示/隐藏下方面板, 可以在面板的集成终端里使用命令。

<br>

## 快捷键编译

vscode 的快捷键功能十分自由, 先后按 `Ctrl+K`, `Ctrl+S`, 再点击右上角的 !["打开键盘快捷方式(JSON)"](./images/1.png "打开键盘快捷方式(JSON)") 图标, 即可打开快捷键配置文件。

将以下片段写入文件即可

```json
[
    {
        "key": "ctrl+alt+n",
        "command": "runCommands",
        "args": {
            "commands": [
                {
                    "command": "workbench.action.files.save"
                },
                {
                    "command": "workbench.action.terminal.focus"
                },
                {
                    "command": "workbench.action.terminal.sendSequence",
                    "args": {
                        "text": "cd ${fileDirname} && g++ -g -std=gnu++20 -O2 -I ${fileDirname} -DLOCAL -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_BACKTRACE -Wall -Wextra -Wconversion ${fileBasename} -o ${fileBasenameNoExtension}.out -lstdc++exp\n"
                    }
                }
            ]
        },
        "when": "terminal.active && resourceLangId == cpp"
    }
]
```

其实现的是:  
当按下 `ctrl+alt+n`, 若集成终端处于活动状态且打开文件是 C++, 则执行 "保存文件 $\rarr$ 光标聚焦到终端 $\rarr$ 向集成终端发送编译命令" 三个动作。  
执行完即可把 `xxx.cpp` 编译成 `xxx.out`, 此时光标已经在终端, 输入 `./xxx.out` 即可执行程序, 可用 `./xxx.out < in.txt` 令程序从文件输入而非键盘。

你可以把 `"key"` 的值改成你顺手的组合键。  
`"text"` 中的 `-std=gnu++20` 要根据参赛手册的环境说明改成相应版本 (改个数字就行)。
