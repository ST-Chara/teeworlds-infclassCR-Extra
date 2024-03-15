// Copyright (c) ST-Chara 2024 - 2024
#pragma once

#include <game/server/entity.h>

class CDoctorFunnel : public CEntity
{
public:
    enum
    {
        NUM_LASER = 9,
        NUM_LASER_C = 16,

        STATE_FOLLOW = 0,
        STATE_FIND,
        STATE_TARGET,
        STATE_STAY,
        NUM_STATE,
    };

public:
    CDoctorFunnel(CGameWorld *pGameWorld, vec2 Pos, int Owner);
    virtual ~CDoctorFunnel();

    virtual void Snap(int SnappingClient);
    virtual void Reset();
    virtual void Tick();

    vec2 GetOwnerPos();
    vec2 GetTargetPos();

private:
    int m_Owner;
    int m_Angle;
    int m_LaserIDs[NUM_LASER];
    int m_aLaserIDs[NUM_LASER_C];
    bool m_LowPower;
    bool m_LockTarget;
    int m_TargetCID;
    int m_ConnectID;
    int m_ChangeTargetNeed;
    vec2 m_TargetPos;
};