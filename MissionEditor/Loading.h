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

#if !defined(AFX_LOADING_H__5D5C3284_8962_11D3_B63B_AAA51FD322E3__INCLUDED_)
#define AFX_LOADING_H__5D5C3284_8962_11D3_B63B_AAA51FD322E3__INCLUDED_

#include "FinalSunDlg.h"	
#include "MissionEditorPackLib.h"
#include "Palettes.h"
#include <memory>
#include <optional>

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Loading.h : header file
//

class VoxelNormalTables;

struct EXPANDMIX
{
	HMIXFILE hExpand; // NULL if expansion mix does not exist
	HMIXFILE hECache; // NULL if no ECache
	HMIXFILE hConquer; // NULL if no Conquer
	HMIXFILE hLocal;
	HMIXFILE hIsoSnow; // NULL if no IsoSnow
	HMIXFILE hIsoTemp; // NULL if no IsoTemp
	HMIXFILE hIsoUrb;
	HMIXFILE hIsoGen;
	HMIXFILE hIsoLun;
	HMIXFILE hIsoDes;
	HMIXFILE hIsoUbn;
	HMIXFILE hIsoGenMd;
	HMIXFILE hIsoLunMd;
	HMIXFILE hIsoDesMd;
	HMIXFILE hIsoUbnMd;
	HMIXFILE hTemperat; // NULL if no Temperat
	HMIXFILE hSnow;
	HMIXFILE hUrban;
	HMIXFILE hLunar;
	HMIXFILE hUrbanN;
	HMIXFILE hDesert;
	HMIXFILE hGeneric;
	HMIXFILE hTem;
	HMIXFILE hSno;
	HMIXFILE hUrb;
	HMIXFILE hLun;
	HMIXFILE hDes;
	HMIXFILE hUbn;
	HMIXFILE hBuildings;
	HMIXFILE hMarble;
	EXPANDMIX() { memset(this, 0, sizeof(EXPANDMIX)); };
};

class CFinalSunDlg;


/////////////////////////////////////////////////////////////////////////////
// dialog field CLoading 


struct FindShpResult
{
	FindShpResult(HMIXFILE mixfile_, TheaterChar mixfile_theater_, CString filename_, TheaterChar theat_, HTSPALETTE palette_) : mixfile(mixfile_), mixfile_theater(mixfile_theater_), filename(filename_), theat(theat_), palette(palette_) { }
	HMIXFILE mixfile;
	TheaterChar mixfile_theater;
	CString filename;
	TheaterChar theat;
	HTSPALETTE palette;
};

class CLoading : public CDialog
{
	// Construction
public:
	void PrepareUnitGraphic(const CString& lpUnittype);
	void LoadStrings();
	void FreeAll();
	void FreeTileSet();
	BOOL InitDirectDraw();

	void InitTMPs(CProgressCtrl* prog = NULL);
	void InitPalettes();

	~CLoading();
	void Unload();
	BOOL InitMixFiles();
	void InitSHPs(CProgressCtrl* prog = NULL);
	void LoadTSIni(LPCTSTR lpFilename, CIniFile* lpIniFile, BOOL bIsExpansion, BOOL bCheckEditorDir = FALSE);
	void CreateINI();
	CLoading(CWnd* pParent = NULL);   // Standardconstructor
	void InitPics(CProgressCtrl* prog = NULL);
	void Load();
	bool LoadSingleFrameShape(const CString& name, int nFrame = 0, int deltaX = 0, int deltaY = 0);
	void LoadBuilding(const CString& ID);
	void LoadInfantry(const CString& ID);
	void LoadTerrainOrSmudge(const CString& ID);
	void LoadVehicleOrAircraft(const CString& ID);

	void SetImageData(unsigned char* pBuffer, const CString& NameInDict, int FullWidth, int FullHeight, Palette* pPal, bool forceNoRemap = false);
	void SetImageData(unsigned char* pBuffer, PICDATA& pData, const int FullWidth, const int FullHeight, Palette* pPal, bool forceNoRemap);
	void UnionSHP_Add(unsigned char* pBuffer, int Width, int Height, int DeltaX = 0, int DeltaY = 0, bool UseTemp = false);
	void UnionSHP_GetAndClear(unsigned char*& pOutBuffer, int* OutWidth, int* OutHeight, bool clearBuffer = true, bool UseTemp = false);
	void VXL_Add(const unsigned char* pCache, int X, int Y, int Width, int Height);
	void VXL_GetAndClear(unsigned char*& pBuffer, int* OutWidth, int* OutHeight);
	void VXL_Reset();
	BOOL LoadUnitGraphic(const CString& lpUnittype);
	void LoadBuildingSubGraphic(const CString& subkey, const CIniFileSection& artSection, BOOL bAlwaysSetChar, char theat, HMIXFILE hShpMix, SHPHEADER& shp_h, BYTE*& shp);
	void LoadOverlayGraphic(const CString& lpOvrlName, int iOvrlNum);
	void InitVoxelNormalTables();
	std::optional<FindShpResult> FindUnitShp(const CString& image, char preferred_theat, const CIniFileSection& artSection);
	char cur_theat;

