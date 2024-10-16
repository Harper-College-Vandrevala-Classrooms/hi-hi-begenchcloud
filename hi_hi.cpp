#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;


int strcmp_case_insensitive(const string &word1, const string &word2) {
    string s1 = word1;
    string s2 = word2;
    int min;


    s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
    s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());

    int lngth1 = s1.length();
    int lngth2 = s2.length();

    if (lngth1 < lngth2)
    {
        min = lngth1;
    } else{
        min = lngth2;
    }


    for (int i = 0; i < min; ++i) {
        char character1 = tolower(s1[i]);
        char character2 = tolower(s2[i]);
        
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
    assert(strcmp_case_insensitive("My Cool String", "MyCoolString") == 0);
    assert(strcmp_case_insensitive("hello helo", "Worldddd worlddddDDdd") < 0);

    cout << "All test cases passed!" << endl;

    return 0;
}
