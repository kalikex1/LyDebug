# LyDebug PE 动态反汇编调试器

<br>

<div align=center>
  
![image](https://user-images.githubusercontent.com/52789403/179908169-e5a9c576-8c79-4858-8b8b-f446319b8de8.png)

</div>

<br>
<b>版本：1.0</b>
<br>
<b>发布日期：2020-05-25 21:00</b>
<br><br>

一款使用C++开发实现的命令行版PE动态反汇编调试器，该调试器支持寄存器查看修改，软硬件断点的设置删除以及遍历，单步执行步过，堆栈检查，内存检查等基本功能。

主要模块与功能:

 - 1.查看修改寄存器功能
 - 2.查看修改内存功能
 - 3.单步步入功能
 - 4.单步步过功能
 - 5.运行功能
 - 6.软件断点功能
 - 7.硬件执行访问断点
 - 8.显示反汇编功能
 - 9.内存断点功能

<br><br>

**打开PE文件:** 打开可执行文件可在命令行下传入`--path`路径，打开后默认会断在程序OEP位置。
```
C:\> LyDebug32.exe --path d://Win32Project.exe
[*] Loca EIP = 0x00EF121C
[LyDebug] #
[LyDebug] # Run
```

**设置软件断点:** 对指定内存地址处写入CC指令设置软件断点，此处传入的是十进制格式。
```
[LyDebug] # SetBreakPoint --address 15667740
[*] SetBreakPoint => 00EF121C
[LyDebug] #
[LyDebug] # SetBreakPoint --address 15667741
[*] SetBreakPoint => 00EF121D
[LyDebug] #
[LyDebug] # SetBreakPoint --address 15667742
[*] SetBreakPoint => 00EF121E
[LyDebug] #
[LyDebug] # SetBreakPoint --address 15667743
[*] SetBreakPoint => 00EF121F
[LyDebug] #
[LyDebug] # SetBreakPoint --address 15667744
[*] SetBreakPoint => 00EF1220
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

**清除软件断点:** 将软件断点从断点列表中移除，此处传入的参数也是十进制格式。
```
[LyDebug] # DelBreakPoint --address 15667740
[-] DelBreakPoint => 00EF121C
[LyDebug] #
[LyDebug] # DelBreakPoint --address 15667741
[-] DelBreakPoint => 00EF121D
[LyDebug] #
[LyDebug] # DelBreakPoint --address 15667742
[-] DelBreakPoint => 00EF121E
[LyDebug] #
[LyDebug] # DelBreakPoint --address 15667743
[-] DelBreakPoint => 00EF121F
[LyDebug] #
[LyDebug] # DelBreakPoint --address 15667744
[-] DelBreakPoint => 00EF1220
```

**设置内存断点:** 设置内存断点，断点存在内存属性`r=读,w=写,e=执行`设置断点时属性也是必须加的。
```
[LyDebug] # SetMemBreakPoint --address 15667740 --flag w
[*] SetMemBreakPoint => 00EF121C
[LyDebug] #
[LyDebug] # SetMemBreakPoint --address 15667744 --flag r
[*] SetMemBreakPoint => 00EF1220
[LyDebug] #
[LyDebug] # SetMemBreakPoint --address 15667748 --flag e
[*] SetMemBreakPoint => 00EF1224
```

**输出内存断点:** 输出当前所有的内存断点信息，内存断点`Protect`表示内存保护类型，`Attribute`是内存属性。
```
[LyDebug] # ShowMemBreakPoint

ID = 1   | Address = 00EF121C    | OldProtect = 32       | NewProtect = 32      | Attribute = W
ID = 2   | Address = 00EF1220    | OldProtect = 32       | NewProtect = 1       | Attribute = E
ID = 3   | Address = 00EF1224    | OldProtect = 1        | NewProtect = 4       | Attribute = E
```

**清除内存断点:** 删除指定的内存断点，此处传入的是一个十进制数值。
```
[LyDebug] # DelMemBreakPoint --address 15667740
[-] DelMemBreakPoint => 00EF121C
[LyDebug] #
[LyDebug] # DelMemBreakPoint --address 15667744
[-] DelMemBreakPoint => 00EF1220
[LyDebug] #
[LyDebug] # DelMemBreakPoint --address 15667748
[-] DelMemBreakPoint => 00EF1224
```

**设置硬件断点:** 硬件断点设置，需要传入断点的长度，以及该段点属性，硬件断点最多设置3个。
```
[LyDebug] # SetHbreakPoint --address 15667740 --len 4 --flag w
[*] SetHBreakPoint => 00EF121C
[LyDebug] #
[LyDebug] # SetHbreakPoint --address 15667744 --len 4 --flag r
[*] SetHBreakPoint => 00EF1220
```

**输出硬件断点:** 输出当前所有的硬件断点，此处输出的是Dr寄存器，如果为空则说明断点是空的。
```
[LyDebug] # ShowHbreakPoint
  DR0 = 00EF121C
W DR1 = 00EF1220
R DR2 = 00000000
  DR3 = 00000000
```

**清除硬件断点:** 清除指定寄存器内的数值，从而清空硬件断点。
```
[LyDebug] # DelHbreakPoint --dr 0
[-] DelHBreakPoint
[LyDebug] #
[LyDebug] # DelHbreakPoint --dr 1
[-] DelHBreakPoint
[LyDebug] #
[LyDebug] # DelHbreakPoint --dr 2
[-] DelHBreakPoint
```

**反汇编当前行:** 该功能需要传入一个反汇编长度，会从当前EIP位置向下反汇编指定行。
```
[LyDebug] # Dissasembler --size 10

00EF35D0 | 55                             | push ebp
00EF35D1 | 8B EC                          | mov ebp, esp
00EF35D3 | 83 EC 14                       | sub esp, 0x14
00EF35D6 | C7 45 F4 00 00 00 00           | mov dword ptr [ebp - 0xc], 0
00EF35DD | C7 45 F8 00 00 00 00           | mov dword ptr [ebp - 8], 0
00EF35E4 | 81 3D 00 90 EF 00 4E E6 40 BB  | cmp dword ptr [0xef9000], 0xbb40e64e
00EF35EE | 74 1F                          | je 0xef360f
00EF35F0 | A1 00 90 EF 00                 | mov eax, dword ptr [0xef9000]
00EF35F5 | 25 00 00 FF FF                 | and eax, 0xffff0000
00EF35FA | 74 13                          | je 0xef360f
```

**StepOut 单步步过:** 执行StepOut单步走，遇到call不进入直接跳过。
```
[LyDebug] # Dissasembler --size 4
00EF35D0 | 55                             | push ebp
00EF35D1 | 8B EC                          | mov ebp, esp
00EF35D3 | 83 EC 14                       | sub esp, 0x14
00EF35D6 | C7 45 F4 00 00 00 00           | mov dword ptr [ebp - 0xc], 0
[LyDebug] #
[LyDebug] # StepOut
[*] 命中断点: 00EF35D1
[LyDebug] #
[LyDebug] # Dissasembler --size 4
00EF35D1 | 8B EC                          | mov ebp, esp
00EF35D3 | 83 EC 14                       | sub esp, 0x14
00EF35D6 | C7 45 F4 00 00 00 00           | mov dword ptr [ebp - 0xc], 0
00EF35DD | C7 45 F8 00 00 00 00           | mov dword ptr [ebp - 8], 0
```

**StepIn 单步步入:** 执行StepIn步入，遇到call等会进入到call内部。
```
[LyDebug] # Dissasembler --size 4
00EF35D1 | 8B EC                          | mov ebp, esp
00EF35D3 | 83 EC 14                       | sub esp, 0x14
00EF35D6 | C7 45 F4 00 00 00 00           | mov dword ptr [ebp - 0xc], 0
00EF35DD | C7 45 F8 00 00 00 00           | mov dword ptr [ebp - 8], 0
[LyDebug] #
[LyDebug] # StepIn
[*] 命中断点: 00EF35D3
[LyDebug] #
[LyDebug] # Dissasembler --size 4
00EF35D3 | 83 EC 14                       | sub esp, 0x14
00EF35D6 | C7 45 F4 00 00 00 00           | mov dword ptr [ebp - 0xc], 0
00EF35DD | C7 45 F8 00 00 00 00           | mov dword ptr [ebp - 8], 0
00EF35E4 | 81 3D 00 90 EF 00 4E E6 40 BB  | cmp dword ptr [0xef9000], 0xbb40e64e
```

**检查寄存器:** 该命令用于检查当前寄存器内的数值，目前可检测通用寄存器，标志寄存器。
```
[LyDebug] # Register

EAX = 225B5D10    | EBX = 0063A000    | ECX = DDA4A2EF
EDX = 00EF121C    | ESI = 00EF121C    | EDI = 00EF121C
ESP = 008FFA34    | EBP = 008FFA7C    | EFLAGS = 00000211

EIP = 00EF1F91

CS = 0023    | SS = 002B    | DS = 002B
ES = 002B    | FS = 0053    | GS = 002B
```

**修改寄存器:** 该命令用于修改指定寄存器内的数值，传入参数为十进制形式。
```
[LyDebug] # SetRegister --reg eax --value 10
[+] 修改寄存器 eax
[LyDebug] #

[LyDebug] # Register

EAX = 0000000A    | EBX = 0063A000    | ECX = DDA4A2EF
EDX = 00EF121C    | ESI = 00EF121C    | EDI = 00EF121C
ESP = 008FFA34    | EBP = 008FFA7C    | EFLAGS = 00000211

EIP = 00EF1F91

CS = 0023    | SS = 002B    | DS = 002B
ES = 002B    | FS = 0053    | GS = 002B
```

**检查堆栈:** 该命令用于检查当前被调试进程堆栈信息。
```
[LyDebug] # Stack
[ 008FFA34 ]     00EF121C
[ 008FFA38 ]     00EF121C
[ 008FFA3C ]     0063A000
[ 008FFA40 ]     00000000
[ 008FFA44 ]     00000000
[ 008FFA48 ]     00000000
[ 008FFA4C ]     00000000
[ 008FFA50 ]     00000000
[ 008FFA54 ]     00000000
```

**检查内存:** 该命令用于检查当前内存，其输出格式为4位4字节。
```
[LyDebug] # Memory --address 6529024

 [0063A000]     04010000 FFFFFFFF 00EE0000 77795D80
 [0063A010]     00C81FB0 00000000 00C80000 77795B40
 [0063A020]     00000000 00000000 00000000 75E01370
 [0063A030]     00000000 00000000 00580000 00000000
 [0063A040]     77795D30 00010003 00000000 7EF40000
 [0063A050]     00000000 7EF40750 7F0A0000 7F0A0000
 [0063A060]     7F0D0028 00000006 00000070 00000000
 [0063A070]     079B8000 FFFFE86D 00100000 00002000
 [0063A080]     00010000 00001000 00000001 00000010
```

**修改内存:** 该命令用于修改指定内存地址中的数值，默认传入格式十进制。
```
[LyDebug] # SetMemory --address 6529024 --value 10
[LyDebug] #
[LyDebug] # Memory --address 6529024

 [0063A000]     0000000A FFFFFFFF 00EE0000 77795D80
 [0063A010]     00C81FB0 00000000 00C80000 77795B40
 [0063A020]     00000000 00000000 00000000 75E01370
```