	HMIXFILE FindFileInMix(LPCTSTR lpFilename, TheaterChar* pTheaterChar = NULL);

	const HMIXFILE CacheMix() const {
		return m_hCache;
	}
	const EXPANDMIX* ExpandMixes() const {
		return m_hExpand;
	}

	enum class ObjectType
	{
		Unknown = -1,
		Infantry = 0,
		Vehicle = 1,
		Aircraft = 2,
		Building = 3,
		Terrain = 4,
		Smudge = 5
	};

	ObjectType GetItemType(const CString& ID);
	CString GetArtID(const CString& ID);
	CString GetVehicleOrAircraftFileID(const CString& ID);
	CString GetTerrainOrSmudgeFileID(const CString& ID);
	CString GetBuildingFileID(const CString& ID);
	CString GetInfantryFileID(const CString& ID);

	// Dialog data
		//{{AFX_DATA(CLoading)
	enum { IDD = IDD_LOADING };
	CStatic	m_Version;
	CStatic	m_BuiltBy;
	CStatic	m_cap;
	CProgressCtrl	m_progress;
	//}}AFX_DATA


// Overwriteables
	// class wizard generated overwriteables
	//{{AFX_VIRTUAL(CLoading)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-support
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL

// Implementation
protected:
	void PrepareBuildingTheaters();

	// generated message handlers
	//{{AFX_MSG(CLoading)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void HackRules();
	void PrepareHouses(void);
	void CalcPicCount();
	int m_pic_count;
	int m_bmp_count;
	BOOL LoadTile(LPCSTR lpFilename, HMIXFILE hOwner, HTSPALETTE hPalette, DWORD dwID, BOOL bReplacement);

	Palettes m_palettes;

	HMIXFILE m_hLocal;
	HMIXFILE m_hSno;
	HMIXFILE m_hTem;
	HMIXFILE m_hUrb;
	HMIXFILE m_hLun;
	HMIXFILE m_hDes;
	HMIXFILE m_hUbn;
	HMIXFILE m_hTibSun;
	HMIXFILE m_hBuildings;
	EXPANDMIX m_hExpand[101]; // 1 added for ra2md.mix
	HMIXFILE m_hECache[100];
	HMIXFILE m_hIsoSnow;
	HMIXFILE m_hIsoTemp;
	HMIXFILE m_hIsoUrb;
	HMIXFILE m_hIsoGen;
	HMIXFILE m_hIsoLun;
	HMIXFILE m_hIsoDes;
	HMIXFILE m_hIsoUbn;
	HMIXFILE m_hTemperat;
	HMIXFILE m_hSnow;
	HMIXFILE m_hUrban;
	HMIXFILE m_hUrbanN;
	HMIXFILE m_hLunar;
	HMIXFILE m_hDesert;
	HMIXFILE m_hCache;
	HMIXFILE m_hConquer;
	HMIXFILE m_hLanguage;
	HMIXFILE m_hLangMD;
	HMIXFILE m_hMarble;
	BOOL loaded;

	std::unique_ptr<VoxelNormalTables> m_voxelNormalTables;

	struct SHPUnionData
	{
		unsigned char* Buffer;// This buffer allocated from outside
		int Width;
		int Height;
		int DeltaX;
		int DeltaY;
	};

	std::map<CString, ObjectType> ObjectTypes;
	std::vector<SHPUnionData> UnionSHP_Data[2];
	static auto constexpr VoxelBlendCacheLength = 0x10000;
	unsigned char VXL_Data[VoxelBlendCacheLength];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ fügt unmittelbar vor der vorhergehenden Zeile zusätzliche Deklarationen ein.

#endif // AFX_LOADING_H__5D5C3284_8962_11D3_B63B_AAA51FD322E3__INCLUDED_
