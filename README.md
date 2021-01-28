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
## 3.Configurando STMCubeIDE
Depois de ter selecionado seu modelo de microcontrolador abrirá uma aba mostrando todos os pinos do seu STM. Utilize o diagrama de pinos a seguir para saber qual a entrada/saída mais adequada para o seu projeto.
![Pinos STM32](https://user-images.githubusercontent.com/65618285/106167939-7f989380-616c-11eb-9bd2-06dd7e41d248.png)

Após realizar toda a configuração de seus pinos clique em _**System Core**_ e vá em _**RCC**_

![System Core](https://user-images.githubusercontent.com/65618285/106168306-e158fd80-616c-11eb-81e1-965219a45dc8.png)

Nele mudaremos nosso _**High Speed Clock(HSE)**_ para _**Crystal/Ceramic Resonator**_, logo em seguida abra a _**Clock Configuration**_ e mude _**Input Frequency**_ para **16Mhz** e selecione o _**System Clock Mux**_ para o _**HSE**_.

![Árvore de Clock](https://user-images.githubusercontent.com/65618285/106169976-bec7e400-616e-11eb-935c-2581443b51fd.png)

Feito essas alterações iremos gerar nosso projeto, para isso clique em _**Project**_ e depois _**Generate Code**_.

![Gerando projeto](https://user-images.githubusercontent.com/65618285/106169898-a8ba2380-616e-11eb-9e07-953654e853de.png)

Agora que nosso código foi gerado pela IDE precisamos configurar mais duas opções para disponibilizar o uso de variáveis float na escrita e saída de dados. Abra novamente _**Projects**_ e depois _**Properties**_.

![Propriedades](https://user-images.githubusercontent.com/65618285/106171001-d5bb0600-616f-11eb-9a41-7ff12b5a05f3.png)

CLique em _**C/C++ Build**_ depois em _**Settings**_, _**MCU Settings**_ e marque as duas caixas da imagem.

![Permitindo floats](https://user-images.githubusercontent.com/65618285/106171405-4104d800-6170-11eb-8188-e75395d90f46.png)

Após isso, iremos em _**Build Steps**_ e colocaremos esse comando **arm-none-eabi-objcopy -0 ihex ${ProjName}.elf ${ProjName}.hex** em _**Post_build Steps, Command**_. Então só clicar em _**Apply and Close**_ que estará tudo configurado.

![Comando](https://user-images.githubusercontent.com/65618285/106171825-ce482c80-6170-11eb-9661-3227f9623762.png)




