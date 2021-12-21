main {
    int m, n;
    array int[10] v;
    boolean b;

    m = 44;
    v[1] = 11;
    v[2] = m;
    printf v[2];
    v[2] = v[1];
    printf v[2];

    n = 2;
    v[n] = n*10;
    printf v[n];

    b = false;
    printf b;
    b = (44>11);
    printf b;

    n = 5;
    v[n] = n*10;
    printf v[n];

}