// File: ChessPiece.cpp
// Author: Kenny Zhou
// Date: 2/10/2025
// A source file that defines a class, ChessPiece that serves as a base class for the other chess pieces. It defines common attributes and behaviors.

#include <iostream>
#include <string> // for strings
#include <cctype> // for toupper() and isalpha()
#include <cstdlib> // for absolute value
#include "ChessPiece.hpp"
using namespace std;

    /**
    * @brief Default Constructor : All values 
    * Default-initializes all private members.  
    * Booleans are default-initialized to False. 
    * Default color : "BLACK"
    * Default row & columns: -1 (ie. represents that it has not been put on the board yet)
    */
ChessPiece::ChessPiece() : color_("BLACK"), row_(-1), column_(-1), movingUp_(false) {}

    /**
    * @brief Parameterized constructor.
    * @pre: 
    * @param : A const reference to the color of the Chess Piece (a string).
    *     Set the color "BLACK" if the provided string contains ANY non-alphabetic characters. 
    *     If the string is purely alphabetical, it is converted and stored in uppercase
    *     NOTE: We DO NOT supply a default value for color, the first parameter.
    *           Notice that if we do, we override the default constructor.
    * @param : The 0-indexed row position of the Chess Piece (as a const reference to an integer).
    *          Default value -1 if not provided.
    * @param : The 0-indexed column position of the Chess Piece (as a const reference to an integer).
    *          Default value -1.
    * @param : A flag indicating whether the Chess Piece is moving up on the board
    *          or not (as a const reference to a boolean). Default value False if not provided.
    * @post : The private members are set to the values of the corresponding parameters. 
    *   If the provided color parameter is invalid (ie. not alphabetic), it is set to "BLACK"
    *   If EITHER of the provided row or col are out-of-bounds, where the bounds are between 0 (inclusive)
    *      and BOARD_LENGTH (not inclusive), then BOTH are set to -1 (regardless of being in-bounds or not).
    */
    ChessPiece::ChessPiece(const string& color, const int& row, const int& column, const bool& movingUp) : row_(-1), column_(-1), movingUp_(movingUp){
        color_ = "";
        int colorLength = color.length();
        for (int i = 0; i < colorLength; i++){
            if(!isalpha(color[i])){ //If the parameter color is not all-alphabetical characters, sets the color to "BLACK" and breaks from for loop.
                color_ = "BLACK";
                break;
            }
            color_ += toupper(color[i]); //If the parameter passes until the end of for loop, sets the color to parameter color.
        }

        if (row >= 0 && row < BOARD_LENGTH && column >= 0 && column < BOARD_LENGTH) { 
            //If the parameter row and column is between 0 and BOARD_LENGTH, set these values to row_ and column_ 
            row_ = row;
            column_ = column;
        }
    }

    /**
    * @brief Gets the color of the chess piece.
    * @return std::string - The value stored in color_
    */
    string ChessPiece::getColor() const {
        return color_;
    }

        /**
    * @brief Gets the row position of the chess piece.
    * @return The integer value stored in row_
    */
    int ChessPiece::getRow() const {
        return row_;
    }

    /**
    * @brief Gets the column position of the chess piece.
    * @return The integer value stored in column_
    */
    int ChessPiece::getColumn() const {
        return column_;
    }

    /**
    * @brief Gets the value of the flag for if a chess piece is moving up
    * @return The boolean value stored in movingUp_
    */
    bool ChessPiece::isMovingUp() const {
        return movingUp_;
    }

    /**
    * @brief Sets the color of the chess piece.
    * @param color A const string reference, representing the color to set the piece to. 
    *     If the string contains non-alphabetic characters, the value is not set (ie. nothing happens)
    *     If the string is alphabetic, then all characters are converted and stored in uppercase
    * @post The color_ member variable is updated to the parameter value in uppercase
    * @return True if the color was set. False otherwise.
     */
    bool ChessPiece::setColor(const string& color) {
        string allUpperColor = "";
        int colorLength = color.length();
        for (int i = 0; i < colorLength; i++){
            if(!isalpha(color[i])){ //If the parameter color is not all-alphabetical characters, return false
                return false;
            }
            allUpperColor += toupper(color[i]);//If the parameter color is all-alphabetical, sets the allUpperColor to the parameter color(in caps`)
        }
        color_ = allUpperColor;
        return true;
    }

    /**
    * @brief Sets the row position of the chess piece 
    * @param row A const reference to an integer representing the new row of the piece
    *
    * If the supplied value is outside the board dimensions [0, BOARD_LENGTH), 
    *    the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
    */
    void ChessPiece::setRow(const int& row){
        if (row >= 0 && row < BOARD_LENGTH){ // If the value is within board dimensions, sets new row position to parameter
            row_ = row;
        } else {
            row_ = -1;
            column_ = -1;
        }
    } 

    /**
    * @brief Sets the column position of the chess piece 
    * @param row A const reference to an integer representing the new column of the piece
    *
    * If the supplied value is outside the board dimensions [0, BOARD_LENGTH),
    *  the ChessPiece is considered to be taken off the board, and its row AND column are set to -1 instead.
    */ 
    void ChessPiece::setColumn(const int& row) {
        if (row >= 0 && row < BOARD_LENGTH){
            column_ = row;
        } else {
            row_ = -1;
            column_ = -1;
        }
    }

    /**
    * @brief Sets the movingUp flag of the chess piece 
    * @param flag A const reference to an boolean representing whether the piece is now moving up or not
    */
    void ChessPiece::setMovingUp(const bool& movingUp) {
        movingUp_ = movingUp;
    }

    /**
    * @brief Displays the chess piece's information in the following format,
    *        if it is considered on the board (ie. its row and col are not -1):
    * <COLOR> piece at (row, col) is moving <UP / DOWN>\n
    * 
    * Otherwise an alternative format is used:
    * <COLOR> piece is not on the board\n
    * @note "\n" just means endline in this case. Please use "std::endl," don't print out the text "\n".
    * Example output 1:
      BLACK piece at (2,4) is moving UP
      Example output 2:
      WHITE piece is not on the board
    */
    void ChessPiece::display() const{
    if(row_ != -1 && column_ != -1 && movingUp_){
        cout << color_ << " piece at (" << row_ << "," << column_ << ") is moving UP" << endl;
    } else if (row_ != -1 && column_ != -1 && !movingUp_) {
        cout << color_ << " piece at (" << row_ << "," << column_ << ") is moving DOWN" << endl;
    } else {
        cout << color_ << " piece is not on the board" << endl;
    }
  } 