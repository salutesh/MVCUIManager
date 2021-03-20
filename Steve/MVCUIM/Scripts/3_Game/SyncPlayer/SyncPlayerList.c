modded class SyncPlayerList
{
	override void CreatePlayerList()
	{
		if ( GetGame().IsServer() )
		{
			if ( m_PlayerList )
			{
				m_PlayerList.Clear();
			} else
			{
				m_PlayerList = new array< ref SyncPlayer >;
			}

			array< Man > players = new array< Man >;
			GetGame().GetWorld().GetPlayerList( players );

			for ( int i = 0; i < players.Count(); ++i )
			{
				Man player = players[i];
				if  ( player.GetIdentity() )
				{
					ref SyncPlayer sync_player = new SyncPlayer;
					sync_player.m_UID = player.GetIdentity().GetPlainId();
					sync_player.m_RUID = player.GetIdentity().GetId();
					sync_player.m_SteamID = player.GetIdentity().GetPlainId();
					sync_player.m_PlayerID = player.GetIdentity().GetPlayerId();
					sync_player.m_PlayerName = player.GetIdentity().GetName();
					m_PlayerList.Insert( sync_player );
				} else
				{
					DebugPrint.LogErrorAndTrace("No Identity in Server Player List");
				}
			}
		}
	}
};