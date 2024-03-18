#include "MyPokemonLevel.h"
#include "Pokemon3rdGen_Core.h"
#include <EngineCore/Actor.h>
#include "BattleHelper.h"

UMyPokemonLevel::UMyPokemonLevel()
{
}

UMyPokemonLevel::~UMyPokemonLevel()
{
}

void UMyPokemonLevel::BeginPlay()
{
	UMenuUILevel::BeginPlay();

	BackGround = SpawnActor<AMyPokemonBackGround>();
	Slot1st = SpawnActor<AMyPokemonSlot>();
	Slot2nd = SpawnActor<AMyPokemonSlot>();
	Slot3rd = SpawnActor<AMyPokemonSlot>();
	Slot4th = SpawnActor<AMyPokemonSlot>();
	Slot5th = SpawnActor<AMyPokemonSlot>();
	Slot6th = SpawnActor<AMyPokemonSlot>();

	CancleButton = SpawnActor<AMyPokemonCancle>();

	SelectBox = SpawnActor<AMyPokemonSelectBox>();
}

void UMyPokemonLevel::Tick(float _DeltaTime)
{
	UMenuUILevel::Tick(_DeltaTime);

	switch (State)
	{
	case EMyPokemonState::Base:
		BaseState();
		break;
	case EMyPokemonState::Switch:
		SwitchState();
		break;
	case EMyPokemonState::BattleSwitch:
		BattleSwitch();
		break;
	default:
		break;
	}
}

void UMyPokemonLevel::LevelStart(ULevel* _PrevLevel)
{
	PrevLevelName = _PrevLevel->GetName();

	if (UEngineString::ToUpper("BattleLevel") == _PrevLevel->GetName())
	{
		State = EMyPokemonState::BattleSwitch;
	}
	else
	{
		State = EMyPokemonState::Base;
	}

	SelectSlot = 0;

	Slot2nd->IsEmpty(163.0f, 20.5f);
	Slot3rd->IsEmpty(163.0f, 20.5f + (24.0f * 1));
	Slot4th->IsEmpty(163.0f, 20.5f + (24.0f * 2));
	Slot5th->IsEmpty(163.0f, 20.5f + (24.0f * 3));
	Slot6th->IsEmpty(163.0f, 20.5f + (24.0f * 4));

	UIEntry = dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->GetEntry();

	SetAllEntryStatus();
}

void UMyPokemonLevel::LevelEnd(ULevel* _NextLevel)
{
	dynamic_cast<Pokemon3rdGen_Core*>(GEngine)->SetEntry(UIEntry);
}

