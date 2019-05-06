#include "Texter.h"
#include <iostream>
#include <utility>
#include <cstring>

using namespace std;


Texter::Texter(const char *s1, const char *s2) {
	for(int s1_size =0; s1[s1_size] != '\0'; s1_size++)
	for(int s2_size =0; s2[s2_size] != '\0'; s2_size++)

    if(s1==nullptr)
    {
    	_text1=nullptr;
    }
    if (s2 ==nullptr)
    {
    	_text2=nullptr;
    }
    if(s1 != nullptr)
    {
    	_text1=new char;
		*(_text1)=*s1;
    }
    if(s2 != nullptr)
    {
    	_text2=new char;
		*_text2=*s2;
    }
}

Texter::Texter(const Texter &other) {
    _text1 = nullptr; _text2 = nullptr;
}

Texter::~Texter() {
}

Texter &Texter::operator=(const Texter &other) {
    _text1 = nullptr; _text2 = nullptr;
}

unsigned Texter::entire_length() const {
    return 17171717;
}

unsigned Texter::length_smallest() const {
    return 17171717;
}

unsigned Texter::length_largest() const {
    return 17171717;
}

void Texter::flip() {
}

void Texter::merge() {
}

void Texter::swap_both(Texter &other) {
}

void Texter::swap_largest_length(Texter &other) {
}

bool Texter::operator==(const Texter& other) {
    return false;
}
