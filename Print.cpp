#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "Board.h"
#include "Print.h"

#define BLACK 0
#define WHITE 1

Print::Print(){

}

void Print::initSDL(){
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Struct.window = SDL_CreateWindow("Abbott Chess", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 765, 765, SDL_WINDOW_SHOWN);
    SDL_Struct.renderer = SDL_CreateRenderer(SDL_Struct.window, -1, 0);
}


void Print::printBoardToWindow(Board gameBoard){
    TTF_Font *font = TTF_OpenFont("font.ttf", 256);
    SDL_Texture *alphaA, *alphaB, *alphaC, *alphaD, *alphaE, *alphaF, *alphaG, *alphaH, *numeric1, *numeric2, *numeric3, *numeric4,
                *numeric5 ,*numeric6, *numeric7, *numeric8;
    SDL_Rect alphaRecA, alphaRecB, alphaRecC, alphaRecD, alphaRecE, alphaRecF, alphaRecG, alphaRecH, numericRec1, numericRec2,
             numericRec3, numericRec4, numericRec5, numericRec6, numericRec7, numericRec8;
    SDL_Surface *alphaSurfaceA = NULL;
    SDL_Surface *alphaSurfaceB = NULL;
    SDL_Surface *alphaSurfaceC = NULL;
    SDL_Surface *alphaSurfaceD = NULL;
    SDL_Surface *alphaSurfaceE = NULL;
    SDL_Surface *alphaSurfaceF = NULL;
    SDL_Surface *alphaSurfaceG = NULL;
    SDL_Surface *alphaSurfaceH = NULL;
    SDL_Surface *numericSurface1 = NULL;
    SDL_Surface *numericSurface2 = NULL;
    SDL_Surface *numericSurface3 = NULL;
    SDL_Surface *numericSurface4 = NULL;
    SDL_Surface *numericSurface5 = NULL;
    SDL_Surface *numericSurface6 = NULL;
    SDL_Surface *numericSurface7 = NULL;
    SDL_Surface *numericSurface8 = NULL;
    alphaRecA.x = 85;
    alphaRecA.y = 8 * 85;
    alphaRecA.w = 85;
    alphaRecA.h = 85;
    alphaSurfaceA = TTF_RenderText_Blended(font, "A", {157,128,0,255});
    alphaA = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceA);
    alphaRecB.x = 2* 85;
    alphaRecB.y = 8 * 85;
    alphaRecB.w = 85;
    alphaRecB.h = 85;
    alphaSurfaceB = TTF_RenderText_Blended(font, "B", {0,0,0,255});
    alphaB = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceB);
    alphaRecC.x = 3 * 85;
    alphaRecC.y = 8 * 85;
    alphaRecC.w = 85;
    alphaRecC.h = 85;
    alphaSurfaceC = TTF_RenderText_Blended(font, "C", {157,128,0,255});
    alphaC = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceC);
    alphaRecD.x = 4 * 85;
    alphaRecD.y = 8 * 85;
    alphaRecD.w = 85;
    alphaRecD.h = 85;
    alphaSurfaceD = TTF_RenderText_Blended(font, "D", {0,0,0,255});
    alphaD = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceD);
    alphaRecE.x = 5 * 85;
    alphaRecE.y = 8 * 85;
    alphaRecE.w = 85;
    alphaRecE.h = 85;
    alphaSurfaceE = TTF_RenderText_Blended(font, "E", {157,128,0,255});
    alphaE = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceE);
    alphaRecF.x = 6 * 85;
    alphaRecF.y = 8 * 85;
    alphaRecF.w = 85;
    alphaRecF.h = 85;
    alphaSurfaceF = TTF_RenderText_Blended(font, "F", {0,0,0,255});
    alphaF = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceF);
    alphaRecG.x = 7 * 85;
    alphaRecG.y = 8 * 85;
    alphaRecG.w = 85;
    alphaRecG.h = 85;
    alphaSurfaceG = TTF_RenderText_Blended(font, "G", {157,128,0,255});
    alphaG = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceG);
    alphaRecH.x = 8 * 85;
    alphaRecH.y = 8 * 85;
    alphaRecH.w = 85;
    alphaRecH.h = 85;
    alphaSurfaceH = TTF_RenderText_Blended(font, "H", {0,0,0,255});
    alphaH = SDL_CreateTextureFromSurface(SDL_Struct.renderer, alphaSurfaceH);
    numericRec1.x = 0;
    numericRec1.y = 7 * 85;
    numericRec1.w = 85;
    numericRec1.h = 85;
    numericSurface1 = TTF_RenderText_Blended(font,"1", {157,128,0,255});
    numeric1 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface1);
    numericRec2.x = 0;
    numericRec2.y = 6 * 85;
    numericRec2.w = 85;
    numericRec2.h = 85;
    numericSurface2 = TTF_RenderText_Blended(font,"2", {0,0,0,255});
    numeric2 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface2);
    numericRec3.x = 0;
    numericRec3.y = 5 * 85;
    numericRec3.w = 85;
    numericRec3.h = 85;
    numericSurface3 = TTF_RenderText_Blended(font,"3", {157,128,0,255});
    numeric3 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface3);
    numericRec4.x = 0;
    numericRec4.y = 4 * 85;
    numericRec4.w = 85;
    numericRec4.h = 85;
    numericSurface4 = TTF_RenderText_Blended(font,"4", {0,0,0,255});
    numeric4 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface4);
    numericRec5.x = 0;
    numericRec5.y = 3 * 85;
    numericRec5.w = 85;
    numericRec5.h = 85;
    numericSurface5 = TTF_RenderText_Blended(font,"5", {157,128,0,255});
    numeric5 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface5);
    numericRec6.x = 0;
    numericRec6.y = 2 * 85;
    numericRec6.w = 85;
    numericRec6.h = 85;
    numericSurface6 = TTF_RenderText_Blended(font,"6", {0,0,0,255});
    numeric6 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface6);
    numericRec7.x = 0;
    numericRec7.y = 85;
    numericRec7.w = 85;
    numericRec7.h = 85;
    numericSurface7 = TTF_RenderText_Blended(font,"7", {157,128,0,255});
    numeric7 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface7);
    numericRec8.x = 0;
    numericRec8.y = 0;
    numericRec8.w = 85;
    numericRec8.h = 85;
    numericSurface8 = TTF_RenderText_Blended(font,"8", {0,0,0,255});
    numeric8 = SDL_CreateTextureFromSurface(SDL_Struct.renderer, numericSurface8);
    int startPos = 1;
    int startPos2 = 2;
    for (int y = 0; y < 8; y++) {
        if(y%2 != 1){
            SDL_Rect rectOutside;
            rectOutside.x = 0;
            rectOutside.y = y * 85;
            rectOutside.w = 85;
            rectOutside.h = 85;
            SDL_SetRenderDrawColor(SDL_Struct.renderer, 157,128,0,255);
            SDL_RenderFillRect(SDL_Struct.renderer, &rectOutside);

        }
        for (int x = startPos2; x < 9; x+=2) {
            SDL_Rect rect;
            rect.x = x * 85;
            rect.y = y * 85;
            rect.w = 85;
            rect.h = 85;
            SDL_SetRenderDrawColor(SDL_Struct.renderer, 191, 32, 32, 255);
            SDL_RenderFillRect(SDL_Struct.renderer, &rect);
        }
        for (int x = startPos; x < 9; x+=2) {
            SDL_Rect rect;
            rect.x = x * 85;
            rect.y = y * 85;
            rect.w = 85;
            rect.h = 85;
            SDL_SetRenderDrawColor(SDL_Struct.renderer, 41, 81, 131, 255);
            SDL_RenderFillRect(SDL_Struct.renderer, &rect);
        }

        if(y%2 == 1){
            startPos = 1;
            startPos2 = 2;
        }
        else{
            startPos = 2;
            startPos2 = 1;

        }
    }
    for (int x = 0; x < 9; x+=2){
        SDL_Rect bottom;
        bottom.x = x * 85;
        bottom.y = 8 * 85;
        bottom.w = 85;
        bottom.h = 85;
        SDL_SetRenderDrawColor(SDL_Struct.renderer, 157,128,0,255);
        SDL_RenderFillRect(SDL_Struct.renderer, &bottom);
    }
    SDL_Texture *whiteRook;
    SDL_Surface *whiteRookSurface;
    whiteRookSurface = SDL_LoadBMP("images/whiteRook.bmp");
    whiteRook = SDL_CreateTextureFromSurface(SDL_Struct.renderer, whiteRookSurface);
    SDL_Texture *whiteKnight;
    SDL_Surface *whiteKnightSurface;
    whiteKnightSurface = SDL_LoadBMP("images/whiteKnight.bmp");
    whiteKnight = SDL_CreateTextureFromSurface(SDL_Struct.renderer, whiteKnightSurface);
    SDL_Texture *whiteBishop;
    SDL_Surface *whiteBishopSurface;
    whiteBishopSurface = SDL_LoadBMP("images/whiteBishop.bmp");
    whiteBishop = SDL_CreateTextureFromSurface(SDL_Struct.renderer, whiteBishopSurface);
    SDL_Texture *whiteQueen;
    SDL_Surface *whiteQueenSurface;
    whiteQueenSurface = SDL_LoadBMP("images/whiteQueen.bmp");
    whiteQueen = SDL_CreateTextureFromSurface(SDL_Struct.renderer, whiteQueenSurface);
    SDL_Texture *whiteKing;
    SDL_Surface *whiteKingSurface;
    whiteKingSurface = SDL_LoadBMP("images/whiteKing.bmp");
    whiteKing = SDL_CreateTextureFromSurface(SDL_Struct.renderer, whiteKingSurface);
    SDL_Texture *whitePawn;
    SDL_Surface *whitePawnSurface;
    whitePawnSurface = SDL_LoadBMP("images/whitePawn.bmp");
    whitePawn = SDL_CreateTextureFromSurface(SDL_Struct.renderer, whitePawnSurface);
    SDL_Texture *blackRook;
    SDL_Surface *blackRookSurface;
    blackRookSurface = SDL_LoadBMP("images/blackRook.bmp");
    blackRook = SDL_CreateTextureFromSurface(SDL_Struct.renderer, blackRookSurface);
    SDL_Texture *blackKnight;
    SDL_Surface *blackKnightSurface;
    blackKnightSurface = SDL_LoadBMP("images/blackKnight.bmp");
    blackKnight = SDL_CreateTextureFromSurface(SDL_Struct.renderer, blackKnightSurface);
    SDL_Texture *blackBishop;
    SDL_Surface *blackBishopSurface;
    blackBishopSurface = SDL_LoadBMP("images/blackBishop.bmp");
    blackBishop = SDL_CreateTextureFromSurface(SDL_Struct.renderer, blackBishopSurface);
    SDL_Texture *blackQueen;
    SDL_Surface *blackQueenSurface;
    blackQueenSurface = SDL_LoadBMP("images/blackQueen.bmp");
    blackQueen = SDL_CreateTextureFromSurface(SDL_Struct.renderer, blackQueenSurface);
    SDL_Texture *blackKing;
    SDL_Surface *blackKingSurface;
    blackKingSurface = SDL_LoadBMP("images/blackKing.bmp");
    blackKing = SDL_CreateTextureFromSurface(SDL_Struct.renderer, blackKingSurface);
    SDL_Texture *blackPawn;
    SDL_Surface *blackPawnSurface;
    blackPawnSurface = SDL_LoadBMP("images/blackPawn.bmp");
    blackPawn = SDL_CreateTextureFromSurface(SDL_Struct.renderer, blackPawnSurface);
    SDL_RenderCopy(SDL_Struct.renderer, alphaA, NULL, &alphaRecA);
    SDL_RenderCopy(SDL_Struct.renderer, alphaB, NULL, &alphaRecB);
    SDL_RenderCopy(SDL_Struct.renderer, alphaC, NULL, &alphaRecC);
    SDL_RenderCopy(SDL_Struct.renderer, alphaD, NULL, &alphaRecD);
    SDL_RenderCopy(SDL_Struct.renderer, alphaE, NULL, &alphaRecE);
    SDL_RenderCopy(SDL_Struct.renderer, alphaF, NULL, &alphaRecF);
    SDL_RenderCopy(SDL_Struct.renderer, alphaG, NULL, &alphaRecG);
    SDL_RenderCopy(SDL_Struct.renderer, alphaH, NULL, &alphaRecH);
    SDL_RenderCopy(SDL_Struct.renderer, numeric1, NULL, &numericRec1);
    SDL_RenderCopy(SDL_Struct.renderer, numeric2, NULL, &numericRec2);
    SDL_RenderCopy(SDL_Struct.renderer, numeric3, NULL, &numericRec3);
    SDL_RenderCopy(SDL_Struct.renderer, numeric4, NULL, &numericRec4);
    SDL_RenderCopy(SDL_Struct.renderer, numeric5, NULL, &numericRec5);
    SDL_RenderCopy(SDL_Struct.renderer, numeric6, NULL, &numericRec6);
    SDL_RenderCopy(SDL_Struct.renderer, numeric7, NULL, &numericRec7);
    SDL_RenderCopy(SDL_Struct.renderer, numeric8, NULL, &numericRec8);

    for(int e = 0; e < 8; e++){
        for (int i = 0; i < 8; i++){
            if (gameBoard.returnSquare(e, i) == "White Left Rook" ||
                    gameBoard.returnSquare(e, i) == "White Right Rook"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i+1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, whiteRook, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "White Left Knight" ||
                 gameBoard.returnSquare(e, i) == "White Right Knight"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, whiteKnight, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "White Left Bishop" ||
                 gameBoard.returnSquare(e, i) == "White Right Bishop"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, whiteBishop, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "White King"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, whiteKing, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "White Queen"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, whiteQueen, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "White Pawn"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, whitePawn, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "Black Left Rook" ||
                 gameBoard.returnSquare(e, i) == "Black Right Rook"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, blackRook, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "Black Left Knight" ||
                 gameBoard.returnSquare(e, i) == "Black Right Knight"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, blackKnight, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "Black Left Bishop" ||
                 gameBoard.returnSquare(e, i) == "Black Right Bishop"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, blackBishop, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "Black King"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, blackKing, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "Black Queen"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, blackQueen, NULL, &tempRec);
            }
            if (gameBoard.returnSquare(e, i) == "Black Pawn"){
                SDL_Rect tempRec;
                tempRec.x = 10 + (85 * (i + 1));
                tempRec.y = 10 + (85 * e);
                tempRec.w = 65;
                tempRec.h = 65;
                SDL_RenderCopy(SDL_Struct.renderer, blackPawn, NULL, &tempRec);
            }
        }
    }
    SDL_RenderPresent(SDL_Struct.renderer);
    SDL_DestroyTexture(numeric1);
    SDL_DestroyTexture(numeric2);
    SDL_DestroyTexture(numeric3);
    SDL_DestroyTexture(numeric4);
    SDL_DestroyTexture(numeric5);
    SDL_DestroyTexture(numeric6);
    SDL_DestroyTexture(numeric7);
    SDL_DestroyTexture(numeric8);
    SDL_DestroyTexture(alphaA);
    SDL_DestroyTexture(alphaB);
    SDL_DestroyTexture(alphaC);
    SDL_DestroyTexture(alphaD);
    SDL_DestroyTexture(alphaE);
    SDL_DestroyTexture(alphaF);
    SDL_DestroyTexture(alphaG);
    SDL_DestroyTexture(alphaH);
    SDL_DestroyTexture(whitePawn);
    SDL_DestroyTexture(whiteRook);
    SDL_DestroyTexture(whiteKnight);
    SDL_DestroyTexture(whiteBishop);
    SDL_DestroyTexture(whiteKing);
    SDL_DestroyTexture(whiteQueen);
    SDL_DestroyTexture(blackPawn);
    SDL_DestroyTexture(blackRook);
    SDL_DestroyTexture(blackKnight);
    SDL_DestroyTexture(blackBishop);
    SDL_DestroyTexture(blackKing);
    SDL_DestroyTexture(blackQueen);
    SDL_FreeSurface(numericSurface1);
    SDL_FreeSurface(numericSurface2);
    SDL_FreeSurface(numericSurface3);
    SDL_FreeSurface(numericSurface4);
    SDL_FreeSurface(numericSurface5);
    SDL_FreeSurface(numericSurface6);
    SDL_FreeSurface(numericSurface7);
    SDL_FreeSurface(numericSurface8);
    SDL_FreeSurface(alphaSurfaceA);
    SDL_FreeSurface(alphaSurfaceB);
    SDL_FreeSurface(alphaSurfaceC);
    SDL_FreeSurface(alphaSurfaceD);
    SDL_FreeSurface(alphaSurfaceE);
    SDL_FreeSurface(alphaSurfaceF);
    SDL_FreeSurface(alphaSurfaceG);
    SDL_FreeSurface(alphaSurfaceH);
    SDL_FreeSurface(blackPawnSurface);
    SDL_FreeSurface(blackRookSurface);
    SDL_FreeSurface(blackKnightSurface);
    SDL_FreeSurface(blackBishopSurface);
    SDL_FreeSurface(blackQueenSurface);
    SDL_FreeSurface(blackKingSurface);
    SDL_FreeSurface(whitePawnSurface);
    SDL_FreeSurface(whiteRookSurface);
    SDL_FreeSurface(whiteKnightSurface);
    SDL_FreeSurface(whiteBishopSurface);
    SDL_FreeSurface(whiteQueenSurface);
    SDL_FreeSurface(whiteKingSurface);
}

