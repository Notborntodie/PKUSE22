# Data Lab

*写在前面:本手册基于Ubuntu20.04.4，另外建议使用vscode完成lab*

## 补充的环境问题

* 如果你是使用ubuntu虚拟机，使用`make`出现以下的问题

  ```shell
  fatal-error-bits-libc-header-start-h-no-such-file-or-directory-while-compiling
  ```

  解决方法在[solution](https://stackoverflow.com/questions/54082459/fatal-error-bits-libc-header-start-h-no-such-file-or-directory-while-compili),这样就安装好了32位的库，可以`make`了。

  ```shell
  sudo apt-get install gcc-multilib
  ```

## CMU指导手册（翻译）











4





## 参考解答

 网上的解答很多，这只是一份参考，操作数不一定最少，在bit部分的解答也力求一行解决因而也不一定最简约。

### bitXor

* `x^y= (~x&y)|(~y&x)=~~((~x&y)|(~y&x))=~((~(~x&y))&(~(~y&x)))`

```c
int bitXor(int x, int y) {
  return ~((~(~x&y))&(~(~y&x)));
}
```

### tmin

* 最小的int的二进制表达是1000 0000 0000 0000 0000 0000 0000 0000

```c
int tmin(void) {
  return 1<<31;
}
```

### isMax

* 最大的int的二进制表达是0111 1111 1111 1111 1111 1111 1111 1111

```c
int isTmax(int x) {
  return !(~(x+x+1)) & (!!(x+1));
}
```

1. 第一部分是主要思路。
2. 第二部分是排除0xFFFFFFFF

* 由于我希望通过一行来完成，这里的函数总有些冗余，使用了较多的操作符。





### isAsciiDigit

0x00000030~0x00000039

(!(x>>3^0x6) |  !(x>>1^0x1C))



(0xFFFFFFFFF+(! x))&y+(0xFFFFFFFF+!!x)&z



