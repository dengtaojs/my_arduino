#ifndef XUANWEN_STRING_H
#define XUANWEN_STRING_H

class StringTools
{
public:
    static void ftoa(float n, char *res, int afterpoint);
    static void reverse(char *str, int len);

private:
    static int intToStr(int x, char *str, int d);
};

#endif