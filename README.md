# algoritmos_de_ordenacao_n*log(n)

Alunos: <br/>
**Marcelo Araujo dos Santos     16/0035481** <br/>
**Joberth Rogers Tavares Costa  16/0128013**

Algoritmos implementados:
* Radix, Heap, Merge e Quick sort

Para rodar o programa deve-se instalar a biblioteca graphics.h

*//////*  Como instalar a biblioteca graphics.h usando SDL  *//////*

Primeiro, deixe baixando um arquivo compactado (link abaixo) <br/>
http://download.savannah.gnu.org/releases/libgraph/libgraph-1.0.2.tar.gz


Instale build-essential executando no terminal <br/>
- sudo apt-get install build-essential

Instale outros pacotes com o comando abaixo <br/>
- sudo apt-get install libsdl-image1.2 libsdl-image1.2-dev guile-1.8 \ <br/>
  guile-1.8-dev libsdl1.2debian libart-2.0-dev libaudiofile-dev \ <br/>
  libesd0-dev libdirectfb-dev libdirectfb-extra libfreetype6-dev \ <br/>
  libxext-dev x11proto-xext-dev libfreetype6 libaa1 libaa1-dev \ <br/>
  libslang2-dev libasound2 libasound2-dev*

Agora extraia o arquivo que foi baixado 'libgraph-1.0.2.tar.gz'.

Entre na pasta do arquivo e rode esses comandos pelo terminal <br/>
- ./configure
- make
- sudo make install
- sudo cp /usr/local/lib/libgraph.* /usr/lib


Agora, para rodar o programa, baixe o projeto com o comando <br/>
- git clone https://github.com/marcelo046/algoritmo_ordenacao_lista2

Entre na pasta do projeto com <br/>
- cd algoritmo_ordenacao_lista2

Compile o programa com <br/>
- gcc main.c -o saida -lgraph

E finalmente execute o programa com <br/>
- ./saida



Para aprender mais sobre a biblioteca graphics.h <br/>
https://www.programmingsimplified.com/c/graphics.h