void UMyPokemonLevel::BaseState()
{
	if (false == IsUseMenu)
	{
		if (true == UEngineInput::IsDown('W'))
		{
			PrevSelectSlot = SelectSlot;
			--SelectSlot;
			if (0 > SelectSlot)
			{
				SelectSlot = 6;
			}
		}
		else if (true == UEngineInput::IsDown('S'))
		{
			PrevSelectSlot = SelectSlot;
			++SelectSlot;
			if (6 < SelectSlot)
			{
				SelectSlot = 0;
			}
		}
		else if (true == UEngineInput::IsDown('A') || true == UEngineInput::IsDown('D'))
		{
			if (0 == SelectSlot)
			{
				if (0 == PrevSelectSlot)
				{
					SelectSlot = 1;
					PrevSelectSlot = SelectSlot;
				}
				else
				{
					SelectSlot = PrevSelectSlot;
					PrevSelectSlot = SelectSlot;
				}
			}
			else
			{
				PrevSelectSlot = SelectSlot;
				SelectSlot = 0;
			}
		}
		else if (true == UEngineInput::IsDown('P') && 6 != SelectSlot)
		{
			IsUseMenu = true;
			CursorSelect = ESelectBoxCursor::Summary;
			SelectBox->SetSelectBoxActive(true);
		}
		else if (true == UEngineInput::IsDown('L'))
		{
			GEngine->ChangeLevel(PrevLevelName);
		}
	}
	else
	{
		switch (CursorSelect)
		{
		case ESelectBoxCursor::Summary:
			SelectBox->SetCursorLocation(156.0f, 114.0f);
			break;
		case ESelectBoxCursor::Switch:
			SelectBox->SetCursorLocation(156.0f, 130.0f);
			break;
		case ESelectBoxCursor::Cancle:
			SelectBox->SetCursorLocation(156.0f, 146.0f);
			break;
		default:
			break;
		}

		if (true == UEngineInput::IsDown('W'))
		{
			switch (CursorSelect)
			{
			case ESelectBoxCursor::Summary:
				CursorSelect = ESelectBoxCursor::Cancle;
				break;
			case ESelectBoxCursor::Switch:
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			case ESelectBoxCursor::Cancle:
				CursorSelect = ESelectBoxCursor::Switch;
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('S'))
		{
			switch (CursorSelect)
			{
			case ESelectBoxCursor::Summary:
				CursorSelect = ESelectBoxCursor::Switch;
				break;
			case ESelectBoxCursor::Switch:
				CursorSelect = ESelectBoxCursor::Cancle;
				break;
			case ESelectBoxCursor::Cancle:
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('P'))
		{
			switch (CursorSelect)
			{
			case ESelectBoxCursor::Summary:
				break;
			case ESelectBoxCursor::Switch:
				IsUseMenu = false;
				SelectBox->SetSelectBoxActive(false);
				CursorSelect = ESelectBoxCursor::Summary;
				State = EMyPokemonState::Switch;
				break;
			case ESelectBoxCursor::Cancle:
				IsUseMenu = false;
				SelectBox->SetSelectBoxActive(false);
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('L'))
		{
			IsUseMenu = false;
			SelectBox->SetSelectBoxActive(false);
			CursorSelect = ESelectBoxCursor::Summary;
		}
	}

	SetAllEntryStatus();

	switch (SelectSlot)
	{
	case 0:
		Slot1st->SetSlotRenderer("MyPokemon_First_Select.png", 44.0f, 46.5f);
		CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
		CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
		CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
		CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
		CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		break;
	case 1:
		if (false == Slot2nd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (0 == PrevSelectSlot)
			{
				SelectSlot = 6;
			}
			else
			{
				SelectSlot = 0;
			}
		}
		break;
	case 2:
		if (false == Slot3rd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (1 == PrevSelectSlot)
			{
				SelectSlot = 6;
			}
			else
			{
				SelectSlot = 1;
			}
		}
		break;
	case 3:
		if (false == Slot4th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 1));
			Slot4th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (2 == PrevSelectSlot)
			{
				SelectSlot = 6;
			}
			else
			{
				SelectSlot = 2;
			}
		}
		break;
	case 4:
		if (false == Slot5th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			Slot5th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (3 == PrevSelectSlot)
			{
				SelectSlot = 6;
			}
			else
			{
				SelectSlot = 3;
			}
		}
		break;
	case 5:
		if (false == Slot6th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			Slot6th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (4 == PrevSelectSlot)
			{
				SelectSlot = 6;
			}
			else
			{
				SelectSlot = 4;
			}
		}
		break;
	case 6:
		Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
		CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
		CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
		CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
		CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
		CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button_Select.png");

		if (true == UEngineInput::IsDown('P'))
		{
			GEngine->ChangeLevel(PrevLevelName);
		}
		break;
	default:
		break;
	}

	if (true == UEngineInput::IsDown('R'))
	{
		UIEntry.front().Hp = UIEntry.front().MaxHp;
	}
}

void UMyPokemonLevel::SwitchState()
{
	if (true == UEngineInput::IsDown('W'))
	{
		PrevSelectSlot = SelectSlot;
		--SelectSlot;
		if (0 > SelectSlot)
		{
			SelectSlot = 5;
		}
	}
	else if (true == UEngineInput::IsDown('S'))
	{
		PrevSelectSlot = SelectSlot;
		++SelectSlot;
		if (5 < SelectSlot)
		{
			SelectSlot = 0;
		}
	}
	else if (true == UEngineInput::IsDown('A') || true == UEngineInput::IsDown('D'))
	{
		if (0 == SelectSlot)
		{
			if (0 == PrevSelectSlot)
			{
				SelectSlot = 1;
				PrevSelectSlot = SelectSlot;
			}
			else
			{
				SelectSlot = PrevSelectSlot;
				PrevSelectSlot = SelectSlot;
			}
		}
		else
		{
			PrevSelectSlot = SelectSlot;
			SelectSlot = 0;
		}
	}

	SetAllEntryStatus();

	switch (SelectSlot)
	{
	case 0:
		Slot1st->SetSlotRenderer("MyPokemon_First_Select.png", 44.0f, 46.5f);
		CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
		CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
		CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
		CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
		CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		break;
	case 1:
		if (false == Slot2nd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			SelectSlot = 0;
		}
		break;
	case 2:
		if (false == Slot3rd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (1 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 1;
			}
		}
		break;
	case 3:
		if (false == Slot4th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 1));
			Slot4th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (2 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 2;
			}
		}
		break;
	case 4:
		if (false == Slot5th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			Slot5th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (3 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 3;
			}
		}
		break;
	case 5:
		if (false == Slot6th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			Slot6th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (4 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 4;
			}
		}
		break;
	default:
		break;
	}

	switch (SwitchSelect)
	{
	case 0:
		SwitchSelect1 = SelectSlot;
		++SwitchSelect;
		break;
	case 1:
		switch (SelectSlot)
		{
		case 0:
			Slot1st->SetSlotRenderer("MyPokemon_First_Select.png", 44.0f, 46.5f);
			break;
		case 1:
			if (false == Slot2nd->GetEmpty())
			{
				Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f);
			}
			else
			{
				if (0 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 0;
				}
			}
			break;
		case 2:
			if (false == Slot3rd->GetEmpty())
			{
				Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 1));
			}
			else
			{
				if (1 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 1;
				}
			}
			break;
		case 3:
			if (false == Slot4th->GetEmpty())
			{
				Slot4th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 2));
			}
			else
			{
				if (2 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 2;
				}
			}
			break;
		case 4:
			if (false == Slot5th->GetEmpty())
			{
				Slot5th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 3));
			}
			else
			{
				if (3 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 3;
				}
			}
			break;
		case 5:
			if (false == Slot6th->GetEmpty())
			{
				Slot6th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 4));
			}
			else
			{
				if (4 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 4;
				}
			}
			break;
		default:
			break;
		}

		switch (SwitchSelect1)
		{
		case 0:
			Slot1st->SetSlotRenderer("MyPokemon_First_Change.png", 44.0f, 46.5f);
			if (SelectSlot == SwitchSelect1)
			{
				Slot1st->SetSlotRenderer("MyPokemon_First_Select_Change.png", 44.0f, 46.5f);
			}
			break;
		case 1:
			if (false == Slot2nd->GetEmpty())
			{
				Slot2nd->SetSlotRenderer("MyPokemon_Slot_Change.png", 163.0f, 20.5f);
				if (SelectSlot == SwitchSelect1)
				{
					Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select_Change.png", 163.0f, 20.5f);
				}
			}
			else
			{
				if (0 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 0;
				}
			}
			break;
		case 2:
			if (false == Slot3rd->GetEmpty())
			{
				Slot3rd->SetSlotRenderer("MyPokemon_Slot_Change.png", 163.0f, 20.5f + (24.0f * 1));
				if (SelectSlot == SwitchSelect1)
				{
					Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select_Change.png", 163.0f, 20.5f + (24.0f * 1));
				}
			}
			else
			{
				if (1 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 1;
				}
			}
			break;
		case 3:
			if (false == Slot4th->GetEmpty())
			{
				Slot4th->SetSlotRenderer("MyPokemon_Slot_Change.png", 163.0f, 20.5f + (24.0f * 2));
				if (SelectSlot == SwitchSelect1)
				{
					Slot4th->SetSlotRenderer("MyPokemon_Slot_Select_Change.png", 163.0f, 20.5f + (24.0f * 2));
				}
			}
			else
			{
				if (2 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 2;
				}
			}
			break;
		case 4:
			if (false == Slot5th->GetEmpty())
			{
				Slot5th->SetSlotRenderer("MyPokemon_Slot_Change.png", 163.0f, 20.5f + (24.0f * 3));
				if (SelectSlot == SwitchSelect1)
				{
					Slot5th->SetSlotRenderer("MyPokemon_Slot_Select_Change.png", 163.0f, 20.5f + (24.0f * 3));
				}
			}
			else
			{
				if (3 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 3;
				}
			}
			break;
		case 5:
			if (false == Slot6th->GetEmpty())
			{
				Slot6th->SetSlotRenderer("MyPokemon_Slot_Change.png", 163.0f, 20.5f + (24.0f * 4));
				if (SelectSlot == SwitchSelect1)
				{
					Slot6th->SetSlotRenderer("MyPokemon_Slot_Select_Change.png", 163.0f, 20.5f + (24.0f * 4));
				}
			}
			else
			{
				if (4 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 4;
				}
			}
			break;
		default:
			break;
		}

		if (true == UEngineInput::IsDown('P'))
		{
			SwitchSelect2 = SelectSlot;
			++SwitchSelect;
		}
		break;
	case 2:
		ChangeEntry(SwitchSelect1, SwitchSelect2);
		SwitchSelect1 = 6;
		SwitchSelect2 = 6;
		SwitchSelect = 0;
		State = EMyPokemonState::Base;
		break;
	default:
		break;
	}

	if (true == UEngineInput::IsDown('R'))
	{
		UIEntry.front().Hp = UIEntry.front().MaxHp;
	}
}

