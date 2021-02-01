#include "GameManager.h"

void SetConsoleWindow(int iWidth, int iHeight)
{
	char buf[256];
	int width = (iWidth * 2) + 1;
	int height = iHeight + 3;
	sprintf(buf, "mode con: lines=%d cols=%d", height, width);
	system(buf);
}

void GameManager::DispLoby()
{
	BLUE
	m_gmMapDraw.BoxDraw(0,0,WIDTH,HEIGHT);
	ORIGINAL
	m_gmMapDraw.DrawMidText("☆★ Creed RPG ★☆",WIDTH,HEIGHT*0.3f);
	m_gmMapDraw.DrawMidText("New Game ", WIDTH, HEIGHT * 0.4f);
	m_gmMapDraw.DrawMidText("Load Game", WIDTH, HEIGHT * 0.5f);
	m_gmMapDraw.DrawMidText("Game Exit", WIDTH, HEIGHT * 0.6f);
}

void GameManager::NewGameSet()
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);

	ifstream fPlayerLoad;
	fPlayerLoad.open("DefaultPlayer.txt");
	ifstream fMonsterLoad;
	fMonsterLoad.open("DefaultMonster.txt");
	fMonsterLoad >> m_iMonsterCount;
	for (int i = 0;i<MAX_CHARACTER;i++)
	{
		if (i == PLAYER)
		{
			m_gmCharacter[i] = new Player;
			YELLOW
			m_gmMapDraw.DrawMidText("Player 이름 입력 : ", WIDTH, HEIGHT * 0.5f);
			ORIGINAL
		}
		else
			m_gmCharacter[i] = new Monster;
		for (int j = 0; j < NUMBER_INFO; j++)
		{
			string strTemp;
			if (i == PLAYER)
			{
				if (j == (int)INFO_LIST_NAME)
					cin >> strTemp;
				else
					fPlayerLoad >> strTemp;
			}
			else
				fMonsterLoad >> strTemp;
			m_gmCharacter[i]->SetInfo(strTemp, j);
		}
	}
	fPlayerLoad.close();
	fMonsterLoad.close();


}

void GameManager::DispPlayMenu()
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText("☆★ Menu ★☆", WIDTH, HEIGHT * 0.3);
	m_gmMapDraw.DrawMidText("Dungeon", WIDTH, HEIGHT * 0.3f+2);
	m_gmMapDraw.DrawMidText("Player Info", WIDTH, HEIGHT * 0.3f +4);
	m_gmMapDraw.DrawMidText("Monster Info", WIDTH, HEIGHT * 0.3f + 6);
	m_gmMapDraw.DrawMidText("Weapon Shop", WIDTH, HEIGHT * 0.3f + 8);
	m_gmMapDraw.DrawMidText("Save", WIDTH, HEIGHT * 0.3f + 10);
	m_gmMapDraw.DrawMidText("Exit", WIDTH, HEIGHT * 0.3f + 12);
}

void GameManager::DispInfo(int selection)
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	if (selection == (int)PLAY_MENU_PLAYER_INFO)
		m_gmCharacter[PLAYER]->ShowInfo();
	else
	{
		int AddCol = 0;
		for (int j = 1; j < MAX_CHARACTER; j++)
		{
			m_gmCharacter[j]->ShowInfo(AddCol);
			AddCol += 4;
		}
	}
	getch();
}



void GameManager::DispEntrance()
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText("====== 던전 입구 ======", WIDTH, HEIGHT * 0.2f);
	int i;
	for (i = 1; i <= MAX_MONSTER; i++)
	{
		string strTemp;
		strTemp = to_string(i) + " 층 던전 : [" + m_gmCharacter[i]->GetName() + "]";
		m_gmMapDraw.TextDraw(strTemp, WIDTH-10, HEIGHT * 0.2f + 3 + 2*i);
	}
	m_gmMapDraw.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.2f + 3 + 2*i);
}

