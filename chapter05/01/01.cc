int main()
{
    char *pc;
    int s[10];
    int (&r)[10] = s;
    const char *ps = "abc";
    char **pp;
    const int i = 1;
    const int *pci = &i;
    int j = 2;
    int * const cpi = &j;

    return 0;
}
