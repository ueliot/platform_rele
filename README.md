# Platform_rele

Description:

Controling PIN5 in ESP32 C3 Kit 
please see you platform.ini abut the board 
use wifi in local network.


https://techtutorialsx.com/2018/05/25/esp32-socket-server-controlling-a-relay-remotely/
https://github.com/espressif/arduino-esp32/tree/master/libraries/WiFi/examples 


Siempre usar al actualizar el repo:
```
git init

git add .

git commit -m "first commit"

git remote add origin https://github.com/NOMBRE_USUARIO/NOMBRE_PROYECTO.git

git push -u origin master

```


https://dev.to/iamjonathanpumares/configura-tu-entorno-de-desarrollo-de-manera-profesional-con-python-y-django-335g 


# Entornos virtuales en python

Creación de entornos virtuales con virtualenv
Python permite la creación de entornos virtuales mediante venv. Una solución que es útil cuando se desea probar diferentes paquetes, pero no permite seleccionar una versión diferente del intérprete. Para solucionar este problema se puede recurrir al paquete virtualenv que es necesario instalar mediante el siguiente comando

``` pip install virtualenv ```
Una vez hecho esto se pude comprobar que el paquete se ha instalado correctamente consultado la versión instalada.

``` virtualenv --version ```
En el caso de que este comando devuelve una versión se puede crear un nuevo entorno visual mediante el comando

``` virtualenv venv ```
donde venv es la ruta donde se creará este. Para cambiar al nuevo entorno solamente se deberá ejecutar

``` source venv/bin/activate ```
En el caso de que se desee trabajar en el entorno visual con una versión diferente de Python es necesario primero instalar esta, no lo hace virtualenv. Una vez instalado solamente se debe crear el entorno mediante el siguiente comando

``` virtualenv -p /path-to-python venv ```
En donde /path-to-python se debe reemplazar por la ruta al entorno que se desea usar. Este proceso puede ser un poco complicado, por lo que una solución más sencilla es usar conda.


# Crear entornos virtuales con conda
Una de las ventajas de conda es la posibilidad de crear entornos virtuales con diferentes versiones de Python de una forma sencilla. Simplemente se debe usar el comando create e indicar mediante la opción python la versión de Python que se desea usar en ese entorno. Por ejemplo, para crear un entorno con Python solamente se debería escribir

``` conda create -n venv-36 python=3.6  ```
Con lo que inmediatamente se creará el entorno e instalarán los recursos necesarios. Una vez hecho esto para cambiar de entorno solamente se deberá escribir

``` conda activate venv-36  ```
y para volver a la configuración por defecto




extension en vscode:   code runner    : muchos scripts de diferentes lenguajes
https://www.youtube.com/watch?v=aY1yzj7ewZM
https://www.youtube.com/watch?v=WjddCoWTqi8   //Entorno virtual



#  Referencia de variables en vscode
https://code.visualstudio.com/docs/editor/variables-reference 

You can also reference environment variables through the ${env:Name} syntax (for example, ${env:USERNAME}).
```
{
  "type": "node",
  "request": "launch",
  "name": "Launch Program",
  "program": "${workspaceFolder}/app.js",
  "cwd": "${workspaceFolder}",
  "args": ["${env:USERNAME}"]
}
```


