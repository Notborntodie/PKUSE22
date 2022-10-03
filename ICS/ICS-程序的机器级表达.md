# ICS-程序的机器级表达

## 从Data Lab说起

我想先从我自己的角度浅谈一下为什么要学习程序的机器级表达------在本章其实也就是汇编语言了。C语言已经是很底层的高级语言，然而有时候如果我们进行一些危险的“极限操作”时，会出现一些意料之外的结果，举一个例子，做`Data Lab`的时候，我想这样完成`isTmax`函数。

```c
int isTmax(int x) {
  return !(x+x+2);
}
```

但奇怪的是`INTMAX+INTMAX+2`的结果是0，`!(INTMAX+INTMAX+2)`的结果也还是0。看C程序我完全不理解这个结果（虽然这个行为确实很危险），我甚至猜测是不是在硬件上做逻辑否运算的时候它会考虑进位的`1`。现在让	我们来看看编译成汇编语言的结果

<img src="http://cdn.zhengyanchen.cn/img202210020047745.png" alt="截屏2022-10-02 00.47.16" style="zoom:50%;" />

1. 移动栈指针`%rsp`。
2. 把 `INTMAX`放进`Memory[%rbp-4]`
3. 比较`Memory[%rbp-4]`也就是`INTMAX`和-1的值
4. 如果两值相等，设置`%al`为1
5. 然后把`%al`的值移到`%eax`寄存器，`%eax`给出的就是需要返回的结果。

编译器的逻辑是这样的：`!(x+x+2)`这样表达式只有x=-1才能等于1，于是只要知道x和-1是否相等就可以给出结果了呀。这和我C程序的逻辑显然大相径庭，所以根本没必要把硬件想得很复杂。事实上，去做`INTMAX+INTMAX+2`这样溢出的危险操作在C语言里是未定义的，出现意外的结果才不意外，但倘若只告诉我们这种行为是**未定义的**这几个字恐怕是不能叫人信服的，编译结果给了我们最直观的解答。









## Condition moves(`cmov`)及其坏结果

 为了便于流水线作业，编译器可能会让两分支都会运算，最后使用`cmov`(condition moves)指令来优化`if else`。

<img src="http://cdn.zhengyanchen.cn/img202209301734075.png" alt="截屏2022-09-30 17.34.45" style="zoom:30%;" />

`cmov`指令也可以用于优化`?:`表达式，但在一些例子里会导致出现一些坏结果。尤其是下图的第三种情况，如果使用`cmov`, 那么x将会参与多次运算，影响最后结果。

<img src="http://cdn.zhengyanchen.cn/img202209301620499.png" alt="截屏2022-09-30 16.20.11" style="zoom: 33%;" />

我运行了gcc(Ubuntu 9.4.0-1ubuntu1~20.04.1)编译器，先赋值`x=1`,再运行上图第三个语句的实际编译结果如下，可以看到在把x的初始化值放在栈区以后，做的第一件事就是比较x和0的大小，并没有先计算再使用`cmov` 。所以事实上，如果编译器足够聪明，它并不会去利用`cmov`对`?:`做优化。

```assembly
cmpl $0 -8(%rbp)//比较x和0的大小
```

<img src="http://cdn.zhengyanchen.cn/img202209301744162.png" alt="截屏2022-09-30 17.44.02" style="zoom:33%;" />

但以防万一，我们可以使用`volatile`关键字,这样就可以避免编译器利用`cmov`的优化。

```c
volatile int x,val;
val=x>0 ? x*=7 : x+=3;
```

*[此处参考](https://stackoverflow.com/questions/50455515/is-the-conditional-move-optimization-against-the-c-standard)*

## 跳转表

<img src="http://cdn.zhengyanchen.cn/img202209301655110.png" alt="截屏2022-09-30 16.55.06" style="zoom:40%;" />

向陈老师确定后，此处的`goto *JTab[x]`的注释是不严谨的。`Jab[x]`和`*(Jab+x)`等效，都可以表示取跳转表第x个地址，使用这两个取代注释都是可以。





