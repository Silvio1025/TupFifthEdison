# 第六章 利用数组处理批量数据

1. 背景：用基本类型处理实际问题时，对于有同一类性质的数据，难以反映其特点，也难以快捷有效地进行处理。
2. 定义：把一批具有**同名的同属性的数据**称为一个数组。
3. 特征：
   * 数组是一组有序数据的集合；
   * 用数组名和下标来确定数组中的元素；
   * 每一个元素都属于同一个数据类型；
   * 下标用方括号[]中的数字表示。

## 6.1 定义和引用一维数组

### 6.1.1 定义一维数组

一般形式：`类型说明符  数组名[常量表达式]`

1. 数组名的命名规则和变量名相同，遵循标识符命名规则。
2. 在定义数组时，需要指定数组中元素的个数，方括号中的常量表达式用来表示元素的个数，即数组长度。
3. 常量表达式中可以包括常量和符号常量，不能包含变量。（c99前不行）
4. **注意**：数组元素的下标从0开始，用“`int a[10];`”定义数组，则最大下标值为9，不存在数组元素`a[10]`。
5. 在被调用的函数中定义了非静态数组，其长度可以是变量或非常量表达式。

### 6.1.2 引用一维数组

引用方式：`数组名[下标]`

1. 只能引用数组元素而不能一次整体调用整个数组全部元素的值。
2. 数组元素与一个简单变量的地位和作用相似。
3. “下标”可以是整型常量或整型表达式。
4. **注意**：定义数组时用到的“`数组名[常量表达式]`” 和引用数组元素时用的“`数组名[下标]`”形式相同，但含义不同。

### 6.1.3 一维数组的初始化

为了使程序简洁，常在定义数组的同时给各数组元素赋值，这称为数组的初始化。

1. 在定义数组时对全部数组元素赋予初值。

   将数组中各元素的初值顺序放在一对花括号内，数据间用逗号分隔。花括号内的数据就称为“初始化列表”。
2. 可以只给数组中的一部分元素赋值。

   定义a数组有10个元素，但花括号内只提供5个初值，这表示只给前面5个元素赋初值，系统自动给后5个元素赋初值为0。
3. 给数组中全部元素赋初值为0。

4. 在对全部数组元素赋初值时，由于数据的个数已经确定，因此可以不指定数组长度。

   但是，如果数组长度与提供初值的个数不相同，则方括号中的数组长度不能省略。
5. 在定义数值型数组时注意：
   1. 如果指定了数组的长度未对之初始话，数组元素是不可预料的；
   2. 如果只对部分数组元素初始化，凡未被“初始化列表”指定初始化的数组元素，系统自动把它们初始化为0；（如果是字符型数组，则初始化未'\0';如果是指针型数组，则初始化为NULL,空指针）。

## 6.2 定义和引用二维数组

1. 背景：在处理实际问题中，为了更好的表示数据的特点和处理数据，采用了二维数据。
2. 形式：二维数组常称为矩阵(matrix)。把二维数组写成行(row)和列(column)的排列形式，可以有助于形象化地理解二维数组的逻辑结构。

### 6.2.1 定义二维数组

1. 一般形式：`类型说明符 数组名[常量表达式][常量表达式]`
2. 存储形式：C语言中二维数组元素排列的顺序是按行存放的。矩阵形式表示二维数组，是逻辑上的概念，能形象的表示行列关系。而在内存中，各元素是连续存放的，是**线性**的，不是二维的。

### 6.2.2 引用二维数组

1. 表现形式：`数组名[下标][下标]`
2. “下标”可以是整型常量或整型表达式。数组元素可以出现在表达式中，也可以被赋值。
3. 注意：
   * 引用时下标值应在已定义的数组大小的范围内。
   * 严格区分在定义数组时用的`a[3][4]`和引用元素时的`a[3][4]`的区别。前者用`a[3][4]`来定义数组的维数和各维的大小，后者`a[3][4]`中的3和4是数组元素的下标值，`a[3][4]`代表行序号为3、列序号为4的元素（行序号和列序号均从0起算）。

### 6.2.3 二维数组的初始化

可以用“初始化列表”对二维数组初始化。

