#include <cassert>

unsigned int length(const char *str)
{
    if (str == nullptr)
        return 0;
    const char *c = str;
    while (*c != '\0')
        ++c;
    return c - str;
}

// проверка строки на полиндом
bool palindrome(const char *str)
{
    int j = 0;
    int n = length(str) - 1;
    for (int i = 0; j = n; i <= j, i++, j--)
    {
        if (str[i] != str[j])
            return false;
    }

    return true;
}

int main()
{
    assert(palindrome(nullptr) == true);
    assert(palindrome(" ") == true);
    assert(palindrome("a") == true);
    assert(palindrome("politech") == false);
    assert(palindrome("mama") == false);
    assert(palindrome(nullptr) == true);

    return 0;
}