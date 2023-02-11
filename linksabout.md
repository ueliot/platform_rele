
# links about printf, sprintf, and floaring point

 * https://www.e-tinkers.com/2020/01/do-you-know-arduino-sprintf-and-floating-point/
 * https://en.wikipedia.org/wiki/Printf_format_string
 * https://cplusplus.com/reference/cstdio/printf/ 
 * https://www.programmingelectronics.com/sprintf-arduino/
 * https://www.esp32.com/viewtopic.php?t=10540
 * https://cpp.hotexamples.com/es/examples/-/WiFiClient/write/cpp-wificlient-write-method-examples.html
 * https://randomnerdtutorials.com/esp32-useful-wi-fi-functions-arduino/
 * https://randomnerdtutorials.com/esp32-web-server-arduino-ide/


# writing in wifi and serial
 ```
 char serbuf[512];  //Buffer for serial server
    //check UART for data, FIFO is 128 in size
    while ((bytesAvail = SerialSS.available()) > 0)
    {
        bytesIn = SerialSS.readBytes(serbuf, min(sizeof(serbuf), bytesAvail));
        if (bytesIn > 0)
        {
            //push UART data to connected telnet client
            if (tcpServerClient && tcpServerClient.connected())
            {
                tcpServerClient.write((uint8_t*)serbuf, bytesIn);
                tcpServerClient.flush(); //2018-11-10 BB: Try to force sending
                SerialDebug.println("Count: " + String(bytesIn)); //2018-11-10 BB: Show count
                delay(0); //Needed to stop wdt resetting on long operations
            }
        }
    }
```


# ======Otros codigos de concatenacion=====
```
//Concatena
        // Int n1=1,n2=2,n3;
        // char aux="";
        // strcat(aux,itoa(n1)); // concateno lo q hay en n1 (convertido en char) a aux
        // strcat(aux,itoa(n2)); // concateno lo q hay en n2 (convertido en char) a aux
        // n3=atoi(aux); // saco lo que tenia el aux





//Concatenar cadenas======================================
int entero = 5;
float decimal = 10.44;
char* cad = "abcde";
 
char buffer[200];
sprintf( buffer, "%s %d - %f", cad, entero, decimal );


en c++
int entero = 5;
float decimal = 10.44;
std::string cad = "abcde";
 
std::stringstream stream;
stream << cad << " " << entero << " - " << decimal;
 
std::string resultado = stream.str( )





//Mostrar el tamaño de una estructura
https://clibre.io/blog/por-secciones/codigo/item/424-calcular-tamano-en-c-sizeof-strlen-uso-y-errores-comunes 

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[])
{
    struct mis_datos_s {
        char dat_char[32];
        short int dat_sint[20];
        int dat_int[10];
        long dat_long;
        double dat_double[10];
    };

    struct mis_datos_s primer_dato = {};
    struct mis_datos_s varios_datos[10] = {};

    printf ("<mis_datos_s> tiene un tamaño de %zd bytes\n", sizeof (struct mis_datos_s));
    printf ("<primer_dato> tiene un tamaño de %zd bytes\n", sizeof (primer_dato));
    printf ("<varios_datos[0]> tiene un tamaño de %zd bytes\n", sizeof (varios_datos[0]));
    printf ("<varios_datos> tiene un tamaño de %zd bytes\n", sizeof (varios_datos));

    printf ("Numero de elementos en <varios_datos>: %zd\n",
            sizeof (varios_datos) / sizeof (varios_datos[0]));

    exit (EXIT_SUCCESS);
}

```

# more links:

- https://www.geeksforgeeks.org/how-to-empty-a-char-array-in-c/
- https://forum.arduino.cc/t/sprintf-zero-padding-with-byte-issue/43221/17 
- https://www.ibm.com/docs/en/zos/2.1.0?topic=programs-sprintf-format-write-data 




- https://cloud.google.com/community/tutorials/embedded-c-getting-started 
- https://www.upesy.com/blogs/tutorials/how-to-connect-wifi-acces-point-with-esp32 



# ============GOOGLE COLAB=============
- https://towardsdatascience.com/7-ways-to-load-external-data-into-google-colab-7ba73e7d5fc7
- https://research.google.com/colaboratory/local-runtimes.html 
- http://arbennett.github.io/software,/machine-learning/2021/08/18/ml_infrastructure_for_eess_beginners.html 
- https://stackoverflow.com/questions/66769956/how-to-get-raw-ipynb-file-from-google-colab-using-sharing-url-command-line 
- https://colab.research.google.com/github/Shaam93/Building-a-classifer-with-Pytorch/blob/master/Uploading_Data_to_Google_Colab.ipynb
- https://anderfernandez.com/en/blog/how-to-code-gan-in-python/
- https://research.google.com/colaboratory/local-runtimes.html


- https://colab.research.google.com/drive/1Je1rk7olA9uTWWaqvvt4_gXf7yX1rTBm 
- https://colab.research.google.com/drive/1-Jb_E_nDuBGHIJ_psI95k-ukh-P_aly-
- https://dagshub.com/blog/reverse-engineering-google-colab/




