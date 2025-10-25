#pragma once

#define MAP_TRANSFER_SIZE 10
#define MAP_TRANSFER_EX_SIZE 20
#define MAX_MAP_TRANSFER_SIZE (MAP_TRANSFER_SIZE > MAP_TRANSFER_EX_SIZE ? MAP_TRANSFER_SIZE : MAP_TRANSFER_EX_SIZE)

class CMapTransferExpand
{
public:
    static unsigned int m_adwFieldList[MAX_MAP_TRANSFER_SIZE]; // CUIMapTransfer
    static unsigned int adwMapTransfer[MAP_TRANSFER_SIZE]; // CharacterData
    static unsigned int adwMapTransferEx[MAP_TRANSFER_EX_SIZE];  // CharacterData
    static void Expand();

private:
    static void Position_CharacterData__Decode_MapTransfer();
    static void Position_CharacterData__Decode_MapTransferEx();
    static void Position_CUIMapTransfer__OnCreate();
    static void Position_CUIMapTransfer__OnCreateScrollBarRange();
    static void Position_CUIMapTransfer__OnRegister();
    static void Position_CUIMapTransfer__SetRet();
    static void Position_CUIMapTransfer__Draw();
    static void Position_CUIMapTransfer__GetMapIndexFromPoint();
    static void Position_CUIMapTransfer__UpdateFieldList();
    static void Position_CWvsContext__OnMapTransferResult();
};