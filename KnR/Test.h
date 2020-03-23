#pragma once
int funcTester(int (*func)(char[]));
int funcArrayCharTester(int (*func)(char[], char), char ch);
void func2ArrayTester(int (*func)(char[], char[]), char ch[]);
int squeeze2Test();