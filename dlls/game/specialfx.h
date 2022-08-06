//-----------------------------------------------------------------------------
//
//  $Logfile:: /Code/DLLs/game/specialfx.h                                   $
// $Revision:: 3                                                              $
//   $Author:: Steven                                                         $
//     $Date:: 10/13/03 8:54a                                                 $
//
// Copyright (C) 1997 by Ritual Entertainment, Inc.
// All rights reserved.
//
// This source is may not be distributed and/or modified without
// expressly written permission by Ritual Entertainment, Inc.
//
//
// DESCRIPTION:
// special effects
//

#ifndef __SPECIAL_FX_H__
#define __SPECIAL_FX_H__

#include "g_local.h"
#include "scriptslave.h"

class Fulcrum : public ScriptSlave
	{
   private:
      float       resetspeed;
      float       dampening;
      float       limit;
      float       speed;
      qboolean    touched;
      Vector      startangles;
      str         movesound;

	public:
      CLASS_PROTOTYPE( Fulcrum );
                  Fulcrum();

      void        Setup( Event *ev );
      void        SetSpeed( Event *ev );
      void        SetResetSpeed( Event *ev );
      void        SetDampening( Event *ev );
      void        SetLimit( Event *ev );
      void        SetMoveSound( Event *ev );
      void        Reset( Event *ev );
      void        Touched( Event *ev );
      void        Adjust( Event *ev );
      virtual void Archive( Archiver &arc );
	};

inline void Fulcrum::Archive
	(
	Archiver &arc
	)
   {
   ScriptSlave::Archive( arc );

   arc.ArchiveFloat( &resetspeed );
   arc.ArchiveFloat( &dampening );
   arc.ArchiveFloat( &limit );
   arc.ArchiveFloat( &speed );
   arc.ArchiveBoolean( &touched );
   arc.ArchiveVector( &startangles );
   arc.ArchiveString( &movesound );
   }


class RunThrough : public Entity
	{
   private:
      Vector      offset;
      float       speed;
      float       chance;
      float       delay;
      float       lasttriggertime;
      float       lip;
      str         spawnmodel;

      void        SetSpeed( Event *ev );
      void        SetChance( Event *ev );
      void        SetDelay( Event *ev );
      void        SetLip( Event *ev );
      void        SetSpawnModel( Event *ev );
      void        SetOffset( Event *ev );
      void        Touched( Event *ev );
	public:
      CLASS_PROTOTYPE( RunThrough );
                  RunThrough();

      virtual void Archive( Archiver &arc );
	};

inline void RunThrough::Archive
	(
	Archiver &arc
	)
   {
   Entity::Archive( arc );

   arc.ArchiveVector( &offset );
   arc.ArchiveFloat( &speed );
   arc.ArchiveFloat( &chance );
   arc.ArchiveFloat( &delay );
   arc.ArchiveFloat( &lasttriggertime );
   arc.ArchiveFloat( &lip );
   arc.ArchiveString( &spawnmodel );
   }

class SinkObject : public ScriptSlave
	{
   private:
      float       resetspeed;
      float       resetdelay;
      float       dampening;
      float       limit;
      float       speed;
      float       delay;
      float       time_touched;
      float       time_reset;
      str         sinksound;
      str         resetsound;
      qboolean    touched;
      qboolean    active;
      Vector      startpos;

	public:
      CLASS_PROTOTYPE( SinkObject );
                  SinkObject();

      void        Setup( Event *ev );
      void        SetSpeed( Event *ev );
      void        SetDelay( Event *ev );
      void        SetResetSpeed( Event *ev );
      void        SetResetDelay( Event *ev );
      void        SetDampening( Event *ev );
      void        SetLimit( Event *ev );
      void        Reset( Event *ev );
      void        Touched( Event *ev );
      void        Adjust( Event *ev );
      void        Fall( Event *ev );
      void        SetResetSound( Event *ev );
      void        SetSinkSound( Event *ev );
      void        MakeActive( Event *ev );
      void        MakeNonActive( Event *ev );
      virtual void Archive( Archiver &arc );
	};

inline void SinkObject::Archive
	(
	Archiver &arc
	)
   {
   ScriptSlave::Archive( arc );

   arc.ArchiveFloat( &resetspeed );
   arc.ArchiveFloat( &resetdelay );
   arc.ArchiveFloat( &dampening );
   arc.ArchiveFloat( &limit );
   arc.ArchiveFloat( &speed );
   arc.ArchiveFloat( &delay );
   arc.ArchiveFloat( &time_touched );
   arc.ArchiveFloat( &time_reset );
   arc.ArchiveString( &sinksound );
   arc.ArchiveString( &resetsound );
   arc.ArchiveBoolean( &touched );
   arc.ArchiveBoolean( &active );
   arc.ArchiveVector( &startpos );
   }

#endif /* specialfx.h */
