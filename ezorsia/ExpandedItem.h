#pragma once

const unsigned int newFullItemHeight = 0x1F6;					// 新全屏道具栏高度 UI/UIWindows/Item/FullBackgrnd
unsigned int diffFullItemHeight = newFullItemHeight - 0x121;	// 新全屏道具栏高度与原高度121h的差值
const DWORD CUIItemHeight = 0x0081C512;							// PUSH 道具栏直接打开渲染高度
const DWORD CUIItemBtCashShopPosY = 0x0081CEFE;					// PUSH 道具栏-扩充道具栏按钮高度
const DWORD CUIItemExpandItemHeight = 0x0081E5BC;				// PUSH 道具栏-放大道具栏按钮点击后渲染高度
bool isItemSlotIDover96 = false;								// 在GetItemSlotRect@CUIItem函数中传入的道具格ID是否大于96
const DWORD getItemSlotRectNewAddress = 0x0081E2C8;				// CodeCave获取GetItemSlotRect@CUIItem函数起始地址
const DWORD updateItemSlotRectValAddress = 0x0081E387;			// CodeCave获取GetItemSlotRect@CUIItem函数末尾传参逻辑
const DWORD itemSlotLimitExpandedAAddress = 0x0081DF74;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedBAddress = 0x0081E01E;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedCAddress = 0x0081DBD0;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedD1Address = 0x004B162E;		// CodeCave获取CCSWnd_Inventory::EnableExButton函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedD2Address = 0x004B1656;		// CodeCave获取CCSWnd_Inventory::EnableExButton函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedD3Address = 0x004B167E;		// CodeCave获取CCSWnd_Inventory::EnableExButton函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedD4Address = 0x004B16A3;		// CodeCave获取CCSWnd_Inventory::EnableExButton函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedEAddress = 0x0047AA6F;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedFAddress = 0x00470912;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedGAddress = 0x0081D346;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedHAddress = 0x00470912;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD itemSlotLimitExpandedIAddress = 0x0046C2DA;			// CodeCave获取CUIItem::Draw函数判断道具格总数逻辑
const DWORD CUIItemCoinPosYAddress = 0x0081DD5F;				// CodeCave获取CUIItem::Draw函数压栈金币数值y坐标地址
const DWORD CUIItemBtCoinPosYAddress = 0x0081CD67;				// CodeCave获取CUIItem::OnCreate函数压栈金币图标y坐标地址
const DWORD COnPacketItemSort2_DecodeSize = 0x00A1EC22;			// CWvsContext::OnInventoryOperation中读取背包排序结果操作总数地址