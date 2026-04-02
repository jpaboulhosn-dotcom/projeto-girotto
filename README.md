Me chamo João Paulo e esse é um projeto desenvolvido para fins acadêmicos, com foco no aprendizado de lógica de programação em C a pedido do professor Pedro giroto do CESUPA. 
Este projeto tem como objetivo praticar conceitos fundamentais de programação em C por meio de minijogos, como:

Estruturas condicionais (if/else);
Estruturas de repetição (while, do while);
Uso de funções (void);
Vetores;
Entrada e saída de dados (scanf e printf);
Geração de números aleatórios (rand).


O primeiro jogo (Pergunta e resposta) é um quiz simples de perguntas básicas que consegui fazer usando somente os comandos:(printf,scanf,if e else).

O segundo jogo (Cobra na caixa!) já é um jogo mais interessante porque envolve aleatoriedade e dois jogadores. Nele, já foi preciso usar comandos mais compolexos, como o while, for e void.
Ele contém:
7 nomes pré-definidos;
sorteio de quem começa;
posições aleatórias da cobra e do botão;
loop até alguém ganhar ou perder;
opção de jogar novamente.
Nesse jogo precisei usar o chatgpt para entender melhor o comando "void" e como aplicá-lo.

O terceiro jogo (Gousmas war), é um jogo estratégico por turnos entre dois jogadores. A respeito da mecânica, O jogo é baseado em turnos alternados entre os dois jogadores. Em cada rodada, o jogador pode escolher entre duas ações:
Atacar:
Uma Gousma do jogador ataca uma Gousma adversária, somando seu nível de fúria ao inimigo. Caso o nível de fúria da Gousma atacada ultrapasse 5, ela é destruída.
Dividir:
O jogador pode dividir uma de suas Gousmas, transferindo parte da fúria para uma nova Gousma. Essa ação só é possível se houver espaço disponível (máximo de duas Gousmas por jogador) e se a fúria for suficiente.
Nesse código, precisei usar o chatgpt para entender melhor como usar funções, por exemplo: gousmasWar(), a qual usei para controlar o fluxo principal do jogo e a função mostrarStatus(), que exibe o estado atual das Gousmas.

O desenvolvimento deste projeto permitiu aplicar, na prática, diversos conceitos fundamentais da programação em linguagem C, como estruturas de decisão, repetição, uso de funções e manipulação de dados. 
Cada jogo apresenta características distintas — desde lógica simples de perguntas e respostas até mecânicas mais estratégicas e interativas — contribuindo para o desenvolvimento do raciocínio lógico e da resolução de problemas.
