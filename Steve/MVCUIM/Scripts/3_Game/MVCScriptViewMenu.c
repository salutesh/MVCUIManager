class MVCScriptViewMenu: ScriptView
{
    private int m_SVMenuID = -1;
	private bool m_IsVisible = false;
	private bool m_Active = false;

	void MVCScriptViewMenu()
	{
		Debug_Logging = true;
		
		if (GetLayoutRoot().IsVisible()) SetIsVisible(true);
	}
	
	void SetIsVisible(bool state)
	{
		m_IsVisible = state;
	}
	
	bool IsVisible()
	{
		return m_IsVisible;
	}
	
	void SetID(int id)
	{
		m_SVMenuID = id;
	}
	
	int GetID()
	{
		return m_SVMenuID;
	}
	
	void Show()
	{
		if (!CanShow())
			return;
		
		SetIsVisible(true);
		GetLayoutRoot().Show(true);
		OnShow();
	}
	
	void OnShow()
	{
		LockControls(true);
		PPEffects.SetBlurMenu(0.5);
		SetFocus(GetLayoutRoot());
	}
	
	void Hide()
	{
		SetIsVisible(false);
		GetLayoutRoot().Show(false);
		OnHide();
	}
	
	void OnHide()
	{
		LockControls(false);
		PPEffects.SetBlurMenu(0.0);
	}
	
	void LockControls(bool active)
	{
		m_Active = active;
		
		Input input = GetGame().GetInput();
		Mission mission = GetGame().GetMission();
		
		// we are in 4_world and this game is bad :)
		Widget hud_root;
		EnScript.GetClassVar(GetGame().GetMission(), "m_HudRootWidget", 0, hud_root);
		if (hud_root) {
			hud_root.Show(!m_Active);
		}
		
		GetGame().GetPlayer().GetInputController().SetDisabled(m_Active);
		if (m_Active == true)
		{
			input.ChangeGameFocus(1, INPUT_DEVICE_MOUSE);
			input.ChangeGameFocus(1, INPUT_DEVICE_KEYBOARD);
			input.ChangeGameFocus(1, INPUT_DEVICE_GAMEPAD);
			mission.PlayerControlDisable(INPUT_EXCLUDE_ALL);
		}
		else
		{
			input.ChangeGameFocus(-1, INPUT_DEVICE_MOUSE);
			input.ChangeGameFocus(-1, INPUT_DEVICE_KEYBOARD);
			input.ChangeGameFocus(-1, INPUT_DEVICE_GAMEPAD);
			mission.PlayerControlEnable(m_Active);
		}
		
		ShowHud(m_Active);
		ShowUICursor(m_Active);
	}
	
	void ShowHud(bool state)
	{
		Mission mission = GetGame().GetMission();
		mission.GetHud().ShowHud(!m_Active);
		mission.GetHud().ShowQuickbarPlayer(!m_Active);
	}
	
	void ShowUICursor(bool state)
	{
		UIManager vanillaUIManager = GetGame().GetUIManager();
		vanillaUIManager.ShowUICursor(m_Active);
	}
	
	bool CanShow()
	{
		return true;
	}
};