int GameManager::WinLoseDraw(int player, int monster)
{
	if (player - monster == 1 || player -monster == -2)
	{
		//Win
		m_gmMapDraw.DrawMidText(" Win", WIDTH, HEIGHT*0.4f+1);
		m_gmMapDraw.DrawMidText("Lose", WIDTH, HEIGHT*0.4f+5);
		return 1;
	}
	else if (player - monster == 0)
	{
		//Draw
		m_gmMapDraw.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 1);
		m_gmMapDraw.DrawMidText("Draw", WIDTH, HEIGHT * 0.4f + 5);
		return 2;
	}
	else
	{
		//Lose
		m_gmMapDraw.DrawMidText("Lose", WIDTH, HEIGHT * 0.4f + 1);
		m_gmMapDraw.DrawMidText(" Win", WIDTH, HEIGHT * 0.4f + 5);
		return 3;
	}
}

void GameManager::DispResult(int result, int WinNumber, int LoseNumber)
{
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	RED
	string strTempName = m_gmCharacter[WinNumber]->GetName();
	m_gmMapDraw.DrawMidText(strTempName + " 승리!!", WIDTH, HEIGHT * 0.3f);
	m_gmMapDraw.DrawMidText(strTempName + "가 경험치 " + to_string(m_gmCharacter[LoseNumber]->GetGetExp()) + "를 얻었습니다.", WIDTH, HEIGHT * 0.4f);
	if(result == LOSE)
	{
		getch();
		m_gmMapDraw.DrawMidText("Game Over", WIDTH, HEIGHT * 0.5f);
	}
	ORIGINAL
}

void GameManager:: CheckGameEnd(int MonsterNumber)
{
	if (m_gmCharacter[MonsterNumber]->GetCurVital() == 0)
	{
		getch();
		//승리 화면 표시
		DispResult(WIN, PLAYER, MonsterNumber);
		m_eSTATE = STATE_WIN;
	}
	else if (m_gmCharacter[PLAYER]->GetCurVital() == 0)
	{
		getch();
		//GameOver 화면 표시
		DispResult(LOSE, MonsterNumber, PLAYER);
		m_eSTATE = STATE_OVER;
	}
	else
	{
		m_eSTATE = STATE_ING;
		return;
	}
}

void GameManager::DispLevelUp()
{
	
	PURPLE
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText(m_gmCharacter[PLAYER]->GetName() + "레벨업", WIDTH, HEIGHT*0.4f);
	m_gmMapDraw.DrawMidText("공격력 " + to_string(m_iAddAttack) + " 증가!!", WIDTH, HEIGHT*0.5f);
	m_gmMapDraw.DrawMidText("생명력 " + to_string(m_iAddVital) + " 증가!!", WIDTH, HEIGHT*0.6f);
	ORIGINAL
}

