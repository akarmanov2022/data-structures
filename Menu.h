//
// Created by akarmanov on 10-12-2022.
//

#ifndef DATA_STRUCTURES_MENU_H
#define DATA_STRUCTURES_MENU_H


#include "lab5/BinaryTree.h"
#include "lab5/Treap.h"

class Menu
{
public:
    static void BinaryTreeMenu(BinaryTree *tree);

    static void TreapMenu(Treap *treap);

    static int InputInt(const char *message);
};


#endif //DATA_STRUCTURES_MENU_H