void Print::printOptionsToWindow(){
    TTF_Font *font = TTF_OpenFont("font.ttf", 24);
    SDL_Texture *serverText, *clientText, *aiText, *changeSideText, *newGameText, *saveGameText, *restoreGameText, *serverCheckBox,
                *clientCheckBox, *aiCheckBox, *changeSideButton, *newGameButton, *saveGameButton, *restoreGameButton, *serverPortInputBox,
                *clientIPInputBox, *clientPortInputBox, *serverPortInputText, *clientIPInputText, *clientPortInputText, *serverPortInputBoxText,
                *clientIPInputBoxText, *recallMoveText, *recallMoveButton, *clientPortInputBoxText;

    SDL_Rect serverTextRec, clientTextRec, aiTextRec, changeSideTextRec, newGameTextRec, saveGameTextRec, restoreGameTextRec, serverCheckBoxRec,
             clientCheckBoxRec, aiCheckBoxRec, changeSideButtonRec, newGameButtonRec, saveGameButtonRec, restoreGameButtonRec, serverPortInputBoxTextRec,
             serverPortInputBoxRec, clientIPInputBoxRec, clientPortInputBoxRec, serverPortInputTextRec, clientIPInputTextRec, clientPortInputTextRec, background,
             clientIPInputTextBoxRec, recallMoveTextRec, recallMoveButtonRec, clientIPInputBoxTextRec, clientPortInputBoxTextRec, menuSquareRec;
    SDL_Surface *serverTextSurface = NULL;
    SDL_Surface *clientTextSurface = NULL;
    SDL_Surface *aiTextSurface = NULL;
    SDL_Surface *changeSideTextSurface = NULL;
    SDL_Surface *newGameTextSurface = NULL;
    SDL_Surface *saveGameTextSurface = NULL;
    SDL_Surface *restoreGameTextSurface = NULL;
    SDL_Surface *serverPortInputTextSurface = NULL;
    SDL_Surface *clientIPInputTextSurface = NULL;
    SDL_Surface *clientPortInputTextSurface = NULL;
    SDL_Surface *serverPortInputBoxTextSurface = NULL;
    SDL_Surface *clientIPInputTextBoxSurface = NULL;
    SDL_Surface *changeSideButtonSurface = NULL;
    SDL_Surface *newGameButtonSurface = NULL;
    SDL_Surface *saveGameButtonSurface = NULL;
    SDL_Surface *restoreGameButtonSurface = NULL;
    SDL_Surface *recallMoveTextSurface = NULL;
    SDL_Surface *recallMoveButtonSurface = NULL;
    SDL_Surface *aiCheckBoxSurface = NULL;
    SDL_Surface *serverCheckBoxSurface = NULL;
    SDL_Surface *clientCheckBoxSurface = NULL;
    SDL_Surface *clientIPInputBoxTextSurface = NULL;
    SDL_Surface *clientPortInputBoxTextSurface = NULL;

    background.x = 0;
    background.y = 0;
    background.w = 765;
    background.h = 765;
    SDL_SetRenderDrawColor(SDL_Struct.renderer, 0,0,0,255);
    SDL_RenderFillRect(SDL_Struct.renderer, &background);
    menuSquareRec.x = 0;
    menuSquareRec.y = 8*85;
    menuSquareRec.w = 85;
    menuSquareRec.h = 85;
    SDL_SetRenderDrawColor(SDL_Struct.renderer, 157,128,0,255);
    SDL_RenderFillRect(SDL_Struct.renderer, &menuSquareRec);
    aiTextSurface = TTF_RenderText_Blended(font, "Play a new game against the computer.", {255,255,255,255});
    aiText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, aiTextSurface);
    aiTextRec.x = 85;
    aiTextRec.y = 85;
    aiTextRec.w = aiTextSurface->w;
    aiTextRec.h = aiTextSurface->h;
    aiCheckBoxRec.x = 8 * 85;
    aiCheckBoxRec.y = 85;
    aiCheckBoxRec.w = 40;
    aiCheckBoxRec.h = 40;
    if(guiOptionToggle == 0)
        aiCheckBoxSurface = SDL_LoadBMP("images/checkBoxActivated.bmp");
    else
        aiCheckBoxSurface = SDL_LoadBMP("images/checkBox.bmp");
    aiCheckBox = SDL_CreateTextureFromSurface(SDL_Struct.renderer, aiCheckBoxSurface);
    serverTextSurface = TTF_RenderText_Blended(font, "Start game as server and wait for client to connect.", {255,255,255,255});
    serverText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, serverTextSurface);
    serverTextRec.x = 85;
    serverTextRec.y = 85 + 50*1;
    serverTextRec.w = serverTextSurface->w;
    serverTextRec.h = serverTextSurface->h;
    serverCheckBoxRec.x = 8 * 85;
    serverCheckBoxRec.y = 85 + 50*1;
    serverCheckBoxRec.w = 40;
    serverCheckBoxRec.h = 40;
    if(guiOptionToggle == 1)
        serverCheckBoxSurface = SDL_LoadBMP("images/checkBoxActivated.bmp");
    else
        serverCheckBoxSurface = SDL_LoadBMP("images/checkBox.bmp");
    serverCheckBox = SDL_CreateTextureFromSurface(SDL_Struct.renderer, serverCheckBoxSurface);
    serverPortInputBoxRec.x = 100;
    serverPortInputBoxRec.y = 85 + 50*2;
    serverPortInputBoxRec.w = 85;
    serverPortInputBoxRec.h = 40;
    SDL_SetRenderDrawColor(SDL_Struct.renderer, 255,255,255,255);
    SDL_RenderFillRect(SDL_Struct.renderer, &serverPortInputBoxRec);
    serverPortInputBoxTextSurface = TTF_RenderText_Blended(font, "Port", {255,255,255,255});
    serverPortInputBoxText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, serverPortInputBoxTextSurface);
    serverPortInputBoxTextRec.x = 200;
    serverPortInputBoxTextRec.y = 85 + 50*2;
    serverPortInputBoxTextRec.w = serverPortInputBoxTextSurface->w;
    serverPortInputBoxTextRec.h = serverPortInputBoxTextSurface->h;
    serverPortInputTextSurface = TTF_RenderText_Blended(font, serverPort, {0,0,0,255});
    serverPortInputText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, serverPortInputTextSurface);/*
    serverPortInputTextRec.x = 105;
    serverPortInputTextRec.y = 85 + 50*2 + 1;
    serverPortInputTextRec.w = 85;
    serverPortInputTextRec.h = 40;*/

    clientTextSurface = TTF_RenderText_Blended(font, "Connect to server as client.", {255,255,255,255});
    clientText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, clientTextSurface);
    clientTextRec.x = 85;
    clientTextRec.y = 85 + 50*3;
    clientTextRec.w = clientTextSurface->w;
    clientTextRec.h = clientTextSurface->h;
    clientCheckBoxRec.x = 85*8;
    clientCheckBoxRec.y = 85 + 50*3;
    clientCheckBoxRec.w = 40;
    clientCheckBoxRec.h = 40;
    if(guiOptionToggle == 2)
        clientCheckBoxSurface = SDL_LoadBMP("images/checkBoxActivated.bmp");
    else
        clientCheckBoxSurface = SDL_LoadBMP("images/checkBox.bmp");
    clientCheckBox = SDL_CreateTextureFromSurface(SDL_Struct.renderer, clientCheckBoxSurface);
    clientIPInputBoxRec.x = 85;
    clientIPInputBoxRec.y = 85 + 50*4;
    clientIPInputBoxRec.w = 85 * 2;
    clientIPInputBoxRec.h = 40;
    SDL_SetRenderDrawColor(SDL_Struct.renderer, 255,255,255,255);
    SDL_RenderFillRect(SDL_Struct.renderer, &clientIPInputBoxRec);
    clientIPInputBoxTextSurface = TTF_RenderText_Blended(font, "IP Address", {255,255,255,255});
    clientIPInputBoxText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, clientIPInputBoxTextSurface);
    clientIPInputBoxTextRec.x = 85 * 3 + 15;
    clientIPInputBoxTextRec.y = 85 + 50*4;
    clientIPInputBoxTextRec.w = clientIPInputBoxTextSurface->w;
    clientIPInputBoxTextRec.h = clientIPInputBoxTextSurface->h;
    clientPortInputBoxRec.x = 85 * 6;
    clientPortInputBoxRec.y = 85 + 50*4;
    clientPortInputBoxRec.w = 85;
    clientPortInputBoxRec.h = 40;
    SDL_SetRenderDrawColor(SDL_Struct.renderer, 255,255,255,255);
    SDL_RenderFillRect(SDL_Struct.renderer, &clientPortInputBoxRec);
    clientPortInputBoxTextSurface = TTF_RenderText_Blended(font, "Port", {255,255,255,255});
    clientPortInputBoxText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, clientPortInputBoxTextSurface);
    clientPortInputBoxTextRec.x = 85 * 7 + 15;
    clientPortInputBoxTextRec.y = 85 + 50*4;
    clientPortInputBoxTextRec.w = clientPortInputBoxTextSurface->w;
    clientPortInputBoxTextRec.h = clientPortInputBoxTextSurface->h;
    changeSideTextSurface = TTF_RenderText_Blended(font, "Change sides colour and start new game.", {255,255,255,255});
    changeSideText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, changeSideTextSurface);
    changeSideTextRec.x = 85;
    changeSideTextRec.y = 85 + 50*5;
    changeSideTextRec.w = changeSideTextSurface->w;
    changeSideTextRec.h = changeSideTextSurface->h;
    changeSideButtonRec.x = 85*6 + 15;
    changeSideButtonRec.y = 85 + 50*5;
    changeSideButtonRec.w = 40;
    changeSideButtonRec.h = 40;
    changeSideButtonSurface = SDL_LoadBMP("images/button.bmp");
    changeSideButton = SDL_CreateTextureFromSurface(SDL_Struct.renderer, changeSideButtonSurface);
    newGameTextSurface = TTF_RenderText_Blended(font, "Start new game.", {255,255,255,255});
    newGameText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, newGameTextSurface);
    newGameTextRec.x = 85;
    newGameTextRec.y = 85 + 50*6;
    newGameTextRec.w = newGameTextSurface->w;
    newGameTextRec.h = newGameTextSurface->h;
    newGameButtonRec.x = 85*6 + 15;
    newGameButtonRec.y = 85 + 50*6;
    newGameButtonRec.w = 40;
    newGameButtonRec.h = 40;
    newGameButtonSurface = SDL_LoadBMP("images/button.bmp");
    newGameButton = SDL_CreateTextureFromSurface(SDL_Struct.renderer, newGameButtonSurface);
    saveGameTextSurface = TTF_RenderText_Blended(font, "Save game.", {255,255,255,255});
    saveGameText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, saveGameTextSurface);
    saveGameTextRec.x = 85;
    saveGameTextRec.y = 85 + 50*7;
    saveGameTextRec.w = saveGameTextSurface->w;
    saveGameTextRec.h = saveGameTextSurface->h;
    saveGameButtonRec.x = 85*6 + 15;
    saveGameButtonRec.y = 85 + 50*7;
    saveGameButtonRec.w = 40;
    saveGameButtonRec.h = 40;
    saveGameButtonSurface = SDL_LoadBMP("images/button.bmp");
    saveGameButton = SDL_CreateTextureFromSurface(SDL_Struct.renderer, saveGameButtonSurface);
    restoreGameTextSurface = TTF_RenderText_Blended(font, "Load saved game.", {255,255,255,255});
    restoreGameText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, restoreGameTextSurface);
    restoreGameTextRec.x = 85;
    restoreGameTextRec.y = 85 + 50*9;
    restoreGameTextRec.w = restoreGameTextSurface->w;
    restoreGameTextRec.h = restoreGameTextSurface->h;
    restoreGameButtonRec.x = 85*6 + 15;
    restoreGameButtonRec.y = 85 + 50*9;
    restoreGameButtonRec.w = 40;
    restoreGameButtonRec.h = 40;
    restoreGameButtonSurface = SDL_LoadBMP("images/button.bmp");
    restoreGameButton = SDL_CreateTextureFromSurface(SDL_Struct.renderer, restoreGameButtonSurface);
    recallMoveTextSurface = TTF_RenderText_Blended(font, "Recall move.", {255,255,255,255});
    recallMoveText = SDL_CreateTextureFromSurface(SDL_Struct.renderer, recallMoveTextSurface);
    recallMoveTextRec.x = 85;
    recallMoveTextRec.y = 85 + 50*8;
    recallMoveTextRec.w = recallMoveTextSurface->w;
    recallMoveTextRec.h = recallMoveTextSurface->h;
    recallMoveButtonRec.x = 85*6 + 15;
    recallMoveButtonRec.y = 85 + 50*8;
    recallMoveButtonRec.w = 40;
    recallMoveButtonRec.h = 40;
    recallMoveButtonSurface = SDL_LoadBMP("images/button.bmp");
    recallMoveButton = SDL_CreateTextureFromSurface(SDL_Struct.renderer, recallMoveButtonSurface);
    SDL_RenderCopy(SDL_Struct.renderer,serverText , NULL, &serverTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,clientCheckBox , NULL, &clientCheckBoxRec);
    SDL_RenderCopy(SDL_Struct.renderer,serverCheckBox , NULL, &serverCheckBoxRec);
    SDL_RenderCopy(SDL_Struct.renderer,serverPortInputBoxText, NULL, &serverPortInputBoxTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,clientText , NULL, &clientTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,clientIPInputBoxText, NULL, &clientIPInputBoxTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,clientPortInputBoxText, NULL, &clientPortInputBoxTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,aiText , NULL, &aiTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,aiCheckBox , NULL, &aiCheckBoxRec);
    SDL_RenderCopy(SDL_Struct.renderer,changeSideText, NULL, &changeSideTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,changeSideButton, NULL, &changeSideButtonRec);
    SDL_RenderCopy(SDL_Struct.renderer,newGameText , NULL, &newGameTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,newGameButton , NULL, &newGameButtonRec);
    SDL_RenderCopy(SDL_Struct.renderer,saveGameText , NULL, &saveGameTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,saveGameButton , NULL, &saveGameButtonRec);
    SDL_RenderCopy(SDL_Struct.renderer,restoreGameText , NULL, &restoreGameTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,restoreGameButton , NULL, &restoreGameButtonRec);
    SDL_RenderCopy(SDL_Struct.renderer,recallMoveText , NULL, &recallMoveTextRec);
    SDL_RenderCopy(SDL_Struct.renderer,recallMoveButton , NULL, &recallMoveButtonRec);
    SDL_RenderCopy(SDL_Struct.renderer,serverPortInputText, NULL, &serverPortInputBoxRec);
    SDL_RenderPresent(SDL_Struct.renderer);
