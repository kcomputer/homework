#pragma once


const char move[5][8] =
{ 
    { 0, 0, 8, 0, 8, 0, 0, 8 },
	{ 9, 0, 9, 0, 9, 6, 0, 9 },
	{ 2, 2, 2, 4, 4, 7, 7, 7 },
	{ 0, 0, 3, 0, 0, 0, 0, 0 },
	{ 0, 0, 5, 0, 5, 0, 0, 0 }
};

bool parse(const char *expression);
bool plusMinusRule(const char *&expression);
bool multiDivRule(const char *&expression);
bool bracketsRule(const char *&expression);