main 
{
    int x, y, resultado;

    function int suma (int num1; int num2) 
    {
        int n, m;

        m = 2;
        n = 2;
        n = n + 1;

        m = 0;
        while ( m <= 4 ){
            printf m;

            n = 0;
            while ( n <= 4 ){
                printf m;
                n = n + 1;

                if (n>2)  {
                    printf n;
                    printf 9999;
                }
            }

            m = m + 1;
        }
		return num1+num2;

	}

    x = 1;
	y = 3;
	
	resultado = suma (x,y);
	printf resultado;


    
}