# Sudoku Education

Простая консольная игра в судоку на C++. Учебный проект.

## Что это?

Классическое судоку 9x9.

## Установка

[Скачать](https://github.com/trapplus/sudoku-education/releases/tag/v1.0) подходящий под вашу систему файл, и запустить его


## Самостояятельная сборка

### Windows

#### Вариант 1: Chocolatey (рекомендуется)
```powershell
# Установи Chocolatey если его нет - 
https://chocolatey.org/install

# Установи CMake
choco install cmake

# Установи Visual Studio Build Tools или MinGW
choco install visualstudio2022buildtools
# ИЛИ
choco install mingw
```

#### Вариант 2: Вручную
1. **CMake**: Скачайте [CMake]( https://cmake.org/download/)
2. **Компилятор**:
   - [Visual Studio]( https://visualstudio.microsoft.com/downloads/)
   
   - [MinGW](https://www.mingw-w64.org/downloads/)


### Linux

#### Ubuntu/Debian
```bash
sudo apt update
sudo apt install build-essential cmake nlohmann-json3-dev
```

#### Arch Linux
```bash
sudo pacman -Sy base-devel cmake nlohmann-json
```

#### Fedora/RHEL
```bash
sudo dnf install gcc-c++ cmake json-devel
```

### macOS
```bash
# Установите Homebrew если его нет - https://brew.sh

brew install cmake nlohmann-json
```

## Компиляция

### Linux / macOS

```bash
git clone https://github.com/trapplus/sudoku-education.git
cd sudoku-education

cmake -B build -S .

cmake --build build

./build/Sudoku
```

### Windows (Visual Studio)

```PowerShell
# Откройте PowerShell или cmd в папке проекта

cmake -B build -S . -G "Visual Studio 17 2022"

cmake --build build --config Release

.\build\Release\Sudoku.exe
```



#### Компиляция

```bash
cmake -B build -S .
cmake --build build
```

#### Запуск

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

- [X] Game - Логика игры

- [X] Engine - решение и управление, логика решения

- [X] Validator - Вынесеная логика валидации ячейки

- [X] Statistic - Сбор статистики, отображение и храниение

## Лицензия

[GPL](LICENSE)
