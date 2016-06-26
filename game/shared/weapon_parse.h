//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: Weapon data file parsing, shared by game & client dlls.
//
// $NoKeywords: $
//=============================================================================//

#ifndef WEAPON_PARSE_H
#define WEAPON_PARSE_H
#ifdef _WIN32
#pragma once
#endif

#include "shareddefs.h"

class IFileSystem;

typedef unsigned short WEAPON_FILE_INFO_HANDLE;

// -----------------------------------------------------------
// Weapon sound types
// Used to play sounds defined in the weapon's classname.txt file
// This needs to match pWeaponSoundCategories in weapon_parse.cpp
// ------------------------------------------------------------
typedef enum {
	EMPTY,
	SINGLE,
	SINGLE_NPC,
	WPN_DOUBLE, // Can't be "DOUBLE" because windows.h uses it.
	DOUBLE_NPC,
	BURST,
	RELOAD,
	RELOAD_NPC,
	MELEE_MISS,
	MELEE_HIT,
	MELEE_HIT_WORLD,
	SPECIAL1,
	SPECIAL2,
	SPECIAL3,
	TAUNT,
	FAST_RELOAD,

	// Add new shoot sound types here

	NUM_SHOOT_SOUND_TYPES,
} WeaponSound_t;

int GetWeaponSoundFromString( const char *pszString );

#define MAX_SHOOT_SOUNDS	16			// Maximum number of shoot sounds per shoot type

#define MAX_WEAPON_STRING	80
#define MAX_WEAPON_PREFIX	16
#define MAX_WEAPON_AMMO_NAME		32

#define WEAPON_PRINTNAME_MISSING "!!! Missing printname on weapon"

class CHudTexture;
class KeyValues;

//-----------------------------------------------------------------------------
// Purpose: Contains the data read from the weapon's script file. 
// It's cached so we only read each weapon's script file once.
// Each game provides a CreateWeaponInfo function so it can have game-specific
// data (like CS move speeds) in the weapon script.
//-----------------------------------------------------------------------------
class FileWeaponInfo_t
{
public:
	FileWeaponInfo_t();
	
	// Each game can override this to get whatever values it wants from the script.
	virtual void Parse( KeyValues *pKeyValuesData, const char *szWeaponName );

public:	
	bool bParsedScript; //0x0004 
	bool bLoadedHudElements; //0x0005 
	char szClassName[MAX_WEAPON_STRING]; //0x0006 
	char szPrintName[MAX_WEAPON_STRING]; //0x0056 
	char szViewModel[MAX_WEAPON_STRING]; //0x00A6 
	char szWorldModel[MAX_WEAPON_STRING]; //0x00F6 
	char szAmmo[MAX_WEAPON_AMMO_NAME]; //0x0146 
	char szAnimationPrefix[MAX_WEAPON_PREFIX]; //0x0166 
	int iSlot; //0x0178 
	int iPosition; //0x017C 
	int iMaxClip1; //0x0180 
	int iMaxClip2; //0x0184 
	int iDefaultClip1; //0x0188 
	int iDefaultClip2; //0x018C 
	int iWeight; //0x0190 
	int iRumbleEffect; //0x0194 
	bool bAutoSwitchTo; //0x0198 
	bool bAutoSwitchFrom; //0x0199 
	char pad_0x019A[0x2]; //0x019A
	int iFlags; //0x019C 
	char szAmmo2[MAX_WEAPON_AMMO_NAME]; //0x01A0 
	char szAIAddOn[MAX_WEAPON_STRING]; //0x01C0 
	char aShootSounds[NUM_SHOOT_SOUND_TYPES][MAX_WEAPON_STRING]; //0x0210 
	int iAmmoType; //0x0710 
	int iAmmo2Type; //0x0714 
	bool m_bMeleeWeapon; //0x0718 
	bool m_bBuiltRightHanded; //0x0719 
	bool m_bAllowFlipping; //0x071A 
	char pad_0x071B[0x1]; //0x071B
	int iSpriteCount; //0x071C 
	CHudTexture* iconActive; //0x0720 
	CHudTexture* iconInactive; //0x0724 
	CHudTexture* iconAmmo; //0x0728 
	CHudTexture* iconAmmo2; //0x072C 
	CHudTexture* iconCrosshair; //0x0730 
	CHudTexture* iconAutoaim; //0x0734 
	CHudTexture* iconZoomedCrosshair; //0x0738 
	CHudTexture* iconZoomedAutoaim; //0x073C 
	CHudTexture* iconSmall; //0x0740 
	bool bShowUsageHint; //0x0744 
	char pad_0x0745[0x3]; //0x0745
	int m_iWeaponType; //0x0748 
	int m_iTeam; //0x074C 
	int m_iWeaponID; //0x0750 
	char pad_0x0754[0x8]; //0x0754
	int m_iWeaponPrice; //0x075C 
	float m_flArmorPenetration; //0x0760 
	float m_flMobility; //0x0764 
	char pad_0x0768[0x10]; //0x0768
	int m_iDamage; //0x0778 
	float m_fRange; //0x077C 
	float m_fRangeModifier; //0x0780 
	int m_iBullets; //0x0784 
	float m_fCycleTime; //0x0788 
	char pad_0x078C[0x4]; //0x078C
	char szMuzzleSmoke[MAX_WEAPON_STRING]; //0x0790 
	char pad_0x07E0[0xC]; //0x07E0
	char szMuzzleFlashFP[MAX_WEAPON_STRING]; //0x07EC 
	char szMuzzleFlash[MAX_WEAPON_STRING]; //0x083C 
	char szShellCasing[MAX_WEAPON_STRING]; //0x088C 
	char szTracer[MAX_WEAPON_STRING]; //0x08DC 
	int iTracerType; //0x092C 
	char pad_0x0930[0x544]; //0x0930
	float N00002541; //0x0E74 
	bool N00002542; //0x0E78 
	char N00002677[MAX_WEAPON_AMMO_NAME]; //0x0E79
	char szWeaponType[MAX_WEAPON_PREFIX]; //0x0E99 
	char szRModel[64]; //0x0EA9 
	char szWorldModel2[MAX_WEAPON_STRING]; //0x0EE9 
	char pad_0x0F39[0xB7]; //0x0F39


