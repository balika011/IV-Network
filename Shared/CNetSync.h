//================= IV:Network - https://github.com/GTA-Network/IV-Network =================
//
// File: CNetSync.h
// Project: Client.Core
// Author: FRi<FRi.developing@gmail.com>
// License: See LICENSE in root directory
//
//==========================================================================================

#ifndef CNetSync_h
#define CNetSync_h

#include "Common.h"
#include "Math/CMaths.h"
#include "Game/eInput.h"

enum ePackageType
{
	RPC_PACKAGE_TYPE_SMALL = 0x1,
	RPC_PACKAGE_TYPE_PLAYER_ONFOOT = 0x21,
	RPC_PACKAGE_TYPE_PLAYER_VEHICLE = 0x22,
	RPC_PACKAGE_TYPE_PLAYER_PASSENGER = 0x23,
	RPC_PACKAGE_TYPE_VEHICLE = 0x3,
	RPC_PACKAGE_TYPE_ACTOR = 0x4,
	RPC_PACKAGE_TYPE_OBJECT = 0x5
};

enum eDisconnectReason
{
	REASON_DISCONNECT,
	REASON_TIMEOUT,
	REASON_KICKED
};

enum eNetworkState
{
	NETSTATE_NONE = 0,
	NETSTATE_STARTED,
	NETSTATE_CONNECTING,
	NETSTATE_CONNECTED,
	NETSTATE_AWAIT_JOIN,
	NETSTATE_DISCONNECTED,
	NETSTATE_TIMEOUT,
	NETSTATE_AWAIT_CONNECT
};

enum eEntityType
{
	PLAYER_ENTITY,
	VEHICLE_ENTITY,
	OBJECT_ENTITY,
	PICKUP_ENTITY,
	LABEL_ENTITY,
	FIRE_ENTITY,
	CHECKPOINT_ENTITY,
	BLIP_ENTITY,
	ACTOR_ENTITY,
	UNKNOWN_ENTITY, // MAX_ENTITY
	INVALID_ENTITY,
};


// Handles data between client ped and network sync(stores the values)
class CNetworkEntitySubPlayer {
private:

public:
	CControls					pControlState;
	CVector3					vecPosition;
	CVector3					vecMovementSpeed;
	CVector3					vecTurnSpeed;
	CVector3					vecDirection;
	CVector3					vecRoll;

	bool						bDuckState;
	float						fHeading;

	struct {
		CVector3				vecAimAtCoordinates;
		float					fArmsHeadingCircle;
		float					fArmsUpDownRotation;
		CVector3				vecShotAtCoordinates;
		CVector3				vecShotAtTarget;
		CVector3				vecLookAtCoordinates;
		//Matrix34				pWeaponCameraA;
		//Matrix34				pWeaponCameraB;
		//Matrix34				pWeaponCameraC;

	}							sWeaponData;
	// Add player members to sync(like weapon sync, key sync etc.)
};

// Handles data between client ped and network sync(stores the values)
class CNetworkEntitySubVehicle {
private:

public:
	CVector3					vecPosition;
	CVector3					vecMovementSpeed;
	CVector3					vecTurnSpeed;
	CVector3					vecDirection;
	CVector3					vecRoll;
	// Add vehicle members to sync(like indicators, variation etc.)
};

class CNetworkEntitySync {
public:

	eEntityType							pEntityType;
	CNetworkEntitySubPlayer				pPlayerPacket;
	CNetworkEntitySubVehicle			pVehiclePacket;
};



#define	NETWORK_TIMEOUT					3000

#endif // CNetSync_h