modded class MissionGameplay
{
	override void Pause()
	{
		if ( GetDayZGame().GetExpansionGame().GetExpansionUIManager().GetMenu() )
			return;
		
		super.Pause();
	}

	override void CloseAllMenus()
	{
		super.CloseAllMenus();
		
		if ( GetDayZGame().GetExpansionGame().GetExpansionUIManager().GetMenu() )
			GetDayZGame().GetExpansionGame().GetExpansionUIManager().CloseAll();
	}
};