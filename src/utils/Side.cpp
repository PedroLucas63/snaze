#include "Side.hpp"

bool cumulativeMovements(Side first_, Side second_) {
   if (first_ == Left && second_ == Right) {
      return false;
   } else if (first_ == Right && second_ == Left) {
      return false;
   } else if (first_ == Up && second_ == Down) {
      return false;
   } else if (first_ == Down && second_ == Up) {
      return false;
   }

   return true;
}