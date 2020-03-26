#pragma once
int funcTester(int (*func)(char[]));
int funcArrayCharTester(int (*func)(char[], char), char ch);
void func2ArrayTester(int (*func)(char[], char[]), char ch[]);
int squeeze2Test();
int anyTest();
int htoi(char s[]);
int squeeze(char s[], int c);
int squeeze2(char s1[], char s2[]);
int any(char s1[], char s2[]);