1. 可以分行赋初值；
2. 可以将所以数据写在一个花括号内，按元素在内存中的排列顺序赋初值；
3. 可以对部分元素赋值
   * 只对各行第一列赋值
   * 对各行中某一元素赋值
   * 只对某几行赋初值
4. 若提供全部初始数据或对部分元素分行赋初值时，可以不指定第一维度，但第二维度不能省。
5. 二维数组的第二维度可以为0，但它将是一个空数组或者称为空列。  
   在大多数编程语言中，允许定义一个二维数组的第二维度为0，但这样的数组在实际中并没有太多的用途。当第二维度为0时，这意味着该二维数组没有列，因此没有存储任何数据。这样的数组可能在某些特殊情况下用于占位符或者作为一种特殊的标记。但一般情况下，我们更常见的是定义有实际列数的二维数组，以便存储和操作数据。

## 6.3 字符数组

字符数据的应用较广泛，尤其作为字符串形式使用，有其自己的特点。

字符型数据是以字符的ASCII代码存储在存储单元中的，一般占一个字节。由于ASCII代码也属于整数形式，因此C99标准中，把字符型归纳为整型类型中的一种。

### 6.3.1 定义字符数组

1. 用来存放字符数据的数组就是字符数组，字符数组中一个元素存放一个字符。
2. 定义方法：`char 字符数组名[常量表达式]`
3. 由于字符型数据是以整数形式(ASCII代码)存放的，因此也可以用整型数组来存放字符数据。`int 字符数组名[常量表达式]`（合法，但浪费存储空间）

### 6.3.2 字符数组的初始化

对字符数组初始化，最容易理解的方式是用“初始化列表”，把各个字符依次赋给数组中各元素。

1. 如果在定义字符数组时不进行初始化，则数组中各元素的值是不可预料的。
2. 如果花括号中提供的初值个数（即字符个数）大于数组长度，则出现语法错误。
3. 如果初值个数小于数组长度，则只将这些字符赋给数组中前面那些元素，其余的元素自动定为空字符(即'\0')。(**字符数组末尾没有结束标志时**)
4. 如果提供的初值个数与预定的数组长度相同，在定义时可以省略数组长度，系统会自动根据初值个数确定数组长度。
5. 也可以定义和初始化一个二维字符数组。

### 6.3.4 字符串和字符串结束标志

在C语言中，是将字符串作为字符数组来处理的。

在实际工作中，人们关心的往往是字符串的有效长度而不是字符数组的长度。

为了测定字符串的实际长度，C语言规定了一个“字符串结束标志”，以字符'\0'作为结束标志。

**注意**：

C系统在用字符数组存储字符串常量时会自动加一个'\0'作为结束符。

在定义字符数组时应估计实际字符串长度，保证数组长度始终大于字符串实际长度。

如果在一个字符数组中先后存放多个不同长度的字符串，则应使数组长度大于最长的字符串的长度。

1. '\0'代表ASCII码为0的字符，是一个“空操作符”，不是一个可以显示的字符，它什么也不做。
2. C系统在用字符数组存储字符串常量时会自动加一个'\0'作为结束符。
3. 在用字符串常量来使字符数组初始化时，可以省略花括号(字符串两端用双撇号("")，数组长度+1，因为字符串常量的最后由系统自动加上一个'\0')。
4. **说明**：字符数组并不要求它的最后一个字符为'\0'，甚至可不包含'\0'。是否需要完全由实际需求决定。由于系统在处理字符串常量存储时会自动加一个'\0'，因此，为了使处理方法一致，便于长度字符串的实际长度，以及程序中做相应的处理，常常人为地在字符数组中加一个'\0'。

### 6.3.5 字符数组的输入输出

1. 逐个字符输入输出。
2. 将整个字符串一次输入或输出。用“%s”格式符，意思是对字符串(string)的输入输出。
   * 输出的字符中不包括结束符'\0'。
   * 用“%s”格式符输出字符串时，printf函数中的输出项是字符数组名，而不是数组元素名。
   * 如果数组长度大于字符串的实际长度，也只输出到遇'\0'结束。
   * 如果一个字符数组中包含一个以上'\0'，则遇第一个'\0'时输出就结束。
   * 可以用scanf输入字符串
     * 输入字符串应短于已定义的字符数组的长度；
     * 输入多个字符串时以空格分隔；
       * 系统把空格字符作为输入的字符串之间的分隔符
     * **注意**：输入项是字符数组名时不要加地址符&；
       * 因为在C语言中，数组名代表该数组的起始地址。
       * 实际执行：按字符数组名找到其起始地址，然后逐个输出其中的字符直到遇见'\0'为止。