void GameManager::StartBattle(int MonsterSelection)
{
	m_eSTATE = STATE_ING;
	string strTemp;
	string strVS = " vs ";
	for (int i = 0; i < 2*(WIDTH-2) - strVS.size(); i++)
	{
		strTemp += "-";
		if (i == (2 * (WIDTH - 2) - strVS.size())/2)
			strTemp += strVS;
	}
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	RED
	m_gmMapDraw.DrawMidText(strTemp, WIDTH, HEIGHT * 0.5f);
	m_gmMapDraw.DrawMidText("가위 : 1   바위 : 2   보 : 3", WIDTH, HEIGHT * 0.3f);
	m_gmCharacter[PLAYER]->ShowInfo(0);
	m_gmCharacter[MonsterSelection]->ShowInfo(20);
	while (m_eSTATE == STATE_ING)
	{
		int iPlayerRPS;
		iPlayerRPS = getch();
		if (iPlayerRPS >= '1' && iPlayerRPS <= '3')
		{
			//Display Player's RPS
			m_gmCharacter[PLAYER]->ThrowRPS(iPlayerRPS);
			//Display Monster's RPS(Random)
			int iMonsterRPS = rand() % 3 + '1';
			m_gmCharacter[MonsterSelection]->ThrowRPS(iMonsterRPS,MONSTER);
			
			//Win, Draw, Lose
			int iWDL = WinLoseDraw(iPlayerRPS, iMonsterRPS);
			switch ((WINDRAWLOSE)iWDL)
			{
			case WLD_WIN:
				m_gmCharacter[MonsterSelection]->Damage(m_gmCharacter[PLAYER]->GetAttack());
				m_gmCharacter[MonsterSelection]->ShowInfo(20);
				break;
			case WLD_DRAW:
				break;
			case WLD_LOSE:	
				m_gmCharacter[PLAYER]->Damage(m_gmCharacter[MonsterSelection]->GetAttack());
				m_gmCharacter[PLAYER]->ShowInfo(0);
				break;
			}
			//Check Win or Game Over
			CheckGameEnd(MonsterSelection);
		}
	}
	getch();
	if (m_eSTATE == STATE_OVER)
		return;
	else if (m_eSTATE == STATE_WIN)
	{
		//몬스터 체력 초기화
		m_gmCharacter[MonsterSelection]->Respawn();
		//골드 + 경험치 획득
		m_gmCharacter[PLAYER]->GetReward(m_gmCharacter[MonsterSelection]->GetGetExp(), m_gmCharacter[MonsterSelection]->GetGold());
		//LEVEL업
		if (m_gmCharacter[PLAYER]->GetCurExp() >= m_gmCharacter[PLAYER]->GetExp())
		{
			m_iAddAttack = rand() % 5 + 1;
			m_iAddVital = rand() % 10 + 1;
			m_gmCharacter[PLAYER]->LevelUp(m_iAddAttack, m_iAddVital, ADD_EXP);
			DispLevelUp();
			getch();
		}
	}
}
void GameManager::DispDetailList(string str)
{	

}
void GameManager::DispWeaponList(int weaponSelection)
{
	string strType;
	switch ((WEAPON_TYPE)weaponSelection)
	{
	case WEAPON_TYPE_DAGGER:
		strType = "Dagger";
		DispDetailList(strType);
		break;
	case WEAPON_TYPE_GUN:
		strType = "Gun";
		DispDetailList(strType);
		break;
	case WEAPON_TYPE_SWORD:
		strType = "Sword";
		DispDetailList(strType);
		break;
	case WEAPON_TYPE_WAND:
		strType = "Wand";
		DispDetailList(strType);
		break;
	case WEAPON_TYPE_BOW:
		strType = "Bow";
		DispDetailList(strType);
		break;
	case WEAPON_TYPE_HAMMER:
		strType = "Hammer";
		DispDetailList(strType);
		break;
	}
}

void GameManager::DispShop()
{
	int iShopSelection;
	int iEnterCusorX = (WIDTH - 8) / 2;
	int iEnterCusorY = HEIGHT * 0.3f + 2;
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	m_gmMapDraw.DrawMidText("♧ ♣ S H O P ♣ ♧",WIDTH,HEIGHT*0.3f);
	m_gmMapDraw.DrawMidText("Dagger  ", WIDTH, HEIGHT * 0.3f + 2);
	m_gmMapDraw.DrawMidText("Gun     ", WIDTH, HEIGHT * 0.3f + 4);
	m_gmMapDraw.DrawMidText("Sword   ", WIDTH, HEIGHT * 0.3f + 6);
	m_gmMapDraw.DrawMidText("Wand    ", WIDTH, HEIGHT * 0.3f + 8);
	m_gmMapDraw.DrawMidText("Bow     ", WIDTH, HEIGHT * 0.3f + 10);
	m_gmMapDraw.DrawMidText("Hammer  ", WIDTH, HEIGHT * 0.3f + 12);
	m_gmMapDraw.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.3f + 12);
	iShopSelection = m_gmMapDraw.MenuSelectCursor(NUMBER_WEAPON_TYPE + 1, 2, iEnterCusorX, iEnterCusorY);
	switch ((WEAPON_TYPE)iShopSelection)
	{
	case WEAPON_TYPE_DAGGER:
		DispWeaponList(iShopSelection);
		break;
	case WEAPON_TYPE_GUN:
		DispWeaponList(iShopSelection);

		break;
	case WEAPON_TYPE_SWORD:
		DispWeaponList(iShopSelection);
		break;
	case WEAPON_TYPE_WAND:
		DispWeaponList(iShopSelection);
		break;
	case WEAPON_TYPE_BOW:
		DispWeaponList(iShopSelection);
		break;
	case WEAPON_TYPE_HAMMER:
		DispWeaponList(iShopSelection);
		break;
	case WEAPON_TYPE_END:
		return;
	}
}

