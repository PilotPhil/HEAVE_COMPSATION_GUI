# IceLoad_GUI

#### 介绍
江苏科技大学---极地海洋装备研究所

冰载荷计算软件

#### 软件架构
界面：Qt Widgets
计算程序：matlab导出


#### 安装教程
1. download from release
2. unzip
3. just use

#### 从源码编译
1. 安装[matlab runtime](https://ww2.mathworks.cn/products/compiler/matlab-runtime.html) R2018b 64-bit
2. 下载[eigen库](https://gitlab.com/libeigen/eigen/-/releases/3.4.0)
3. 下载[IceLoad_GUI源码](https://gitee.com/pilot12138/ice-load_-gui)
4. 安装matlab runtime并将
    ```
    C:\Program Files\MATLAB\MATLAB Runtime\v95\extern\include
    C:\Program Files\MATLAB\MATLAB Runtime\v95\bin\win64
    ```
    添加到环境变量path

5. 执行`build.bat`
```bat
::1.mkdir
mkdir mybuild
cd mybuild

::2.cmake gen mingw makefile
cmake ..^
 -G "MinGW Makefiles"^
 -DCMAKE_BUILD_TYPE=Debug

::3.make
mingw32-make -j16

::4.test
IceLoadGUI.exe
```

#### 发布
```bat
::1.mkdir
mkdir myrelease
cd myrelease
mkdir bin

::2.cmake gen mingw makefile
cmake ..^
 -G "MinGW Makefiles"^
 -DCMAKE_BUILD_TYPE=Release^
 -DEXECUTABLE_OUTPUT_PATH=bin

::3.make
mingw32-make -j16

::4.deploy
cd bin
windeployqt IceLoadGUI.exe --release

::5.test
IceLoadGUI.exe
```

#### 参与贡献
1. 计算主程序：顾等
2. GUI：pilot.phil