void UMyPokemonLevel::BattleSwitch()
{
	if (false == IsUseMenu)
	{
		if (true == UEngineInput::IsDown('W'))
		{
			PrevSelectSlot = SelectSlot;
			--SelectSlot;
			if (0 > SelectSlot)
			{
				SelectSlot = 5;
			}
		}
		else if (true == UEngineInput::IsDown('S'))
		{
			PrevSelectSlot = SelectSlot;
			++SelectSlot;
			if (5 < SelectSlot)
			{
				SelectSlot = 0;
			}
		}
		else if (true == UEngineInput::IsDown('A') || true == UEngineInput::IsDown('D'))
		{
			if (0 == SelectSlot)
			{
				if (0 == PrevSelectSlot)
				{
					SelectSlot = 1;
					PrevSelectSlot = SelectSlot;
				}
				else
				{
					SelectSlot = PrevSelectSlot;
					PrevSelectSlot = SelectSlot;
				}
			}
			else
			{
				PrevSelectSlot = SelectSlot;
				SelectSlot = 0;
			}
		}
		else if (true == UEngineInput::IsDown('P'))
		{
			IsUseMenu = true;
			CursorSelect = ESelectBoxCursor::Summary;
			SelectBox->SetSelectBoxActive(true);
		}
		else if (true == UEngineInput::IsDown('L'))
		{
			GEngine->ChangeLevel(PrevLevelName);
		}
	}
	else
	{
		switch (CursorSelect)
		{
		case ESelectBoxCursor::Summary:
			SelectBox->SetCursorLocation(156.0f, 114.0f);
			break;
		case ESelectBoxCursor::Switch:
			SelectBox->SetCursorLocation(156.0f, 130.0f);
			break;
		case ESelectBoxCursor::Cancle:
			SelectBox->SetCursorLocation(156.0f, 146.0f);
			break;
		default:
			break;
		}

		if (true == UEngineInput::IsDown('W'))
		{
			switch (CursorSelect)
			{
			case ESelectBoxCursor::Summary:
				CursorSelect = ESelectBoxCursor::Cancle;
				break;
			case ESelectBoxCursor::Switch:
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			case ESelectBoxCursor::Cancle:
				CursorSelect = ESelectBoxCursor::Switch;
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('S'))
		{
			switch (CursorSelect)
			{
			case ESelectBoxCursor::Summary:
				CursorSelect = ESelectBoxCursor::Switch;
				break;
			case ESelectBoxCursor::Switch:
				CursorSelect = ESelectBoxCursor::Cancle;
				break;
			case ESelectBoxCursor::Cancle:
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('P'))
		{
			switch (CursorSelect)
			{
			case ESelectBoxCursor::Summary:
				break;
			case ESelectBoxCursor::Switch:
				SwitchSelect = 2;
				SwitchSelect2 = SelectSlot;
				IsUseMenu = false;
				SelectBox->SetSelectBoxActive(false);
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			case ESelectBoxCursor::Cancle:
				IsUseMenu = false;
				SelectBox->SetSelectBoxActive(false);
				CursorSelect = ESelectBoxCursor::Summary;
				break;
			default:
				break;
			}
		}
		else if (true == UEngineInput::IsDown('L'))
		{
			IsUseMenu = false;
			SelectBox->SetSelectBoxActive(false);
			CursorSelect = ESelectBoxCursor::Summary;
		}
	}

	SetAllEntryStatus();

	switch (SelectSlot)
	{
	case 0:
		Slot1st->SetSlotRenderer("MyPokemon_First_Select.png", 44.0f, 46.5f);
		CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
		CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
		CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
		CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
		CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
		CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		break;
	case 1:
		if (false == Slot2nd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			SelectSlot = 0;
		}
		break;
	case 2:
		if (false == Slot3rd->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (1 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 1;
			}
		}
		break;
	case 3:
		if (false == Slot4th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 1));
			Slot4th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (2 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 2;
			}
		}
		break;
	case 4:
		if (false == Slot5th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			Slot5th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 3));
			CheakEmptySlot(Slot6th, 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (3 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 3;
			}
		}
		break;
	case 5:
		if (false == Slot6th->GetEmpty())
		{
			Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
			CheakEmptySlot(Slot2nd, 163.0f, 20.5f);
			CheakEmptySlot(Slot3rd, 163.0f, 20.5f + (24.0f * 1));
			CheakEmptySlot(Slot4th, 163.0f, 20.5f + (24.0f * 2));
			CheakEmptySlot(Slot5th, 163.0f, 20.5f + (24.0f * 3));
			Slot6th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 4));
			CancleButton->SetCancleRenderer("MyPokemon_Cancel_Button.png");
		}
		else
		{
			if (4 == PrevSelectSlot)
			{
				SelectSlot = 0;
			}
			else
			{
				SelectSlot = 4;
			}
		}
		break;
	default:
		break;
	}

	switch (SwitchSelect)
	{
	case 0:
		SwitchSelect1 = 0;
		++SwitchSelect;
		break;
	case 1:
		switch (SelectSlot)
		{
		case 0:
			Slot1st->SetSlotRenderer("MyPokemon_First_Select.png", 44.0f, 46.5f);
			break;
		case 1:
			if (false == Slot2nd->GetEmpty())
			{
				Slot2nd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f);
			}
			else
			{
				if (0 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 0;
				}
			}
			break;
		case 2:
			if (false == Slot3rd->GetEmpty())
			{
				Slot3rd->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 1));
			}
			else
			{
				if (1 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 1;
				}
			}
			break;
		case 3:
			if (false == Slot4th->GetEmpty())
			{
				Slot4th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 2));
			}
			else
			{
				if (2 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 2;
				}
			}
			break;
		case 4:
			if (false == Slot5th->GetEmpty())
			{
				Slot5th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 3));
			}
			else
			{
				if (3 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 3;
				}
			}
			break;
		case 5:
			if (false == Slot6th->GetEmpty())
			{
				Slot6th->SetSlotRenderer("MyPokemon_Slot_Select.png", 163.0f, 20.5f + (24.0f * 4));
			}
			else
			{
				if (4 == PrevSelectSlot)
				{
					SelectSlot = 5;
				}
				else
				{
					SelectSlot = 4;
				}
			}
			break;
		default:
			break;
		}
		break;
	case 2:
		ChangeEntry(SwitchSelect1, SwitchSelect2);
		SwitchSelect1 = 6;
		SwitchSelect2 = 6;
		SwitchSelect = 0;
		BattleHelper::IsSwitch = true;
		GEngine->ChangeLevel(PrevLevelName);
		break;
	default:
		break;
	}

	if (true == UEngineInput::IsDown('R'))
	{
		UIEntry.front().Hp = UIEntry.front().MaxHp;
	}
}

