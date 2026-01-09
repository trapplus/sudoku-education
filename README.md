# Sudoku Education

Простая консольная игра в судоку на C++. Учебный проект.

## Что это?

Классическое судоку 9x9 через backtracking.

## Компиляция

```bash
cmake -B build -S .
cmake --build build
```

## Запуск

```bash
./build/Sudoku
```

## Структура

```
├── CMakeLists.txt
├── include
│   └── sudoku-education
│       ├── Board.h
│       ├── Engine.h
│       ├── Game.h
│       ├── Statistics.h
│       └── Validator.h
├── LICENSE
├── README.md
└── src
    ├── Board.cpp
    ├── Engine.cpp
    ├── Game.cpp
    ├── main.cpp
    ├── Statistics.cpp
    └── Validator.cpp
```

## Компоненты

- **Board** - игровое поле
- **Engine** - логика решения
- **Game** - игровой цикл
- **Validator** - проверка правил
- **Achivments** - рекорды и статистика 

## Зависимости

- C++20
- CMake 3.20+
- Clang/GCC

## TODO

[*] Game - Логика игры

[*] Engine - решение и управление, логика решения

[*] Validator - Вынесеная логика валидации ячейки

[ ] Statistic - Сбор статистики, отображение и храниение

## Лицензия

[GPL](LICENSE)
