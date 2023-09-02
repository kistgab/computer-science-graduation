# Manage a Queue data structure

- Função que insere nodo na FILA (Inserção)
- Função que remove um nodo da FILA (Remoção)
- Função que consulta nodo da FILA (Acesso)

```
Algoritmo InserirFilaArr
   Entradas:  Fila (TipoFila)
              LI, LS, IF, FF (inteiros)
              Info (TipoNodo)
   Saídas: IF, FF (inteiros)
           Sucesso (lógico)
Início
   Se (FF ≠ IF - 1) e ((IF ≠ LI)  ou  (FF ≠ LS))
   Então
      Início
         Se IF = LI - 1
         Então
            IF ← FF ← LI  { INSERÇÃO DO PRIMEIRO NODO }
         Senão
            Se FF = LS
            Então
               FF ← LI  { INSERÇÃO NO INÍCIO }
            Senão
               FF ← FF + 1  { INSERÇÃO NO MEIO OU ATRÁS }
            FILA[FF] ← Info
            Sucesso ← Verdadeiro
         Fim
      Fim
   Senão
      Sucesso ← Falso
Fim

```
