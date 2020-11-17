第一讲 Windows位图（Bitmap）和调色板（Palette）
source目录下为本章介绍的源程序
功能是打开一幅位图，并显示在屏幕上。

命令行编译过程如下
vcvars32
rc bmp.rc
cl bmp.c bmp.res user32.lib gdi32.lib

注意事项：
运行时，文件c:\test.bmp必须存在