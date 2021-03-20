modded class MissionGameplay
{
    ref MVCUIMenuManager m_MVCUIMenuManager;
	
	void MissionGameplay()
	{		
		CreateMVCUIMenuManager();
	}

	void ~MissionGameplay()
	{
		DestroyMVCUIMenuManager();
	}

	override void Pause()
	{
		if ( GetDayZGame().GetMVCUIManager().GetMenu() )
			return;
		
		super.Pause();
	}

	override void CloseAllMenus()
	{
		super.CloseAllMenus();
		
		if ( GetDayZGame().GetMVCUIManager().GetMenu() )
			GetDayZGame().GetMVCUIManager().CloseAll();
	}

    void CreateMVCUIMenuManager()
	{
		ref MVCUIManager mvcUIManager = GetDayZGame().GetMVCUIManager();
		if (mvcUIManager && !m_MVCUIMenuManager)
			m_MVCUIMenuManager = new MVCUIMenuManager(mvcUIManager);
	}
	
	void DestroyMVCUIMenuManager()
	{
		if (m_MVCUIMenuManager)
			delete m_MVCUIMenuManager;
	}
	
	MVCUIMenuManager GetMVCUIMenuManager()
	{
		return m_MVCUIMenuManager;
	}
	
	override void OnUpdate( float timeslice )   
	{
        super.OnUpdate(timeslice);

		Print("Update!");
		
		//! Checking for keyboard focus
		bool inputIsFocused = false;
		//! Reference to focused windget
		Widget focusedWidget = GetFocus();

		if ( focusedWidget )
		{
			if (focusedWidget.ClassName().Contains("EditBoxWidget"))
			{
				inputIsFocused = true;
			}
			else if (focusedWidget.ClassName().Contains("MultilineEditBoxWidget"))
			{
				inputIsFocused = true;
			}
		}

		Man man 						= GetGame().GetPlayer(); 	//! Refernce to man
		Input input 					= GetGame().GetInput(); 	//! Reference to input
		UIScriptedMenu topMenu 			= m_UIManager.GetMenu(); 	//! Reference to menu
		PlayerBase playerPB 			= PlayerBase.Cast( man );	//! Reference to player
		
		if (playerPB && playerPB.GetHumanInventory()) 
		{
			if (playerPB.GetPlayerState() == EPlayerStates.ALIVE && !playerPB.IsUnconscious())
			{
				if (input.LocalPress("UAMVCPlayerListToggle", false))
				{
					if (!topMenu && !inputIsFocused)
					{
						OnPlayerListTogglePressed();
					}
				}
			}
		}
    }
	
	void OnPlayerListTogglePressed()
	{
		Print("Test");
		MVCUIManager uiManager = GetDayZGame().GetMVCUIManager();	//! Reference to mvc ui manager
		ScriptView menu	= uiManager.GetMenu();						//! Reference to current opened script view menu
		
		MVCPlayerListMenu playerListMenu = MVCPlayerListMenu.Cast(menu);
		if (!playerListMenu)
		{
			uiManager.CreateSVMenu(MVC_PLAYERLIST_MENU);
		} 
		else if (playerListMenu && playerListMenu.IsVisible())
		{
			uiManager.CloseMenu();
		}
	}
};