void GameManager::EnterDungeon()
{
	int iMonsterSelect;
	int iEnterCusorX = (WIDTH - 14) / 2;
	int iEnterCusorY = HEIGHT * 0.2f + 5;
	DispEntrance();
	iMonsterSelect = m_gmMapDraw.MenuSelectCursor(MAX_MONSTER+1, 2, iEnterCusorX, iEnterCusorY);
	switch (iMonsterSelect)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		StartBattle(iMonsterSelect);
	case 7:
		return;
	}

}

void GameManager::DispSave()
{
	int iEnterCusorX = (WIDTH - 8) / 2;
	int iEnterCusorY = HEIGHT * 0.3f + 2;
	m_gmMapDraw.BoxErase(WIDTH, HEIGHT);
	for (int i = 0; i < NUMBER_SAVE_SLOT; i++)
	{
		m_gmMapDraw.DrawMidText(to_string(i) + "번 슬롯 : <파일 여부 : >", WIDTH, HEIGHT * 0.3f);
	}
	m_gmMapDraw.DrawMidText("♧ ♣ S H O P ♣ ♧", WIDTH, HEIGHT * 0.3f);
	m_gmMapDraw.DrawMidText("Dagger  ", WIDTH, HEIGHT * 0.3f + 2);
	m_gmMapDraw.DrawMidText("Gun     ", WIDTH, HEIGHT * 0.3f + 4);
	m_gmMapDraw.DrawMidText("Sword   ", WIDTH, HEIGHT * 0.3f + 6);
	m_gmMapDraw.DrawMidText("Wand    ", WIDTH, HEIGHT * 0.3f + 8);
	m_gmMapDraw.DrawMidText("Bow     ", WIDTH, HEIGHT * 0.3f + 10);
	m_gmMapDraw.DrawMidText("Hammer  ", WIDTH, HEIGHT * 0.3f + 12);
	m_gmMapDraw.DrawMidText("돌아가기", WIDTH, HEIGHT * 0.3f + 12);
}

void GameManager::StartGame()
{
	int iSelect;
	int iMainMenuCount = 6;
	int iMainMenuAddCol = 2;
	int iMenuCusorX = (WIDTH - 10) / 2;
	int iMenuCusorY = HEIGHT * 0.3f + 2;
	while (1)
	{
		//Display Play Menu
		DispPlayMenu();
		iSelect = m_gmMapDraw.MenuSelectCursor(iMainMenuCount, iMainMenuAddCol, iMenuCusorX, iMenuCusorY);
		switch ((PLAY_MENU)iSelect)
		{
		case PLAY_MENU_DUNGEON:
			EnterDungeon();
			if (m_eSTATE == STATE_OVER)
				return;
			else
				break;
		case PLAY_MENU_PLAYER_INFO:
			DispInfo(iSelect);
			break;
		case PLAY_MENU_MONSTER_INFO:
			DispInfo(iSelect);
			break;
		case PLAY_MENU_WEAPONG_SHOP:
			DispShop();
			break;
		case PLAY_MENU_SAVE:
			DispSave();
			break;
		case PLAY_MENU_EXIT:
			//Make delete function***
			for (int i = 0; i < MAX_CHARACTER; i++)
			{
				if (m_gmCharacter[i] != NULL)
					delete m_gmCharacter[i];
			}
			return;
		}
	}
}

void GameManager::LoadWeapon()
{

}

void GameManager::RunGame()
{
	int iLobyMenuCount = 3;
	int iLobyCursorX = (WIDTH-8)/2;
	int iLobyCursorY = HEIGHT*0.4f;
	int iLobyAddCol = 3;
	//Set Console Window
	SetConsoleWindow(WIDTH, HEIGHT);
	//To make random RPS of Monster
	srand((unsigned)time(NULL));
	//Load Weapon Info
	LoadWeapon();

	while (1)
	{
		int iSelect;
		DispLoby();
		iSelect = m_gmMapDraw.MenuSelectCursor(iLobyMenuCount, iLobyAddCol, iLobyCursorX, iLobyCursorY);
		switch ((LOBY_MENU)iSelect)
		{
		case LOBY_MENU_NEW:
			//Init & Set
			NewGameSet();
			//Game Start
			StartGame();
			break;
		case LOBY_MENU_LOAD:
			break;
		case LOBY_MENU_EXIT:
			return;
		}
	}
}