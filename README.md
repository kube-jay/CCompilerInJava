# Компилятор подмножества языка C (Java + ANTLR)

Этот проект представляет собой простой компилятор ограниченного подмножества языка **C**, написанный на **Java** с использованием **ANTLR 4**.

### 📁 Структура проекта

- `src/main/antlr` — грамматика ANTLR для подмножества C
- `src/main/java/ru/vsu/cs/antlr` — сгенерированные лексер и парсер
- `src/main/java/ru/vsu/cs` — семантический анализ и логика компиляции
- `test/` — модульные тесты JUnit
- `input.c` — пример входной программы на языке C

### 🚀 Как запустить

Убедитесь, что установлена Java 17+ и ANTLR 4. Затем выполните генерацию:

```bash
java -jar lib/antlr-4.9.3-complete.jar -visitor -no-listener -o src/main/java/ru/vsu/cs/antlr src/main/antlr/CSubset.g4
