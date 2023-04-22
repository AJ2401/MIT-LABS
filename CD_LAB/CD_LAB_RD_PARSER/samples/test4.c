main()
{
    int x;
    int i;
    int first, second, current;
    
    x = 10;
    first = 0;
    second = 1;
    current = second;
    i = 2;
    while(i < x)
    {
        current = first + second;
        first = second;
        second = current;
    }
}