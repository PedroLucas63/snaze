#include "Random.hpp"

void RandomPlayer::thinking(Snake snake_, Fruit fruit_) {
   /// Mapa de movimentos possíveis com peso (pegar ultimo movimento).
   /// Peso recebe 0 para movimento não cumulativo ao atual.
   /// Movimentos cumulativos são testados com o corpo (0 se conflito).
   /// Movimentos cumulativos são testados com o cenário (0 se conflito).
   /// Movimentos sem conflito desejados recebem incremento no peso:
      /// A fruta está a esquerda da cobra e o movimento a esquerda ainda é valido? Peso do left recebe +2.
      /// A fruta está a direita da cobra e o movimento a direita não é valido? Nada a fazer.
   /// Escolha de movimento de forma aleatória baseada nos pesos.
      /// Situação indefinida para todas posições com peso 0.
   /// Inclui o movimento a Stack e para.
}
