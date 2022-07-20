# LyDebug PE 动态调试器

<br>

<div align=center>
  
![image](https://user-images.githubusercontent.com/52789403/179908169-e5a9c576-8c79-4858-8b8b-f446319b8de8.png)

</div>

<br>
版本：1.0
<br>
发布日期：2020-05-25 21:00
<br><br>

一款使用C++开发实现的命令行版PE动态调试器，该调试器支持寄存器查看修改，软硬件断点的设置删除以及遍历，单步执行步过，堆栈检查，内存检查等基本功能。
<br><br><br>

**打开PE文件:** 打开可执行文件可在命令行下传入`--path`路径，打开后默认会断在程序OEP位置。
```
C:\> LyDebug32.exe --path d://Win32Project.exe
[*] Loca EIP = 0x00EF121C
[LyDebug] #
```

**设置软件断点:** 对指定内存地址处写入CC指令设置软件断点，此处传入的是十进制格式。
```
[LyDebug] # SetBreakPoint --address 15667740
[*] SetBreakPoint => 00EF121C
[LyDebug] #
[LyDebug] # SetBreakPoint --address 15667741
[*] SetBreakPoint => 00EF121D
[LyDebug] # SetBreakPoint --address 15667742
[*] SetBreakPoint => 00EF121E
[LyDebug] # SetBreakPoint --address 15667743
[*] SetBreakPoint => 00EF121F
[LyDebug] # SetBreakPoint --address 15667744
[*] SetBreakPoint => 00EF1220
[LyDebug] #
```

**输出软件断点:** 输出当前设置过的软件断点，输出断点为地址和该地址处指令属性。
```
[LyDebug] # ShowBreakPoint

ID = 1   | Address = 00EF121C    | Code = FFFFFFE9       | Attribute = 1
ID = 2   | Address = 00EF121D    | Code = 6F             | Attribute = 1
ID = 3   | Address = 00EF121E    | Code = 11             | Attribute = 1
ID = 4   | Address = 00EF121F    | Code = 0              | Attribute = 1
ID = 5   | Address = 00EF1220    | Code = 0              | Attribute = 1
```














































