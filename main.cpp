#include <iostream>
#include "Rook.hpp"

using namespace std;

int main() {
     // Test Default Constructor
     Rook r1;
     std::cout << "Default Rook: " << r1.getColor() << " at (" 
               << r1.getRow() << ", " << r1.getColumn() 
               << "), Castle Moves Left: " << r1.getCastleMovesLeft() << std::endl;
 
     // Test Parameterized Constructor
     Rook r2("WHITE", 0, 0, true, 2);
     std::cout << "Rook r2: " << r2.getColor() << " at (" 
               << r2.getRow() << ", " << r2.getColumn() 
               << "), Castle Moves Left: " << r2.getCastleMovesLeft() << std::endl;
 
     // Test Invalid Color
     Rook r3("1234", 1, 1, false, 3);
     std::cout << "Rook r3 (invalid color): " << r3.getColor() << " at (" 
               << r3.getRow() << ", " << r3.getColumn() 
               << "), Castle Moves Left: " << r3.getCastleMovesLeft() << std::endl;
 
     // Test Out-of-Bounds Position
     Rook r4("BLACK", -1, 8, false, 3);
     std::cout << "Rook r4 (out of bounds): " << r4.getColor() << " at (" 
               << r4.getRow() << ", " << r4.getColumn() 
               << "), Castle Moves Left: " << r4.getCastleMovesLeft() << std::endl;
 
     // Test canCastle() method
     Rook r5("WHITE", 0, 3, true, 1);
     Rook r6("WHITE", 0, 4, true, 1);
     std::cout << "Can r5 castle with r6? " << (r5.canCastle(r6) ? "Yes" : "No") << std::endl;
 
     // Test Invalid Castling (Different Colors)
     Rook r7("BLACK", 0, 4, true, 1);
     std::cout << "Can r5 castle with r7? " << (r5.canCastle(r7) ? "Yes" : "No") << std::endl;
 
     return 0;
}
