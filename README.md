# RedeCAN
## Introdução
As instruções seguintes ajudam a como fazer uma programação do microcontrolador STM32 em C/C++ para a aplicação de Rede CAN. Dando-se da seguinte forma:
1. Requisitos
2. Instalação
3. Configuração
4. Código
## 1.Requisitos
* STM32F103C8
* STMCubeIDE
* Módulo CAN Bus
    * MCP2551
    * TJA1050
## 2.Instalando STMCubeIDE
### 2.1 Baixando o instalador
Para instalar o STMCubeIDE clique [aqui](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-ides/stm32cubeide.html) e escolha qual das opçoes deseja instalar. No caso será instalado a versão 1.5.1 para Windows.
![Versões STMCube](https://user-images.githubusercontent.com/65618285/105992189-8dbeb500-6083-11eb-9d3f-e2259412451e.png)
Após clicar em _**Get Software**_ abrirá a licença do programa.
![License](https://user-images.githubusercontent.com/65618285/105992586-14739200-6084-11eb-8915-2305537ca5eb.png)
Então, depois de ler a licença e aceitar abrirá mais uma aba para realizar o cadastro na STM. Essa parte é importante pois será enviado por e-mail o download do STMCubeIDE.
![Download](https://user-images.githubusercontent.com/65618285/105993035-9f548c80-6084-11eb-889d-5a628295590b.png)
Clique em _**Download**_ e espere a chegada do seguinte e-mail.
![E-mail](https://user-images.githubusercontent.com/65618285/105993588-5bae5280-6085-11eb-911a-e570ae3aa054.png)

Clique em _**Download Now**_ e você será encaminhado para uma aba do site da STM e o download de um arquivo .ZIP será feito.
### 2.2 Executando o instalador
Após ter baixado o .ZIP extraia e execute o .EXE e clique em _**Next**_.

![STM EXE](https://user-images.githubusercontent.com/65618285/105994332-44239980-6086-11eb-8d02-2e4c1eefda47.png)

Então será aberta uma aba para ler e aceitar mais uma licença, você deve aceitar para poder usar o software e depois será pedido o local de instalação dos arquivos. Em seguida surgirá a seguinte aba.

![Instalando STM](https://user-images.githubusercontent.com/65618285/106041945-33414b00-60bb-11eb-89a8-0beb5ba10b65.png)

Clique em _**Intall**_ e está tudo pronto.
### Abrindo STMCubeIDE pela primeira vez
Logo após abrir será requisitado um _Workspace_ para salvar os arquivo e depois clique em _**Launch**_.
![STMCubeIDE](https://user-images.githubusercontent.com/65618285/106042916-7223d080-60bc-11eb-835a-cdf948b820b2.png)
Clique em _**Start New STM32 project_**_ e abrirá a seguinte aba
![PartNumber](https://user-images.githubusercontent.com/65618285/106043257-e199c000-60bc-11eb-8e10-53264510c479.png)
Em _**Part Number**_ escreva o modelo do seu STM32, no caso usaremos o **STM32F103C8** e clique em _**Next**_, em seguida coloque o nome do seu projeto e clique em _**Finish**_.

**OBS:** Caso apareça uma opção perguntando se deseja usar _**Open Associated Perespective**_ selecione _**Yes**_.
## 3.Configurando os pinos
