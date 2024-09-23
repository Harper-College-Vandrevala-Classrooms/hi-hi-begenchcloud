#include <iostream>
#include <cctype>
#include <string>
#include <cassert>

using namespace std;


int strcmp_case_insensitive(const string &word1, const string &word2) {
    int lngth1 = word1.length();
    int lngth2 = word2.length();
    int min;

    if (lngth1 < lngth2)
    {
        min = lngth1;
    } else{
        min = lngth2;
    }


    for (int i = 0; i < min; ++i) {
        char character1 = tolower(word1[i]);
        char character2 = tolower(word2[i]);
        
        if (character1 < character2){
            return -1;
        }
        if (character1 > character2){
            return 1;
        }
    }


    if (lngth1 < lngth2) {
        return -1;
    }
    if (lngth1 > lngth2) {
        return 1;
    }

    return 0;
}

int main() {

    assert(strcmp_case_insensitive("Hello", "heLlo") == 0);
    assert(strcmp_case_insensitive("hello", "Worldddd") < 0);
    assert(strcmp_case_insensitive("woRld", "hello") > 0);

    cout << "All test cases passed!" << endl;

    return 0;
}