### 6.3.6 使用字符串处理函数

1. 输出字符串的函数
   `puts(字符数组)`
   * 作用：将一个字符串(以'\0'结束的字符序列)输出到终端。
   * 用puts函数输出的字符串中可以包含转义字符。
   * 在用puts输出时将字符串结束标志'\0'转换成'\n'，即输出完字符串后换行。
2. 输入字符串的函数
   `gets(字符数组)`
   * 作用：从终端输入一个字符串到字符数组，并且得到一个函数值。该函数值是字符数组的起始地址。
3. 字符串连接函数
   `strcat(字符数组1，字符数组2)`
   * 作用：把两个字符数组中的字符串连接起来：
     * 把字符串2接到字符串1的后面，结果放在字符数组1中，
     * 函数调用后得到一个函数值——字符数组1的地址。
     * 字符数组1必须足够大，以便容纳连接后的新字符串。
     * 连接前两个字符串的后面都有'\0'，连接时将字符串1后面的'\0'取消，只在新串最后保留'\0'。
4. 字符串复制函数
   `strcpy(字符数组1，字符数组2)`
   * 作用：将字符串2复制到字符数组1中去。
   * 字符数组1必须定义得足够大，以便容纳被复制的字符串2。字符数组1的长度不应小于字符串2的长度。
   * “字符数组1”必须写成数组名形式，“字符串2”可以是字符数组名，也可以是一个字符串常量。
   * 若在复制前未对字符数组1初始化或赋值，则其各字节中的内容无法预知，复制时将字符串2和其后的′\0′一起复制到字符数组1中，取代字符数组1中前面的字符，未被取代的字符保持原有内容。
   * 不能用赋值语句将一个字符串常量或字符数组直接给一个字符数组。字符数组名是一个地址常量，它不能改变值，正如数值型数组名不能被赋值一样。
   * 可以用strncpy函数将字符串2中前面n个字符复制到字符数组1中去。

   ```c
   strncpy(str1, str2, 2);
   ```

   * 将str2中最前面2个字符复制到str1中，取代str1中原有的最前面2个字符。但复制的字符个数n不应多于str1中原有的字符（不包括′\0′）。
5. 字符串比较函数
   `strcmp(字符数组1，字符数组2)`
   * 作用：比较字符串1和字符串2。
   * 字符串比较的规则是: 将两个字符串自左至右逐个字符相比(按ASCII码值大小比较)，直到出现不同的字符或遇到′\0′为止。
     * 如全部字符相同，则认为两个字符串相等；
     * 若出现不相同的字符，则以第1对不相同的字符的比较结果为准。
     * 比较的结果由函数值带回。
       1. 如果字符串1与字符串2相同，则函数值为0。
       2. 如果字符串1>字符串2，则函数值为一个正整数。
       3. 如果字符串1<字符串2，则函数值为一个负整数。
   * **注意**：对两个字符串比较不能直接用str1>str2进行比较，因为str1和str2代表地址而不代表数组中全部元素，而只能用 (strcmp(str1，str2)>0)实现，系统分别找到两个字符数组的第一个元素，然后顺序比较数组中各个元素的值。
6. 测字符串长度的函数
   `strlen(字符数组名)`
   * 作用：测试字符串长度的函数。函数的值为字符串中的实际长度(不包括′\0′在内)。
7. 转换为大小写的函数
   `strlwr(字符串)`
   * 作用：将字符串中大写字母换成小写字母。
   `strupr(字符串)`
   * 作用：将字符串中小写字母换成大写字母。
8. **注意**：以上介绍了常用的8种字符串处理函数，它们属于库函数。库函数并非C语言本身的组成部分，而是C语言编译系统为方便用户使用而提供的公共函数。不同的编译系统提供的函数数量和函数名、函数功能都不尽相同，使用时要小心，必要时查一下库函数手册。
在使用字符串处理函数时，应当在程序文件的开头用`#include <string.h>`把string.h文件包含到本文件中。见字符串处理函数[详细内容](details.md)