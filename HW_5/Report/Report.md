# Домашнее задание №5

Выполнил: Романцов Николай Сергеевич

Группа: БПИ-205

Вариант: 27

## Постановка задачи

Неправильные
пчелы, подсчитав в конце месяца убытки от наличия в лесу Винни-Пуха,
решили разыскать его и наказать в назидание всем другим любителям
сладкого. Для поисков медведя они поделили лес на участки, каждый из
которых прочесывает одна стая неправильных пчел. В случае нахождения
медведя на своем участке стая проводит показательное наказание и
возвращается в улей. Если участок прочесан, а Винни-Пух на нем не
обнаружен, стая также возвращается в улей. Требуется создать
многопоточное приложение, моделирующее действия пчел. При решении
использовать парадигму портфеля задач

## Реализация

В программе реализовано моделирование вышеописанного процесса.
Проводится сравнение использование многопоточного подхода и 
последовательного выполнения задачи

## Входные данные

* количество ячеек, на которые разделен лес.
* время, необходимое для поиска в одной ячейке(ms).

# Результаты


* n=20, t=100ms
  - с потоками: 115ms
  - без потоков: 2167ms
* n=20, t=500ms
  - с потоками: 515ms
  - без потоков: 10s
* n=50, t=100ms
  - с потоками: 118ms
  - без потоков: 5425ms
* n=50, t=300ms
   - с потоками: 311ms
   - без потоков: 15s
* n=8, t=300ms
    - с потоками: 317ms
    - без потоков: 2489ms
* n=8, t=1300ms
    - с потоками: 1315ms
    - без потоков: 10s

## Выводы

Использование многопоточного подхода дало значительное ускорение 
по времени для всех тестов.