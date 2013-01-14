void func1(char *, int &);
typedef void (*p_func)(char *, int &);
p_func p_func1;
void func2(p_func);
p_func func3(void);

p_func func4(p_func p_func1)
{
    return p_func1;
}

int main()
{
    return 0;
}
