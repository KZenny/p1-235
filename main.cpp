// File: ChessPiece.cpp
// Author: Kenny Zhou
// Date: 2/10/2025
// A main file that tests out every function of the ChessPiece, Rook, and Pawn class. 

#include <iostream>
#include "ChessPiece.hpp"
#include "Rook.hpp"
#include "Pawn.hpp"
using namespace std;

int main() {
    //Default ChessPiece Constructor Test
    cout << "Default ChessPiece Default Constructor: " << endl;
    ChessPiece test1;
    test1.display(); // BLACK piece is not on the board
    cout << endl;

    //Parameterized ChessPiece Constructor Test
    cout << "Parameterized ChessPiece Default Constructor: " << endl;
    ChessPiece test2("white", 2, 6, true); // WHITE piece at (2,6) is moving UP
    test2.display();
    ChessPiece test3("yell0w", 3,5,false); // BLACK piece at (3,5) is moving DOWN
    test3.display();
    ChessPiece test4("white", 100,100, true); // White piece is not on board
    test4.display();
    cout << endl;

    //ChessPiece Setters Test
    cout << "setColor() test: " << endl;
    test1.setColor("yellow"); // YELLOW piece is not on the board
    test1.display();
    test1.setColor("gr3en"); //  YELLOW piece is not on the board
    test1.display();
    cout << endl;

    cout << "setRow() test: " << endl;
    test2.setRow(5);
    test2.display(); //WHITE piece at (5,6) is moving UP
    test2.setRow(10);
    test2.display(); //WHITE piece is not on the board
    test2.setRow(5);
    cout << endl;

    cout << "setColumn() test: " << endl;
    test2.setColumn(1);
    test2.display(); //WHITE piece at (5,1) is moving UP
    test2.setColumn(10);
    test2.display(); //WHITE piece is not on the board
    cout << endl;

    cout << "setMovingUp() test: " << endl;
    test3.setMovingUp(true);
    test3.display(); // BLACK piece at (3,5) is moving UP
    cout << endl;

    //ChessPiece Getter Test
    cout << "getColor() test: " << endl;
    cout << test3.getColor() << endl; // BLACk
    cout << "getRow() test: " << endl;
    cout << test3.getRow() << endl; // 3
    cout << "getColumn() test: " << endl;
    cout << test3.getColumn() << endl; // 5
    cout << "isMovingUp() test: " << endl;
    cout << test3.isMovingUp() << endl; // TRUE/1
    cout << endl;

    //Pawn Default Constructor and canDoubleJump() Test
    cout << "Pawn Default Constructor test: " << endl;
    Pawn test5;
    test5.display(); //BLACK piece is not on the board
    cout << "canDoubleJump() test: " <<  test5.canDoubleJump() << endl; // FALSE/0
    cout << endl;

    //Pawn Parameterized Constructor and canDoubleJump() Test
    cout << "Parameterized Constructor test: " << endl;
    Pawn test6("white",1,1,false,true);
    test6.display(); // WHITE piece at (1,1) is moving DOWN
    cout << "canDoubleJump() test: " <<  test6.canDoubleJump() << endl; // TRUE/1
    Pawn test7("yell0w",2,2,false,true);
    test7.display(); // "BLACK piece at (2,2) is moving DOWN"
    cout << "canDoubleJump() test: " <<  test6.canDoubleJump() << endl; // TRUE/1
    Pawn test8("blue", 100, 100, true, true); 
    test8.display(); // "BLUE piece is not on the board"
    cout << "canDoubleJump() test: " <<  test6.canDoubleJump() << endl; // TRUE/1
    cout << endl;

    //toggleDoubleJump() and canPromote() test
    cout << "canPromote() test: " << endl;
    Pawn test9("white", 7, 1, true, false);  
    Pawn test10("black", 0, 6, false, true); 
    Pawn test11("black", 4, 4, false, false); 

    cout << test9.canPromote() << endl; // TRUE/1
    cout << test10.canPromote() << endl; // TRUE/1
    cout << test11.canPromote() << endl; //FALSE/0
    cout << endl;

    cout << "toggleDoubleJump() test: " << endl;
    test9.toggleDoubleJump();
    cout << test9.canDoubleJump() << endl; // TRUE/1
    test10.toggleDoubleJump();
    cout << test10.canDoubleJump() << endl; // FALSE/0
    cout << endl; 

    //Default Rook Constructor Test
    cout << "Default Rook Constructor test: " << endl;
    Rook test12;
    test12.display(); //BLACK piece is not on the board
    cout << test12.getCastleMovesLeft() << endl; // 3
    cout << endl;

    //Parameterized Rook Constructor Test
    cout << "Parameterized Rook Constructor test: " << endl;
    Rook test13("yellow", 2, 2, true, 4);
    test13.display(); // YELLOW piece at (2,2) is moving UP
    cout << test13.getCastleMovesLeft() << endl; // 4
    Rook test14("gre3n", 3, 3, true, 5); 
    test14.display();//BLACK piece at (3,3) is moving UP
    cout << test14.getCastleMovesLeft() << endl; // 5
    Rook test15("blue", -1, -1, true, 6); 
    test15.display();//BLUE piece is not on the board
    cout << test15.getCastleMovesLeft() << endl; // 6
    cout << endl;

    //canCastle() test
    cout << "canCastle() test: " << endl;
    Rook test16("white", 1,2,true,3);
    Rook test17("white",1,3,true,4);
    Rook test18("black", 1,2,false,3);
    Rook test19("white" , -1 , 1, true ,3);
    Rook test20("white" , 1 , -1, true ,3);
    Rook test21("white" , 1 , 1, true ,0);
    cout << test16.canCastle(test17) << endl; // TRUE/1 
    cout << test16.canCastle(test18) << endl; // FALSE/0 NOT SAME COLOR
    cout << test16.canCastle(test19) << endl; // FALSE/0 ROW OFF BOARD
    cout << test16.canCastle(test20) << endl; // FALSE/0 COLUMN OFF BOARD
    cout << test21.canCastle(test16) << endl; // FALSE/0 DOES NOT HAVE ANY CASTLE MOVES LEFT

    return 0;
}