## Практическая работа №5. 
# Наследование и полиморфизм

В работе необходимо реализовать иерархию классов для заданного базового типа.
В качестве базового класса можно использовать вариант из таблицы, либо предложить
свой собственный базовый класс и иерархию наследников (но отсутствующие в
таблице).

Помимо базового класса необходимо реализовать не менее 5 производных классов и
по крайней мере 3 уровня в иерархии (н-р, класс С наследует B, а класс B наследует
A). В иерархии необходимо ввести по крайней мере один абстрактный класс и
задействовать закрытое наследование для одного классов.

Структурировать программу следующим образом: каждый класс определяется двумя
файлами (н-р, Notebook.h и Notebook.cpp), файл main.cpp содержит код, связанный с
консольным меню; допускаются дополнительные файлы для структурирования кода.

В каждом классе ввести закрытые поля и открытые методы доступа к полям. По
крайней мере для одного из классов устраните возможность создания объектов с
помощью конструктора без параметров и конструктора копирования.

В базовом классе ввести виртуальный метод toString для получения информации об
объекте в формате строки, в производных классах ввести переопределение
виртуального метода.

Ввести статические элементы (функции и неконстантные поля) хотя бы в 3 классах.

В главном модуле main.cpp ввести динамический массив для возможности работы с
объектами разных типов. Число элементов определяется динамически при
взаимодействии с пользователем.

Для работы с объектами реализовать консольное меню. Предоставить пользователю
возможность ввода объектов произвольного типа и заполнения массива.

После ввода данных пользователь может получить следующую информацию, которая
определяется по заполненному массиву:
* количество объектов каждого типа (без учёта наследования и возможности
преобразования; например, Animal = 0, Mammal = 1, Tiger = 2, Elefant = 3);
* количество объектов заданного типа (с учётом наследования; например, для
Mammal получаем 6 (с учётом Tiger, Elefant);
* информация по всем объектам, а также по выбранному объекту (с помощью
toString);
* найти объекты, удовлетворяющие условию по какой-либо характеристике,
которая определена для всех типов в иерархии;
* найти объекты, удовлетворяющие условию по какой-либо характеристике,
которая определена только некоторых типов в иерархии.