/*    SDL_DestroyTexture(serverText);
    SDL_DestroyTexture(clientText);
    SDL_DestroyTexture(aiText);
    SDL_DestroyTexture(changeSideText);
    SDL_DestroyTexture(newGameText);
    SDL_DestroyTexture(saveGameText);
    SDL_DestroyTexture(restoreGameText);
    SDL_DestroyTexture(serverCheckBox);
    SDL_DestroyTexture(aiCheckBox);
    SDL_DestroyTexture(changeSideButton);
    SDL_DestroyTexture(newGameButton);
    SDL_DestroyTexture(saveGameButton);
    SDL_DestroyTexture(restoreGameButton);
    SDL_DestroyTexture(serverPortInputBox);
    SDL_DestroyTexture(clientIPInputBox);
    SDL_DestroyTexture(clientPortInputBox);
    SDL_DestroyTexture(serverPortInputText);
//    SDL_DestroyTexture(clientIPInputText);
//    SDL_DestroyTexture(clientPortInputText);
    SDL_DestroyTexture(serverPortInputBoxText);
    SDL_DestroyTexture(clientIPInputBoxText);
    SDL_DestroyTexture(recallMoveText);
    SDL_DestroyTexture(recallMoveButton);
    SDL_DestroyTexture(clientPortInputBoxText);
    SDL_FreeSurface(serverTextSurface);
    SDL_FreeSurface(clientTextSurface);
    SDL_FreeSurface(aiTextSurface);
    SDL_FreeSurface(changeSideTextSurface);
    SDL_FreeSurface(newGameTextSurface);
    SDL_FreeSurface(saveGameTextSurface);
    SDL_FreeSurface(restoreGameTextSurface);
    SDL_FreeSurface(serverPortInputTextSurface);
    SDL_FreeSurface(clientIPInputTextSurface);
    SDL_FreeSurface(clientPortInputTextSurface);
    SDL_FreeSurface(serverPortInputBoxTextSurface);
    SDL_FreeSurface(clientIPInputTextBoxSurface);
    SDL_FreeSurface(changeSideButtonSurface);
    SDL_FreeSurface(newGameButtonSurface);
    SDL_FreeSurface(saveGameButtonSurface);
    SDL_FreeSurface(restoreGameButtonSurface);
    SDL_FreeSurface(recallMoveTextSurface);
    SDL_FreeSurface(recallMoveButtonSurface);
    SDL_FreeSurface(aiCheckBoxSurface);
    SDL_FreeSurface(serverCheckBoxSurface);
    SDL_FreeSurface(clientCheckBoxSurface);
    SDL_FreeSurface(clientIPInputBoxTextSurface);
    SDL_FreeSurface(clientPortInputBoxTextSurface);
*/
}

