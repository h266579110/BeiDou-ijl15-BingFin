#include "stdafx.h"
#include "CMapTransferExpand.h"

unsigned int CMapTransferExpand::adwMapTransfer[MAP_TRANSFER_SIZE];
unsigned int CMapTransferExpand::adwMapTransferEx[MAP_TRANSFER_EX_SIZE];
unsigned int CMapTransferExpand::m_adwFieldList[MAX_MAP_TRANSFER_SIZE];

void CMapTransferExpand::Expand()
{
    // fill array with 999999999
    std::fill(std::begin(adwMapTransfer), std::end(adwMapTransfer), 999999999);
    std::fill(std::begin(adwMapTransferEx), std::end(adwMapTransferEx), 999999999);
    std::fill(std::begin(m_adwFieldList), std::end(m_adwFieldList), 999999999);

    // CharacterData::Decode
    // MapTransfer
    Memory::CodeCave(Position_CharacterData__Decode_MapTransfer, 0x004E63D7, 8);
    // MapTransferEx
    Memory::CodeCave(Position_CharacterData__Decode_MapTransferEx, 0x004E63F0, 8);
    // CUIMapTransfer::OnCreate
    // Scroll bar
    unsigned char array0[] = { 0x90, 0x90 };
    Memory::WriteByteArray(0x008396FE, array0, sizeof(array0));
    Memory::CodeCave(Position_CUIMapTransfer__OnCreateScrollBarRange, 0x0083975B, 8);
    // MapTransfer
    Memory::WriteByte(0x00839866 + 1, 0x0D);
    Memory::WriteInt(0x00839866 + 2, reinterpret_cast<DWORD>(&adwMapTransfer));
    // MapTransferEx
    Memory::WriteByte(0x0083985E + 1, 0x0D);
    Memory::WriteInt(0x0083985E + 2, reinterpret_cast<DWORD>(&adwMapTransferEx));
    Memory::CodeCave(Position_CUIMapTransfer__OnCreate, 0x0083986C, 10);
    // FieldList
    Memory::WriteByte(0x0083987E + 1, 0x05);
    Memory::WriteInt(0x0083987E + 2, reinterpret_cast<DWORD>(&m_adwFieldList));
    Memory::WriteByte(0x00839892 + 1, 0x05);
    Memory::WriteInt(0x00839892 + 2, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::OnRegister - Your teleport list is full.\r\nPlease delete an entry before trying again.
    Memory::CodeCave(Position_CUIMapTransfer__OnRegister, 0x0083A09E, 10);
    // FieldList
    Memory::WriteByte(0x0083A0B4 + 1, 0x0D);
    Memory::WriteInt(0x0083A0B4 + 2, reinterpret_cast<DWORD>(&m_adwFieldList));
    unsigned char array1[] = { 0x8D, 0x3D };
    Memory::WriteByteArray(0x0083A11C, array1, sizeof(array1)); // 0x8D
    Memory::WriteInt(0x0083A11C + 2, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::OnDelete
    unsigned char array2[] = { 0x34, 0x85 };
    Memory::WriteByteArray(0x0083A2E3 + 1, array2, sizeof(array2));
    Memory::WriteInt(0x0083A2E3 + 3, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::DeleteSelectedField
    Memory::WriteByteArray(0x0083A3A9 + 1, array2, sizeof(array2));
    Memory::WriteInt(0x0083A3A9 + 3, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::SetRet
    Memory::CodeCave(Position_CUIMapTransfer__SetRet, 0x0083A4F1, 16);
    // FieldList
    unsigned char array3[] = { 0x04, 0x8D };
    Memory::WriteByteArray(0x0083A51F + 1, array3, sizeof(array3));
    Memory::WriteInt(0x0083A51F + 3, reinterpret_cast<DWORD>(&m_adwFieldList));
    Memory::WriteByteArray(0x0083A57B + 1, array2, sizeof(array2));
    Memory::WriteInt(0x0083A57B + 3, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::GetResult
    unsigned char array4[] = { 0x04, 0x85 };
    Memory::WriteByteArray(0x0083A6B3 + 1, array4, sizeof(array4));
    Memory::WriteInt(0x0083A6B3 + 3, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::Draw
    unsigned char array5[] = { 0x90, 0x90, 0x90 };
    Memory::CodeCave(Position_CUIMapTransfer__Draw, 0x00839902, 10);
    Memory::WriteByteArray(0x00839914, array5, sizeof(array5)); // remove and esi, 5
    Memory::WriteByteArray(0x0083991C, array5, sizeof(array5)); // remove add esi, 5
    // FieldList
    unsigned char array6[] = { 0x04, 0xBD };
    Memory::WriteByteArray(0x00839A72 + 1, array6, sizeof(array6));
    Memory::WriteInt(0x00839A72 + 3, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::GetMapIndexFromPoint
    Memory::CodeCave(Position_CUIMapTransfer__GetMapIndexFromPoint, 0x00839E99, 10);
    // FieldList
    Memory::WriteByte(0x00839E2E + 1, 5);
    Memory::WriteInt(0x00839E2E + 2, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CUIMapTransfer::UpdateFieldList
    Memory::CodeCave(Position_CUIMapTransfer__UpdateFieldList, 0x0083A6D3, 16);
    // FieldList
    Memory::WriteByte(0x0083A6ED + 1, 0x1D);
    Memory::WriteInt(0x0083A6ED + 2, reinterpret_cast<DWORD>(&m_adwFieldList));

    // CWvsContext::OnMapTransferResult
    // MapTransfer
    Memory::WriteByte(0x00A252BA + 1, 0x3D);
    Memory::WriteInt(0x00A252BA + 2, reinterpret_cast<DWORD>(&adwMapTransfer));
    // MapTransferEx
    Memory::WriteByte(0x00A252B2 + 1, 0x3D);
    Memory::WriteInt(0x00A252B2 + 2, reinterpret_cast<DWORD>(&adwMapTransferEx));
    Memory::CodeCave(Position_CWvsContext__OnMapTransferResult, 0x00A252C0, 10);
}

const DWORD dw_CharacterData__Decode_MapTransfer_Ret = 0x004E63DF;
__declspec(naked) void CMapTransferExpand::Position_CharacterData__Decode_MapTransfer()
{
    __asm {
        push MAP_TRANSFER_SIZE
        lea esi, [adwMapTransfer]
            jmp dw_CharacterData__Decode_MapTransfer_Ret
    }
}

const DWORD dw_CharacterData__Decode_MapTransferEx_Ret = 0x004E63F8;
__declspec(naked) void CMapTransferExpand::Position_CharacterData__Decode_MapTransferEx()
{
    __asm {
        push MAP_TRANSFER_EX_SIZE
        lea esi, [adwMapTransferEx]
            jmp dw_CharacterData__Decode_MapTransferEx_Ret
    }
}

const DWORD dw_CUIMapTransfer__OnCreate_Ret = 0x00839876;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__OnCreate()
{
    __asm {
        mov eax, [esi + 0xF0] // m_bCanTransferContinent
        cmp eax, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov eax, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov eax, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CUIMapTransfer__OnCreate_Ret
    }
}

const DWORD dw_CUIMapTransfer__OnCreateScrollBarRange_Ret = 0x00839763;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__OnCreateScrollBarRange()
{
    __asm {
        mov ecx, [esi + 0xAC] // original asm
        push eax
        mov eax, [esi + 0xF0] // m_bCanTransferContinent
        cmp eax, 1 // compare to 1
        pop eax
        jge vip // >= 1 jmp to VIP

        push(MAP_TRANSFER_SIZE - 4) // teleport rock 10 (10 - 5 + 1)
        jmp back

        vip :
        push(MAP_TRANSFER_EX_SIZE - 4) // vip teleport rock 20 (20 - 5 + 1)

            back :
            jmp dw_CUIMapTransfer__OnCreateScrollBarRange_Ret
    }
}

const DWORD dw_CUIMapTransfer__OnRegister_Ret = 0x0083A0A8;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__OnRegister()
{
    __asm {
        mov esi, [edi + 0xF0] // m_bCanTransferContinent
        cmp esi, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov esi, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov esi, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CUIMapTransfer__OnRegister_Ret
    }
}

const DWORD dw_CUIMapTransfer__SetRet_Ret = 0x0083A501;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__SetRet()
{
    __asm {
        mov ecx, [esi + 0xF0] // m_bCanTransferContinent
        cmp ecx, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov ecx, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov ecx, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CUIMapTransfer__SetRet_Ret
    }
}

const DWORD dw_CUIMapTransfer__Draw_Ret = 0x0083990C;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__Draw()
{
    __asm {
        mov esi, [ebx + 0xF0] // m_bCanTransferContinent
        cmp esi, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov esi, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov esi, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CUIMapTransfer__Draw_Ret
    }
}

const DWORD dw_CUIMapTransfer__GetMapIndexFromPoint_Ret = 0x00839EA3;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__GetMapIndexFromPoint()
{
    __asm {
        mov eax, [esi + 0xF0] // m_bCanTransferContinent
        cmp eax, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov eax, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov eax, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CUIMapTransfer__GetMapIndexFromPoint_Ret
    }
}

const DWORD dw_CUIMapTransfer__UpdateFieldList_Ret = 0x0083A6E3;
__declspec(naked) void CMapTransferExpand::Position_CUIMapTransfer__UpdateFieldList()
{
    __asm {
        mov esi, [edi + 0xF0] // m_bCanTransferContinent
        cmp esi, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov esi, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov esi, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CUIMapTransfer__UpdateFieldList_Ret
    }
}

const DWORD dw_CWvsContext__OnMapTransferResult_Ret = 0x00A252CA;
__declspec(naked) void CMapTransferExpand::Position_CWvsContext__OnMapTransferResult()
{
    __asm {
        // mov eax, eax // m_bCanTransferContinent (Decode1 -> movzx eax, al)
        cmp eax, 1 // compare to 1
        jge vip // >= 1 jmp to VIP

        mov eax, MAP_TRANSFER_SIZE // teleport rock 10
        jmp back

        vip :
        mov eax, MAP_TRANSFER_EX_SIZE // vip teleport rock 20

            back :
        jmp dw_CWvsContext__OnMapTransferResult_Ret
    }
}