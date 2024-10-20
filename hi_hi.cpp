#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <cassert>

using namespace std;


int strcmp_case_insensitive(const int &amount, const string &word1, const string &word2) {
    string s1 = word1;
    string s2 = word2;

    if (amount == 0) {
        return 0;
    }
    if (amount < 0) {
        return strcmp_case_insensitive(max(word1.length(), word2.length()), word1, word2);
    }


    s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
    s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());

    int lngth1 = s1.length();
    int lngth2 = s2.length();


    int comparison_limit = min({lngth1, lngth2, amount});

    for (int i = 0; i < comparison_limit; ++i) {
        char character1 = tolower(s1[i]);
        char character2 = tolower(s2[i]);

        if (character1 < character2) {
            return -1;
        }
        if (character1 > character2) {
            return 1;
        }
    }


    if (amount >= max(lngth1, lngth2)) {
        if (lngth1 < lngth2) {
            return -1;
        }
        if (lngth1 > lngth2) {
            return 1;
        }
    }

    return 0;
}

int main() {

    assert(strcmp_case_insensitive(5, "Hello", "heLlo") == 0);
    assert(strcmp_case_insensitive(5, "hello", "Worldddd") < 0);
    assert(strcmp_case_insensitive(5, "woRld", "hello") > 0);
    assert(strcmp_case_insensitive(5, "My Cool String", "MyCoolString") == 0);
    assert(strcmp_case_insensitive(5, "hello helo", "Worldddd worlddddDDdd") < 0);
    assert(strcmp_case_insensitive(20, "hello helo", "Worldddd worlddddDDdd") < 0);
    assert(strcmp_case_insensitive(0, "hello", "world") == 0);
    assert(strcmp_case_insensitive(-1, "hello", "world") < 0);
    assert(strcmp_case_insensitive(100, "Short", "Shorter") < 0);

    cout << "All test cases passed!" << endl;

    return 0;
}
