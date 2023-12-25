#pragma once
#include "../bigint/bigint.cpp"

const int MAXITERATION = 50;		//Maximum iterates before make decision

int task1(int lastNumber);
int task2(int searched);

bool isItLychrelNumber(BigInt inspected);
bool isItPalindrom(BigInt& number);
BigInt reverse(BigInt& number);