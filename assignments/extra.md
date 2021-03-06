# Доп Задачи

### Task 1. Слоники*
###### 4 points

У вас имеется пустая шахматная доска размером n x n клеток, а также бесконечное количество [слонов](https://ru.wikipedia.org/wiki/%D0%A1%D0%BB%D0%BE%D0%BD_(%D1%88%D0%B0%D1%85%D0%BC%D0%B0%D1%82%D1%8B))(bishop).  
Вам нужно поместить минимальное количество слонов на доску так, чтобы все клетки были "под боем".  
Выведите на экран минимальное кол-во слонов.
Пример для поля 4 x 4:  
![image](https://user-images.githubusercontent.com/23273750/110202343-781a8780-7e9a-11eb-992f-918e6694a3ca.png)

[Может помочь](https://lichess.org/editor/8/8/8/8/8/8/8/8_w_-_-_0_1)

Вход: 
 - int n - размерность доски

Выход:
 - Количество слонов

Пример:
 | Входные данные  | Выход|
|------------------|------|
| 4 | 4 |


### Task 2. 0XFF
###### 0xFFFFFFFF points

Создайте переменную типа int со значением 0xFFFFFFFF. Выведите значение на экран используя целочисленный спецификатор %d.

Выход:
 - %d 0xFFFFFFFF

### Task 3. Reverse Easy*
###### 10 points

Reverse engineering - одно из основных направлений в компьютерной безопасности. Так называется исследование какого либо устройства или программы с целью понять ее работу. Например с помощью обратной разработки исследуют вирусные программы, исследуют софт конкурентов, пишут различные патчи. Вам представилась возможность попробовать свои силы в качестве настоящего реверс-инжинера.  

##### Задача:  
Исследуя просторы сети вы наткнулись на вирус-шифровальщик! Все ваши файлы были зашифрованы, а автор вируса требует у вас выкуп в размере 0.1 BTC (~360000 р). К счастью, разработчик вируса не зашифровал сам исполняемый файл вируса. Вы загружаете его в специальную программу - _дизассемблер_ - и получаете следующий ассемблерный код.

```asm
.LC0:
        .string "Здесь была строка, ваша задача узнать какая"
        .string ""
main:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 32
        mov     rax, QWORD PTR .LC0[rip]
        mov     QWORD PTR [rbp-24], rax
        mov     DWORD PTR [rbp-12], 7
        mov     DWORD PTR [rbp-16], 10
        mov     DWORD PTR [rbp-4], 0
        jmp     .L2
.L5:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        movzx   eax, BYTE PTR [rbp-24+rax]
        mov     BYTE PTR [rbp-5], al
        mov     eax, DWORD PTR [rbp-4]
        and     eax, 1
        test    eax, eax
        je      .L3
        mov     eax, DWORD PTR [rbp-12]
        xor     BYTE PTR [rbp-5], al
        jmp     .L4
.L3:
        mov     eax, DWORD PTR [rbp-16]
        xor     BYTE PTR [rbp-5], al
.L4:
        mov     eax, DWORD PTR [rbp-4]
        cdqe
        movzx   edx, BYTE PTR [rbp-5]
        mov     BYTE PTR [rbp-24+rax], dl
        add     DWORD PTR [rbp-4], 1
.L2:
        cmp     DWORD PTR [rbp-4], 6
        jle     .L5
        lea     rax, [rbp-24]
        mov     rdi, rax
        call    puts
        mov     eax, 0
        leave
        ret
```

Прочитайте ассемблерный листинг, поймите что делает программа, восстановите секрет из 7 символов, если после шифрования получилась строка `^HEBKTS`

##### Hint

Вам может помочь https://godbolt.org/. Используйте следующие параметры:  
![image](https://user-images.githubusercontent.com/23273750/110287528-41b74680-8019-11eb-9a8c-7bebcb05343d.png)

##### Hint

Реверс-инжиниринг это не олимпиадные задачки, все что вам нужно сделать это кропотливо и медленно рассмотреть инструкцию за инструкцией. Не держите вещи в голове, записывайте комментарии по ходу разбора. Не смотря на кажущуюся краткость листинга, запутаться в нем очень легко!

##### Hint

Для декодирования / кодирования используйте таблицу ASCII

##### Hint

Секрет это строка из 7 символов A-Z (только заглавные)

### Task 4. Вес булева вектора
###### 4 points

Весом булева вектора называют количество единиц в нем. Всякое число можно записать в виде бинарного вектора (переведя в двоичную систему счисления).  
На вход вам поступает целое положительное число. Найдите вес соответствующего ему вектора.

Вход: 
 - unsigned int a

Выход:
 - Кол-во единичных разрядов

Пример:

```
33 -> 2 (33 = 0b100001)
255 -> 8 (255 = 0b11111111)
256 -> 1 (256 = 0b100000000)
```
