# Домашнее задание 06

[![Build Status](https://travis-ci.org/ithamsteri/homework_06.svg?branch=master)](https://travis-ci.org/ithamsteri/homework_06)
[![Build status](https://ci.appveyor.com/api/projects/status/ghu55vd93exbf55k?svg=true)](https://ci.appveyor.com/project/ithamsteri/homework-06)

## Условие задания

Спроектировать 2-мерную разряженную бесконечную матрицу заполненную значениями
по умолчанию. Матрица должна хранить только занятые элементы, те значения
которых хотя бы раз присваивались. Присвоение ячейки в значение по-умолчанию
освобождает ячейку.

Необходимо уметь отвечать на вопрос - сколько ячеек реально занято?

Необходимо уметь проходить по всем занятым ячейкам. Порядок не имеет значения.
Возвращается позиция ячейки и её значение.

При чтении элемента из свободной ячейки возвращать значение по-умолчанию.

Пример:

```cpp
Matrix<int, -1> matrix;     // бесконечная матрица int заполена значениями -1
assert(matrix.size() == 0); // все ячейки свободны

auto a = matrix[0][0];
assert(a == -1);
assert(matrix.size() == 0);

matrix[100][100] = 314;
assert(matrix[100][100] == 314);
assert(matrix.size() == 1);

// выведется одна строка:
// 100100314
for(auto c: matrix)
{
    int x, y, v;
    std::tie(x, y, v) = c;
    std::cout << x << y << v << std::endl;
}
```

При запуске программы необходимо создать матрицу с пустым значением 0,
заполнить главную диагональ матрицы (от [0,0] до [9,9]) значениями от 0 до 9.

```
0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0 0
0 0 0 3 0 0 0 0 0 0
0 0 0 0 4 0 0 0 0 0
0 0 0 0 0 5 0 0 0 0
0 0 0 0 0 0 6 0 0 0
0 0 0 0 0 0 0 7 0 0
0 0 0 0 0 0 0 0 8 0
0 0 0 0 0 0 0 0 0 9
```

Второстепенную диагональ (от [0,9] до [9,0]) значениями от 9 до 0.

```
0 0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 1 0
0 0 2 0 0 0 0 2 0 0
0 0 0 3 0 0 3 0 0 0
0 0 0 0 4 4 0 0 0 0
0 0 0 0 5 5 0 0 0 0
0 0 0 6 0 0 6 0 0 0
0 0 7 0 0 0 0 7 0 0
0 8 0 0 0 0 0 0 8 0
9 0 0 0 0 0 0 0 0 9
```

Необходимо вывести фрагмент матрицы от [1,1] до [8,8]. Между столбцами пробел.
Каждая строка матрицы на новой стоке консоли.

```
1 0 0 0 0 0 0 1
0 2 0 0 0 0 2 0
0 0 3 0 0 3 0 0
0 0 0 4 4 0 0 0
0 0 0 5 5 0 0 0
0 0 6 0 0 6 0 0
0 7 0 0 0 0 7 0
8 0 0 0 0 0 0 8
```

Вывести количество занятых ячеек.

Вывести все занятые ячейки вместе со своими позициями.

Опционально реализовать N-мерную матрицу.

Опционально реализовать каноническую форму оператора `=`, допускающую
выражения:

```cpp
((matrix[100][100] = 314) = 0) = 217
```

## Самоконтроль

* индексация оператором `[]`;
* количество занятых ячеек должно быть 18;
* пакет `matrix` с бинарным файлом `matrix` опубликован на JFrog Bintray.

## Проверка

Задание считается выполненным успешно, если после анализа кода, установки пакета
и запуска приложения появился фрагмент матрицы, количество ячеек и список всех
значений с позициями.

## Установка, сборка и тестирование

### Клонирование репозитория

```
git clone https://github.com/ithamsteri/homework_06
cd homework_06
git submodule update --init --recursive
```

### Установка пакета

Для Ubuntu Trusty нужно сделать следующее:

```shell
echo "deb http://dl.bintray.com/hamsterisoftware/deb-repo trusty main" | sudo tee -a /etc/apt/sources.list
sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys 379CE192D401AB61
sudo apt-get update && sudo apt-get install matrix
```