void UMyPokemonLevel::SetAllEntryStatus()
{
	std::list<PokemonInfo>::iterator UIEntryIter;

	UIEntryIter = UIEntry.begin();
	Slot1st->SetSlotRenderer("MyPokemon_First.png", 44.0f, 46.5f);
	Slot1st->SetDotRenderer(16.0f, 41.0f, *UIEntryIter);
	Slot1st->SetDataRenderers(*UIEntryIter,
		30.0f, 42.0f,
		46.0f, 51.6f,
		76.0f, 52.0f,
		56.0f, 60.5f,
		63.0f, 68.5f,
		64.0f, 68.5f);

	UIEntryIter++;
	if (UIEntryIter != UIEntry.end())
	{
		Slot2nd->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f);
		Slot2nd->SetDotRenderer(101.0f, 23.0f, *UIEntryIter);
		Slot2nd->SetDataRenderers(*UIEntryIter,
			115.0f, 18.0f,
			134.0f, 27.6f,
			164.0f, 28.0f,
			208.0f, 19.5f,
			215.0f, 26.5f,
			216.0f, 26.5f);

		UIEntryIter++;
		if (UIEntryIter != UIEntry.end())
		{
			Slot3rd->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 1));
			Slot3rd->SetDotRenderer(101.0f, 23.0f + (24.0f * 1), *UIEntryIter);
			Slot3rd->SetDataRenderers(*UIEntryIter,
				115.0f, 18.0f + (24.0f * 1),
				134.0f, 27.6f + (24.0f * 1),
				164.0f, 28.0f + (24.0f * 1),
				208.0f, 19.5f + (24.0f * 1),
				215.0f, 26.5f + (24.0f * 1),
				216.0f, 26.5f + (24.0f * 1));

			UIEntryIter++;
			if (UIEntryIter != UIEntry.end())
			{
				Slot4th->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 2));
				Slot4th->SetDotRenderer(101.0f, 23.0f + (24.0f * 2), *UIEntryIter);
				Slot4th->SetDataRenderers(*UIEntryIter,
					115.0f, 18.0f + (24.0f * 2),
					134.0f, 27.6f + (24.0f * 2),
					164.0f, 28.0f + (24.0f * 2),
					208.0f, 19.5f + (24.0f * 2),
					215.0f, 26.5f + (24.0f * 2),
					216.0f, 26.5f + (24.0f * 2));

				UIEntryIter++;
				if (UIEntryIter != UIEntry.end())
				{
					Slot5th->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 3));
					Slot5th->SetDotRenderer(101.0f, 23.0f + (24.0f * 3), *UIEntryIter);
					Slot5th->SetDataRenderers(*UIEntryIter,
						115.0f, 18.0f + (24.0f * 3),
						134.0f, 27.6f + (24.0f * 3),
						164.0f, 28.0f + (24.0f * 3),
						208.0f, 19.5f + (24.0f * 3),
						215.0f, 26.5f + (24.0f * 3),
						216.0f, 26.5f + (24.0f * 3));

					UIEntryIter++;
					if (UIEntryIter != UIEntry.end())
					{
						Slot6th->SetSlotRenderer("MyPokemon_Slot.png", 163.0f, 20.5f + (24.0f * 4));
						Slot6th->SetDotRenderer(101.0f, 23.0f + (24.0f * 4), *UIEntryIter);
						Slot6th->SetDataRenderers(*UIEntryIter,
							115.0f, 18.0f + (24.0f * 4),
							134.0f, 27.6f + (24.0f * 4),
							164.0f, 28.0f + (24.0f * 4),
							208.0f, 19.5f + (24.0f * 4),
							215.0f, 26.5f + (24.0f * 4),
							216.0f, 26.5f + (24.0f * 4));
					}
				}
			}
		}
	}
}

void UMyPokemonLevel::CheakEmptySlot(AMyPokemonSlot* _Slot, float _Slot_X, float _Slot_Y)
{
	if (true == _Slot->GetEmpty())
	{
		_Slot->IsEmpty(_Slot_X, _Slot_Y);
	}
	else
	{
		_Slot->SetSlotRenderer("MyPokemon_Slot.png", _Slot_X, _Slot_Y);
	}
}

void UMyPokemonLevel::ChangeEntry(int _Select1, int _Select2)
{
	std::list<PokemonInfo>::iterator UIEntryIter1;
	std::list<PokemonInfo>::iterator UIEntryIter2;

	UIEntryIter1 = std::next(UIEntry.begin(), _Select1);
	UIEntryIter2 = std::next(UIEntry.begin(), _Select2);

	PokemonInfo ChangeSave;
	ChangeSave = *UIEntryIter1;
	*UIEntryIter1 = *UIEntryIter2;
	*UIEntryIter2 = ChangeSave;
}