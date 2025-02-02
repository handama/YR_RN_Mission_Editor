﻿/*
	FinalSun/FinalAlert 2 Mission Editor

	Copyright (C) 1999-2024 Electronic Arts, Inc.
	Authored by Matthias Wagner

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

// BackCliffModifier.h: Schnittstelle für die Klasse CBackCliffModifier.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BACKCLIFFMODIFIER_H__3853D325_CD37_11D4_9C87_F2DC6A2E6849__INCLUDED_)
#define AFX_BACKCLIFFMODIFIER_H__3853D325_CD37_11D4_9C87_F2DC6A2E6849__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CliffModifier.h"

class CBackCliffModifier : public CCliffModifier
{
public:
	CBackCliffModifier();
	virtual ~CBackCliffModifier();

protected:
	virtual CString GetDataSection();
	virtual void ModifyStartPos(DWORD* dwPos, BOOL bSmall);
	virtual void ModifyCurrentPos(DWORD* dwPos, BOOL bBeforePlacing, BOOL bSmall);
};

#endif // !defined(AFX_BACKCLIFFMODIFIER_H__3853D325_CD37_11D4_9C87_F2DC6A2E6849__INCLUDED_)
