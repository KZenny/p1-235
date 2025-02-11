// File: ChessPiece.cpp
// Author: Kenny Zhou
// Date: 2/10/2025
// A main file that tests out every function of the ChessPiece, Rook, and Pawn class. 

#include <iostream>
#include "ChessPiece.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"

int main() {
    //Default ChessPiece Constructor Test
    std::cout << "Default ChessPiece Default Constructor: " << std::endl;;
    ChessPiece test1;
    test1.display(); // BLACK piece is not on the board
    std::cout << std::endl;

    //Parameterized ChessPiece Constructor Test
    std::cout << "Parameterized ChessPiece Default Constructor: " << std::endl;
    ChessPiece test2("white", 2, 6, true); // WHITE piece at (2,6) is moving UP
    test2.display();
    ChessPiece test3("yell0w", 3,5,false); // BLACK piece at (3,5) is moving DOWN
    test3.display();
    ChessPiece test4("white", 100,100, true); // White piece is not on board
    test4.display();
    std::cout << std::endl;

    //ChessPiece Setters Test
    std::cout << "setColor() test: " << std::endl;
    test1.setColor("yellow"); // YELLOW piece is not on the board
    test1.display();
    test1.setColor("gr3en"); //  YELLOW piece is not on the board
    test1.display();
    std::cout << std::endl;

    std::cout << "setRow() test: " << std::endl;
    test2.setRow(5);
    test2.display(); //WHITE piece at (5,6) is moving UP
    test2.setRow(10);
    test2.display(); //WHITE piece is not on the board
    test2.setRow(5);
    std::cout << std::endl;

    std::cout << "setColumn() test: " << std::endl;
    test2.setColumn(1);
    test2.display(); //WHITE piece at (5,1) is moving UP
    test2.setColumn(10);
    test2.display(); //WHITE piece is not on the board
    std::cout << std::endl;

    std::cout << "setMovingUp() test: " << std::endl;
    test3.setMovingUp(true);
    test3.display(); // BLACK piece at (3,5) is moving UP
    std::cout << std::endl;

    //ChessPiece Getter Test
    std::cout << "getColor() test: " << std::endl;
    std::cout << test3.getColor() << std::endl; // BLACk
    std::cout << "getRow() test: " << std::endl;
    std::cout << test3.getRow() << std::endl; // 3
    std::cout << "getColumn() test: " << std::endl;
    std::cout << test3.getColumn() << std::endl; // 5
    std::cout << "isMovingUp() test: " << std::endl;
    std::cout << test3.isMovingUp() << std::endl; // TRUE/1
    std::cout << std::endl;

    //Pawn Default Constructor and canDoubleJump() Test
    std::cout << "Pawn Default Constructor test: " << std::endl;
    Pawn test5;
    test5.display(); //BLACK piece is not on the board
    std::cout << "canDoubleJump() test: " <<  test5.canDoubleJump() << std::endl; // FALSE/0
    std::cout << std::endl;

    //Pawn Parameterized Constructor and canDoubleJump() Test
    std::cout << "Parameterized Constructor test: " << std::endl;
    Pawn test6("white",1,1,false,true);
    test6.display(); // WHITE piece at (1,1) is moving DOWN
    std::cout << "canDoubleJump() test: " <<  test6.canDoubleJump() << std::endl; // TRUE/1
    Pawn test7("yell0w",2,2,false,true);
    test7.display(); // "BLACK piece at (2,2) is moving DOWN"
    std::cout << "canDoubleJump() test: " <<  test6.canDoubleJump() << std::endl; // TRUE/1
    Pawn test8("blue", 100, 100, true, true); 
    test8.display(); // "BLUE piece is not on the board"
    std::cout << "canDoubleJump() test: " <<  test6.canDoubleJump() << std::endl; // TRUE/1
    std::cout << std::endl;

    //toggleDoubleJump() and canPromote() test
    std::cout << "canPromote() test: " << std::endl;
    Pawn test9("white", 7, 1, true, false);  
    Pawn test10("black", 0, 6, false, true); 
    Pawn test11("black", 4, 4, false, false); 

    std::cout << test9.canPromote() << std::endl; // TRUE/1
    std::cout << test10.canPromote() << std::endl; // TRUE/1
    std::cout << test11.canPromote() << std::endl; //FALSE/0
    std::cout << std::endl;

    std::cout << "toggleDoubleJump() test: " << std::endl;
    test9.toggleDoubleJump();
    std::cout << test9.canDoubleJump() << std::endl; // TRUE/1
    test10.toggleDoubleJump();
    std::cout << test10.canDoubleJump() << std::endl; // FALSE/0
    std::cout << std::endl; 

    //Default Rook Constructor Test
    std::cout << "Default Rook Constructor test: " << std::endl;
    Rook test12;
    test12.display(); //BLACK piece is not on the board
    std::cout << test12.getCastleMovesLeft() << std::endl; // 3
    std::cout << std::endl;

    //Parameterized Rook Constructor Test
    std::cout << "Parameterized Rook Constructor test: " << std::endl;
    Rook test13("yellow", 2, 2, true, 4);
    test13.display(); // YELLOW piece at (2,2) is moving UP
    std::cout << test13.getCastleMovesLeft() << std::endl; // 4
    Rook test14("gre3n", 3, 3, true, 5); 
    test14.display();//BLACK piece at (3,3) is moving UP
    std::cout << test14.getCastleMovesLeft() << std::endl; // 5
    Rook test15("blue", -1, -1, true, 6); 
    test15.display();//BLUE piece is not on the board
    std::cout << test15.getCastleMovesLeft() << std::endl; // 6
    std::cout << std::endl;

    //canCastle() test
    std::cout << "canCastle() test: " << std::endl;
    Rook test16("white", 1,2,true,3);
    Rook test17("white",1,3,true,4);
    Rook test18("black", 1,2,false,3);
    Rook test19("white" , -1 , 1, true ,3);
    Rook test20("white" , 1 , -1, true ,3);
    Rook test21("white" , 1 , 1, true ,0);
    std::cout << test16.canCastle(test17) << std::endl; // TRUE/1 
    std::cout << test16.canCastle(test18) << std::endl; // FALSE/0 NOT SAME COLOR
    std::cout << test16.canCastle(test19) << std::endl; // FALSE/0 ROW OFF BOARD
    std::cout << test16.canCastle(test20) << std::endl; // FALSE/0 COLUMN OFF BOARD
    std::cout << test21.canCastle(test16) << std::endl; // FALSE/0 DOES NOT HAVE ANY CASTLE MOVES LEFT

    return 0;
}