void Print::destroySDL(){
    SDL_DestroyRenderer(SDL_Struct.renderer);
    SDL_DestroyWindow(SDL_Struct.window);
}

void Print::printBoardToTerminal(Board gameBoard){
    int a = 1;
    int b = 3;
    int c = 5;
    int d = 7;
    std::string piece;
    for(int e = 0; e < 9; e++){
        for (int i = 0; i < 9; i++){
            if (e > 0 && i > 0){
                if (gameBoard.returnSquare(e - 1, i - 1) == "White Left Rook" ||
                    gameBoard.returnSquare(e - 1, i - 1) == "White Right Rook")
                    piece = "\e[97m\u265C";
                if (gameBoard.returnSquare(e - 1, i - 1) == "White Left Knight" ||
                    gameBoard.returnSquare(e - 1, i - 1) == "White Right Knight")
                    piece = "\e[97m\u265E";
                if (gameBoard.returnSquare(e - 1, i - 1) == "White Left Bishop" ||
                    gameBoard.returnSquare(e - 1, i - 1) == "White Right Bishop")
                    piece = "\e[97m\u265D";
                if (gameBoard.returnSquare(e - 1, i - 1) == "White King")
                    piece = "\e[97m\u265A";
                if (gameBoard.returnSquare(e - 1, i - 1) == "White Queen")
                    piece = "\e[97m\u265B";
                if (gameBoard.returnSquare(e - 1, i - 1) == "White Pawn")
                    piece = "\e[97m\u265F";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Black Left Rook" ||
                    gameBoard.returnSquare(e - 1, i - 1) == "Black Right Rook")
                    piece = "\e[30m\u265C";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Black Left Knight" ||
                    gameBoard.returnSquare(e - 1, i - 1) == "Black Right Knight")
                    piece = "\e[30m\u265E";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Black Left Bishop" ||
                    gameBoard.returnSquare(e - 1, i - 1) == "Black Right Bishop")
                    piece = "\e[30m\u265D";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Black King")
                    piece = "\e[30m\u265A";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Black Queen")
                    piece = "\e[30m\u265B";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Black Pawn")
                    piece = "\e[30m\u265F";
                if (gameBoard.returnSquare(e - 1, i - 1) == "Empty")
                    piece = " ";
                if (i == a || i == b || i == c || i == d)
                    std::cout << "\e[44m " << piece << " ";
                else
                    std::cout << "\e[101m " << piece << " ";
            }
            if(i == 0){
                if(e == 0)
                    std::cout << "\e[49m   \e[49m\e[39m";
                if(e == 1)
                    std::cout << "\e[43m \e[30m8 \e[49m\e[39m";
                if(e == 2)
                    std::cout << "\e[49m \e[33m7 \e[49m\e[39m";
                if(e == 3)
                    std::cout << "\e[43m \e[30m6 \e[49m\e[39m";
                if(e == 4)
                    std::cout << "\e[49m \e[33m5 \e[49m\e[39m";
                if(e == 5)
                    std::cout << "\e[43m \e[30m4 \e[49m\e[39m";
                if(e == 6)
                    std::cout << "\e[49m \e[33m3 \e[49m\e[39m";
                if(e == 7)
                    std::cout << "\e[43m \e[30m2 \e[49m\e[39m";
                if(e == 8)
                    std::cout << "\e[49m\e[33m 1 \e[49m\e[39m";
            }
        }
        std::cout << "\e[49m\e[39m" << std::endl;
        if (e == 1){
            a++;
            b++;
            c++;
            d++;
        }
        else if (e == 2){
            a--;
            b--;
            c--;
            d--;
        }
        else if (e == 3){
            a++;
            b++;
            c++;
            d++;
        }
        else if (e == 4){
            a--;
            b--;
            c--;
            d--;
        }
        else if (e == 5){
            a++;
            b++;
            c++;
            d++;
        }
        else if (e == 6){
            a--;
            b--;
            c--;
            d--;
        }
        else if (e == 7){
            a++;
            b++;
            c++;
            d++;
        }
    }
    std::cout << "\e[43m   " << "\e[49m \e[33mA " << "\e[43m \e[30mB " << "\e[49m \e[33mC " << "\e[43m \e[30mD " << "\e[49m \e[33mE " << "\e[43m \e[30mF " << "\e[49m \e[33mG " << "\e[43m \e[30mH " << "\e[49m\e[39m" << std::endl;
}

