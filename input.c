// Функции и процедуры
int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void printPrimes(int limit) {
    int i, j;
    bool isPrime;

    for (i = 2; i <= limit; i++) {
        isPrime = true;
        j = 2;
        while (j * j <= i && isPrime) {
            if (i % j == 0) {
                isPrime = false;
            }
            Inc(j);
        }

        if (isPrime) {
            WriteLn("Prime: ", i);
        }
    }
}

// Основная программа
int main() {
    // Тест базовых типов
    int i, j, k;
    char c = 'A';
    bool flag = true;

    // Тест массивов
    int arr[5] = {10, 20, 30, 40, 50};
    bool bArr[3] = {true, false, true};
    char chArr[3] = {'x', 'y', 'z'};

    // Тест операций
    WriteLn("Arithmetic:");
    WriteLn(i, " + ", j, " = ", i + j);
    WriteLn(i, " - ", j, " = ", i - j);
    WriteLn(i, " * ", j, " = ", i * j);
    WriteLn(i, " / ", j, " = ", i / j);
    WriteLn(i, " % ", j, " = ", i % j);

    // Тест сравнений
    WriteLn("Comparisons:");
    WriteLn(i, " > ", j, " = ", i > j);
    WriteLn(i, " < ", j, " = ", i < j);
    WriteLn(i, " == ", j, " = ", i == j);
    WriteLn(i, " != ", j, " = ", i != j);

    // Тест логики
    WriteLn("Logic:");
    WriteLn("!flag = ", !flag);
    WriteLn("flag && false = ", flag && false);
    WriteLn("flag || false = ", flag || false);

    // Тест массивов
    WriteLn("Arrays:");
    for (k = 0; k < 5; k++) {
        Write("arr[", k, "] = ", arr[k], "  ");
    }
    WriteLn();

    // Тест функций
    WriteLn("Functions:");
    WriteLn("max(", i, ", ", j, ") = ", max(i, j));

    // Тест процедур
    WriteLn("Procedures:");
    printPrimes(20);

    // Тест системных функций
    WriteLn("System functions:");
    k = 5;
    Inc(k);
    WriteLn("After Inc: ", k);
    Dec(k, 2);
    WriteLn("After Dec: ", k);
    WriteLn("Abs(-10) = ", Abs(-10));

    // Тест ввода
    Write("Enter a number: ");
    ReadLn(i);
    WriteLn("You entered: ", i);

    // Тест do-while
    do {
        Write("Enter 0 to exit: ");
        ReadLn(j);
    } while (j != 0);

    return 0;
}