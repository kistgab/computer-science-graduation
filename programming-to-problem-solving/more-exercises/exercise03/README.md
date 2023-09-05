# Sistema Bolão

Zeca está organizando um bolão de futebol.
Segundo suas regras, os apostadores informam o placar do jogo e ganham 10 pontos se acertarem o vencedor ou se acertarem que foi empate, e ganham mais 5 pontos para o placar de cada time que acertarem.

A tabela a seguir dá um exemplo, considerando que o placar real foi 3x2:

Placar Apostado Pontos Justificativa
0x1 0 Não acertou nada
0x2 5 Acertou o número de gols do segundo time
3x5 5 Acertou o número de gols do primeiro time
1x0 10 Acertou o vencedor mas errou os gols
3x1 15 Acertou o vencedor e o número de gols do primeiro time
3x2 20 Acertou tudo

Escreva um programa que requisita do usuário o placar apostado e depois o placar do jogo e informa quantos pontos o apostador fez.
