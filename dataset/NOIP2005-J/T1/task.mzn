%NOIP2005-J T1
%input

array[1..10] of int: apple;
int: h;
%输入文件包括两行数据。第一行包含 10 个 100 到 200 之间(包括 100 和 200)的整数(以 厘米为单位)分别表示 10 个苹果到地面的高度，两个相邻的整数之间用一个空格隔开。第 二行只包括一个 100 到 120 之间(包含 100 和 120)的整数(以厘米为单位)，表示陶陶 把手伸直的时候能够达到的最大高度。


%description

var int: num;
constraint num=count([apple[i]<=h+30 | i in 1..10]);
%陶陶有个 30 厘米高的板凳，当她不能直接用手摘到苹果的时候，就会踩到板凳上再试试。
%现在已知 10 个苹果到地面的高度，以及陶陶把手伸直的时候能够达到的最大高度，请帮陶陶算一下她能够摘到的苹果的数目。

%solve

solve satisfy;

%output

output[show(num)];
%输出文件包括一行，这一行只包含一个整数，表示陶陶能够摘到的苹果的数目。