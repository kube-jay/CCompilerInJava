package ru.vsu.cs;

import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.tree.*;
import java.nio.file.*;
import java.io.IOException;

public class CSubsetCompiler {
    public static void main(String[] args) {
        try {
            String inputFile = "input.c";
            String input = Files.readString(Paths.get(inputFile));

            CharStream inputStream = CharStreams.fromString(input);
            ru.vsu.cs.CSubsetLexer lexer = new ru.vsu.cs.CSubsetLexer(inputStream);

            // Создаем свой обработчик ошибок для лексера
            SyntaxErrorListener lexerErrorListener = new SyntaxErrorListener();
            lexer.removeErrorListeners();
            lexer.addErrorListener(lexerErrorListener);

            CommonTokenStream tokens = new CommonTokenStream(lexer);
            ru.vsu.cs.CSubsetParser parser = new ru.vsu.cs.CSubsetParser(tokens);

            // Создаем свой обработчик ошибок для парсера
            SyntaxErrorListener parserErrorListener = new SyntaxErrorListener();
            parser.removeErrorListeners();
            parser.addErrorListener(parserErrorListener);

            // Парсим
            ParseTree tree = parser.program();

            // Если были ошибки - выходим
            if (lexerErrorListener.hasErrors() || parserErrorListener.hasErrors()) {
                System.exit(1);
            }

            // Печатаем AST только если нет ошибок
            ASTPrinter printer = new ASTPrinter();
            printer.visit(tree);
            printer.printToConsole();

        } catch (NoSuchFileException e) {
            System.err.println("Файл не найден: " + e.getFile());
            System.exit(1);
        } catch (IOException e) {
            System.err.println("Ошибка ввода-вывода: " + e.getMessage());
            System.exit(1);
        } catch (Exception e) {
            System.err.println("Неожиданная ошибка: " + e.getMessage());
            e.printStackTrace();
            System.exit(1);
        }
    }
}