	//bool					bParsedScript;
	//bool					bLoadedHudElements;
	//// SHARED
	//char					szClassName[MAX_WEAPON_STRING];
	//char					szPrintName[MAX_WEAPON_STRING];			// Name for showing in HUD, etc.
	//
	//char					szViewModel[MAX_WEAPON_STRING];			// View model of this weapon
	//char					szWorldModel[MAX_WEAPON_STRING];		// Model of this weapon seen carried by the player
	//char					szAmmo[MAX_WEAPON_AMMO_NAME];
	//char					szAnimationPrefix[MAX_WEAPON_PREFIX];	// Prefix of the animations that should be used by the player carrying this weapon
	//int					iSlot;									// inventory slot.
	//int					iPosition;								// position in the inventory slot.
	//int					iMaxClip1;								// max primary clip size (-1 if no clip)
	//int					iMaxClip2;								// max secondary clip size (-1 if no clip)
	//int					iDefaultClip1;							// amount of primary ammo in the gun when it's created
	//int					iDefaultClip2;							// amount of secondary ammo in the gun when it's created
	//int					iWeight;								// this value used to determine this weapon's importance in autoselection.
	//int					iRumbleEffect;							// Which rumble effect to use when fired? (xbox)
	//bool					bAutoSwitchTo;							// whether this weapon should be considered for autoswitching to
	//bool					bAutoSwitchFrom;						// whether this weapon can be autoswitched away from when picking up another weapon or ammo
	//int					iFlags;									// miscellaneous weapon flags
	//char					szAmmo2[MAX_WEAPON_AMMO_NAME];
	//char					szAIAddOn[MAX_WEAPON_STRING];			// addon that this weapon can become
	//
	//// Sound blocks
	//char					aShootSounds[NUM_SHOOT_SOUND_TYPES][MAX_WEAPON_STRING];	
	//int					iAmmoType;
	//int					iAmmo2Type;
	//bool					m_bMeleeWeapon;		// Melee weapons can always "fire" regardless of ammo.
	//// This tells if the weapon was built right-handed (defaults to true).
	//// This helps cl_righthand make the decision about whether to flip the model or not.
	//bool					m_bBuiltRightHanded;
	//bool					m_bAllowFlipping;	// False to disallow flipping the model, regardless of whether
	//											// it is built left or right handed.
	//// CLIENT DLL
	//// Sprite data, read from the data file
	//int						iSpriteCount; // 0x71C
	//CHudTexture*			iconActive;
	//CHudTexture*			iconInactive;
	//CHudTexture*			iconAmmo;
	//CHudTexture*			iconAmmo2;
	//CHudTexture*			iconCrosshair;
	//CHudTexture*			iconAutoaim;
	//CHudTexture*			iconZoomedCrosshair;
	//CHudTexture*			iconZoomedAutoaim;
	//CHudTexture*			iconSmall;
	//bool					bShowUsageHint;
	//char					szMuzzleSmoke[MAX_WEAPON_STRING];
	////
	//char					szMuzzleFlashFP[MAX_WEAPON_STRING];
	//char					szMuzzleFlash[MAX_WEAPON_STRING];
	//char					szShellCasing[MAX_WEAPON_STRING];
	//char					szTracer[MAX_WEAPON_STRING];
	//int						iTracerType;
};//Size=0x0FF0

// The weapon parse function
bool ReadWeaponDataFromFileForSlot( IFileSystem* filesystem, const char *szWeaponName, 
	WEAPON_FILE_INFO_HANDLE *phandle, const unsigned char *pICEKey = NULL );

// If weapon info has been loaded for the specified class name, this returns it.
WEAPON_FILE_INFO_HANDLE LookupWeaponInfoSlot( const char *name );

FileWeaponInfo_t *GetFileWeaponInfoFromHandle( WEAPON_FILE_INFO_HANDLE handle );
WEAPON_FILE_INFO_HANDLE GetInvalidWeaponInfoHandle( void );
void PrecacheFileWeaponInfoDatabase( IFileSystem *filesystem, const unsigned char *pICEKey );


// 
// Read a possibly-encrypted KeyValues file in. 
// If pICEKey is NULL, then it appends .txt to the filename and loads it as an unencrypted file.
// If pICEKey is non-NULL, then it appends .ctx to the filename and loads it as an encrypted file.
//
// (This should be moved into a more appropriate place).
//
KeyValues* ReadEncryptedKVFile( IFileSystem *filesystem, const char *szFilenameWithoutExtension, const unsigned char *pICEKey );


// Each game implements this. It can return a derived class and override Parse() if it wants.
extern FileWeaponInfo_t* CreateWeaponInfo();


#endif // WEAPON_PARSE_H
