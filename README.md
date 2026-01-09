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
│       └── Validator.h
├── LICENSE
├── README.md
└── src
    ├── Board.cpp
    ├── Engine.cpp
    ├── Game.cpp
    ├── main.cpp
    └── Validator.cpp
```

## Компоненты

- **Board** - игровое поле
- **Engine** - логика решения
- **Game** - игровой цикл
- **Validator** - проверка правил
- **Achivments** - рекорды, их запись, отслеживание, просмотр

## Зависимости

- C++20
- CMake 3.20+
- Clang/GCC

## Лицензия

MIT
